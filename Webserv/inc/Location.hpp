#ifndef LOCATION_HPP
#define LOCATION_HPP

#include "utiles.hpp"


class Location{

	private:
		std::string					_path; 
		std::string					_root;
		bool						_autoindex;
		std::string					_index;
		std::vector<std::string>	_methods; // GET+ POST- DELETE
		std::string					_return;
		std::string					_rewrite;
		std::string					_cgi_path;
		std::string					_cgi_ext;


	public:
		Location();
		Location(const Location &other);
		Location &operator=(const Location &rhs);
		~Location();
		void setPath(std::string path);
		void setRootLocation(std::string parametr);
		void setMethods(std::vector<std::string> methods);
		void setAutoindex(std::string parametr);
		void setIndexLocation(std::string parametr);
		void setReturn(std::string parametr);
		void setRewrite(std::string parametr);
		void setCgiPath(std::string path);
		void setCgiExtension(std::string extension);


		std::string getPath() const;
		std::string getRootLocation() const;
		std::vector<std::string> getMethods() const;
		bool 		getAutoindex() const;
		std::string getIndexLocation() const;
		std::string getReturn() const;
		std::string getRewrite() const;
		std::string getCgiPath() const;
		std::string getCgiExtension() const;

		void	loc_print()
		{
			std::cout<<"_path: "<<_path<<std::endl
					<<"_root: "<<_root<<std::endl
					<<"_autoindex: "<<_autoindex<<std::endl
					<<"_index: "<<_index<<std::endl
					<<"_return: "<<_return<<std::endl
					<<"_rewrite: "<<_rewrite<<std::endl
					<<"_cgi_path: "<<_cgi_path<<std::endl
					<<"_cgi_ext: "<<_cgi_ext<<std::endl;
			std::cout<<"mthods: ";
			for(std::vector<std::string>::iterator it=_methods.begin(); it != _methods.end();it++)
				std::cout<<*it<<",";
			std::cout<<std::endl;
		}
};

#endif