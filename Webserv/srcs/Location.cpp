#include	"../inc/Location.hpp"

Location::Location()
{
		_path = "";
		_root = "";
		_autoindex = false;
		_index = "";
		_return = "";
		_rewrite = "";
		_cgi_path = "";
		_cgi_ext = "";
}

Location::Location(const Location &other)
{
	*this = other;
}

Location &Location::operator=(const Location &rhs)
{
	if (this != &rhs){
		_path = rhs._path;
		_root = rhs._root;
		_autoindex = rhs._autoindex;
		_index = rhs._index;
		_return = rhs._return;
		_rewrite = rhs._rewrite;
		_cgi_path = rhs._cgi_path;
		_cgi_ext = rhs._cgi_ext;
		for(std::vector<std::string>::const_iterator it=rhs._methods.begin(); it!=rhs._methods.end();it++)
			_methods.push_back(*it);
	}
	return *this;	
}

Location::~Location(){}

void Location::setPath(std::string path)
{
	_path = path;
}

void Location::setRootLocation(std::string parametr)
{
	_root = parametr;
}

void Location::setMethods(std::vector<std::string> methods)
{
	_methods = methods;
}

void Location::setAutoindex(std::string parametr)
{
	if (parametr == "on")
		_autoindex = true;
	else
		_autoindex = false;
}

void Location::setIndexLocation(std::string parametr)
{
	_index = parametr;
}


void Location::setReturn(std::string parametr)
{
	_return = parametr;
}


void Location::setRewrite(std::string parametr)
{
	_rewrite = parametr;
}


void Location::setCgiPath(std::string path)
{
	_cgi_path = path;
}

void Location::setCgiExtension(std::string extension)
{
	_cgi_ext = extension;
}

std::string Location::getPath() const
{
	return _path;
}

std::string Location::getRootLocation() const
{
	return _root;
}

std::vector<std::string> Location::getMethods() const
{
	return _methods;
}

bool Location::getAutoindex() const
{
	return _autoindex;
}

std::string Location::getIndexLocation() const
{
	return _index;
}

std::string Location::getReturn() const
{
	return _return;
}

std::string Location::getRewrite() const
{
	return _rewrite;
}

std::string Location::getCgiPath() const
{
	return _cgi_path;
}

std::string Location::getCgiExtension() const
{
	return _cgi_ext;
}