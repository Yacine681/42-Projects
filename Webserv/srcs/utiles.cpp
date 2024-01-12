#include "../inc/utiles.hpp"

void to_lower( std::string &str)
{
    if(!str.empty())
    {
        for(size_t i=0; i < str.length(); i++)
            str[i]= std::tolower(str[i]);
    }
}

int ft_stoi(std::string str)
{
    std::stringstream ss(str);
    if (str.length() > 10)
        throw std::exception();
    for (size_t i = 0; i < str.length(); ++i)
    {
        if(!isdigit(str[i]))
            throw std::exception();
    }
    int res;
    ss >> res;
    return (res);
}

bool	is_file(std::string	name)
{
	struct stat	st;
	if (stat(name.c_str(), &st) == 0)
		if (S_ISREG(st.st_mode))
			return true;
	return false;
	
}
template <typename T>
std::string toString(const T val)
{
    std::stringstream stream;
    stream << val;
    return stream.str();
}

bool	is_directory(std::string name)
{
	struct stat	st;
	if (stat(name.c_str(), &st) == 0)
		if (S_ISDIR(st.st_mode))
			return true;
	return false;
}
bool	is_readable(std::string name)
{
	if(access(name.c_str(), R_OK) == 0)
		return true;
	return false;
}
bool	is_exist(std::string name)
{
	if (access(name.c_str(), F_OK) == 0)
		return true;
	return false;
}

std::string statusCodeString(short statusCode)
{
    switch (statusCode)
    {
        case 100:
            return "Continue";
        case 101:
            return "Switching Protocol";
        case 200:
            return "OK";
        case 201:
            return "Created";
        case 202:
            return "Accepted";
        case 203:
            return "Non-Authoritative Information";
        case 204:
            return "No Content";
        case 205:
            return "Reset Content";
        case 206:
            return "Partial Content";
        case 300:
            return "Multiple Choice";
        case 301:
            return "Moved Permanently";
        case 302:
            return "Moved Temporarily";
        case 303:
            return "See Other";
        case 304:
            return "Not Modified";
        case 307:
            return "Temporary Redirect";
        case 308:
            return "Permanent Redirect";
        case 400:
            return "Bad Request";
        case 401:
            return "Unauthorized";
        case 403:
            return "Forbidden";
        case 404:
            return "Not Found";
        case 405:
            return "Method Not Allowed";
        case 406:
            return "Not Acceptable";
        case 407:
            return "Proxy Authentication Required";
        case 408:
            return "Request Timeout";
        case 409:
            return "Conflict";
        case 410:
            return "Gone";
        case 411:
            return "Length Required";
        case 412:
            return "Precondition Failed";
        case 413:
            return "Payload Too Large";
        case 414:
            return "URI Too Long";
        case 415:
            return "Unsupported Media Type";
        case 416:
            return "Requested Range Not Satisfiable";
        case 417:
            return "Expectation Failed";
        case 418:
            return "I'm a teapot";
        case 421:
            return "Misdirected Request";
        case 425:
            return "Too Early";
        case 426:
            return "Upgrade Required";
        case 428:
            return "Precondition Required";
        case 429:
            return "Too Many Requests";
        case 431:
            return "Request Header Fields Too Large";
        case 451:
            return "Unavailable for Legal Reasons";
        case 500:
            return "Internal Server Error";
        case 501:
            return "Not Implemented";
        case 502:
            return "Bad Gateway";
        case 503:
            return "Service Unavailable";
        case 504:
            return "Gateway Timeout";
        case 505:
            return "HTTP Version Not Supported";
        case 506:
            return "Variant Also Negotiates";
        case 507:
            return "Insufficient Storage";
        case 510:
            return "Not Extended";
        case 511:
            return "Network Authentication Required";
        default:
            return "Undefined";
        }
}

unsigned int fromhectoDec(const std::string& nb)
{
   unsigned int x;
    std::stringstream ss;
    ss<<nb;
    ss>>std::hex>>x;
    return x;
}

std::string getErrorPage(short _code)
{
    std::string tmp;
    tmp.append("<!DOCTYPE html>\r\n");
    tmp.append("<html>\r\n");
    tmp.append("<head>");
    tmp.append("<link rel=\"stylesheet\" type=\"text/css\" href=\"/css/my_styles.css\">\n");
    // tmp.append("<title>");
    // tmp.append(std::to_string(_code)+ " ");
    // tmp.append(statusCodeString(_code));
    // tmp.append("</title>");
    tmp.append("</head>\r\n");
    tmp.append("<body>");
    tmp.append("<div class=\"center-container\">\n");
    tmp.append("<p>\n");
    tmp.append(std::to_string(_code)+ " ");
    tmp.append(statusCodeString(_code));
   	tmp.append("\n");
	tmp.append("</p>\n");
	tmp.append("<h3>\n");
	tmp.append("<a href=\"/index.html\">");
	tmp.append("home page");
	tmp.append("</a");
	tmp.append("\n");
	tmp.append("</h3>\n");
	tmp.append("</div>\n");
    tmp.append("</body>\n");
    tmp.append("</html>");
    return tmp;
}
std::string file_deleted(const std::string name)
{
    std::string tmp;
    tmp.append("<!DOCTYPE html>\r\n");
    tmp.append("<html>\r\n");
    tmp.append("<head>");
    tmp.append("<title>");
    tmp.append("delete method");
    tmp.append("</title>");
    tmp.append("</head>\r\n");
    tmp.append("<body>");
    tmp.append("<center><h1>");
    tmp.append(name + " file deleted successfully!");
    tmp.append("</center></h1>");
    tmp.append("</body>");
    tmp.append("</html>");
    return tmp;
}
std::string file_upload(const std::string name)
{
    std::string tmp;
    tmp.append("<!DOCTYPE html>\r\n");
    tmp.append("<html>\r\n");
    tmp.append("<head>");
    tmp.append("<title>");
    tmp.append("delete method");
    tmp.append("</title>");
    tmp.append("</head>\r\n");
    tmp.append("<body>");
    tmp.append("<center><h1>");
    tmp.append(name + " file upload successfully!");
    tmp.append("</center></h1>");
    tmp.append("</body>");
    tmp.append("</html>");
    return tmp;
}


std::string upload_list(std::string path)
{
    struct dirent   *ents;
    DIR             *directory;
    std::string        page;
    directory = opendir(path.c_str());
    if(directory == NULL)
        return "";
    page.append("<!DOCTYPE html>");
    page.append("<html>\n");
    page.append("<head>\n");
    page.append("<title> index of ");
    page.append(path);
    page.append("</title>\n");
    page.append("<body>\n");
    page.append("<h1>"+ path+ "</h1>\n");
    page.append("<table style=\"width:80%; font-size: 15px\">\n");
    page.append("<hr>\n");
    page.append("<th style=\"text-align:left\"> File Name </th>\n");
    page.append("<th style=\"text-align:left\"> Last Modification  </th>\n");
    page.append("<th style=\"text-align:left\"> File Size </th>\n");
    // page.append("<th style=\"text-align:left\"> Delete File</th>\n");
    struct stat st;
    std::string f_path;
    while((ents = readdir(directory)) != NULL)
    {
        if(strcmp(ents->d_name, ".") ==0)
            continue;
        f_path = path + "/" + ents->d_name;
        stat(f_path.c_str(), &st);
        page.append("<tr>\n");
        page.append("<td>");
        page.append("<a href = \"/upload/");
        page.append(ents->d_name);
        // if(S_ISDIR(st.st_mode))
        //     page.append("/");
        page.append("\">");
        page.append(ents->d_name);
        if(S_ISDIR(st.st_mode))
            page.append("/");
        page.append("</a>\n");
        page.append("</td>\n");
        page.append("<td>");
        page.append(ctime(&st.st_mtime));
        page.append("</td>\n");
        page.append("<td>");
        if(!S_ISDIR(st.st_mode))
            page.append(toString(st.st_size));
        page.append("</td>\n");
        page.append("</tr>\n");
    }
    page.append("</table>\n");
    page.append("</body>\n");
    page.append("</head>\n");
    page.append("</html>\n");
    closedir(directory);
    return page;
}
std::string directory_list(std::string path, std::string loc)
{
    struct dirent   *ents;
    DIR             *directory;
    std::string        page;
    directory = opendir(path.c_str());
    if(directory == NULL)
        return "";
    page.append("<!DOCTYPE html>");
    page.append("<html>\n");
    page.append("<head>\n");
    page.append("<title> index of ");
    page.append(path);
    page.append("</title>\n");
    page.append("<body>\n");
    page.append("<h1>"+ path+ "</h1>\n");
    page.append("<table style=\"width:80%; font-size: 15px\">\n");
    page.append("<hr>\n");
    page.append("<th style=\"text-align:left\"> File Name </th>\n");
    page.append("<th style=\"text-align:left\"> Last Modification  </th>\n");
    page.append("<th style=\"text-align:left\"> File Size </th>\n");
    page.append("<th style=\"text-align:left\"> Delete File</th>\n");
    struct stat st;
    std::string f_path;
    while((ents = readdir(directory)) != NULL)
    {
        if(strcmp(ents->d_name, ".") ==0)
            continue;
        f_path = path + "/" + ents->d_name;
        stat(f_path.c_str(), &st);
        page.append("<tr>\n");
        page.append("<td>");
        page.append("<a href = \"");
        page.append( loc);
        page.append( "/");
        page.append( ents->d_name);
        // if(S_ISDIR(st.st_mode))
        //     page.append("/");
        page.append("\">");
        page.append(ents->d_name);
        if(S_ISDIR(st.st_mode))
            page.append("/");
        page.append("</a>\n");
        page.append("</td>\n");
        page.append("<td>");
        page.append(ctime(&st.st_mtime));
        page.append("</td>\n");
        page.append("<td>");
        if(!S_ISDIR(st.st_mode))
            page.append(toString(st.st_size));
        page.append("</td>\n");
        page.append("</tr>\n");
    }
    page.append("</table>\n");
    page.append("</body>\n");
    page.append("</head>\n");
    page.append("</html>\n");
    closedir(directory);
    return page;
}