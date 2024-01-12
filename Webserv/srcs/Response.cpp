#include "../inc/Response.hpp"

Response::Response()
{
    _target_file = "";
    _body.clear();
    _body_length = 0;
    _response_content = "";
    _response_body = "";
    new_url = "";
    _code = 0;
    _is_cgi = 0;
	_method= "";
 //   _is_cgi_response_length = 0;
    _auto_index = false;	
}
Response::Response(Request &req):request(req)
{
    _target_file = "";
    _body.clear();
    _body_length = 0;
    _response_content = "";
    _response_body = "";
    new_url = "";
    _code = 0;
    _is_cgi = 0;
 //   _is_cgi_response_length = 0;
    _auto_index = false;	
}
Response::~Response()
{
	
}

void	Response::setRequest(Request &req)
{
	this->request = req;
		
}
void    	Response::setCode(int c)
{
	this->_code = c;
		
}
void	Response::setServer(ConfigServer &ser)
{
	_server = ser;
}
void		Response::setResponseBody(std::string& str)
{
	_response_body.clear();
	_response_body = str;
}

void Response::setServerDefaultErrorPages()
{
	_response_body = getErrorPage(_code);
}
int     	Response::getisCgi()const
{
	return _is_cgi;
}
void    	Response::setisCgi(int c)
{
	_is_cgi = c;
}
void        Response::cutRes(size_t i)
{
    _response_content = _response_content.substr(i);
}

bool	Response::readTargetFile()
{
	std::ifstream	file(_target_file.c_str());
	if (file.fail())
	{
		_code = 404;
		return 1;
	}
	std::stringstream	ss;
	ss<<file.rdbuf();
	//file.close();
	_response_body = ss.str();
	return 0;
}

std::string	Response::get_target_file()
{
	return _target_file;
}

//400-505 create error page, samll than 400 let it go
void	Response::BuildErrorBody()
{
	if(_code >= 400 &&  _code <= 505)
	{
		
		if(!_server.getErrorPages().count(_code) || !_server.getErrorPages().at(_code).length())
			setServerDefaultErrorPages();	
		else
		{
			if(_code >= 400 &&  _code <= 505)
			{
				_target_file = _server.getErrorPages().at(_code);
				short old = _code;
				if(readTargetFile())
				{
					_code = old;
					_response_body = getErrorPage(_code);
				}
			}
		}
	}
}

int	Response::get_match_location(std::string &path, std::vector<Location> locations, std::string &location_key)
{
	size_t biggest_match = 0;
	std::vector<Location>::const_iterator it;
	for(it = locations.begin(); it != locations.end(); ++it)
	{
		if(it->getPath() != "/" && path.find(it->getPath()) == 0)
		{
			if(it->getPath() == "/python"){
				if(path.compare("/python") && path.compare("/python.html"))
				{
					_code = 401;
					return 1;
				}
				
			}
			if(it->getPath() == "/cpp"){
				if(path.compare("/cpp") && path.compare("/cpp.html"))
				{
					_code = 401;
					return 1;
				}
			}
			if(!path.compare(it->getPath()))
			{
				location_key = it->getPath();
				return 0;
			}
			if(path.find("/", it->getPath().length(), 1) != std::string::npos)
			{
			    if(it->getPath().length() > biggest_match)
                    {
                        biggest_match = it->getPath().length();
                        location_key = it->getPath();
                    }	
			}
		}
		
	}
	if(location_key.length() == 0)
		location_key = "/";
	return 0;
}


bool	Response::is_allowed_method(Location loc)
{
	if (request.getMethod() == 0)
		_method = "get";
	else if (request.getMethod() == 1)
		_method = "post";
	else if (request.getMethod() == 2)
		_method = "delete";
	if(_method.length() == 0)
	{
		_code = 501;
		std::cout << "METHOD NOT IMPLEMENTED \n";
		return 0;
	}
	std::vector<std::string> methods = loc.getMethods();
	std::vector<std::string>::iterator it;
	for(it = methods.begin(); it!=methods.end();it++)
	{
		if(*it == _method)
		{
			if (_method != "delete")
				return true;
			else
			{
				if (loc.getPath().find("/upload") != std::string::npos)
					return 1;
				else
				{
					_code = 403;
					std::cout << "forbiden \n";
					return false;
				}
			}
		}
		
	}
	if (it==methods.end())
	{
		_code = 405;
		std::cout << "METHOD NOT ALLOWED \n";
		return false;
	}
_code = 405;
return false;
}

int Response::check_return_rewrite(Location loc)
{
	if(!loc.getReturn().empty())
	{
		_code = 301;
		new_url = loc.getReturn();
		return 1;
	}
	if(!loc.getRewrite().empty())
	{
		_code = 302;
		new_url = loc.getRewrite();
		return 1;
	}
	return 0;
}

std::string decode(std::string& qury )
{
	size_t p = qury.find("%");
	while(p != std::string::npos)
	{
		if(qury.length() < p + 2)
			break;
		
		int dem = fromhectoDec(qury.substr(p +1 , 2));
		char c= static_cast<char>(dem);
		qury.replace(p, 3,1, c);
		p =qury .find("%");
	}
	
	return qury;
}

void	Response::handle_cpp(Location loc)
{
	cgi.setCgiPath(loc.getCgiPath());
	cgi.setCgiFile(loc.getRootLocation() + "/" + loc.getIndexLocation());
	cgi.setStrEnv(request);
	cgi.setCharEnv();
	std::string qry = decode(request.getQuery());
	cgi.setArgv_cpp(qry);
	if(cgi.getcode() != 0)
		_code = cgi.getcode();
	else if(cgi.getcode() == 0 )
		cgi.exc_Cgi();
	if(cgi.getcode() != 0)
		_code = cgi.getcode();
}
void	Response::handle_python(Location loc)
{
	cgi.setCgiPath(loc.getCgiPath());
	cgi.setCgiFile(loc.getRootLocation() + "/" + loc.getIndexLocation());
	cgi.setStrEnv(request);
	std::string bodys ="no";
	if(request.getBody().length() != 0)
		bodys = request.getBody();
	std::string ss="no";
	if(request.getHeader("cookie").length() != 0)
	{
		ss = request.getHeader("cookie");
		size_t p = ss.find("=");
		ss = ss.substr(p+1);
	}
		
	cgi.setArgv_python(bodys, ss);
		if(cgi.getcode() != 0)
		_code = cgi.getcode();
	else if(cgi.getcode() == 0 )
		cgi.exc_Cgi();
	if(cgi.getcode() != 0)
		_code = cgi.getcode();
}

int Response::handleCgi(Location loc)
{
	
	if (!loc.getPath().compare("/cpp"))
		handle_cpp(loc);
	else if(!loc.getPath().compare("/python"))
		handle_python(loc);
	
	return 1;
}

void   Response::clear()
{
    _target_file.clear();
    _body.clear();
    _body_length = 0;
    _response_content.clear();
    _response_body.clear();
    new_url.clear();
    _code = 0;
    _is_cgi = 0;
//    _is_cgi_response_length = 0;
    _auto_index = 0;
	cgi.clear();
}


int Response::handel_upload(Location loc)
{
	if (_method == "delete")
	{
		std::string path = request.getPath();
		size_t p = path.find_first_of("/",1);
		_target_file = loc.getRootLocation() + path.substr(p);
		if (!is_exist(_target_file))
		{
			_code = 404;
			return 1;
		}
		if(remove(_target_file.c_str()))
		{
			_code = 500;
			return 1;
		}
		_code = 200;
		_response_body = file_deleted(_target_file);
		return 1;
	}
	else if((_method == "get" || _method == "post") && request.getBody().length() == 0)
	{
		
		std::string path = request.getPath();
		if (path.compare("/upload"))
		{
			size_t p = path.find_last_of("/");
			_target_file = loc.getRootLocation() + path.substr(p);
			if (!is_exist(_target_file))
			{
				_code = 404;
				return 1;
			}
			if(readTargetFile())
				return 1;
			_code = 200;
			return 1;
		}
		if(!path.compare("/upload"))
		{
			if(loc.getAutoindex())
			{
				_target_file = loc.getRootLocation();
				_response_body = upload_list(_target_file);
				_code = 200;
				if(_response_body.length() == 0)
					_code = 500;
			}
			else if(request.getQuery().length() == 0 && request.getBody().length() == 0)
			{
				_target_file = loc.getRootLocation()+ loc.getIndexLocation();
				if (!is_exist(_target_file))
				{
					_code = 404;
					return 1;
				}
				if(readTargetFile())
					return 1;
				_code = 200;
			}
			return 1;
		}
		
	}
	else if (_method == "post" && request.getBody().length() != 0)
	{
		std::string body = request.getBody();
		std::string	filename;
		if(request.getMultiformFlag())
		{
			body = removeBoundary(body, request.getBoundary(), filename);
			_target_file = loc.getRootLocation() + "/" + filename;
		}
		else
		{
			std::stringstream ss;
			filename = ss.str();
			_target_file = loc.getRootLocation() + "/"+ filename;
		}
		std::ofstream f_upload;
		f_upload.open(_target_file.c_str(), std::ofstream::out | std::ofstream::binary);
		if(f_upload.fail())
		{
			_code = 500;
			return 1;
		}
		f_upload.write(body.c_str(), body.length());
		_response_body = file_upload(filename);
		_code = 200;
		return 1;
	}

	_code = 404;
	return 1;
}

std::string Response::removeBoundary(std::string &body, std::string &boundary, std::string& file)
{
std::string buffer;
    std::string new_body;
    std::string filename;
    bool is_boundary = false;
    bool is_content = false;

    if (body.find("--" + boundary) != std::string::npos && body.find("--" + boundary + "--") != std::string::npos)
    {
        for (size_t i = 0; i < body.size(); i++)
        {
            buffer.clear();
            while(body[i] != '\n')
            {
                buffer += body[i];
                i++;
            }
            if (!buffer.compare(("--" + boundary + "--\r")))
            {
                is_content = true;
                is_boundary = false;
            }
            if (!buffer.compare(("--" + boundary + "\r")))
            {
                is_boundary = true;
            }
            if (is_boundary)
            {
                if (!buffer.compare(0, 31, "Content-Disposition: form-data;"))
                {
                    size_t start = buffer.find("filename=\"");
                    if (start != std::string::npos)
                    {
                        size_t end = buffer.find("\"", start + 10)- (start + 10);
                        if (end != std::string::npos)
						{
                            filename = buffer.substr(start + 10, end);
							file = filename;
						}
                    }
                }
                else if (!buffer.compare(0, 1, "\r") && !filename.empty())
                {
                    is_boundary = false;
                    is_content = true;
                }

            }
            else if (is_content)
            {
                if (!buffer.compare(("--" + boundary + "\r")))
                {
                    is_boundary = true;
                }
                else if (!buffer.compare(("--" + boundary + "--\r")))
                {
                    new_body.erase(new_body.end() - 1);
                    break ;
                }
                else
                    new_body += (buffer + "\n");
            }

        }
    }

    body.clear();
    return (new_body);	
}

int Response::handleRequest()
{
	std::string loc_path;
	if(get_match_location(request.getPath(), _server.getLocation(), loc_path))
		return 1;
	Location target_location;
	 _server.get_one_Location((loc_path), target_location);
	if(!is_allowed_method(target_location))
		return 1;
	if(check_return_rewrite(target_location))
		return 1;
	if(!target_location.getCgiExtension().empty() && !target_location.getCgiPath().empty())
	{
		if(!loc_path.compare("/cpp"))
		{
			_is_cgi = 1;
			handle_cpp(target_location);
		}
		else if(!loc_path.compare("/python"))
		{
			_is_cgi = 2;
			handle_python(target_location);
			
		}
		return 0;
	}
	if(loc_path == "/upload")
		return handel_upload(target_location);
	
	//loc_path is directory; no need to chech "/" is autoindex , alreay check 
	if(loc_path != "/upload"  && target_location.getAutoindex())
	{
		std::string f_path = target_location.getRootLocation() + request.getPath();
		_target_file = f_path;
		if (!is_exist(f_path))
		{
			_code = 404;
			return 1;
		}
		if (is_directory(f_path))
		{
			_response_body = directory_list(_target_file, target_location.getPath());
			_code = 200;
			if(_response_body.length() == 0)
				_code = 500;
		}
		else if (is_readable(_target_file) && is_file(_target_file))
		{
			if(readTargetFile())
				return 1;
			_code = 200;		
		}
		else
			_code = 404;
		return 1;
	}
	if (loc_path == "/")
	{

		std::string f_path = target_location.getRootLocation() + request.getPath();
		_target_file = f_path;
		if (!is_exist(f_path))
		{
			_code = 404;
			return 1;
		}
		if (is_directory(f_path))
		{
			_target_file = f_path + "/" + "index.html";
			if (!is_exist(f_path))
			{
				_code = 404;
				return 1;
			}
			if(readTargetFile())
				return 1;
			_code = 200;
		}
		else if(is_file(_target_file) && is_readable(_target_file))
		{			
			if(readTargetFile())
				return 1;
			_code = 200;
		}
		return 1;		
	}
	else
	{
		std::string f_path = target_location.getRootLocation() + request.getPath();
		_target_file = f_path;
		if (!is_exist(f_path))
		{
			_code = 404;
			return 1;
		}
		if (is_directory(f_path))
		{
			_target_file = f_path + "/" + "index.html";
			if (!is_exist(f_path))
			{
				_code = 404;
				return 1;
			}
			if(readTargetFile())
				return 1;
			_code = 200;
		}
		else if(is_file(_target_file) && is_readable(_target_file))
		{
			if(readTargetFile())
				return 1;
			_code = 200;
		}
		return 1;			
	}
	
	//locpath is file ;
	
}

void	Response::BuildResponse()
{
	if(request.errorCode())
	{
		_code = request.errorCode();
		BuildErrorBody();//400-505 create error page, samll than 400 let it go
	}
	else if(_server.getMaxBody() < request.getBody().length())
	{
		_code = 413;
		BuildErrorBody();//400-505 create error page, samll than 400 let it go
	}
	else if(handleRequest())
		BuildErrorBody();//400-505 create error page, samll than 400 let it go
	if(_is_cgi == 0)
	{
		setStatusLine();
		setHeaders();
		//_response_content.append(_response_body);
	}

}
void	Response::setStatusLine()
{
    _response_content.append("HTTP/1.1 " + std::to_string(_code) + " ");
    _response_content.append(statusCodeString(_code));
    _response_content.append("\r\n");	
}

void	Response::setHeaders()
{
    contentType();
    contentLength();
    connection();
    new_Url();
    date();	
	_response_content.append("\r\n");
	_response_content.append(_response_body);
}

void	Response::setPythonHeaders(const std::string session, const std::string time)
{
    contentType();
    contentLength();
    connection();
    new_Url();
	if(session.compare("no") && time.compare("no"))
	{
		_response_content.append("Set-Cookie: ");
		// _response_content.append("session_id=cccb-789abc; Expires=Mon,17-Jul-2023 16:18:00 GMT;");
		_response_content.append("session_id=");
		_response_content.append(session);
		_response_content.append("; Expires=");
		_response_content.append(time);
		_response_content.append(";");
		_response_content.append("\r\n");
	}
    date();	
	_response_content.append("\r\n");
	_response_content.append(_response_body);
	
}

void   Response::contentType()
{
	 _response_content.append("Content-Type: ");
	 if(_target_file.rfind(".", std::string::npos) != std::string::npos && _code == 200)
		_response_content.append(_mime.getMimeType(_target_file.substr(_target_file.rfind(".", std::string::npos))) );
	else
		_response_content.append(_mime.getMimeType("default"));
	 _response_content.append("\r\n");	
	 
}

void   Response::contentLength()
{
    std::stringstream ss;
    ss << _response_body.length();
    _response_content.append("Content-Length: ");
    _response_content.append(ss.str());
    _response_content.append("\r\n");
}
void   Response::connection()
{
    if(request.getHeader("connection") == "keep-alive")
        _response_content.append("Connection: keep-alive\r\n");
}

void    Response::new_Url()
{
    if (new_url.length())
        _response_content.append("Location: "+ new_url +"\r\n");
}

void    Response::date()
{
    char date[1000];
    time_t now = time(0);
    struct tm tm = *gmtime(&now);
    strftime(date, sizeof(date), "%a, %d %b %Y %H:%M:%S %Z", &tm);
    _response_content.append("Date: ");
    _response_content.append(date);
    _response_content.append("\r\n");
}

int      Response::getCode() const
{
    return (_code);
}