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
	if (params.size() == 2 )
	{
		if (params[1] == srv.getPassword())
		{
			usr.setPassword(params[1]);
			return;
		}
	}
	string buf = "ERROR: Closing link: (ben@127.0.0.1) [wrong password]";
	srv.sending(usr.getFdUser(), buf);
}
