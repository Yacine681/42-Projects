#ifndef CONFIGFILE_HPP
#define CONFIGFILE_HPP

#include "utiles.hpp"

class ConfigFile{

	private:
		std::string		name;
		std::size_t		size;

	public:
		ConfigFile(const std::string name);
		std::string	readFile() const;
		std::string	getName() const;
		size_t	getSize() const;
	class Exception_ConfigFile:public std::exception{
		private:
		std::string		msg;
		public:
			Exception_ConfigFile(std::string msg):std::exception()
			{
				this->msg = "Exception_ConfigFile: " + msg;
			}
			~Exception_ConfigFile() throw(){}
			const char* what()const throw(){return msg.c_str();}
	};
};

#endif