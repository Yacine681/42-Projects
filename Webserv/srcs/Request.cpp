#include "../inc/Request.hpp"

Request::Request()
{
	r_methodStr[::GET] = "GET";
	r_methodStr[::POST] = "POST";
	r_methodStr[::DELETE] = "DELETE";
/*changed*/	r_methodStr[::PUT] = "PUT";
	r_methodStr[::HEAD] = "HEAD";
	r_path = "";
	r_query = "";
	r_fragment = "";
	r_bodyStr = "";
	r_errorCode = 0;
	r_chunkLength = 0;
	r_method = NONE;
	r_methodIndex = 1;
	r_state = Request_Line;
	r_fieldsDoneFlag = false;
	r_bodyFlag = false;
	r_bodyDoneFlag = false;
	r_chunkedFlag = false;
	r_bodyLength = 0;
	r_storage = "";
	r_keyStorage = "";
	r_multiformFlag = false;
	r_boundary = "";
}

Request::Request(const Request& obj)
{
    *this =obj;
}
Request& Request::operator=(const Request& obj)
{
    if (this != &obj)
    {
	r_path = obj.r_path;
	r_query = obj.r_query;
	r_fragment = obj.r_fragment;
	r_bodyStr = obj.r_bodyStr;
	r_errorCode = obj.r_errorCode;
	r_chunkLength = obj.r_chunkLength;
	r_method = obj.r_method;
	r_methodIndex = obj.r_methodIndex;
	r_state = obj.r_state;
	r_fieldsDoneFlag = obj.r_fieldsDoneFlag;
	r_bodyFlag = obj.r_bodyFlag;
	r_bodyDoneFlag = obj.r_bodyDoneFlag;
	r_chunkedFlag = obj.r_chunkedFlag;
	r_bodyLength = obj.r_bodyLength;
	r_storage = obj.r_storage;
	r_keyStorage = obj.r_keyStorage;
	r_multiformFlag = obj.r_multiformFlag;
	r_boundary = obj.r_boundary;
    for(std::vector<u_int8_t>::const_iterator it= obj.r_body.begin(); it !=obj.r_body.end();it++)
		r_body.push_back(*it);
	for(std::map<std::string, std::string> ::const_iterator it= obj.r_requestHeaders.begin(); it !=obj.r_requestHeaders.end();it++)
		r_requestHeaders[it->first] = it->second;
	for(std::map<u_int8_t, std::string>::const_iterator it= obj.r_methodStr.begin(); it !=obj.r_methodStr.end();it++)
		r_methodStr[it->first] = it->second;

    }
    return *this;
}

size_t      Request::getmaxBody()
{
    return r_maxBody;
}

Request::~Request() {}

// verif s'il y'a des chemins relatives
bool    checkUriPos(std::string path)
{
    std::string tmp(path);
    char *res = strtok((char*)tmp.c_str(), "/");
    int pos = 0;
    while (res != NULL)
    {
        if (!strcmp(res, ".."))
            pos--;
        else
            pos++;
        if (pos < 0)
            return (1);
        res = strtok(NULL, "/");
    }
    return (0);
}

bool    allowedCharURI(uint8_t ch)
{
    if ((ch >= '#' && ch <= ';') || (ch >= '?' && ch <= '[') || (ch >= 'a' && ch <= 'z') ||
       ch == '!' || ch == '=' || ch == ']' || ch == '_' || ch == '~')
        return (true);
    return (false);
}

bool    isToken(uint8_t ch)
{
    if (ch == '!' || (ch >= '#' && ch <= '\'') || ch == '*'|| ch == '+' || ch == '-'  || ch == '.' ||
       (ch >= '0' && ch <= '9') || (ch >= 'A' && ch <= 'Z') || (ch >= '^' && ch <= '`') ||
       (ch >= 'a' && ch <= 'z') || ch == '|')
        return (true);
    return (false);
}

void    trimStr(std::string &str)
{
    static const char* spaces = " \t";
    str.erase(0, str.find_first_not_of(spaces));
    str.erase(str.find_last_not_of(spaces) + 1);
}

void    toLower(std::string &str)
{
    for (size_t i = 0; i < str.length(); ++i)
        str[i] = std::tolower(str[i]);
}

/*
Example http request: 	GET /api/users/123 HTTP/1.1
						Host: example.com
						Accept: application/json */
void    Request::feed(const char *data, size_t size)
{
    u_int8_t character;
    static std::stringstream s;
    for (size_t i = 0; i < size; ++i)
    {
        character = data[i];
        switch (r_state)
        {
            case Request_Line:
            {
                if (character == 'G')
                    r_method = GET;
                else if (character == 'P')
                {
                    r_state = Request_Line_Post_Put;
                    break ;
                }
                else if (character == 'D')
                    r_method = DELETE;
                else if (character == 'H')
                    r_method = HEAD;
                else
                {
                    r_errorCode = 501;
                    std::cout << "Method Error Request_Line and Character is = " << character << std::endl;
                    return ;
                }
                r_state = Request_Line_Method;
                break ;
            }
            case Request_Line_Post_Put:
            {
                if (character == 'O')
                    r_method = POST;
                else if (character == 'U')
                    r_method = PUT;
                else
                {
                    r_errorCode = 501;
                    std::cout << "Method Error Request_Line and Character is = " << character << std::endl;
                    return ;
                }
                r_methodIndex++;
                r_state = Request_Line_Method;
                break ;
            }
            case Request_Line_Method:
            {
                if (character == r_methodStr[r_method][r_methodIndex])
                    r_methodIndex++;
                else
                {
                    r_errorCode = 501;
                    std::cout << "Method Error Request_Line and Character is = " << character << std::endl;
                    return ;
                }

                if ((size_t) r_methodIndex == r_methodStr[r_method].length())
                    r_state = Request_Line_First_Space;
                break ;
            }
            case Request_Line_First_Space:
            {
                if (character != ' ')
                {
                    r_errorCode = 400;
                    std::cout << "Bad Character (Request_Line_First_Space)" << std::endl;
                    return ;
                }
                r_state = Request_Line_URI_Path_Slash;
                continue ;
            }
            case Request_Line_URI_Path_Slash:
            {
                if (character == '/')
                {
                    r_state = Request_Line_URI_Path;
                    r_storage.clear();
                }
                else
                {
                    r_errorCode = 400;
                    std::cout << "Bad Character (Request_Line_URI_Path_Slash)" << std::endl;
                    return ;
                }
                break ;
            }
            case Request_Line_URI_Path:
            {
                if (character == ' ')
                {
                    r_state = Request_Line_Ver;
                    r_path.append(r_storage);
                    r_storage.clear();
                    continue ;
                }
                else if (character == '?')
                {
                    r_state = Request_Line_URI_Query;
                    r_path.append(r_storage);
                    r_storage.clear();
                    continue ;
                }
                else if (character == '#')
                {
                    r_state = Request_Line_URI_Fragment;
                    r_path.append(r_storage);
                    r_storage.clear();
                    continue ;
                }
                else if (!allowedCharURI(character))
                {
                    r_errorCode = 400;
                    std::cout << "Bad Character (Request_Line_URI_Path)" << std::endl;
                    return ;
                }
                else if ( i > MAX_URI_LENGTH)
                {
                    r_errorCode = 414;
                    std::cout << "URI Too Long (Request_Line_URI_Path)" << std::endl;
                    return ;
                }
                break ;
            }
            case Request_Line_URI_Query:
            {
                if (character == ' ')
                {
                    r_state = Request_Line_Ver;
                    r_query.append(r_storage);
                    r_storage.clear();
                    continue ;
                }
                else if (character == '#')
                {
                    r_state = Request_Line_URI_Fragment;
                    r_query.append(r_storage);
                    r_storage.clear();
                    continue ;
                }
                else if (!allowedCharURI(character))
                {
                    r_errorCode = 400;
                    std::cout << "Bad Character (Request_Line_URI_Query)" << std::endl;
                    return ;
                }
                else if ( i > MAX_URI_LENGTH)
                {
                    r_errorCode = 414;
                    std::cout << "URI Too Long (Request_Line_URI_Path)" << std::endl;
                    return ;
                }
                break ;
            }
            case Request_Line_URI_Fragment:
            {
                if (character == ' ')
                {
                    r_state = Request_Line_Ver;
                    r_fragment.append(r_storage);
                    r_storage.clear();
                    continue ;
                }
                else if (!allowedCharURI(character))
                {
                    r_errorCode = 400;
                    std::cout << "Bad Character (Request_Line_URI_Fragment)" << std::endl;
                    return ;
                }
                else if ( i > MAX_URI_LENGTH)
                {
                    r_errorCode = 414;
                    std::cout << "URI Too Long (Request_Line_URI_Path)" << std::endl;
                    return ;
                }
                break ;
            }
            case Request_Line_Ver:
            {
                if (checkUriPos(r_path))
                {
                    r_errorCode = 400;
                    std::cout << "Request URI ERROR: goes before root !!" << std::endl;
                    return ;
                }
                if (character != 'H')
                {
                    r_errorCode = 400;
                    std::cout << "Bad Character (Request_Line_Ver)" << std::endl;
                    return ;
                }
                r_state = Request_Line_HT;
                break ;
            }
            case Request_Line_HT:
            {
                if (character != 'T')
                {
                    r_errorCode = 400;
                    std::cout << "Bad Character (Request_Line_HT)" << std::endl;
                    return ;
                }
                r_state = Request_Line_HTT;
                break ;
            }
            case Request_Line_HTT:
            {
                if (character != 'T')
                {
                    r_errorCode = 400;
                    std::cout << "Bad Character (Request_Line_HTT)" << std::endl;
                    return ;
                }
                r_state = Request_Line_HTTP;
                break ;
            }
            case Request_Line_HTTP:
            {
                if (character != 'P')
                {
                    r_errorCode = 400;
                    std::cout << "Bad Character (Request_Line_HTTP)" << std::endl;
                    return ;
                }
                r_state = Request_Line_HTTP_Slash;
                break ;
            }
            case Request_Line_HTTP_Slash:
            {
                if (character != '/')
                {
                    r_errorCode = 400;
                    std::cout << "Bad Character (Request_Line_HTTP_Slash)" << std::endl;
                    return ;
                }
                r_state = Request_Line_Major;
                break ;
            }
            case Request_Line_Major:
            {
                if (!isdigit(character))
                {
                    r_errorCode = 400;
                    std::cout << "Bad Character (Request_Line_Major)" << std::endl;
                    return ;
                }
                r_verMajor = character;

                r_state = Request_Line_Dot;
                break ;
            }
            case Request_Line_Dot:
            {
                if (character != '.')
                {
                    r_errorCode = 400;
                    std::cout << "Bad Character (Request_Line_Dot)" << std::endl;
                    return ;
                }
                r_state = Request_Line_Minor;
                break ;
            }
            case Request_Line_Minor:
            {
                if (!isdigit(character))
                {
                    r_errorCode = 400;
                    std::cout << "Bad Character (Request_Line_Minor)" << std::endl;
                    return ;
                }
                r_verMinor = character;
                r_state = Request_Line_CR;
                break ;
            }
            case Request_Line_CR:
            {
                if (character != '\r')
                {
                    r_errorCode = 400;
                    std::cout << "Bad Character (Request_Line_CR)" << std::endl;
                    return ;
                }
                r_state = Request_Line_LF;
                break ;
            }
            case Request_Line_LF:
            {
                if (character != '\n')
                {
                    r_errorCode = 400;
                    std::cout << "Bad Character (Request_Line_LF)" << std::endl;
                    return ;
                }
                r_state = Field_Name_Start;
                r_storage.clear();
                continue ;
            }
            case Field_Name_Start:
            {
                if (character == '\r')
                    r_state = Fields_End;
                else if (isToken(character))
                    r_state = Field_Name;
                else
                {
                    r_errorCode = 400;
                    std::cout << "Bad Character (Field_Name_Start)" << std::endl;
                    return ;
                }
                break ;
            }
            case Fields_End:
            {
                if (character == '\n')
                {
                    r_storage.clear();
                    r_fieldsDoneFlag = true;
                    r_handleHeaders();
                    //if no body then parsing is completed.
                    if (r_bodyFlag == 1)
                    {
                        if (r_chunkedFlag == true)
                            r_state = Chunked_Length_Begin;
                        else
                        {
                            r_state = Message_Body;
                        }
                    }
                    else
                    {
                        r_state = Parsing_Done;
                    }
                    continue ;
                }
                else
                {
                    r_errorCode = 400;
                    std::cout << "Bad Character (Fields_End)" << std::endl;
                    return ;
                }
                break ;
            }
            case Field_Name:
            {
                if (character == ':')
                {
                    r_keyStorage = r_storage;
                    r_storage.clear();
                    r_state = Field_Value;
                    continue ;
                }
                else if (!isToken(character))
                {
                    r_errorCode = 400;
                    std::cout << "Bad Character (Field_Name)" << std::endl;
                    return ;
                }
                break ;
                //if (!character allowed)
                // error;
            }
            case Field_Value:
            {
                if ( character == '\r' )
                {
                    setHeader(r_keyStorage, r_storage);
                    r_keyStorage.clear();
                    r_storage.clear();
                    r_state = Field_Value_End;
                    continue ;
                }
                break ;
            }
            case Field_Value_End:
            {
                if ( character == '\n' )
                {
                    r_state = Field_Name_Start;
                    continue ;
                }
                else
                {
                    r_errorCode = 400;
                    std::cout << "Bad Character (Field_Value_End)" << std::endl;
                    return ;
                }
                break ;
            }
            case Chunked_Length_Begin:
            {
                if (isxdigit(character) == 0)
                {
                    r_errorCode = 400;
                    std::cout << "Bad Character (Chunked_Length_Begin)" << std::endl;
                    return ;
                }
                s.str("");
                s.clear();
                s << character;
                s >> std::hex >> r_chunkLength;
                if (r_chunkLength == 0)
                    r_state = Chunked_Length_CR;
                else
                    r_state = Chunked_Length;
                continue ;
            }
            case Chunked_Length:
            {
                if (isxdigit(character) != 0)
                {
                    int temp_len = 0;
                    s.str("");
                    s.clear();
                    s << character;
                    s >> std::hex >> temp_len;
                    r_chunkLength *= 16;
                    r_chunkLength += temp_len;
                }
                else if (character == '\r')
                    r_state = Chunked_Length_LF;
                else
                    r_state = Chunked_Ignore;
                continue ;
            }
            case Chunked_Length_CR:
            {
                if ( character == '\r')
                    r_state = Chunked_Length_LF;
                else
                {
                    r_errorCode = 400;
                    std::cout << "Bad Character (Chunked_Length_CR)" << std::endl;
                    return ;
                }
                continue ;
            }
            case Chunked_Length_LF:
            {
                if ( character == '\n')
                {
                    if (r_chunkLength == 0)
                        r_state = Chunked_End_CR;
                    else
                        r_state = Chunked_Data;
                }
                else
                {
                    r_errorCode = 400;
                    std::cout << "Bad Character (Chunked_Length_LF)" << std::endl;
                    return ;
                }
                continue ;
            }
            case Chunked_Ignore:
            {
                if (character == '\r')
                    r_state = Chunked_Length_LF;
                continue ;
            }
            case Chunked_Data:
            {
				r_body.push_back(character);
				--r_chunkLength;
                if (r_chunkLength == 0)
                    r_state = Chunked_Data_CR;
				continue ;
            }
            case Chunked_Data_CR:
            {
                if ( character == '\r')
                    r_state = Chunked_Data_LF;
                else
                {
                    r_errorCode = 400;
                    std::cout << "Bad Character (Chunked_Data_CR)" << std::endl;
                    return ;
                }
                continue ;
            }
            case Chunked_Data_LF:
            {
                if ( character == '\n')
                    r_state = Chunked_Length_Begin;
                else
                {
                    r_errorCode = 400;
                    std::cout << "Bad Character (Chunked_Data_LF)" << std::endl;
                    return ;
                }
                continue ;
            }
            case Chunked_End_CR:
            {
                if (character != '\r')
                {
                    r_errorCode = 400;
                    std::cout << "Bad Character (Chunked_End_CR)" << std::endl;
                    return ;
                }
                r_state = Chunked_End_LF;
                continue ;

            }
            case Chunked_End_LF:
            {
                if (character != '\n')
                {
                    r_errorCode = 400;
                    std::cout << "Bad Character (Chunked_End_LF)" << std::endl;
                    return ;
                }
                r_bodyDoneFlag = true;
                r_state = Parsing_Done;
                continue ;
            }
            case Message_Body:
            {
                if (r_body.size() < r_bodyLength )
                    r_body.push_back(character);
                if (r_body.size() == r_bodyLength )
                {
                    r_bodyDoneFlag = true;
                    r_state = Parsing_Done;
                }
                break ;
            }
            case Parsing_Done:
            {
               break;
  /*changed */  //return ;
            }
        }//end of swtich
        r_storage += character;
    }
    if(r_state == Parsing_Done)
    {
        r_bodyStr.append((char*)r_body.data(), r_body.size());
    }
	erase_slash_end(r_path);
}

bool	Request::parsingCompleted()
{
/* problem*/return (r_state == Parsing_Done);
}

HttpMethod	&Request::getMethod()
{
	return (r_method);
}

std::string &Request::getPath()
{
	return (r_path);
}

std::string &Request::getQuery()
{
	return (r_query);
}

std::string &Request::getFragment()
{
	return (r_fragment);
}

std::string Request::getHeader(std::string const &name)
{
	return (r_requestHeaders[name]);
}

const std::map<std::string, std::string> &Request::getHeaders() const
{
	return (this->r_requestHeaders);
}

std::string Request::getMethodStr()
{
	return (r_methodStr[r_method]);
}

std::string &Request::getBody()
{
	return (r_bodyStr);
}

std::string Request::getServerName()
{
	return (this->r_serverName);
}

bool Request::getMultiformFlag()
{
	return (this->r_multiformFlag);
}

std::string &Request::getBoundary()
{
	return (this->r_boundary);
}

short     Request::errorCode()
{
    return (this->r_errorCode);
}

void Request::setBody(std::string body)
{
	r_body.clear();
	r_body.insert(r_body.begin(), body.begin(), body.end());
	r_bodyStr = body;
}

void Request::setMethod(HttpMethod & method)
{
	r_method = method;
}

void Request::setHeader(std::string &name, std::string &value)
{
	trimStr(value);
	toLower(name);
	r_requestHeaders[name] = value;
}

void Request::setMaxBodySize(size_t size)
{
	r_maxBody = size;
}

void        Request::printMessage()
{
    std::cout<<std::endl
        <<"r_path :"<<r_path<<std::endl
        <<"r_query :"<<r_query<<std::endl
        <<"r_bodyStr :"<<r_bodyStr<<std::endl
        <<"r_errorCode :"<<r_errorCode<<std::endl
        <<"r_chunkLength :"<<r_chunkLength<<std::endl
        <<"r_method :"<<r_method<<std::endl
        <<"r_state :"<<r_state<<std::endl
        <<"r_fieldsDoneFlag :"<<r_fieldsDoneFlag<<std::endl
        <<"r_bodyFlag :"<<r_bodyFlag<<std::endl
        <<"r_bodyDoneFlag :"<<r_bodyDoneFlag<<std::endl
        <<"r_chunkedFlag :"<<r_chunkedFlag<<std::endl
        <<"r_bodyLength :"<<r_bodyLength<<std::endl
        <<"r_multiformFlag :"<<r_multiformFlag<<std::endl
        <<"r_boundary :"<<r_boundary<<std::endl
        <<"r_maxBody :"<<r_maxBody<<std::endl;
       // <<"r_storage :"<<r_storage<<std::endl
       // <<"r_keyStorage :"<<r_keyStorage<<std::endl;

    for (std::map<std::string, std::string>::iterator it = r_requestHeaders.begin();
    it != r_requestHeaders.end(); ++it)
    {
        std::cout << it->first + ":" + it->second << std::endl;
    }
    std::cout << std::endl << "END OF BODY" << std::endl;

    std::cout << "BODY FLAG =" << r_bodyFlag << "  _BOD_done_flag= " << r_bodyDoneFlag << "FEIDLS FLAG = " << r_fieldsDoneFlag
    << std::endl;
	std::cout << "=====" << r_path << std::endl;
}

void        Request::r_handleHeaders()
{
    std::stringstream ss;

    if (r_requestHeaders.count("content-length"))
    {
        r_bodyFlag = true;
        ss << r_requestHeaders["content-length"];
        ss >> r_bodyLength;
    }
    if ( r_requestHeaders.count("transfer-encoding"))
    {
        if (r_requestHeaders["transfer-encoding"].find_first_of("chunked") != std::string::npos)
            r_chunkedFlag = true;
        r_bodyFlag = true;
    }
    if (r_requestHeaders.count("host"))
    {
        size_t pos = r_requestHeaders["host"].find_first_of(':');
        r_serverName = r_requestHeaders["host"].substr(0, pos);
    }
    if (r_requestHeaders.count("content-type") && r_requestHeaders["content-type"].find("multipart/form-data") != std::string::npos)
    {
        size_t pos = r_requestHeaders["content-type"].find("boundary=", 0);
        if (pos != std::string::npos)
            this->r_boundary = r_requestHeaders["content-type"].substr(pos + 9, r_requestHeaders["content-type"].size());
        this->r_multiformFlag = true;
    }
}

void    Request::clear()
{
    r_path.clear();
    r_errorCode = 0;
    r_query.clear();
    r_fragment.clear();
    r_method = NONE;
    r_methodIndex = 1;
    r_state = Request_Line;
    r_bodyLength = 0;
    r_chunkLength = 0x0;
    r_storage.clear();
    r_bodyStr = "";
    r_keyStorage.clear();
    r_requestHeaders.clear();
    r_serverName.clear();
    r_body.clear();
    r_boundary.clear();
    r_fieldsDoneFlag = false;
    r_bodyFlag = false;
    r_bodyDoneFlag = false;
    r_completeFlag = false;
    r_chunkedFlag = false;
    r_multiformFlag = false;
}

bool        Request::keepAlive()
{
    if (r_requestHeaders.count("connection"))
    {
        if (r_requestHeaders["connection"].find("close", 0) != std::string::npos)
            return (false);
    }
    return (true);
}

void            Request::cutReqBody(int bytes)
{
    r_bodyStr = r_bodyStr.substr(bytes);
}

void Request::erase_slash_end(std::string &path)
{
	if (path != "/")
	{
		size_t end = path.find_last_of("/");
		if (end == path.length() - 1)
			path.erase(end);
	}
}