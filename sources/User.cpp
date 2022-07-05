//
// Created by antoine on 20/06/22.
//

#include "../includes/User.hpp"
#include "../includes/Message.hpp"
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

void	cap_cmd(User & user, Server & server, std::vector<std::string> & buffer);
void	die_cmd(User & user, Server & server, std::vector<std::string> & buffer);
void	join_cmd(User & user, Server & server, std::vector<std::string> & buffer);
void	list_cmd(User & user, Server & server, std::vector<std::string> & buffer);
void	mode_cmd(User & user, Server & server, std::vector<std::string> & buffer);
void	msg_cmd(User & user, Server & server, std::vector<std::string> & buffer);
void	names_cmd(User & user, Server & server, std::vector<std::string> & buffer);
void	nick_cmd(User & user, Server & server, std::vector<std::string> & buffer);
void	notice_cmd(User & user, Server & server, std::vector<std::string> & buffer);
void	oper_cmd(User & user, Server & server, std::vector<std::string> & buffer);
void	part_cmd(User & user, Server & server, std::vector<std::string> & buffer);
void	pass_cmd(User & user, Server & server, std::vector<std::string> & buffer);
void	ping_cmd(User & user, Server & server, std::vector<std::string> & buffer);
void	pong_cmd(User & user, Server & server, std::vector<std::string> & buffer);
void	privmsg_cmd(User & user, Server & server, std::vector<std::string> & buffer);
void	quit_cmd(User & user, Server & server, std::vector<std::string> & buffer);
void	rehash_cmd(User & user, Server & server, std::vector<std::string> & buffer);
void	restart_cmd(User & user, Server & server, std::vector<std::string> & buffer);
void	squit_cmd(User & user, Server & server, std::vector<std::string> & buffer);
void	user_cmd(User & user, Server & server, std::vector<std::string> & buffer);
void	wallops_cmd(User & user, Server & server, std::vector<std::string> & buffer);

/**************************** CONSTRUCTORS ****************************/

User::User() : _nickname("yoka"), cmap()
{
	init_map_cmd();
	return ;
}

User::User(int fd, struct sockaddr_in address) :
		_nickname("yoka"),
		_fd(fd),
		_hostname(),
		cmap(),
		_msg(),
		bufsize(512)
{
	init_map_cmd();
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

void 				User::write_buf(User * user, std::string const &msg)
{
	//_waitingToSend.push_back(message);
	this->buffer =  msg + "\n";
}

ssize_t 			User::send_buf(Server & serv, std::string const &msg)
{
	//user.write(":" + this->getPrefix() + " " + message);
	ssize_t res;
	write_buf(serv.getUser(), msg);
	std::cout << this->buffer.c_str() << std::endl;
	res = send(serv.getUser()->getFdUser(), this->buffer.c_str(), this->buffer.length(), 0);
	if (res == -1)
	{
		return (res);
	}


	//this->buffer.clear();
	//this->lastping = std::time(NULL);
	return (res);
}

void 				User::connection_replies(Server & serv)
{
	this->_msg->reply(serv, *this, 1, serv.getUser()->getNickName());
	this->_msg->reply(serv, *this, 2, serv.getUser()->getNickName());
	this->_msg->reply(serv, *this, 3, serv.getUser()->getNickName());
	this->_msg->reply(serv, *this, 4, serv.getUser()->getNickName());

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

/********************* GETTERS ***********************/

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

std::string 		&User::getBuffer()
{
	return (this->buffer);
}


int 				User::getBufsize() const
{
	return (this->bufsize);
}

User::map_cmd		User::getCommand() const
{
	return (this->cmap);
}

std::string 		User::getPassWord() const
{
	return (this->_password);
}

std::string 		User::getUserName() const
{
	return (this->_username);
}

std::string			User::getRealName() const
{
	return (this->_realname);
}

std::string 		User::getHostname() const
{
	return (this->_hostname);
}

std::string 		User::getNickName() const
{
	return (this->_nickname);
}

/********************** SETTERS ***********************/

void 				User::setFdUser(int fd)
{
	this->_fd = fd;
}

void				User::setBuffer(std::string buf)
{
	this->buffer = buf;
}

void				User::setNickName(std::string nickname)
{
	this->_nickname = nickname;
}

void				User::setUserName(std::string username)
{
	this->_username = username;
}

void				User::setRealName(std::string realname)
{
	this->_realname = realname;
}

void				User::setHostName(std::string hostname)
{
	this->_hostname = hostname;
}

void				User::setPassWord(std::string password)
{
	this->_password = password;
}

/******************** COMMANDS **********************/

void		User::init_map_cmd()//Server & serv, User & user)
{
	//std::string buf("Salut les amis");
	//map_cmd cmd;
	//cmd.insert(pair<string, pointer_function>("CAP", com.cap_cmd()));

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
	//return (cmd);
}

void				User::tokenize(std::string const &str, const char delim, std::vector<std::string> &out)
{
	std::stringstream ss(str);

	std::string s;
	while (std::getline(ss, s, delim))
	{
		out.push_back(s);
	}
}

void				User::parse_buffer_command(Server & serv)
{
	const char delim = ' ';

	tokenize(this->buffer, delim, this->parameters); //this splits the buffer into a vector
	this->server = &serv;
	std::cout << "calling command ... ";
	cmap.find(*this->parameters.begin())->second(*this, *this->server, this->parameters);
	/* Uncomment this for displaying all the vector content
	std::vector<std::string>::iterator it = out.begin();
	std::vector<std::string>::iterator ite = out.end();
	for (std::vector<std::string>::iterator i = it; i != ite; i++)
		std::cout << *i << std::endl;
	*/
}

