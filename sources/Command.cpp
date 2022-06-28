//
// Created by alangloi on 6/23/22.
//

#include "../includes/Command.hpp"
#include "../includes/Server.hpp"
#include "../includes/User.hpp"

std::string RPL_WELCOME(std::string prefix)
{
	return (":Welcome to the Internet Relay Network" + prefix);
}

std::string RPL_YOURHOST(std::string servername, std::string ver)
{
	return (":Your host is " + servername + ", running version " + ver);
}

std::string RPL_CREATED(std::string date)
{
	return (":This server was created " + date);
}

std::string RPL_MYINFO(std::string servername, std::string version, std::string umodes, std::string cmodes)
{
	return (servername + " " + version + " " + umodes + " " + cmodes);
}

irc::Command::Command(User *user, Server *server, std::string message) :
	user(user),
	server(server),
	query(message)
{
	;
}

irc::User &irc::Command::getUser()
{
	return (*user);
}

irc::Server &irc::Command::getServer()
{
	return (*server);
}

void irc::Command::reply(User &user, unsigned short code, std::string arg1, std::string arg2, std::string arg3, std::string arg4, std::string arg5, std::string arg6, std::string arg7)
{
	std::stringstream sscode;
	sscode << code;
	std::string scode = sscode.str();
	while (scode.length() < 3)
		scode = "0" + scode;

	user.send_buf(user, scode + " " + get_reply(code, arg1, arg2, arg3, arg4, arg5, arg6, arg7));
}


void irc::Command::reply(unsigned short code, std::string arg1, std::string arg2, std::string arg3, std::string arg4, std::string arg5, std::string arg6, std::string arg7)
{
	reply(*user, code, arg1, arg2, arg3, arg4, arg5, arg6, arg7);
}

std::string	irc::Command::get_reply(unsigned short code, std::string arg1, std::string arg2, std::string arg3, std::string arg4, std::string arg5, std::string arg6, std::string arg7)
{
	std::string target = "salut";

	switch (code)
	{
		case 001:
			reply(code, arg1);
			//return (target + RPL_WELCOME(arg1));
		case 002:
			reply(code, arg1, arg2);
			//return (target + RPL_YOURHOST(arg1, arg2));
		case 003:
			reply(code, arg1);
			//return (target + RPL_CREATED(arg1));
		case 004:
			reply(code, arg1, arg2, arg3, arg4);
			//return (target + RPL_MYINFO(arg1, arg2, arg3, arg4));
		default:
			return (std::string());
	}
}

