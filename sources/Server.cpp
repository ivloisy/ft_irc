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
	_servername("irc.sample.com"),
	portNum(6667)
	//bufsize(1024)
{
	//int client, server;
	// default port for irc
	//bool isExit = false;
	//struct sockaddr_in server_addr;
	socklen_t size;
	//this->buffer = new char[bufsize];
	//irc::User *user = new irc::User;

	user.establishConnection();

	this->createServerAddr(portNum);
	this->bindServer(user);

	this->size = sizeof(this->getServerAddr());
	std::cout << "Looking for clients..." << std::endl;

	this->listenUser(user);
}

irc::Server::Server(Server const & src)
{
	;
}

irc::Server::~Server()
{
	;
}

irc::Config &irc::Server::getConfig()
{
	return (_config);
}

std::string irc::Server::getUpTime()
{
	return (_upTime);
}

void irc::Server::createServerAddr(int portNum)
{
	this->_serverAddr.sin_family = AF_INET;
	this->_serverAddr.sin_addr.s_addr = htons(INADDR_ANY);
	this->_serverAddr.sin_port = htons(portNum);
}

void irc::Server::bindServer(User const & user)
{
	if (bind(user.getFdUser(), (struct sockaddr*)&this->_serverAddr, sizeof(this->_serverAddr)) < 0 )
	{
		std::cout << "Error binding socket..." << std::endl;
		//exit(1);
	}
}

void irc::Server::listenUser(User const & user)
{
	listen(user.getFdUser(), 1);
}

int irc::Server::acceptUser(User const & user, int size)
{
	this->_fdServer = accept(user.getFdUser(), (struct sockaddr*)&this->_serverAddr,
						  reinterpret_cast<socklen_t *>(&size));

	if (this->_fdServer < 0)
	{
		std::cout << "Error on accepting..." << std::endl;
		return (-1);
	}
	return (1);
}

void irc::Server::closeUser(User const & user)
{
	close(user.getFdUser());
}

int irc::Server::getFdServer(void) const
{
	return (this->_fdServer);
}

struct sockaddr_in irc::Server::getServerAddr() const
{
	return (this->_serverAddr);
}

irc::User			*irc::Server::getUser() const
{
	return (this->user);
}

socklen_t			irc::Server::getSize() const
{
	return (this->size);
}

int 				irc::Server::getPortNum() const
{
	return (this->portNum);
}

std::string 		irc::Server::getBuffer() const
{
	return (this->buffer);
}

/*
int 				irc::Server::getBufsize() const
{
	return (this->bufsize);
}
*/

std::string 		irc::Server::getServerName() const
{
	return (this->_servername);
}