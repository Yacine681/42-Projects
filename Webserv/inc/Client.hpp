#ifndef CLIENT_HPP
#define CLIENT_HPP

#include	"utiles.hpp"
#include	"Request.hpp"
#include	"Response.hpp"
#include	"ConfigServer.hpp"


class Client{

	private:

		int					_client_socket;
		struct sockaddr_in	_client_address;
		time_t				_last_msg_time;

	public:
		ConfigServer	server;
		Request			request;
		Response		response;

        Client();
        Client(const Client &other);
        Client(ConfigServer &ser);
		Client &operator=(const Client & rhs);
        ~Client();

        int                 getSocket() const;
        struct sockaddr_in  getAddress() const;
        Request         	  getRequest() const;
        time_t              getLastTime() const;

        void                setSocket(int &);
        void                setAddress(sockaddr_in &);
        void                setServer(ConfigServer &);
        void                buildResponse();
        void                updateTime();

        void                clearClient();
};

#endif
