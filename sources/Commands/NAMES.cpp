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

string		add_nick(vector<User *> & users)
{
	string	ret;

	for (size_t i = 0; i < users.size(); i++)
	{
		if (!users[i]->getInvisible())
		{
			ret += users[i]->getNickName();
			if (i + 1 != users.size())
				ret += ", ";
		}
	}
	return ret;
}

void		names_cmd(Server & srv, User & usr, vector<string> params)
{
	(void)usr;

	vector<User *>	users;
	string			ret = "\n";

	if (!srv.check_command(&usr, 1, params))
		return ;
	if (params.size() == 1)
	{
		users = srv.getUsers();
		ret += srv.getServerName() + " = { ";
		ret += add_nick(users);
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
			users.clear();
			schan += s + " ";
			Channel * test = srv.getChannelByName(s);
			if (test != NULL)
				users = test->getChannelUsers();
			ret += s + " = { ";
			ret += add_nick(users);
			ret += " }";
			srv.ft_reply(&usr, RPL_NAMREPLY, s, ret);
			cout << "////// i = " << i << endl;
			i++;
		}
		srv.ft_reply(&usr, RPL_ENDOFNAMES, schan);
	}
	std::cout << "names command called" << std::endl;
}
