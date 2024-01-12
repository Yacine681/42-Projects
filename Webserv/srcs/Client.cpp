#include "../inc/Client.hpp"

Client::Client()
{
	_last_msg_time = time(NULL);
}

Client::~Client() {}

Client::Client(const Client &other)
{
	*this = other;
}
/* Assinment operator */
Client &Client::operator=(const Client & rhs)
{
	if (this != &rhs)
	{
		this->_client_socket = rhs._client_socket;
		this->_client_address = rhs._client_address;
		this->request = rhs.request;
		this->response = rhs.response;
		this->server = rhs.server;
		this->_last_msg_time = rhs._last_msg_time;
	}
	return (*this);
}

Client::Client(ConfigServer &_server):server(_server),request(),response()
{
    request.setMaxBodySize(_server.getMaxBody());
    _last_msg_time = time(NULL); //current time 
}

void    Client::setSocket(int &sock)
{
    _client_socket = sock;
}

void    Client::setAddress(sockaddr_in &addr)
{
    _client_address =  addr;
}

void    Client::setServer(ConfigServer &_server)
{
    this->server = _server;
    // response.setServer(_server);
}

int     Client::getSocket() const
{
    return (_client_socket);
}

Request   Client::getRequest() const
{
    return (request);
}

struct sockaddr_in    Client::getAddress() const
{
    return (_client_address);
}

time_t     Client::getLastTime() const
{
    return (_last_msg_time);
}

void        Client::buildResponse()
{
    response.setServer(this->server);
    request.setMaxBodySize(this->server.getMaxBody());
    response.setRequest(this->request);
    response.BuildResponse();

}

void      Client::updateTime()
{
    _last_msg_time = time(NULL);
}
void             Client::clearClient()
{
    response.clear();
    request.clear();
}