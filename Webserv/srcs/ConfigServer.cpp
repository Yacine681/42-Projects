#include "../inc/ConfigServer.hpp"

ConfigServer::ConfigServer()
{
	s_port = 0;	
	s_index = "";
	s_root = "";
	s_serverName = "";
	s_host = 0;
	s_timeout = 0;
	s_maxBody = 0;
	s_socketFd = 0;
	
	/* Init error pages */
	// s_errorPages[301] = "";
	// s_errorPages[302] = "";
	s_errorPages[400] = "";
	s_errorPages[401] = "";
	s_errorPages[402] = "";
	s_errorPages[403] = "";
	s_errorPages[404] = "";
	s_errorPages[405] = "";
	s_errorPages[406] = "";
	s_errorPages[500] = "";
	s_errorPages[501] = "";
	s_errorPages[502] = "";
	s_errorPages[503] = "";
	s_errorPages[505] = "";
	s_errorPages[505] = "";
}

ConfigServer::~ConfigServer() {}

ConfigServer::ConfigServer(const ConfigServer& obj)
{
	*this = obj;
}
ConfigServer& ConfigServer::operator=(const ConfigServer& obj)
{
	if (this != &obj)
	{
			s_port = obj.s_port;	
		s_index = obj.s_index;
		s_root = obj.s_root;
		s_serverName = obj.s_serverName;
		s_host = obj.s_host;
		s_timeout = obj.s_timeout;
		s_maxBody = obj.s_maxBody;
		s_socketFd = obj.s_socketFd;
		for(std::vector<Location> ::const_iterator it= obj.s_locations.begin(); it !=obj.s_locations.end();it++)
			s_locations.push_back(*it);
		for(std::map<int, std::string>::const_iterator it= obj.s_errorPages.begin(); it !=obj.s_errorPages.end();it++)
			s_errorPages[it->first] = it->second;
	}
	return *this;
}

void ConfigServer::setServerName(std::string serverName)
{
	s_serverName = serverName;
}

void ConfigServer::setHost(std::string host)
{
	if (host == "localhost")
		host = "127.0.0.1";
	struct sockaddr_in sockaddr;
	if(inet_pton(AF_INET,host.c_str(), &(sockaddr.sin_addr)) != 1)
		Exception_ConfigServer("not a valid ip or host adresse!");
	s_host = inet_addr(host.data());
}

void ConfigServer::setRoot(std::string root)
{
	if (!is_directory(root))
		Exception_ConfigServer("Wrong syntax: root");
	s_root = root;
}

void ConfigServer::setPort(std::string port)
{
	unsigned int portt;
	for (size_t i = 0; i < port.length(); i++)
	{
		if (!std::isdigit(port[i]))
			throw Exception_ConfigServer("Wrong syntax: port");
	}
	portt = ft_stoi((port));
	if (portt < 1 || portt > 65636)
		throw Exception_ConfigServer("Wrong syntax: port");
	s_port = (uint16_t)portt;
}

void ConfigServer::setSocketFd(int socketFd)
{
	s_socketFd = socketFd;
}

void ConfigServer::setMaxBody(std::string maxBody)
{
	for (size_t i = 0; i < maxBody.length(); i++)
	{
		if (maxBody[i] < '0' || maxBody[i] > '9')
			throw Exception_ConfigServer("Wrong syntax: client_max_body_size");
	}
	if (!ft_stoi(maxBody))
		throw Exception_ConfigServer("Wrong syntax: client_max_body_size");
	s_maxBody = ft_stoi(maxBody);
}

void ConfigServer::setErrorPages(std::vector<std::string> &parameter)
{
	if (parameter.empty())
		return ;
	if (parameter.size() % 2 != 0)
		throw Exception_ConfigServer("Error page initialization failed!");
	for (size_t i = 0; i < parameter.size() - 1; i++) {
 		for (size_t j = 0; j < parameter[i].size(); j++) {
   				if (!std::isdigit(parameter[i][j]))
					throw Exception_ConfigServer("Error code is invalid!");
   		}
		if (parameter[i].size() != 3)
			throw Exception_ConfigServer("Incorrect error code: " + parameter[i]);
		int code_error = ft_stoi(parameter[i]);
		if (statusCodeString(code_error) == "Undefined" || code_error < 400)
			throw Exception_ConfigServer("Incorrect error code: " + parameter[i]);
		i++;
		std::string path = parameter[i];
		if (!is_file(path))
			throw Exception_ConfigServer("Error page!");
		if (!is_readable(path))
			throw Exception_ConfigServer("Error Page not readable!");

	std::map<int, std::string>::iterator it = this->s_errorPages.find(code_error);
		if (it != s_errorPages.end())
			this->s_errorPages[code_error] = path;
		else
			this->s_errorPages.insert(std::make_pair(code_error, path));
	}
}

void ConfigServer::setIndex(std::string index)
{
	s_index = index;
}

bool method_locaton(std::string method)
{
	std::vector<std::string> methods;
	methods.push_back("get");
	methods.push_back("post");
	methods.push_back("delete");

	for (std::vector<std::string>::iterator it=methods.begin(); it != methods.end();it++)
	{
		if(*it == method)
			return true;
	}
	return false;
}

void ConfigServer::setLocation(std::string path, std::vector<std::string> parametr)
{
	 Location new_location;
	 std::vector<std::string> methods;
	 bool flag_methods = false;
	 bool flag_autoindex = false;


	new_location.setPath(path);
	for(size_t i = 0; i<parametr.size(); i++)
	{
		if (parametr[i] == "root" && (i + 1) < parametr.size())
		{
			std::string root = parametr[++i];
			if (!new_location.getRootLocation().empty())
				throw Exception_ConfigServer("Root of location is duplicated");
			if(!is_directory(root))
				throw Exception_ConfigServer("Root of location is not directory");
			new_location.setRootLocation(root);
		}
		else if (parametr[i] == "autoindex" && (i + 1) < parametr.size())
		{
			if (flag_autoindex)
				throw Exception_ConfigServer("Autoindex of location is duplicated");
			new_location.setAutoindex(parametr[++i]);
			flag_autoindex = true;
		}
		else if ((parametr[i] == "index" || parametr[i] == "index_page")&& (i + 1) < parametr.size())
		{
			if (!new_location.getIndexLocation().empty())
				throw Exception_ConfigServer("Index of location is duplicated");
			new_location.setIndexLocation(parametr[++i]);
		}
		else if (parametr[i] == "return" && (i + 1) < parametr.size())
		{
			if (!new_location.getReturn().empty())
				throw Exception_ConfigServer("Return of location is duplicated");
			new_location.setReturn(parametr[++i]);
		}
		else if (parametr[i] == "rewrite" && (i + 1) < parametr.size())
		{
			if (!new_location.getRewrite().empty())
				throw Exception_ConfigServer("Return of location is duplicated");
			new_location.setRewrite(parametr[++i]);
		}
		else if (parametr[i] == "cgi" && (i + 1) < parametr.size())
		{
			if (!new_location.getCgiPath().empty() || !new_location.getCgiExtension().empty() )
				throw Exception_ConfigServer("Return of location is duplicated");
			if (i + 1 < parametr.size())
				new_location.setCgiExtension(parametr[++i]);
			if (i + 1 < parametr.size())
				new_location.setCgiPath(parametr[++i]);
		}
		else if ((parametr[i] == "allow_methods" || parametr[i] == "allow") && (i + 1) < parametr.size())
		{
			if (flag_methods)
				throw Exception_ConfigServer("Allow_methods of location is duplicated");
			std::vector<std::string> methods;
			std::string mh;
			// mh = to_lower(parametr[++i]);
			if ((i +1) < parametr.size())
				mh = parametr[++i];
			else
				throw Exception_ConfigServer("Allow_methods of location is empty ");
			to_lower(mh);
 			if (!method_locaton(mh))
				throw Exception_ConfigServer("Allow_methods of location is empty ");
			methods.push_back(mh);
			mh.clear();
			if(i + 1 == parametr.size())
			{
				new_location.setMethods(methods);
				break;
			}
			mh = parametr[++i];
			to_lower(mh);
			if (method_locaton(mh))
			{
				methods.push_back(mh);
				mh.clear();
				if(i + 1 == parametr.size())
				{
					new_location.setMethods(methods);
					break;
				}
				mh = parametr[++i];
				to_lower(mh);
				if (method_locaton(mh))
				{
					methods.push_back(mh);
					if(i + 1== parametr.size())
					{
						new_location.setMethods(methods);
						break;
					}
				}
				else
					i--;
				mh.clear();
			}
			else
				i--;
			new_location.setMethods(methods);
		}		
		else if (i < parametr.size())
		{
			throw Exception_ConfigServer("Parametr in a location "+ path + " is invalid");
		}
	}
	s_locations.push_back(new_location);
}
void	ConfigServer::check_set_location(Location& loc)
{
	
	if(loc.getMethods().size()==0)
			throw Exception_ConfigServer(this->getServerName() + " , "+loc.getPath()+ " : location should have at list one method ");
	if (!loc.getPath().compare("/upload"))
	{
		std::string root = loc.getRootLocation();
		if(root.empty())
			throw Exception_ConfigServer("root of upload location can't be empty ");
		if(!is_exist(root))
			throw Exception_ConfigServer("root of upload location don't exist");
		if(!is_directory(root))
			throw Exception_ConfigServer("root of upload location is not dirctory ");
		if (!loc.getReturn().empty())	
			throw Exception_ConfigServer("upload location can't have redirection ");
		if (!loc.getRewrite().empty())
			throw Exception_ConfigServer("upload location can't have redirection ");
		if(!loc.getCgiPath().empty())
			throw Exception_ConfigServer("upload location can't have cgi ");
		if(!loc.getCgiExtension().empty())
			throw Exception_ConfigServer("upload location can't have cgi ");
		if (!loc.getIndexLocation().empty())
		{
			std::string path = loc.getRootLocation() + "/" + loc.getIndexLocation();
			if(!is_exist(path) || !is_readable(path) || !is_file(path))
				throw Exception_ConfigServer("index of upload location ");
		}
	}
	else if (!loc.getPath().compare("/python"))
	{
		if(loc.getRootLocation().empty())
			throw Exception_ConfigServer("python location should have root ");
		if(loc.getIndexLocation().empty())
			throw Exception_ConfigServer("python location should have index ");
		std::string path = loc.getRootLocation() + "/" + loc.getIndexLocation();
		if(!is_exist(path) || !is_readable(path) || !is_file(path))
			throw Exception_ConfigServer("index of python location ");
		if(loc.getCgiPath().empty())
			throw Exception_ConfigServer("python location can't have cgi ");
		if(loc.getCgiExtension().empty())
			throw Exception_ConfigServer("python location can't have cgi ");
		if(loc.getAutoindex())
			throw Exception_ConfigServer("python location can't have autoindex ");
		if (!loc.getReturn().empty())	
			throw Exception_ConfigServer("pyhton location can't have redirection ");
		if (!loc.getRewrite().empty())
			throw Exception_ConfigServer("python location can't have redirection ");
	}
	else if (!loc.getPath().compare("/cpp"))
	{
		if(loc.getRootLocation().empty())
			throw Exception_ConfigServer("cpp location should have root ");
		if(loc.getIndexLocation().empty())
			throw Exception_ConfigServer("cpp location should have index ");
		std::string path = loc.getRootLocation() + "/" + loc.getIndexLocation();
		if(!is_exist(path) || !is_file(path))
			throw Exception_ConfigServer("index of cpp location ");
		if(loc.getCgiPath().empty())
			throw Exception_ConfigServer("cpp location should have cgi ");
		if(loc.getCgiExtension().empty())
			throw Exception_ConfigServer("cpp location should have cgi ");
		if (loc.getCgiPath().compare(path))
			throw Exception_ConfigServer("index of cpp location ");
		if(loc.getAutoindex())
			throw Exception_ConfigServer("cpp location can't have autoindex ");
		if (!loc.getReturn().empty())	
			throw Exception_ConfigServer("cpp location can't have redirection ");
		if (!loc.getRewrite().empty())
			throw Exception_ConfigServer("cpp location can't have redirection ");
	}
	else if(!loc.getPath().compare("/"))
	{
		if(!loc.getRewrite().empty())
			throw Exception_ConfigServer("/ location value can't have redirection ");
		if(loc.getAutoindex())
			throw Exception_ConfigServer("/ location  can't have autoindex ");
		if(!loc.getCgiPath().empty())
			throw Exception_ConfigServer("/ location  can't have cgi ");
		if(!loc.getCgiExtension().empty())
			throw Exception_ConfigServer("/ location  can't have cgi ");
		if(!loc.getReturn().empty())
			throw Exception_ConfigServer("/ location  can't have redir external ");	
		if(loc.getRootLocation().empty())
			loc.setRootLocation(this->getRoot());
		if(loc.getRootLocation().empty())
			throw Exception_ConfigServer("/ location  should have valid root ");
		if(loc.getRootLocation().compare(this->getRoot()) && (this->getRoot().length()!=0))
			throw Exception_ConfigServer("/ location  must have same root with server");
		if(loc.getIndexLocation().empty())
			loc.setIndexLocation(this->getIndex());
		if(loc.getIndexLocation().empty())
			loc.setIndexLocation("index.html");
		std::string path=loc.getRootLocation() + "/" + loc.getIndexLocation();
		if (!is_exist(path) || !is_readable(path) || !is_file(path))
				throw Exception_ConfigServer(loc.getPath() + " location : is't valid  index ");
	}
	else if(loc.getPath().compare("/"))
	{
		if(!loc.getReturn().empty() && loc.getRewrite().empty())
		{
			if(loc.getReturn().empty() )
				throw Exception_ConfigServer("redirection value can't be empty ");
			if(loc.getAutoindex())
				throw Exception_ConfigServer("redirection location can't have autoindex ");
			if(!loc.getCgiPath().empty())
				throw Exception_ConfigServer("redir location can't have cgi ");
			if(!loc.getCgiExtension().empty())
				throw Exception_ConfigServer("redir location can't have cgi ");
			if(!loc.getRootLocation().empty())
				throw Exception_ConfigServer("redir location should have root ");
			if(!loc.getIndexLocation().empty())
				throw Exception_ConfigServer("redir location should have index ");
			if(!loc.getRewrite().empty())
				throw Exception_ConfigServer("redir location can't have  internal redir ");
		}
		else if (!loc.getRewrite().empty() && loc.getReturn().empty())
		{
			if(loc.getRewrite().empty())
				throw Exception_ConfigServer(loc.getPath()+ " :internal redirection value can't be empty ");
			if(loc.getAutoindex())
				throw Exception_ConfigServer(loc.getPath()+ " :internal redirection  can't have autoindex ");
			if(!loc.getCgiPath().empty())
				throw Exception_ConfigServer(loc.getPath()+ " :internal redirection  can't have cgi ");
			if(!loc.getCgiExtension().empty())
				throw Exception_ConfigServer(loc.getPath()+ " :internal redirection  can't have cgi ");
			if(!loc.getRootLocation().empty())
				throw Exception_ConfigServer(loc.getPath()+ " :internal redirection  cant have root ");
			if(!loc.getIndexLocation().empty())
				throw Exception_ConfigServer(loc.getPath()+ " :internal redirection  cant have index ");
			if(!loc.getReturn().empty())
				throw Exception_ConfigServer(loc.getPath()+ " :internal redirection  cant have redir external ");
			std::string path = s_root + loc.getRewrite();
			if(is_exist(path))
			{
				if(is_file(path))
					if(!is_readable(path))
						throw Exception_ConfigServer(loc.getPath()+ " : internal redirection  not a valid ");
			}
			else
				throw Exception_ConfigServer(loc.getPath()+ " : internal redirection  cot a valid ");
		}
		else if (!loc.getRewrite().empty() && !loc.getReturn().empty())
			throw Exception_ConfigServer("can't have two redirection ");
		else
		{
			if(loc.getRootLocation().empty())
				loc.setRootLocation(this->getRoot());
			std::string path=loc.getRootLocation() + loc.getPath();
			if (!is_exist(path) || !is_directory(path))
				throw Exception_ConfigServer(loc.getPath() + " location : is't valid  directory ");
			if (!loc.getIndexLocation().empty())
			{
				path = path + "/" + loc.getIndexLocation();
				if (!is_exist(path) || !is_readable(path) || !is_file(path))
					throw Exception_ConfigServer(loc.getPath() + " location : can't valid  index ");
			}
			if(!loc.getCgiPath().empty())
				throw Exception_ConfigServer(loc.getPath() + " location :  can't have cgi ");
			if(!loc.getCgiExtension().empty())
				throw Exception_ConfigServer(loc.getPath() + " location :  can't have cgi ");
		}
	}

	
}
void 	ConfigServer::checkLocaitons()
{
	if (s_locations.size() < 1)
		throw Exception_ConfigServer("there is no location in one of the server");
	std::vector<Location>::iterator it1;
	std::vector<Location>::iterator it2;
	for(it1 = s_locations.begin(); it1!=s_locations.end()-1; it1++)
		for(it2 = it1 +1; it2!=s_locations.end();it2++)
			if(it1->getPath() == it2->getPath())
				throw Exception_ConfigServer("location name duplicated ");
	std::vector<Location>::iterator it;
	for(it=s_locations.begin(); it !=s_locations.end(); it++ )
		if(!it->getPath().compare("/"))
			break ;
	if(it == s_locations.end())
		throw Exception_ConfigServer(this->getServerName() + " server: must have / location");
	for(std::vector<Location>::iterator it=s_locations.begin(); it !=s_locations.end(); it++ )
		check_set_location(*it);
}




void ConfigServer::setTimeOut(long timeout)
{
	s_timeout = timeout;
}

std::string ConfigServer::getServerName()
{
	return (s_serverName);
}
uint16_t ConfigServer::getPort()
{
	return (s_port);
}

in_addr_t ConfigServer::getHost()
{
	return (s_host);
}

size_t	ConfigServer::getMaxBody()
{
	return (s_maxBody);
}

std::vector<Location> ConfigServer::getLocation()
{
	return (s_locations);
}

std::string ConfigServer::getRoot()
{
	return (s_root);
}

std::map<int, std::string> ConfigServer::getErrorPages()
{
	return (s_errorPages);
}

std::string ConfigServer::getIndex()
{
	return (s_index);
}

void 	ConfigServer::get_one_Location(std::string path, Location& loc)
{
	for(std::vector<Location>::iterator it= s_locations.begin(); it!= s_locations.end(); it++)
	{
		if(it->getPath() == path)
		{
			loc = *it;
		}
	}
}

long ConfigServer::getTimeOut()
{
	return (s_timeout);
}

int ConfigServer::getSocketFd()
{
	return (s_socketFd);
}

void	ConfigServer::setupServer()
{
	struct in_addr	adrr;
	adrr.s_addr = s_host;
	std::string h(inet_ntoa(adrr));
	if((s_socketFd =socket(AF_INET, SOCK_STREAM, 0)) == -1)
	{
		std::cout<<h<<":"<<s_port<<" : socket error"<<std::endl;
		exit(EXIT_FAILURE);
	}
	int optval = 1;
	if(setsockopt(s_socketFd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(int)))
	{
		std::cout<<h<<":"<<s_port<<" : socketopt error"<<std::endl;
		exit(EXIT_FAILURE);		
	}
	memset(&s_serverAdress, 0, sizeof(s_serverAdress));
	s_serverAdress.sin_family = AF_INET;
	s_serverAdress.sin_addr.s_addr = adrr.s_addr;
	// s_serverAdress.sin_addr.s_addr = s_host;
	s_serverAdress.sin_port = htons(s_port);
	int t=bind(s_socketFd, (struct sockaddr*)&s_serverAdress, sizeof(s_serverAdress));
	if( t == -1)
	{
		std::cout<<h<<":"<<s_port<<" : bind error"<<std::endl;
		exit(EXIT_FAILURE);		
	}
	std::cout<<s_serverName<<"("<<h<<":"<<s_port<<") : server is created !"<<std::endl;
}