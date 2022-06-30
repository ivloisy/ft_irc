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


/**************************** CONSTRUCTORS ****************************/

irc::User::User() :
	_nickname("yoka")
{
	;
}

irc::User::User(int fd, struct sockaddr_in address) :
		_fd(fd),
		_hostname(),
		_waitingToSend(),
		_command()
{
	//fcntl(_fd, F_SETFL, O_NONBLOCK);
	//this->_hostaddr = inet_ntoa(addr.sin_addr);

	{
		char tmp[NI_MAXHOST];
		if (getnameinfo((struct sockaddr *)&addr, sizeof(addr), tmp, NI_MAXHOST, NULL, 0, NI_NUMERICSERV))
			error("getnameinfo");
		else
			this->_hostname = tmp;
	}
	;
}

/*
irc::User::User(User const &src)
{
	;
}
*/
/***************************** DESTRUCTORS ****************************/
/*
irc::User::~User()
{
	;
}
*/
/************************* ASSIGNMENT OPERATOR ************************/
/*
irc::User &irc::User::operator=(User const &rhs)
{
	return (*this);
}
*/
/*************************** MEMBER FUNCTIONS **************************/



/******************************* GETTERS *******************************/

int 				irc::User::getFdUser(void) const
{
	return (this->_fd);
}

/*
int 				irc::User::getIdUser(void) const
{
	return (this->_idUser);
}
*/

std::string 		irc::User::getPrefix() const
{
	std::string prefix = "prefix";
	return (prefix);
}

std::string 		irc::User::getHostname() const
{
	return (this->_hostname);
}

std::string 		irc::User::getNickName() const
{
	return (this->_nickname);
}

void 				irc::User::write_buf(User &user, std::string const &msg)
{
	//_waitingToSend.push_back(message);
	this->buffer += ":" + this->getPrefix() + " " + msg + "\r\n";
}

ssize_t 			irc::User::send_buf(irc::User &user, std::string const &msg)
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

void 				irc::User::connection_replies(irc::Server serv)
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
void					irc::User::send_message(int nb_command, irc::Server serv)
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