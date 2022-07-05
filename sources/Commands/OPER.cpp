//
// Created by antoine on 04/07/22.
//


#include "../../includes/User.hpp"
#include "../../includes/Server.hpp"

using namespace irc;

/********************* OPERATOR COMMAND **********************/

/*
 * OPER
 * A normal user uses the OPER command to obtain operator privileges.
 * The combination of name and password are required to gain operator privileges.
 *  ERR_NEEDMOREPARAMS  RPL_YOUREOPER ERR_NOOPERHOST   ERR_PASSWDMISMATCH
 */

void	oper_cmd(User & user, Server & server, std::vector<std::string> & buffer)
{
	std::cout << "oper command called" << std::endl;
}