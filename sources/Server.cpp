//
// Created by blyzance on 18/06/22.
//

#include "../includes/Server.hpp"
#include "../includes/User.hpp"
#include <iostream>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>

irc::Server::Server() :
	_serverName("irc.sample.com"),
	_portNum(6667)
{
	//int client, server;
	// default port for irc
	//bool isExit = false;
	//struct sockaddr_in server_addr;
	socklen_t size;
	//this->buffer = new char[bufsize];
	//user = new irc::User;

	this->establishConnection();

	this->createServerAddr(_portNum);

	this->bindServer();

	this->_size = sizeof(this->getServerAddr());
	std::cout << "Looking for clients..." << std::endl;

	this->listenUser(this->getUser());
}

irc::Server::Server(Server const & src)
{
	;
}

irc::Server::~Server()
{
	;
}

/*
irc::Config &irc::Server::getConfig()
{
	return (_config);
}
*/
/*
std::string irc::Server::getUpTime()
{
	return (_upTime);
}
*/

void				 irc::Server::establishConnection(void)
{
	this->_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (this->_fd < 0)
	{
		std::cout << "Error establishing connection..." << std::endl;
		//exit(1);
		return ;
	}
	std::cout << "Server Socket connection created..." << std::endl;
}

void				irc::Server::createServerAddr(int portNum)
{
	this->_serverAddr.sin_family = AF_INET;
	this->_serverAddr.sin_addr.s_addr = htons(INADDR_ANY);
	this->_serverAddr.sin_port = htons(portNum);
}

void				irc::Server::bindServer()
{
	if (bind(this->_fd, (struct sockaddr*)&this->_serverAddr, sizeof(this->_serverAddr)) < 0 )
	{
		std::cout << "Error binding socket..." << std::endl;
		//exit(1);
	}
}

void				irc::Server::listenUser(User & user)
{
	listen(user.getFdUser(), 1);
}

int					irc::Server::acceptUser(User & user, int size)
{
	int fd = accept(user.getFdUser(), (struct sockaddr*)&this->_serverAddr,
						  reinterpret_cast<socklen_t *>(&size));

	if (fd < 0)
	{
		std::cout << "Error on accepting..." << std::endl;
		return (-1);
	}
	_user.push_back(User(fd, this->_serverAddr));
	return (1);
}

void				irc::Server::closeUser(User & user)
{
	close(user.getFdUser());
}

int					irc::Server::getFdServer(void) const
{
	return (this->_fd);
}

struct sockaddr_in	irc::Server::getServerAddr() const
{
	return (this->_serverAddr);
}

irc::User 			&irc::Server::getUser()
{
	return (this->_user[0]);
}

socklen_t			irc::Server::getSize() const
{
	return (this->_size);
}

int 				irc::Server::getPortNum() const
{
	return (this->_portNum);
}



std::string 		irc::Server::getServerName() const
{
	return (this->_serverName);
}