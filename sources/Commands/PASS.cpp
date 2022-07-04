//
// Created by antoine on 04/07/22.
//

#include "../../includes/User.hpp"
#include "../../includes/Server.hpp"

using namespace irc;

//optionnal for the moment, dont use

/********************* USER COMMAND **********************/

/*
 * Command: PASS
 * Parameters: <password>
 * Create a password variable (std::string)
 * Erreurs : ERR_NEEDMOREPARAMS ERR_ALREADYREGISTERED
 */

void	pass_cmd(User & user, Server & server, std::vector<std::string> & buffer)
{
	std::cout << "pass command called" << std::endl;
}