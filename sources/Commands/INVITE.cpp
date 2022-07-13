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
	User * user = *srv.getUser(params[1]);
	//cout << "params size = " << newParams.size() << endl;
	join_cmd(srv, *user, newParams);
	//cout << "invite command exit" << cout;
}
