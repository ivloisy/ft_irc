//
// Created by antoine on 04/07/22.
//


#include "../../includes/User.hpp"
#include "../../includes/Server.hpp"

using namespace irc;

/********************* CHANNEL COMMAND **********************/

/*
 * JOIN command
 * ( <channel> *( "," <channel> ) [ <key> *( "," <key> ) ] )
               / "0"
 */

void	join_cmd(User & user, Server & server, std::vector<std::string> & buffer)
{
	std::cout << "join command called" << std::endl;
}