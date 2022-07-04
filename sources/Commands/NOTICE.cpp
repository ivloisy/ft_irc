//
// Created by antoine on 04/07/22.
//

#include "../../includes/User.hpp"
#include "../../includes/Server.hpp"

using namespace irc;

/*********************** SEND MESSAGES ********************/

void	notice_cmd(User & user, Server & server, std::vector<std::string> & buffer)
{
	std::cout << "notice command called" << std::endl;
}