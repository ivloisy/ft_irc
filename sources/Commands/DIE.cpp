//
// Created by antoine on 05/07/22.
//

#include "../../includes/User.hpp"
#include "../../includes/Server.hpp"
#include "../../includes/Command.hpp"

using namespace irc;

/******************** OPERATOR COMMAND ***********************/

void	die_cmd()
{
	// cmd->getServer().setState(0);
	std::cout << "die command called" << std::endl;
}
