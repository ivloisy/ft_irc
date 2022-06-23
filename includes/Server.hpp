//
// Created by blyzance on 18/06/22.
//

#ifndef SERVER_HPP
#define SERVER_HPP

// #include <netinet/in.h>
// #include <sys/socket.h>
#include <ft_irc.hpp>
#include "Client.hpp"

class Server
{
	Server();
	Server(Server const & src);
	Server operator=(Server const & src);
	int		_port;
	string	_password;
    //int client; //(instantiation client)
	int _fdServer;
    //int nbClients; (client class, static variable)
    //int channels; //(instantiation channels)
    //int portNum;
	struct sockaddr_in _serverAddr;
	//MAP Client client;
	socklen_t size;

public:
	virtual ~Server();
	Server(string port, string password);
	void				bindServer(Client const & client);
	void				createServerAddr(int portNum);
	void				listenClient(Client const & client);
	void				acceptClient(Client const & client, int size);
	void				closeClient(Client const & client);

	int 				getFdServer() const;
	struct sockaddr_in	getServerAddr() const;
};


#endif //SERVER_HPP
