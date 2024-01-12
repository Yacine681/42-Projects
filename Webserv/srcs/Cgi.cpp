#include "../inc/Cgi.hpp"

Cgi::Cgi()
{
	_env = NULL;
	_argv = NULL;
	_pid = -1;
	_cgi_path = "";
	_cgi_file = "";
	_code = 0;
	_exit_status = 0;
	_client_socket = 0;
	_pipe[0] = -1;
	_pipe[1] = -1;
}
Cgi::~Cgi()
{
	if (this->_env)
	{
		for (int i = 0; this->_env[i]; i++)
			free(this->_env[i]);
		free(this->_env);
	}
	if (this->_argv)
	{
		for (int i = 0; this->_argv[i]; i++)
			free(_argv[i]);
		free(_argv);
	}
	this->str_env.clear();
}

void 	Cgi::setPid(pid_t pid)
{
	_pid = pid;
}
void 	Cgi::setCgiPath(const std::string &cgi_path)
{
	_cgi_path = cgi_path;

}
void 	Cgi::setCgiFile(const std::string &file)
{
		_cgi_file = file;
}
pid_t 	Cgi::getPid()
{
	return _pid;
}
short	Cgi::getcode()
{
	return _code;
}
void	Cgi::setcode(short n)
{
	 _code = n;
}

void	Cgi::setStrEnv(Request &req)
{
	str_env["SERVER_NAME"] = req.getHeader("host");
	str_env["CONTENT_TYPE"] = req.getHeader("content-type");
	str_env["CONTENT_LENGTH"] = req.getBody().length();
	str_env["SERVER_PROTOCOL"] = "HTTP/1.1";
	str_env["HTTP_COOKIE"] = req.getHeader("Cookie");
	str_env["GATEWAY_INTERFACE"] = std::string("CGI/1.1");
	
}

void	Cgi::setCharEnv()
{
	this->_env = (char **)calloc(sizeof(char *), this->str_env.size() + 1);
	if(this->_env == NULL)
	{
		_code =500;
		return ;
	}
	std::map<std::string, std::string>::const_iterator it = this->str_env.begin();
	for (int i = 0; it != this->str_env.end(); it++, i++)
	{
		std::string tmp = it->first + "=" + it->second;
		this->_env[i] = strdup(tmp.c_str());
	}
}

void	Cgi::setArgv_cpp(std::string mssage)
{
	this->_argv = (char **)calloc(sizeof(char *), 3);
	if(this->_argv == NULL)
	{
		_code =500;
		return ;
	}
	this->_argv[0] = strdup(_cgi_path.c_str());
	this->_argv[1] = strdup(mssage.c_str());
	this->_argv[2] = NULL;
}
void 	Cgi::setArgv_python(std::string bodys, std::string ss)
{
	this->_argv = (char **)calloc(sizeof(char *), 5);
	if(this->_argv == NULL)
	{
		_code =500;
		return ;
	}
	this->_argv[0] = strdup(_cgi_path.c_str());
	this->_argv[1] = strdup(_cgi_file.c_str());
	this->_argv[2] = strdup(bodys.c_str());
	this->_argv[3] = strdup(ss.c_str());
	this->_argv[4] = NULL;

}

void	Cgi::set_one_StrEnv(const std::string str, const std::string mssage)
{
	str_env[str] = mssage;
}

void 	Cgi::exc_Cgi()
{
	if (this->_argv[0] == NULL || this->_argv[1] == NULL)
	{
		_code = 500;
		return ;
	}
	if(pipe(_pipe) < 0)
	{
		_code = 500;
		return ;		
	}
	_pid = fork();
	if(_pid == 0)
	{
		dup2(_pipe[1], STDOUT_FILENO);
		close(_pipe[0]);
		_exit_status = execve(_argv[0], _argv, _env);
		exit(_exit_status);
	}
	else if(_pid < 0)
	{
		_code = 500;
		return ;		
	}
	else{
		waitpid(_pid, 0, 0);
		close(_pipe[1]);
		// exit(0);
	}
}
void	Cgi::clear()
{
	_pid = -1;
	_cgi_path = "";
	_cgi_file = "";
	_code = 0;
	_exit_status = 0;
	_client_socket = 0;
	_pipe[0] = -1;
	_pipe[1] = -1;
	if (this->_env)
	{
		for (int i = 0; this->_env[i]; i++)
			free(this->_env[i]);
		free(this->_env);
		_env = NULL;
	}
	if (this->_argv)
	{
		for (int i = 0; this->_argv[i]; i++)
			free(_argv[i]);
		free(_argv);
		_argv = NULL;
	}
	this->str_env.clear();
}
void	Cgi::setSocket(int s)
{
	_client_socket = s;
}

int		Cgi::getSocket()
{
	return _client_socket;
}