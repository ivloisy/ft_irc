//
// Created by antoine on 04/07/22.
//

#include "../../includes/User.hpp"
#include "../../includes/Server.hpp"

using namespace irc;

/********************* CHANNEL COMMAND **********************/

/*
 * PART
 * parameters: <channel> *( "," <channel> ) [ <Part Message> ]
 */

void	part_cmd(User & user, Server & server, std::vector<std::string> & buffer)
{
	std::cout << "part command called" << std::endl;
}