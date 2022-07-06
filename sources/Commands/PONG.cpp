//
// Created by alangloi on 6/24/22.
//

/********************* USER COMMAND **********************/

#include "../../includes/Command.hpp"
#include "../../includes/User.hpp"
#include "../../includes/Server.hpp"
#include <list>
#include "../../includes/Command.hpp"

using namespace irc;

void	pong_cmd(Command * cmd)
{
	(void)cmd;
	std::cout << "pong command called" << std::endl;
}
