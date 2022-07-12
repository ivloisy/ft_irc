//
// Created by antoine on 04/07/22.
//

#include "../../includes/ft_irc.hpp"

using namespace irc;
using namespace std;

/********************* CHANNEL COMMAND **********************/

//not mandatory but usefull for bebugging

/*
 * NAMES
 * parameters: [ <channel> *( "," <channel> ) [ <target> ] ]
 */

string		add_nick(vector<User *> & user)
{
	string	ret;

	cout << "add begin" << endl;

	for (size_t i = 0; i < user.size(); i++)
	{
		if (!user[i]->getInvisible())
		{
			ret += user[i]->getNickName();
			if (i + 1 != user.size())
				ret += ", ";
		}
	}
	cout << "add end" << endl;
	return ret;
}

void		names_cmd(Server & srv, User & usr, std::vector<std::string> params)
{
	// (void)srv;
	(void)usr;
	// (void)params;
	vector<User *>	user;
	string			ret = "\n";
	if (!usr.getWelcome())
		return ;
	if (params.size() == 1)
	{
		user = srv.getUsers();
		ret += srv.getServerName() + " = { ";
		ret += add_nick(user);
		ret += " }";
		srv.ft_reply(&usr, RPL_NAMREPLY, srv.getServerName(), ret);
		srv.ft_reply(&usr, RPL_ENDOFNAMES, srv.getServerName());
	}
	else if (params.size() == 2)
	{
		stringstream	ss(params[1]);
		string			s;
		string			schan = "";
		int i = 0;
		while (getline(ss, s, ','))
		{
			// bzero(ret, ret.length());
			user.clear();
			schan += s + " ";
			if (srv.getChannelByName(s))
				user = srv.getChannelByName(s)->getChannelUsers();
			ret += s + " = { ";
			cout << "add_nick = " << add_nick(user) << endl;
			// ret += (*user.begin())->getNickName();//add_nick(user);
			// for (int i = 0; i < user.size(); i++)
			// {
			// 	if (!user[i].getInvisible())
			// 		ret += user[i].getNickName();
			// 		if (i != user.size() - 1)
			// 			ret += ", ";
			// }
			ret += " }";
			srv.ft_reply(&usr, RPL_NAMREPLY, s, ret);
			cout << "////// i = " << i << endl;
			i++;
		}
		srv.ft_reply(&usr, RPL_ENDOFNAMES, schan);
	}
	std::cout << "names command called" << std::endl;
}
