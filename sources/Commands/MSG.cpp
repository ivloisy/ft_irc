//
// Created by antoine on 04/07/22.
//

#include "../../includes/User.hpp"
#include "../../includes/Server.hpp"
#include "../../includes/Command.hpp"

//do not use this command

using namespace irc;

void msg_cmd(Command * cmd)
{
	(void)cmd;
	std::cout << "msg command called" << std::endl;
}