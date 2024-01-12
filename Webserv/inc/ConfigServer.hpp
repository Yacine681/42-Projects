#ifndef CONFIGSERVER_HPP
# define CONFIGSERVER_HPP

#include "utiles.hpp"
#include "Location.hpp"


class Location;

class ConfigServer {

	private:
		uint16_t 					s_port;	
		std::string					s_index;
		std::string 				s_root;
		std::string					s_serverName;
		in_addr_t					s_host;
		long						s_timeout;
		std::vector<Location> 		s_locations;
		std::map<int, std::string> 	s_errorPages;
		size_t 						s_maxBody;
		
		struct sockaddr_in  		s_serverAdress; /* Bind and Socket */
		int    						s_socketFd;

	public:
		
		ConfigServer();
		ConfigServer(const ConfigServer& obj);
		ConfigServer& operator=(const ConfigServer& obj);
		~ConfigServer();

		void 	setServerName(std::string serverName);
		void	setupServer();
		void 	setHost(std::string host);
		void 	setRoot(std::string root);
		void 	setSocketFd(int socketFd);
		void 	setPort(std::string port);
		void 	setMaxBody(std::string maxBody);
		void 	setErrorPages(std::vector<std::string> &parameter);
		void 	setIndex(std::string index);
		void 	setLocation(std::string path, std::vector<std::string> parameter);
		// void setMethods(std::vector<std::string> methods);
		void	checkLocaitons();
		void	check_set_location(Location& loc);
		void 	setTimeOut(long timeout);
		
		std::string 					getServerName();
		uint16_t 						getPort();
		in_addr_t 						getHost();
		size_t 							getMaxBody();
		std::vector<Location> 			getLocation();
		void 							get_one_Location(std::string path, Location& loc);
		std::string 					getRoot();
		std::map<int, std::string> 		getErrorPages();
		std::string 					getIndex();
		// std::vector<std::string>		getMethods();
		long							getTimeOut();
		int 							getSocketFd();
	
		class Exception_ConfigServer:public std::exception{
			private:
				std::string		msg;
			public:
				Exception_ConfigServer(std::string msg):std::exception()
				{
					this->msg = "Exception_ConfigServer: " + msg;
				}
				~Exception_ConfigServer() throw(){}
				const char* what()const throw(){return msg.c_str();}
	};

		void	conf_print()
		{
			std::cout<<"s_port: "<<s_port<<std::endl
					<<"s_index: "<<s_index<<std::endl
					<<"s_root: "<<s_root<<std::endl
					<<"s_serverName: "<<s_serverName<<std::endl
					<<"s_host: "<<s_host<<std::endl
					<<"s_timeout: "<<s_timeout<<std::endl
					<<"s_maxBody: "<<s_maxBody<<std::endl;
			for(std::map<int, std::string>::iterator it = s_errorPages.begin(); it!=s_errorPages.end(); it++)
			{
					std::cout<<it->first<<" = "<<it->second<<std::endl;
			}
			for(std::vector<Location>::iterator it = s_locations.begin(); it!=s_locations.end(); it++)
			{
					std::cout<<"++++++++++++++++"<<std::endl;
					it->loc_print();
					std::cout<<"++++++++++++++++"<<std::endl;
			}
		}
};

#endif