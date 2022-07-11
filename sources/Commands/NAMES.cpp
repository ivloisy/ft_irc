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

	for (size_t i = 0; i < user.size(); i++)
	{
		if (!user[i]->getInvisible())
		{
			ret += user[i]->getNickName();
			if (i + 1 != user.size())
				ret += ", ";
		}
	}
	return ret;
}

void		names_cmd(Server & srv, User & usr, std::vector<std::string> params)
{
	// (void)srv;
	(void)usr;
	// (void)params;
	vector<User *>	user;
	string			schan = "";
	stringstream	ss(params[1]);
	string			s;
	string			ret = "\n";
	if (params.size() == 1)
	{
		user = srv.getUsers();
		ret += srv.getServerName() + " = { ";
		ret += add_nick(user);
		ret += " }";
		srv.ft_reply(&usr, RPL_NAMREPLY, s, ret);
		srv.ft_reply(&usr, RPL_ENDOFNAMES, srv.getServerName());
	}
	else if (params.size() == 2)
	{
		while (getline(ss, s, ','))
		{
			// bzero(ret, ret.length());
			user.clear();
			schan += s + " ";
			user = srv.getChannelByName(s)->getChannelUsers();
			ret += s + " = { ";
			ret += add_nick(user);
			// for (int i = 0; i < user.size(); i++)
			// {
			// 	if (!user[i].getInvisible())
			// 		ret += user[i].getNickName();
			// 		if (i != user.size() - 1)
			// 			ret += ", ";
			// }
			ret += " }";
			srv.ft_reply(&usr, RPL_NAMREPLY, s, ret);
		}
		srv.ft_reply(&usr, RPL_ENDOFNAMES, schan);
	}
	std::cout << "names command called" << std::endl;
}
