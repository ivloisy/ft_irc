//
// Created by blyzance on 18/06/22.
//

#include "../includes/Server.hpp"
#include "../includes/Client.hpp"
#include <iostream>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>

Server::Server()
{

}

Server::Server(Server const & src)
{

}

Server::~Server()
{

}

void Server::createServerAddr(int portNum)
{
	this->_serverAddr.sin_family = AF_INET;
	this->_serverAddr.sin_addr.s_addr = htons(INADDR_ANY);
	this->_serverAddr.sin_port = htons(portNum);
}

void	Server::bindServer(Client const & client)
{
	if (bind(client.getFdClient(), (struct sockaddr*)&this->_serverAddr, sizeof(this->_serverAddr)) < 0 )
	{
		std::cout << "Error binding socket..." << std::endl;
		exit(1);
	}
}

void Server::listenClient(Client const & client)
{
	listen(client.getFdClient(), 1);
}

void Server::acceptClient(Client const & client, int size)
{
	this->_fdServer = accept(client.getFdClient(), (struct sockaddr*)&this->_serverAddr,
						  reinterpret_cast<socklen_t *>(&size));

	if (this->_fdServer < 0)
	{
		std::cout << "Error on accepting..." << std::endl;
		exit(1);
	}
}

void Server::closeClient(Client const & client)
{
	close(client.getFdClient());
}

int Server::getFdServer(void) const
{
	return (this->_fdServer);
}

struct sockaddr_in Server::getServerAddr() const
{
	return (this->_serverAddr);
}