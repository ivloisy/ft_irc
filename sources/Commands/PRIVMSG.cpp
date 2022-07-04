//
// Created by antoine on 04/07/22.
//

#include "../../includes/User.hpp"
#include "../../includes/Server.hpp"

using namespace irc;

/********* SENDING MESSAGES ************/

/*
 * PRIVMSG
 * <msgtarget> <text to be sent>
 */

void	privmsg_cmd(User & user, Server & server, std::vector<std::string> & buffer)
{
	std::cout << "privmsg command called" << std::endl;
}