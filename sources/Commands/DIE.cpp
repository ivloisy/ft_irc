//
// Created by antoine on 05/07/22.
//

#include "../../includes/User.hpp"
#include "../../includes/Server.hpp"
#include "../../includes/Command.hpp"

using namespace irc;

/******************** OPERATOR COMMAND ***********************/

void	die_cmd(Server * srv, User * usr, std::vector<std::string> params)
{
	(void)srv;
	(void)usr;
	(void)params;
	//cmd->getServer().setState(0);
	std::cout << "die command called" << std::endl;
}