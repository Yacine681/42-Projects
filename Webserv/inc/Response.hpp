#ifndef RESPONSE_HPP 
#define RESPONSE_HPP

#include "utiles.hpp"
#include "Mime.hpp"
#include "Request.hpp"
#include "ConfigServer.hpp"
#include "Location.hpp"
#include "Cgi.hpp"


class Cgi;
class Location;
class Response
{
	private:
		ConfigServer	_server;
		std::string		_method;
		std::string		_target_file;	
		std::vector<uint8_t> _body;
		size_t          _body_length;
		std::string     _response_body;
        std::string     new_url; //when has redirect external and internal new url
        short           _code;		
//        char            *_res;
		int				_is_cgi;
//		int				_cgi_fd[2];
//		size_t			_cgi_response_length;
        bool            _auto_index;
		

		int		get_match_location(std::string &path, std::vector<Location> locations, std::string &location_key);
		bool	is_allowed_method(Location loc);
		int 	check_return_rewrite(Location loc);
		std::string removeBoundary(std::string &body, std::string &boundary, std::string& file);
	/* must do*/	int 	handleCgi(Location loc); //must implement it
	/* must do*/	int 	handel_upload(Location loc); 
	void	handle_python(Location loc);
	void	handle_cpp(Location loc);
		
	public:
		Mime			_mime;
		Request     	request;
		Cgi     		cgi;
		std::string     _response_content;
		
		Response();
		Response(Request &req);
		~Response();
		
		void        setRequest(Request &);
        void        setServer(ConfigServer &);
		std::string	get_target_file();

		int     	getCode() const;
		void     	setCode(int c);
		int     	getisCgi() const;
		void     	setisCgi(int c);
		void	setPythonHeaders(const std::string session, const std::string time);
		
		void        cutRes(size_t i);

		
		void		BuildResponse();
		void		BuildErrorBody();
		void 		setServerDefaultErrorPages();
		bool		readTargetFile();
		// int    		buildBody();
		int 		handleRequest();
		void		setStatusLine();
		void		setResponseBody(std::string& str);
		void		setHeaders();
		void   		contentType();
		void   		contentLength();
		void   		connection();
		void    	new_Url();
		void    	date();
        void        clear();

		void response_print()
		{
			std::cout<<"+++++++++++++++++++++++\n"
					<<_response_content<<std::endl;
		}
};

#endif