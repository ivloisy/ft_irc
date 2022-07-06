//
// Created by antoine on 20/06/22.
//

#include "../includes/User.hpp"
#include "../includes/Command.hpp"
#include "../includes/Server.hpp"
//#include <sys/socket.h>

//#include <netinet/in.h>
//#include <netinet/ip.h>

#include <sstream>
#include <stdlib.h> //exit

#include <fcntl.h>
//#include <iostream>
//#include <sys/socket.h>
//#include <algorithm>
//#include <netdb.h>
//#include <arpa/inet.h>
//#include <unistd.h>
//#include <ctime>

using namespace irc;

void	cap_cmd(Command * cmd);
void	die_cmd(Command * cmd);
void	join_cmd(Command * cmd);
void	list_cmd(Command * cmd);
void	mode_cmd(Command * cmd);
void	msg_cmd(Command * cmd);
void	names_cmd(Command * cmd);
void	nick_cmd(Command * cmd);
void	notice_cmd(Command * cmd);
void	oper_cmd(Command * cmd);
void	part_cmd(Command * cmd);
void	pass_cmd(Command * cmd);
void	ping_cmd(Command * cmd);
void	pong_cmd(Command * cmd);
void	privmsg_cmd(Command * cmd);
void	quit_cmd(Command * cmd);
void	rehash_cmd(Command * cmd);
void	restart_cmd(Command * cmd);
void	squit_cmd(Command * cmd);
void	user_cmd(Command * cmd);
void	wallops_cmd(Command * cmd);

/**************************** CONSTRUCTORS ****************************/

User::User(int fd, struct sockaddr_in address) :
		cmap(),
		_fd(fd),
		_hostname(),
		_nickname("yoka"),
		bufsize(512),
		_command(),
		_acceptConnect(1)
{
	(void) address;
	init_map_cmd();
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
	}
	return (*this);
}

/*************************** MEMBER FUNCTIONS **************************/

void 					User::write_buf(User * user, std::string const &msg)
{
	(void)user;
	this->buffer = msg + "\n";
}

ssize_t 				User::send_buf(Server & serv, std::string const &msg)
{
	ssize_t res;
	write_buf(serv.getUser(), msg);
	std::cout << this->buffer.c_str() << std::endl;
	res = send(serv.getUser()->getFdUser(), this->buffer.c_str(), this->buffer.length(), 0);
	if (res == -1)
	{
		return (res);
	}
	this->buffer.clear();
	return (res);
}

void 					User::connection_replies(Command * com)
{
	com->reply(com->getServer(), *this, 1, com->getUser().getNickName());
	com->reply(com->getServer(), *this, 2, com->getUser().getNickName());
	com->reply(com->getServer(), *this, 3, com->getUser().getNickName());
	com->reply(com->getServer(), *this, 4, com->getUser().getNickName());
}

/********************* GETTERS ***********************/

int 					User::getFdUser(void) const
{
	return (this->_fd);
}

std::string 			User::getPrefix() const
{
	std::string prefix = "prefix";
	return (prefix);
}

std::string 			&User::getBuffer()
{
	return (this->buffer);
}


int 					User::getBufsize() const
{
	return (this->bufsize);
}

std::vector<Command *>	User::getCommand() const
{
	return (this->_command);
}

std::string 			User::getPassWord() const
{
	return (this->_password);
}

std::string 			User::getUserName() const
{
	return (this->_username);
}

std::string				User::getRealName() const
{
	return (this->_realname);
}

std::string 			User::getHostname() const
{
	return (this->_hostname);
}

std::string 			User::getNickName() const
{
	return (this->_nickname);
}

bool					User::getAcceptConnect() const
{
	return (this->_acceptConnect);
}

bool					User::getOper() const
{
	return (this->_isOper);
}



/********************** SETTERS ***********************/

void					User::setOper(bool op)
{
	this->_isOper = op;
}

void 					User::setFdUser(int fd)
{
	this->_fd = fd;
}

void					User::setBuffer(std::string buf)
{
	this->buffer = buf;
}

void					User::setNickName(std::string nickname)
{
	this->_nickname = nickname;
}

void					User::setUserName(std::string username)
{
	this->_username = username;
}

void					User::setRealName(std::string realname)
{
	this->_realname = realname;
}

void					User::setHostName(std::string hostname)
{
	this->_hostname = hostname;
}

void					User::setPassWord(std::string password)
{
	this->_password = password;
}



void					User::setAcceptConnect(bool ac)
{
	this->_acceptConnect = ac;
}


/******************** COMMANDS **********************/

void					User::init_map_cmd()
{
	cmap["CAP"] 	= 	cap_cmd;
	cmap["DIE"] 	= 	user_cmd;
	cmap["JOIN"] 	= 	join_cmd;
	cmap["LIST"] 	= 	list_cmd;
	cmap["MODE"] 	= 	mode_cmd;
	cmap["MSG"] 	= 	msg_cmd;
	cmap["NAMES"] 	= 	names_cmd;
	cmap["NICK"] 	=	nick_cmd;
	cmap["NOTICE"] 	= 	notice_cmd;
	cmap["OPER"] 	= 	oper_cmd;
	cmap["PART"] 	=	part_cmd;
	cmap["PASS"] 	= 	pass_cmd;
	cmap["PING"] 	= 	ping_cmd;
	cmap["PONG"] 	= 	pong_cmd;
	cmap["PRIVMSG"] =	privmsg_cmd;
	cmap["QUIT"] 	=	quit_cmd;
	cmap["REHASH"] 	= 	rehash_cmd;
	cmap["RESTART"] = 	restart_cmd;
	cmap["SQUIT"] 	= 	squit_cmd;
	cmap["USER"] 	= 	user_cmd;
	cmap["WALLOPS"] = 	wallops_cmd;
}

void					User::tokenize(std::string const &str, Server *serv)
{
	std::stringstream ss(str);
	std::string s;
	while (std::getline(ss, s, '\n'))
	{
		std::stringstream o(s);
		std::string u;
		while (std::getline(o, u, ' '))
		{
			this->parameters.push_back(u);
			//u.clear();
		}
		this->_command.push_back(new Command(serv, this, this->parameters));
		this->parameters.clear();
		//s.clear();
	}
}

void					User::parse_buffer_command(Server * serv)
{
	tokenize(this->buffer,  serv); //this splits the buffer into different vectors of parameters

	/*			Uncomment this for printing parameters
	for(std::vector<Command *>::iterator itc = this->_command.begin(); itc != this->_command.end(); itc++)
	{
		(*itc)->print_parameters();
		std::cout << "nl" << std::endl;
	}
	*/

	/*			Uncomment this for executing commands
	cmap.find(*this->parameters.begin())->second(this->_command[0]);
	for (std::vector<Command *>::iterator itc = this->_command.begin(); itc != this->_command.end(); itc++)
	{
		cmap.find(*(*itc)->getParameters().begin())->second(*itc);
	}
	*/

	if (this->getAcceptConnect()) // connection ok
	{
		this->connection_replies(*this->_command.begin());
		this->setAcceptConnect(0);
	}
}
