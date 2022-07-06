//
// Created by antoine on 05/07/22.
//

#include "../../includes/User.hpp"
#include "../../includes/Server.hpp"
#include "../../includes/Command.hpp"

using namespace irc;

/*********************** OPERATOR COMMAND ************************/

void	wallops_cmd(Command * cmd)
{
	(void)cmd;
	std::cout << "wallops command called" << std::cout;
}