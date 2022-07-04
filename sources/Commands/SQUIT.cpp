//
// Created by antoine on 04/07/22.
//

#include "../../includes/User.hpp"
#include "../../includes/Server.hpp"

using namespace irc;

/********************* OPERATOR COMMAND **********************/

/*
 * Operator command for disonnecting the server
 * parameters <server> <comment>
 */

void squit_cmd(User & user, Server & server, std::vector<std::string> & buffer)
{
	std::cout << "squit command called" << std::endl;
}