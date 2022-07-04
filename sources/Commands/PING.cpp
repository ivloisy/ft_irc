//
// Created by antoine on 04/07/22.
//

#include "../../includes/User.hpp"
#include "../../includes/Server.hpp"

using namespace irc;

void	ping_cmd(User & user, Server & server, std::vector<std::string> & buffer)
{
	std::cout << "ping command called" << std::endl;
}