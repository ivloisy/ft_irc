//
// Created by antoine on 04/07/22.
//

#include "../../includes/User.hpp"
#include "../../includes/Server.hpp"
#include "../../includes/Command.hpp"

using namespace irc;

/********************* CHANNEL COMMAND **********************/

//not mandatory but usefull for debugging

/*
 * LIST
 * parameters : [ <channel> *( "," <channel> ) [ <target> ] ]
 */

void		list_cmd(Command * cmd)
{
	(void)cmd;
	std::cout << "list command called " << std::endl;
}