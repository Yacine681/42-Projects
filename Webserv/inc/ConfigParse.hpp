#ifndef CONFIGPARSE_HPP
#define CONFIGPARSE_HPP

#include "Location.hpp"
#include "utiles.hpp"
#include "ConfigFile.hpp"
#include "ConfigServer.hpp"

class ConfigServer;

class ConfigParse{

	private:
		std::vector<ConfigServer>	_servers;
		std::vector<std::string>	_server_config;
		size_t							_nb_server;

	public:
		ConfigParse();
		~ConfigParse();
	
		int createCluster(const std::string &config_file);		
		void removeComments(std::string &content);
		void removeWhiteSpace(std::string &content);
		void splitServers(std::string &content);
		size_t findStartServer(size_t start, std::string &content);
		size_t findEndServer(size_t start, std::string &content);

		void createServer(std::string &config, ConfigServer &server);
		void checkServers();
		std::vector<ConfigServer>	getServers();

	class Exception_ConfigParse:public std::exception{
		private:
		std::string		msg;
		public:
			Exception_ConfigParse(std::string msg):std::exception()
			{
				this->msg = "Exception_ConfigParse: " + msg;
			}
			~Exception_ConfigParse() throw(){}
			const char* what()const throw(){return msg.c_str();}

	};
	void	conf_print()
	{
		std::cout<<"_nb_server: "<<_nb_server<<std::endl;
		for (std::vector<std::string>::iterator it = _server_config.begin(); it!= _server_config.end();it++)
		{
			std::cout<<*it<<std::endl;
			std::cout<<"+++++++++++++++++++++++++"<<std::endl;
		}
	}
};

#endif