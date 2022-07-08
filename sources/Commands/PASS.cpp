//
// Created by antoine on 04/07/22.
//

#include "../../includes/User.hpp"
#include "../../includes/Server.hpp"
#include "../../includes/Command.hpp"

using namespace irc;
using namespace std;

//optionnal for the moment, dont use

/********************* USER COMMAND **********************/

/*
 * Command: PASS
 * Parameters: <password>
 * Create a password variable (std::string)
 * Erreurs : ERR_NEEDMOREPARAMS ERR_ALREADYREGISTERED
 */

void	pass_cmd(Server * srv, User * usr, std::vector<std::string> params)
{
	// user.setPassWord(*(buffer.begin() + 1));
	(void)srv;
	(void)usr;
	(void)params;
	passw = srv.getPassword();
	if (params.len != 1)
		cout << "===================WTF=============================" << endl;
	string testing = params[0];
	if (params[0] != serv.getPassword())
	{
		usr.setToClose(1);
	}
	std::cout << "pass command called" << std::endl;
}
