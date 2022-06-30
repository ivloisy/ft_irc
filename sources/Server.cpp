//
// Created by blyzance on 18/06/22.
//

#include "../includes/Server.hpp"
#include "../includes/User.hpp"
#include <iostream>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>

using namespace irc;

Server::Server() :
	_serverName("irc.sample.com"),
	_portNum(6667)
{
	socklen_t size;

	this->establishConnection();

	this->_fdMax = this->_fd;

	this->createServerAddr(this->_portNum);

	this->bindServer();

	this->_size = sizeof(this->getServerAddr());
	std::cout << "Looking for clients..." << std::endl;

	if (listen(this->_fd, this->getServerAddr().sin_port) < 0)
	{
		//error
		;
	}

}

Server::Server(Server const & src)
{
	return;
}

Server::~Server()
{
	return;
}

/*
Config &Server::getConfig()
{
	return (_config);
}
*/
/*
std::string Server::getUpTime()
{
	return (_upTime);
}
*/

void				 Server::establishConnection(void)
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

void				Server::createServerAddr(int portNum)
{
	this->_serverAddr.sin_family = AF_INET;
	this->_serverAddr.sin_addr.s_addr = htons(INADDR_ANY);
	this->_serverAddr.sin_port = htons(portNum);
}

void				Server::bindServer()
{
	if (bind(this->_fd, (struct sockaddr*)&this->_serverAddr, sizeof(this->_serverAddr)) < 0 )
	{
		std::cout << "Error binding socket..." << std::endl;
		//exit(1);
	}
}

void				Server::listenUser()
{
	std::cout << "fd = " << this->_user.at(0).getFdUser() << std::endl;
	listen(this->_user.at(0).getFdUser(), 1);

}

int					Server::acceptUser(User & user, socklen_t  size)
{
	std::cout << "1acceptUser function" << std::endl;
	int fd = accept(this->_fd, (struct sockaddr*)&this->_serverAddr,
						  reinterpret_cast<socklen_t *>(&size));
	std::cout << "2acceptUser function" << std::endl;
	if (fd < 0)
	{
		std::cout << "Error on accepting..." << std::endl;
		return (-1);
	}
	std::cout << "3acceptUser function" << std::endl;
	_user.push_back(User(fd, this->_serverAddr));
	_user[0].setFdUser(fd);
	//std::cout << "before" << std::endl;
	//std::cout << &(_user.at(0)) << std::endl;
	//std::cout << "after" << std::endl;
	return (fd);
}

void				Server::closeUser(User & user)
{
	close(user.getFdUser());
}

int 				Server::getFdMax() const
{
	return this->_fdMax;
}


void 				Server::setUpFdMax(int fdCurrent)
{
	if (fdCurrent > this->_fdMax)
		this->_fdMax = fdCurrent;
}
//
// void 				Server::setDownFdMax(int fdCurrent)
// {

// }


int					&Server::getFdServer(void)
{
	return (this->_fd);
}

struct sockaddr_in	Server::getServerAddr() const
{
	return (this->_serverAddr);
}

User 			&Server::getUser()
{
	return (this->_user[0]);
}

socklen_t			Server::getSize() const
{
	return (this->_size);
}

int 				Server::getPortNum() const
{
	return (this->_portNum);
}

std::string 		Server::getServerName() const
{
	return (this->_serverName);
}
