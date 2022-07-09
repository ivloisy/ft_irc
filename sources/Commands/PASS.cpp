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
	// user.setPassWord(*(buffer.begin() + 1));
	// (void)srv;
	// (void)usr;
	// (void)params;
	// string passw = srv.getPassword();
	if (params.size() != 1)
		cout << "===================WTF=============================" << endl;
	// string testing = params[0];
	if (params[0] != srv.getPassword())
	{
		usr.setToClose(1);
	}
	//std::cout << "pass command called" << std::endl;
}
