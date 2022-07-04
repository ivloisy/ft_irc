//
// Created by antoine on 04/07/22.
//

#include "../../includes/User.hpp"
#include "../../includes/Server.hpp"

//do not use this command

using namespace irc;

void msg_cmd(User & user, Server & server, std::vector<std::string> & buffer)
{
	std::cout << "msg command called" << std::endl;
}