//
// Created by antoine on 04/07/22.
//

#include "../../includes/ft_irc.hpp"

using namespace irc;
using namespace std;

/********************* USER COMMAND **********************/

/*
 * QUIT
 * Parameters <quit message>
 */

void	quit_cmd(Server & srv, User & usr, std::vector<std::string> params)
{
	(void)srv;
	(void)usr;
	(void)params;
	// vector<User *> users = srv.getUsers();
	// for (vector<User *>::iterator it = users.begin(); it != users.end(); it++)
	// 	if ((*it)->getFdUser() == usr.getFdUser())
	// 		srv.deleteUser(it);
	usr.setToClose(1);
	std::cout << "quit command called" << std::endl;
}
