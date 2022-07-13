//
// Created by antoine on 05/07/22.
//

#include "../../includes/ft_irc.hpp"

using namespace irc;
using namespace std;

//DONT DO THIS COMMAND

/*********************** OPERATOR COMMAND ************************/

void	wallops_cmd(Server & srv, User & usr, std::vector<std::string> params)
{
	(void)srv;
	(void)usr;
	(void)params;
	if (!srv.check_command(&usr, 1, params) || (usr.isOperator()))
		return ;
	cout << params[0] << endl;
	params[0].replace("NOTICE");
	cout << params[0] << endl;
	vector<User *> users = srv.getUsers();
	for (vector<User *>::iterator it = users.begin(); it != users.end(); it++)
	{
		notice_cmd(srv, *it, params);
	}
	//std::cout << "wallops command called" << std::cout;
}
