//
// Created by antoine on 04/07/22.
//

#include "../../includes/User.hpp"
#include "../../includes/Server.hpp"

using namespace irc;

/********************* CHANNEL COMMAND **********************/

//not mandatory but usefull for bebugging

/*
 * NAMES
 * parameters: [ <channel> *( "," <channel> ) [ <target> ] ]

 */

void		names_cmd(User & user, Server & server, std::vector<std::string> & buffer)
{
	std::cout << "names command called" << std::endl;
}