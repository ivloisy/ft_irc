//
// Created by alangloi on 6/23/22.
//


#include "../includes/Command.hpp"
#include "../includes/Server.hpp"
#include "../includes/User.hpp"

using namespace irc;

std::string RPL_WELCOME(std::string servername, std::string nickname)
{
	return (":" + servername + " 001 " + nickname + " :Welcome to the Internet Relay Network" + nickname);
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

//--------------------------

/*
Command::Command(User *user, Server *server, std::string message) :
	user(user),
	server(server),
	query(message)
{
	;
}
*/

//User			Command::getUser()
//{
//	return (user);
//}

//Server			Command::getServer()
//{
//	return (server);
//}

void				Command::reply(Server & serv, User &user, unsigned short code, std::string nickname)
{
	// std::stringstream sscode;
	// sscode << code;
	// std::string scode = sscode.str();
	// while (scode.length() < 3)
	// 	scode = "0" + scode;

	user.send_buf(serv, get_reply(code, serv.getServerName(), nickname));
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
