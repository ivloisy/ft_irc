//
// Created by antoine on 05/07/22.
//

#include "../../includes/User.hpp"
#include "../../includes/Server.hpp"

using namespace irc;

/****************** OPERATOR COMMAND **********************/

void	restart_cmd(User & user, Server & server, std::vector<std::string> & buffer)
{
	std::cout << "restart command called" << std::endl;
}