//
// Created by antoine on 05/07/22.
//

#include "../../includes/ft_irc.hpp"

using namespace irc;
using namespace std;

//DONT DO THIS COMMAND

/*********************** OPERATOR COMMAND ************************/

void	invite_cmd(Server & srv, User & usr, vector<string> params)
{
	//cout << "invite fonction called" << endl;
	if (!srv.check_command(&usr, 1, params) || !(usr.isOperator()))
		return ;
	if (srv.getUser(params[1]) == srv.getUsers().end())
	{
		srv.ft_error(&usr, ERR_NOSUCHNICK, params[1]);
		return;
	}
	User * user = *srv.getUser(params[1]);
	Channel * chan = srv.getChannelByName(params[2]);
	if (chan->getUser(user->getNickName()))
	{
		srv.ft_error(&usr, ERR_USERONCHANNEL, user->getNickName());
		return ;
	}
	vector<string> newParams;
	newParams.push_back(string("JOIN"));
	size_t x = 2;
	while (x < params.size())
	{
		if (srv.getChannelByName(params[x]) == *srv.getChannels().end())
		{
			srv.ft_error(&usr, ERR_NOSUCHCHANNEL, params[x]);
			return;
		}
		newParams.push_back(params[x]);
		x++;
	}

	//cout << "params size = " << newParams.size() << endl;
	join_cmd(srv, *user, newParams);
	//cout << "invite command exit" << cout;
}
