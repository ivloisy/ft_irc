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
	(void)srv;
	(void)usr;
	(void)params;
	if (!srv.check_command(&usr, 1, params) || (usr.isOperator()))
		return ;
	if (srv.getUser(params[1]) == srv.getUsers().end())
	{
		srv.ft_error(&usr, ERR_NOSUCHNICK, params[1]);
		return;
	}
	vector<string> newParams;
	newParams.push_back(string("JOIN"));
	size_t x = 2;
	while (x < params.size() - 1)
	{
		if (srv.getChannelByName(params[x]) == srv.getChannels().end())
		{
			srv.ft_error(&usr, ERR_NOSUCHCHANNEL, params[x]);
			return;
		}
		newParams.push_back(params[x]);
	}
	join_cmd(srv, srv.getUser(params[1]), newParams);
	cout << "wallops command called" << cout;
}
