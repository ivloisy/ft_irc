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
	//fcntl(_fdUser, F_SETFL, O_NONBLOCK);
	//this->_hostaddr = inet_ntoa(addr.sin_addr);

	/*{
		char tmp[NI_MAXHOST];
		if (getnameinfo((struct sockaddr *)&addr, sizeof(addr), tmp, NI_MAXHOST, NULL, 0, NI_NUMERICSERV))
			error("getnameinfo");
		else
			this->_hostname = tmp;
	}*/
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

void irc::User::write_buf(User &user, std::string const &msg)
{
	//_waitingToSend.push_back(message);
	this->buffer += ":" + this->getPrefix() + " " + msg + "\r\n";
}

ssize_t irc::User::send_buf(irc::User &user, std::string const &msg)
{
	//user.write(":" + this->getPrefix() + " " + message);
	ssize_t res;

	res = send(this->_fdUser, this->buffer.c_str(), this->buffer.length(), 0);
	if (res == -1)
		return (res);

	//this->buffer.clear();
	//this->lastping = std::time(NULL);
	return (res);
}

void irc::User::post_registration(irc::Command *command)
{
	command->reply(1, command->getUser().getPrefix());
	command->reply(2, command->getUser().getHostname(), command->getServer().getConfig().get("version"));
	command->reply(3, command->getServer().getUpTime());
	command->reply(4, command->getServer().getConfig().get("name"), command->getServer().getConfig().get("version"), command->getServer().getConfig().get("user_mode"), command->getServer().getConfig().get("channel_givemode") + command->getServer().getConfig().get("channel_togglemode") + command->getServer().getConfig().get("channel_setmode"));

	//LUSERS(command);
	//MOTD(command);
}