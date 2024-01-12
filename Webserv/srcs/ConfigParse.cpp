#include "../inc/ConfigParse.hpp"

ConfigParse::ConfigParse():_nb_server(0)
{

}
ConfigParse::~ConfigParse()
{

}

std::vector<ConfigServer>	ConfigParse::getServers()
{
	return (this->_servers);
}

/* checking and read config file, split servers to strings and creating vector of servers */
int ConfigParse::createCluster(const std::string &config_file)
{
	std::string		content;
	ConfigFile		file(config_file);
	content = file.readFile();
	if (content.empty())
		throw Exception_ConfigParse("File is empty");
	removeComments(content);
	removeWhiteSpace(content);
	splitServers(content);
	if (this->_server_config.size() != this->_nb_server)
		throw Exception_ConfigParse("Somthing with size"); //rewrite the sentence
	for (size_t i = 0; i < this->_nb_server; i++)
	{
		ConfigServer server;
		createServer(this->_server_config[i], server);
		this->_servers.push_back(server);
//server.conf_print();
	}
	if (this->_nb_server > 1)
		checkServers();
	return (0);
}
void ConfigParse::checkServers()
{
	std::vector<ConfigServer>::iterator it1;
	std::vector<ConfigServer>::iterator it2;
	for(it1 = _servers.begin(); it1!=_servers.end() - 1; it1++){
		for(it2 = it1 +1; it2!=_servers.end();it2++){
			if(it1->getHost() == it2->getHost() && it1->getPort()== it2->getPort())
				throw Exception_ConfigParse(it1->getServerName() + " :host and port are duplicated!");
		}
	}
}
/*remove comments from char # to \n */
void ConfigParse::removeComments(std::string &content)
{
	size_t pos;

	pos = content.find('#');
	while (pos != std::string::npos)
	{
		size_t pos_end;
		pos_end = content.find('\n', pos);
		content.erase(pos, pos_end - pos);
		pos = content.find('#');
	}
}

/* deleting whitespaces in the start, end and in the content if more than one */
void ConfigParse::removeWhiteSpace(std::string &content)
{
	size_t	i = 0;

	while (content[i] && isspace(content[i]))
		i++;
	content = content.substr(i);
	i = content.length() - 1;
	while (i > 0 && isspace(content[i]))
		i--;
	content = content.substr(0, i + 1);
}

/* spliting servers on separetly strings in vector */
void ConfigParse::splitServers(std::string &content)
{
	size_t start = 0;
	size_t end = 1;

	if (content.find("server", 0) == std::string::npos )
		throw Exception_ConfigParse("Server did not find");
	while (start != end && start < content.length())
	{
		start = findStartServer(start, content);
		end = findEndServer(start, content);
		if (start == end)
			throw Exception_ConfigParse("problem with scope");
		this->_server_config.push_back(content.substr(start, end - start + 1));
		this->_nb_server++;
		start = end + 1;
	}
}

/* finding a server begin and return the index of { start of server */
size_t ConfigParse::findStartServer (size_t start, std::string &content)
{
	size_t i;

	for (i = start; content[i]; i++)
	{
		if (content[i] == 's')
			break ;
		if (!isspace(content[i]))
			throw  Exception_ConfigParse("Wrong character out of server scope{}");
	}
	if (!content[i])
		return (start);
	if (content.compare(i, 6, "server") != 0)
		throw Exception_ConfigParse("Wrong character out of server scope{}");
	i += 6;
	while (content[i] && isspace(content[i]))
		i++;
	if (content[i] == '{')
		return (i);
	else
		throw  Exception_ConfigParse("Wrong character out of server scope{}");

}

/* finding a server end and return the index of } end of server */
size_t ConfigParse::findEndServer (size_t start, std::string &content)
{
	size_t	i;
	size_t	scope;
	
	scope = 0;
	for (i = start + 1; content[i]; i++)
	{
		if (content[i] == '{')
			scope++;
		if (content[i] == '}')
		{
			if (!scope)
				return (i);
			scope--;
		}
	}
	return (start);
}

/* spliting line by separator */
std::vector<std::string> splitParametrs(std::string line, std::string sep)
{
	std::vector<std::string>	str;
	std::string::size_type		start, end;

	start = end = 0;
	while (1)
	{
		end = line.find_first_of(sep, start);
		if (end == std::string::npos)
			break;
		std::string tmp = line.substr(start, end - start);
		str.push_back(tmp);
		start = line.find_first_not_of(sep, end);
		if (start == std::string::npos)
			break;
	}
	return (str);
}

void ConfigParse::createServer(std::string &config, ConfigServer &server)
{
	std::vector<std::string>	parametrs;
	std::vector<std::string>	error_codes;
	int		flag_loc = 1;
	// bool	flag_autoindex = false;
	bool	flag_max_size = false;

	parametrs = splitParametrs(config += ' ', std::string(" \r\n\t;"));
	if (parametrs.size() < 3)
		throw  Exception_ConfigParse("Failed server validation");
	for (size_t i = 0; i < parametrs.size(); i++)
	{
		if (parametrs[i] == "listen" && (i + 1) < parametrs.size() && flag_loc)
		{
			if (server.getPort())
				throw  Exception_ConfigParse("Port is duplicated");
			server.setPort(parametrs[++i]);
		}
		else if (parametrs[i] == "location" && (i + 1) < parametrs.size())
		{
			std::string	path;
			i++;
			if (parametrs[i] == "{" || parametrs[i] == "}")
				throw  Exception_ConfigParse("Wrong character in server scope{}");
			path = parametrs[i];
			std::vector<std::string> codes;
			if (parametrs[++i] != "{")
				throw  Exception_ConfigParse("Wrong character in server scope{}");
			i++;
			while (i < parametrs.size() && parametrs[i] != "}")
				codes.push_back(parametrs[i++]);
			server.setLocation(path, codes);
			if (i < parametrs.size() && parametrs[i] != "}")
				throw  Exception_ConfigParse("Wrong character in server scope{}");
			flag_loc = 0;
		}
		else if (parametrs[i] == "host" && (i + 1) < parametrs.size() && flag_loc)
		{
			if (server.getHost())
				throw  Exception_ConfigParse("Host is duplicated");
			std::string host = parametrs[++i];
			size_t c = host.find(":");
			if (c != host.npos)
			{
				std::string port = host.substr(c+1);
				if (server.getPort())
					throw  Exception_ConfigParse("Port is duplicated");
				server.setPort(port);
				host = host.substr(0,c-0);
				std::cout<<"host"<<host<<std::endl;
			}
			server.setHost(host);
		}
		else if (parametrs[i] == "root" && (i + 1) < parametrs.size() && flag_loc)
		{
			if (!server.getRoot().empty())
				throw  Exception_ConfigParse("Root is duplicated");
			server.setRoot(parametrs[++i]);
		}
		else if (parametrs[i] == "error_page" && (i + 1) < parametrs.size() && flag_loc)
		{
			if (i + 1 <= parametrs.size())
				error_codes.push_back(parametrs[++i]);
			else
				throw Exception_ConfigParse("Wrong character with error pages " );
			if (i + 1 <= parametrs.size())
				error_codes.push_back(parametrs[++i]);
			else
				throw Exception_ConfigParse("Wrong character with error pages");
		}
		else if (parametrs[i] == "max_body" && (i + 1) < parametrs.size() && flag_loc)
		{
			if (flag_max_size)
				throw  Exception_ConfigParse("Client_max_body_size is duplicated");
			server.setMaxBody(parametrs[++i]);
			flag_max_size = true;
		}
		else if (parametrs[i] == "server_name" && (i + 1) < parametrs.size() && flag_loc)
		{
			if (!server.getServerName().empty())
				throw  Exception_ConfigParse("Server_name is duplicated");
			server.setServerName(parametrs[++i]);
		}
		else if ((parametrs[i] == "index" || parametrs[i] == "index_page") && (i + 1) < parametrs.size() && flag_loc)
		{
			if (!server.getIndex().empty())
				throw  Exception_ConfigParse("Index is duplicated");
			server.setIndex(parametrs[++i]);
		}

		else if (parametrs[i] != "}" && parametrs[i] != "{")
		{
			if (!flag_loc)
				throw  Exception_ConfigParse("Parametrs after location");
			else
				throw  Exception_ConfigParse("Unsupported directive");
		}
	}
	if (server.getRoot().empty())
		server.setRoot("./www");
	if (server.getHost() == 0)
		server.setHost("localhost");
	if (server.getIndex().empty())
		server.setIndex("index.html");
	server.setErrorPages(error_codes);
	std::string f_path = server.getRoot() + "/" + server.getIndex();
	if (!is_file(f_path))
		throw Exception_ConfigParse("index is not a file");
	if (!is_readable(f_path))
		throw Exception_ConfigParse("index is not readable");
	server.checkLocaitons();
}