//
// Created by antoine on 04/07/22.
//

#include "../../includes/User.hpp"
#include "../../includes/Server.hpp"
#include "../../includes/Command.hpp"

using namespace irc;

/********************* CHANNEL COMMAND **********************/

/*
 * PART
 * parameters: <channel> *( "," <channel> ) [ <Part Message> ]
 */

void	part_cmd(Command * cmd)
{
	(void)cmd;
	std::cout << "part command called" << std::endl;
}
