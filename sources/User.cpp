//
// Created by antoine on 20/06/22.
//

#include "../includes/User.hpp"
#include "../includes/Command.hpp"
#include "../includes/Server.hpp"
//#include <sys/socket.h>

//#include <netinet/in.h>
//#include <netinet/ip.h>

//#include <iostream>
#include <stdlib.h> //exit

//#include <fcntl.h>
//#include <iostream>
//#include <sys/socket.h>
//#include <algorithm>
//#include <netdb.h>
//#include <arpa/inet.h>
//#include <unistd.h>
//#include <ctime>

using namespace irc;

/**************************** CONSTRUCTORS ****************************/

User::User() : _nickname("yoka")
{
	;
}

User::User(int fd, struct sockaddr_in address) :
		_fd(fd),
		_hostname(),
		_waitingToSend(),
		_command(),
		bufsize(512)
{
	//fcntl(_fd, F_SETFL, O_NONBLOCK);
	//this->_hostaddr = inet_ntoa(addr.sin_addr);

	//buffer = new char[512];

	//{
	//	char tmp[NI_MAXHOST];
	//	if (getnameinfo((struct sockaddr *)&addr, sizeof(addr), tmp, NI_MAXHOST, NULL, 0, NI_NUMERICSERV))
	//		error("getnameinfo");
	//	else
	//		this->_hostname = tmp;
	//}
	;
}

/*
User::User(User const &src)
{
	;
}
*/
/***************************** DESTRUCTORS ****************************/
/*
User::~User()
{
	;
}
*/
/************************* ASSIGNMENT OPERATOR ************************/

User &User::operator=(User const &rhs)
{
	if (this != &rhs)
	{
		this->_fd = rhs._fd;
		//this->_serverAddr = rhs._serverAddr;
	}
	return (*this);
}

/*************************** MEMBER FUNCTIONS **************************/



/******************************* GETTERS *******************************/

int 				User::getFdUser(void) const
{
	return (this->_fd);
}

/*
int 				User::getIdUser(void) const
{
	return (this->_idUser);
}
*/

std::string 		User::getPrefix() const
{
	std::string prefix = "prefix";
	return (prefix);
}

std::string 		User::getHostname() const
{
	return (this->_hostname);
}

std::string 		User::getNickName() const
{
	return (this->_nickname);
}

void 				User::write_buf(User &user, std::string const &msg)
{
	//_waitingToSend.push_back(message);
	this->buffer =  msg + "\n";
}

ssize_t 			User::send_buf(User &user, std::string const &msg)
{
	//user.write(":" + this->getPrefix() + " " + message);
	ssize_t res;

	res = send(this->_fd, this->buffer.c_str(), this->buffer.length(), 0);
	if (res == -1)
		return (res);

	//this->buffer.clear();
	//this->lastping = std::time(NULL);
	return (res);
}

void 				User::connection_replies(Server serv)
{
	this->_command->reply(*this, 1, serv.getServerName(),
						 serv.getUser().getNickName());
	this->_command->reply(*this, 2, serv.getServerName(),
						 serv.getUser().getNickName());
	this->_command->reply(*this, 3, serv.getServerName(),
						 serv.getUser().getNickName());
	this->_command->reply(*this, 4, serv.getServerName(),
						 serv.getUser().getNickName());

	//LUSERS(command);
	//MOTD(command);
}
/*
void					User::send_message(int nb_command, Server serv)
{
	//std::string message;

	switch (nb_command)
	{
		case 001:
			this->_command.reply(this, nb_command, serv.getServerName().c_str(), serv.getUser().getNickName().c_str(), ":Welcome to the Internet Relay Network yoka");
			//message = ":" + serv.getServerName() + " " + itoa(nb_command).c_str() + " " + serv.getUser().getNickName() + ;
			//send(serv.getFdServer(), message.c_str(), message.length(), 0);
			//message.clear();
			return ;
		case 002:
			this->_command.reply(this, nb_command, serv.getServerName().c_str(), serv.getUser().getNickName().c_str(), ":Your host is irc.sample.com, running version 12");
			//message = ":irc.sample.com 002 yoka :Your host is irc.sample.com, running version 12";
			//send(serv.getFdServer(), message.c_str(), message.length(), 0);
			//message.clear();
			return ;
		case 003:
			this->_command.reply(this, nb_command, serv.getServerName().c_str(), serv.getUser().getNickName().c_str(), ":This server was created today");
			//message = ":irc.sample.com 003 yoka :This server was created today";
			//send(serv.getFdServer(), message.c_str(), message.length(), 0);
			//message.clear();
			return ;
		case 004:
			this->_command.reply(this, nb_command, serv.getServerName().c_str(), serv.getUser().getNickName().c_str(), ":localhost 12 2i1j4oi jwer");
			//message = ":irc.sample.com 004 yoka :localhost 12 2i1j4oi jwer";
			//send(serv.getFdServer(), message.c_str(), message.length(), 0);
			//message.clear();
			return ;
		default:
			return ;
	}
}
*/


std::string 		&User::getBuffer()
{
	return (this->buffer);
}


int 				User::getBufsize() const
{
	return (this->bufsize);
}

void 				User::setFdUser(int & fd)
{
		this->_fd = fd;
}
