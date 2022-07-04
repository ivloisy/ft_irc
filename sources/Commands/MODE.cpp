//
// Created by antoine on 04/07/22.
//

#include "../../includes/User.hpp"
#include "../../includes/Server.hpp"

using namespace irc;

/********************* USER COMMAND **********************/

/*
 * MODE
 * parameters <nickname> *( ( "+" / "-" ) *( "i" / "w" / "o" / "O" / "r" ) )
 */

void	mode_cmd(User & user, Server & server, std::vector<std::string> & buffer)
{
	std::cout << "mode command called" << std::endl;
}