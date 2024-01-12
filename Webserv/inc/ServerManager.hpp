#ifndef SERVERMANAGER_HPP
#define SERVERMANAGER_HPP

#include "ConfigServer.hpp"
#include "Client.hpp"
#include "utiles.hpp"


class ServerManager{

	private:
//		std::vector<ConfigServer>		_servers;
		std::map<int, ConfigServer>		_servers_map;
		std::map<int, Client>		_Clients_map;
		fd_set						_recv_fd_pool;
		fd_set						_write_fd_pool;
		int							_biggest_fd;

		void	addToSet(const int fd, fd_set &set);
		void	acceptNewConnection(ConfigServer &server);
		void	removeFromSet(int fd, fd_set &set);
		void	readRequest(Client	&client);
		void	closeConnection(int fd);
		void	sendResponse(Client	&client);
		void 	handle_cgi_recieve(Client	&client);
		void	checkTimeOut();
		
		
	public:
		ServerManager();
		~ServerManager();
        void    setupServers(std::vector<ConfigServer>);
        void    runServers();
};

#endif