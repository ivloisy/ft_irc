//
// Created by antoine on 04/07/22.
//


#include "../../includes/User.hpp"
#include "../../includes/Server.hpp"
#include "../../includes/Command.hpp"

using namespace irc;
using namespace std;

/********************* OPERATOR COMMAND **********************/

/*
 * OPER
 * A normal user uses the OPER command to obtain operator privileges.
 * The combination of name and password are required to gain operator privileges.
 *  ERR_NEEDMOREPARAMS  RPL_YOUREOPER ERR_NOOPERHOST   ERR_PASSWDMISMATCH
 */

void	oper_cmd(Server * srv, User * usr, std::vector<std::string> params)
{
	(void)srv;
	(void)usr;
	(void)params;
	if (params.size() < 2)
	{
		//wrong number of parameters
	}
	else
	{

	}
	std::cout << "oper command called" << std::endl;
}
