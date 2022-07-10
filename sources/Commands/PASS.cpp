//
// Created by antoine on 04/07/22.
//

#include "../../includes/ft_irc.hpp"

using namespace irc;
using namespace std;

/********************* USER COMMAND **********************/

/*
 * Command: PASS
 * Parameters: <password>
 * Create a password variable (std::string)
 * Erreurs : ERR_NEEDMOREPARAMS ERR_ALREADYREGISTERED
 */

void	pass_cmd(Server & srv, User & usr, std::vector<std::string> params)
{
	cout << params[1] << " : " << srv.getPassword() << endl;
	if (params[1] != srv.getPassword())
	{
		// vector<User *> users = srv.getUsers();
		// for (vector<User *>::iterator it = users.begin(); it != users.end(); it++)
		// 	if ((*it)->getFdUser() == usr.getFdUser())
		// 		srv.deleteUser(it);
		usr.setToClose(1);
		string buf = "ERROR: Closing link: (ben@127.0.0.1) [wrong password]";
		srv.sending(usr.getFdUser(), buf);

		// delete(&usr);
	}
	//std::cout << "pass command called" << std::endl;
}
