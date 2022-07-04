//
// Created by antoine on 04/07/22.
//

#include "../../includes/User.hpp"
#include "../../includes/Server.hpp"

using namespace irc;

/********************* USER COMMAND **********************/

/*
 * QUIT
 * Parameters <quit message>
 */

void	quit_cmd(User & user, Server & server, std::vector<std::string> & buffer)
{
	std::cout << "quit command called" << std::endl;
}