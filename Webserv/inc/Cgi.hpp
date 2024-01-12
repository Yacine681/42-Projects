#ifndef CGI_HPP
#define CGI_HPP

#include	"utiles.hpp"
#include	"Location.hpp"
#include	"Request.hpp"

class Request;
class Cgi{

	private:
		std::map<std::string, std::string>	str_env;
		char								**_env;
		char								**_argv;
		pid_t								_pid;
		std::string							_cgi_path;
		std::string							_cgi_file;
		short								_code;
		int									_exit_status;
		int									_client_socket;
		
	public:
		int		_pipe[2];

		Cgi();
		~Cgi();
		
		void	setPid(pid_t cgi_pid);
		void	setCgiPath(const std::string &cgi_path);
		void	setCgiFile(const std::string &file);
		pid_t	getPid();
		short	getcode();
		void	setSocket(int s);
		int		getSocket();
		void	setcode(short n);

		void	setStrEnv(Request &req);
		void	set_one_StrEnv(std::string str, std::string mssage);
		void	setCharEnv();
		// void	setArgv(std::string str, std::string mssage);
		void	setArgv_cpp(std::string mssage);
		void 	setArgv_python(std::string bodys, std::string ss);
		void	exc_Cgi();
		void	clear();
};

#endif