//
// Created by antoine on 20/06/22.
//

#include "../includes/User.hpp"
//#include <sys/socket.h>

//#include <netinet/in.h>
//#include <netinet/ip.h>

//#include <iostream>
//#include <stdlib.h>

//#include <fcntl.h>
//#include <iostream>
//#include <sys/socket.h>
//#include <algorithm>
//#include <netdb.h>
//#include <arpa/inet.h>
//#include <unistd.h>
//#include <ctime>


/**************************** CONSTRUCTORS ****************************/

irc::User::User()
{
	;
}

irc::User::User(int fd, struct sockaddr_in address) :
		_fdUser(fd),
		_hostname(),
		_waitingToSend(),
		_commands()
{
	;
}

irc::User::User(User const &src)
{
	;
}

/***************************** DESTRUCTORS ****************************/

irc::User::~User()
{
	;
}

/************************* ASSIGNMENT OPERATOR ************************/

irc::User &irc::User::operator=(User const &rhs)
{
	return (*this);
}

/*************************** MEMBER FUNCTIONS **************************/

void irc::User::establishConnection(void)
{
	this->_fdUser = socket(AF_INET, SOCK_STREAM, 0);
	if (this->_fdUser < 0)
	{
		std::cout << "Error establishing connection..." << std::endl;
		exit(1);
	}
	std::cout << "Server Socket connection created..." << std::endl;
}

/******************************* GETTERS *******************************/

int irc::User::getFdUser(void) const
{
	return (this->_fdUser);
}

int irc::User::getIdUser(void) const
{
	return (this->_idUser);
}

std::string irc::User::getPrefix()
{
	std::string prefix = "prefix";
	return (prefix);
}

std::string irc::User::getHostname()
{
	return (this->_hostname);
}

void irc::User::write(std::string message)
{
	_waitingToSend.push_back(message);
}

void irc::User::sendTo(irc::User &toUser, std::string message)
{
	toUser.write(":" + this->getPrefix() + " " + message);
}

void irc::User::post_registration()
{
	_commands->reply(1, _commands->getUser().getPrefix());
	_commands->reply(2, _commands->getUser().getHostname(), _commands->getServer().getConfig().get("version"));
	_commands->reply(3, _commands->getServer().getUpTime());
	_commands->reply(4, _commands->getServer().getConfig().get("name"), _commands->getServer().getConfig().get("version"), _commands->getServer().getConfig().get("user_mode"), _commands->getServer().getConfig().get("channel_givemode") + _commands->getServer().getConfig().get("channel_togglemode") + _commands->getServer().getConfig().get("channel_setmode"));

	//LUSERS(command);
	//MOTD(command);
}