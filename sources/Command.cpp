//
// Created by antoine on 01/07/22.
//

#include "../includes/Command.hpp"
#include <list>
#include "../includes/Server.hpp"

//void	Command::pong_cmd(std::string &buf, std::list<User>::iterator it_user, Server & serv);
//void	Command::cap_cmd(std::string &buf, std::list<User>::iterator it_user, Server & serv);
//void	Command::user_cmd(std::string &buf, std::list<User>::iterator it_user, Server & serv);
//void	Command::nick_cmd(std::string &buf, std::list<User>::iterator it_user, Server & serv);

//void	pong_cmd();
//void	cap_cmd();
//void	user_cmd();
//void	nick_cmd();

using namespace irc;

std::string RPL_WELCOME(std::string servername, std::string nickname)
{
	return (":" + servername + " 001 " + ":" + nickname + " Welcome to the Internet Relay Network " + nickname);
}

std::string RPL_YOURHOST(std::string servername, std::string nickname)
{
	std::string ver("1.0");
	return (":" + servername + " 002 " + nickname + " :Your host is " + servername + ", running version " + ver);
}

std::string RPL_CREATED(std::string servername, std::string nickname)
{
	std::string date("today");
	return (":" + servername + " 003 " + nickname + " :This server was created " + date);
}

std::string RPL_MYINFO(std::string servername, std::string nickname)
{
	std::string version("1.0");
	return (":" + servername + " 004 " + nickname + " " + servername + " " + version);// + " " + umodes + " " + cmodes);
}

Command::Command(Server * serv, User * user, std::vector<std::string> & params) :
	server(serv),
	user(user),
	parameters(params)
{
	return ;
}

Command::~Command()
{
	return ;
}

//--------------------------

void				Command::reply(Server & serv, User &usr, unsigned short code, std::string nickname)
{
	// std::stringstream sscode;
	// sscode << code;
	// std::string scode = sscode.str();
	// while (scode.length() < 3)
	// 	scode = "0" + scode;
	//std::cout << " reply //";
	usr.send_buf(serv, get_reply(code, serv.getServerName(), nickname));
}

/*
void Command::reply(unsigned short code, std::string arg1, std::string arg2, std::string arg3, std::string arg4, std::string arg5, std::string arg6, std::string arg7)
{
	reply(*user, code, arg1, arg2, arg3, arg4, arg5, arg6, arg7);
}
*/

std::string			Command::get_reply(unsigned short code, std::string servername, std::string nickname) {
	//std::string target;
	//if (user->getStatus() == PASSWORD || user->getStatus() == REGISTER)
	//	target = "*";
	//else
	//	target = user->getNickname();
	//target += " ";

	switch (code) {
		case 001:
			return (RPL_WELCOME(servername, nickname));
		case 002:
			return (RPL_YOURHOST(servername, nickname));
		case 003:
			return (RPL_CREATED(servername, nickname));
		case 004:
			return (RPL_MYINFO(servername, nickname));
		default:
			return std::string();
	}
}

Server									&Command::getServer()
{
	return (*this->server);
}

User									&Command::getUser()
{
	return (*this->user);
}

std::vector<std::string>				Command::getParameters()
{
	return (this->parameters);
}

void									Command::print_parameters()
{
	for (std::vector<std::string>::iterator it = this->parameters.begin(); it != this->parameters.end(); it++)
		std::cout << *it << std::endl;
}
