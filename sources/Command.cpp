//
// Created by antoine on 01/07/22.
//

#include "../includes/Command.hpp"
#include <list>
#include "../includes/Server.hpp"

//void	Command::pong_cmd(string &buf, list<User>::iterator it_user, Server & serv);
//void	Command::cap_cmd(string &buf, list<User>::iterator it_user, Server & serv);
//void	Command::user_cmd(string &buf, list<User>::iterator it_user, Server & serv);
//void	Command::nick_cmd(string &buf, list<User>::iterator it_user, Server & serv);

//void	pong_cmd();
//void	cap_cmd();
//void	user_cmd();
//void	nick_cmd();

using namespace irc;
using namespace std;

string 				RPL_WELCOME(string servername, string nickname)
{
	return (":" + servername + " 001 " + ":" + nickname + " Welcome to the Internet Relay Network " + nickname);
}

string 				RPL_YOURHOST(string servername, string nickname)
{
	string ver("1.0");
	return (":" + servername + " 002 " + nickname + " :Your host is " + servername + ", running version " + ver);
}

string 				RPL_CREATED(string servername, string nickname)
{
	string date("today");
	return (":" + servername + " 003 " + nickname + " :This server was created " + date);
}

string 				RPL_MYINFO(string servername, string nickname)
{
	string version("1.0");
	return (":" + servername + " 004 " + nickname + " " + servername + " " + version);// + " " + umodes + " " + cmodes);
}

Command::Command(Server * serv, User * user, vector<string> & params) :
	user(user),
	server(serv),
	parameters(params)
{
	return ;
}

Command::~Command()
{
	return ;
}

//--------------------------
//
// void						Command::reply(Server & serv, User &usr, unsigned short code, string nickname)
// {
// 	usr.send_buf(serv, get_reply(code, serv.getServerName(), nickname));
// }

/*
void Command::reply(unsigned short code, string arg1, string arg2, string arg3, string arg4, string arg5, string arg6, string arg7)
{
	reply(*user, code, arg1, arg2, arg3, arg4, arg5, arg6, arg7);
}
*/

string					Command::get_reply(unsigned short code, string servername, string nickname)
{
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
			return string();
	}
}

Server						&Command::getServer()
{
	return (*this->server);
}

User						&Command::getUser()
{
	return (*this->user);
}

vector<string>	Command::getParameters()
{
	return (this->parameters);
}

void						Command::print_parameters()
{
	int i = 0;
	for (vector<string>::iterator it = this->parameters.begin(); it != this->parameters.end(); it++)
	{
		cout << "param " << i << " : " << *it << endl;
		i++;
	}
}
