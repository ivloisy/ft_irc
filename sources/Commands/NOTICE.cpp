//
// Created by antoine on 04/07/22.
//

#include "../../includes/User.hpp"
#include "../../includes/Server.hpp"
#include "../../includes/Command.hpp"

using namespace irc;

/*********************** SEND MESSAGES ********************/

void	notice_cmd(Command * cmd)
{
	std::cout << "notice command called" << std::endl;
}