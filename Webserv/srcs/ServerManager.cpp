#include	"../inc/ServerManager.hpp"

ServerManager::ServerManager()
{

}

ServerManager::~ServerManager()
{

}

void    ServerManager::setupServers(std::vector<ConfigServer> servers)
{
	_biggest_fd = 0;
	FD_ZERO(&_recv_fd_pool);
    FD_ZERO(&_write_fd_pool);
	std::cout<<std::endl<<"Initializing  Servers..."<<std::endl;
	for(std::vector<ConfigServer>::iterator it=servers.begin(); it != servers.end(); it++)
	{
		it->setupServer();
		if(listen(it->getSocketFd(), 512) == -1)
		{
			std::cout<<it->getServerName()<<": listen error!"<<std::endl;
			exit(EXIT_FAILURE);
		}
		if(fcntl(it->getSocketFd(),F_SETFL, O_NONBLOCK) < 0)
		{
			std::cout<<it->getServerName()<<": fcntl error!"<<std::endl;
			exit(EXIT_FAILURE);			
		}
		addToSet(it->getSocketFd(), _recv_fd_pool);
		_servers_map.insert(std::make_pair(it->getSocketFd(), *it));
	}
	// _biggest_fd = (_servers_map.rbegin()->first);
}

void	ServerManager::addToSet(const int fd, fd_set &set)
{
	FD_SET(fd, &set);
	if(fd > _biggest_fd)
		_biggest_fd = fd;
}

void	ServerManager::removeFromSet(int fd, fd_set &set)
{
	FD_CLR(fd, &set);
	if(fd == _biggest_fd)
		_biggest_fd--;
}

void	ServerManager::acceptNewConnection(ConfigServer &server)
{
	struct sockaddr_in	client_addr;
	long	client_addr_size= sizeof(client_addr);
	int		client_fd;
	
	// client_addr.sin_family  = AF_INET;
	// client_addr.sin_addr.s_addr = 
	Client	new_client(server);
	if((client_fd = accept(server.getSocketFd(), (struct sockaddr*)&client_addr, (socklen_t *)&client_addr_size)) == -1)
	{
		std::cout<<server.getServerName()<<": accept error"<<std::endl;
		return;
	}
	addToSet(client_fd, _recv_fd_pool);
	if((fcntl(client_fd, F_SETFL, O_NONBLOCK)) < 0)
	{
		std::cout<<server.getServerName()<<": fcntl error"<<std::endl;
		removeFromSet(client_fd, _recv_fd_pool);
		close(client_fd);
		return;
	}
	new_client.setSocket(client_fd);
	if(_Clients_map.count(client_fd) !=0)
		_Clients_map.erase(client_fd);
	_Clients_map.insert(std::make_pair(client_fd, new_client));
	in_addr _ip =client_addr.sin_addr;
	std::string	c_ip (inet_ntoa(_ip));
	std::cout<<"ip("<<c_ip<<") connect to the "<<server.getServerName()<<std::endl;
	std::cout<<"ip connect to the "<<server.getServerName()<<std::endl;
}

void    ServerManager::runServers()
{
    fd_set  recv_set_cpy;
    fd_set  write_set_cpy;
    int     select_ret;

	struct timeval	timer;
	while(true)
	{
		timer.tv_sec = 1;
		timer.tv_usec = 0;
        recv_set_cpy = _recv_fd_pool;
        write_set_cpy = _write_fd_pool;
		if((select_ret = select(_biggest_fd + 1, &recv_set_cpy, &write_set_cpy, NULL, &timer)) < 0)
		{
			std::cout<<"select error"<<std::endl;
			exit(1);
		}
		for(int i=0; i < _biggest_fd + 1; i++)
		{
			if(FD_ISSET(i, &recv_set_cpy) && _servers_map.count(i))
				acceptNewConnection(_servers_map.at(i));
			else if(FD_ISSET(i, &recv_set_cpy) && _Clients_map.count(i))
			{
				// if(_Clients_map.at(i).response.getisCgi() == 0)
					readRequest(_Clients_map.at(i));
			}
			else if( _Clients_map.count(i) && _Clients_map.at(i).response.getisCgi() != 0 && FD_ISSET(_Clients_map.at(i).response.cgi._pipe[0], &recv_set_cpy))
				{
					handle_cgi_recieve(_Clients_map.at(i));	
				}
			else if(FD_ISSET(i, &write_set_cpy) && _Clients_map.count(i))
				sendResponse(_Clients_map.at(i));
			
		}	
		checkTimeOut();
	}
	
}

void	ServerManager::checkTimeOut()
{
	for(std::map<int, Client>::iterator it=_Clients_map.begin(); it != _Clients_map.end(); it++)
	{
		if(time(NULL) - it->second.getLastTime() > CONNECTION_TIMEOUT)
		{
			std::cout<<it->second.server.getServerName()<<" time out"<<std::endl;
			closeConnection(it->first);
			return ;
		}
	}
}

void 	ServerManager::handle_cgi_recieve(Client	&client)
{
	size_t size = MESSAGE_BUFFER;
	char	buf[size * 2];
	int		reads = 0;
	std::string str;
	memset(buf, 0, size * 2);
	reads = read(client.response.cgi._pipe[0], buf, size * 2 - 1);
	while(reads)
	{
		str += std::string(buf);
		memset(buf, 0, size * 2);
		reads = read(client.response.cgi._pipe[0], buf, size * 2 - 1);
	}
	if(reads < 0)
		client.response.cgi.setcode(500);
	client.updateTime();
	if(client.response.getCode() != 0)
	{
		client.response.setCode(client.response.cgi.getcode());
		client.response.BuildErrorBody();
		client.response.setStatusLine();
		client.response.setHeaders();

	}
	else
	{

		if(client.response.getisCgi() == 2)
		{
			/*
			200\n
			abc-12345 | no \n
			timre mode | no \n
			body
			*/
			size_t s=str.find_first_of("\n");
			std::string code= str.substr(0,s);
			size_t e=str.find_first_of("\n",s + 1);
			std::string session= str.substr(s+1,e - s - 1);
			s = e + 1;
			e =str.find_first_of("\n",s);
			std::string time= str.substr(s, e - s);
			std::string new_body = str.substr(e + 1);
			try{
				int new_c =std::stoi(code);
				client.response.setCode(new_c);
			}
			catch(std::exception &e)
			{
				client.response.setCode(500);
			}
			client.response.setResponseBody(new_body);
			client.response.setStatusLine();
			client.response.setPythonHeaders(session, time);	
		}
		else if(client.response.getisCgi() == 1)
		{
			size_t p=str.find_first_of("\n");
			std::string code_ses= str.substr(0,p);
			std::string new_body = str.substr(p+ 1);
			try{
				int new_c =std::stoi(code_ses);
				client.response.setCode(new_c);
			}
			catch(std::exception &e)
			{
				client.response.setCode(500);
			}
			client.response.setResponseBody(new_body);
			client.response.setStatusLine();
			client.response.setHeaders();
		}
	}
	client.response.setisCgi(0);
	removeFromSet(client.response.cgi._pipe[0],_recv_fd_pool);
	close(client.response.cgi._pipe[0]);
	addToSet(client.getSocket(), _write_fd_pool);
}


void	ServerManager::readRequest(Client	&client)
{
	//size_t size = client.server.getMaxBody() > MAX_URI_LENGTH ? client.server.getMaxBody() : MAX_URI_LENGTH;
	size_t size = MESSAGE_BUFFER;
	char	buf[size * 2];
	int		reads = 0;
	memset(buf, 0, size * 2);
	reads = read(client.getSocket(), buf, size * 2 - 1);
	if(reads == 0) //client close connection....
	{
		std::cout<<client.server.getServerName()<<" server close connection.."<<std::endl;
		closeConnection(client.getSocket());
		return ;
	}
	else if(reads < 0)
	{
		std::cout<<client.server.getServerName()<<" read errror, close conection.."<<std::endl;
		closeConnection(client.getSocket());
		return ;
	}
	else
	{
		client.updateTime();
		client.request.feed(buf, reads);
		memset(buf, 0, size * 2);
	}
	if(client.request.parsingCompleted() || client.request.errorCode())
	{
		client.buildResponse();	
		if(client.response.getisCgi() == 0)
		{
			removeFromSet(client.getSocket(), _recv_fd_pool);
			addToSet(client.getSocket(), _write_fd_pool);
		}
		else
		{
			client.response.cgi.setSocket(client.getSocket());
			addToSet(client.response.cgi._pipe[0], _recv_fd_pool);
		}
	}
}

void	ServerManager::sendResponse(Client	&client)
{
	int	bytes;
	std::string responses = client.response._response_content;
	if(responses.length()  >= MESSAGE_BUFFER)
		bytes = write(client.getSocket(), responses.c_str(),MESSAGE_BUFFER);
	else
		bytes = write(client.getSocket(), responses.c_str(), responses.length());
	if(bytes < 0)
	{
		std::cout<<client.server.getServerName()<<": responde send error.."<<std::endl;
		closeConnection(client.getSocket());
	}
	else if(bytes == 0|| (size_t)bytes == responses.length())
	{
		if(!client.request.keepAlive() || client.request.errorCode())
		{
			closeConnection(client.getSocket());
		}
		else
		{
			removeFromSet(client.getSocket(), _write_fd_pool);
			addToSet(client.getSocket(), _recv_fd_pool);
			client.clearClient();
		}	
	}
	else
	{
		client.updateTime();
        client.response.cutRes(bytes);
	}
}

void	ServerManager::closeConnection(int fd)
{
	
	if(FD_ISSET(fd, &_recv_fd_pool))
		removeFromSet(fd, _recv_fd_pool);
	if(FD_ISSET(fd, &_write_fd_pool))
		removeFromSet(fd, _write_fd_pool);
	close(fd);
	std::cout<<((this->_Clients_map)[fd]).request.getPath()<<"  :: path disconneted\n";
/*change*/	_Clients_map[fd].clearClient();
	this->_Clients_map.erase(fd);
}