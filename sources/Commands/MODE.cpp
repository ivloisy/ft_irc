//
// Created by antoine on 04/07/22.
//

#include "../../includes/User.hpp"
#include "../../includes/Server.hpp"
#include "../../includes/Command.hpp"

using namespace irc;
using namespace std;

/********************* USER COMMAND **********************/

/*
 * MODE
 * parameters <nickname> *( ( "+" / "-" ) *( "i" / "w" / "o" / "O" / "r" ) )
 */

void	mode_cmd(Server * srv, User * usr, std::vector<std::string> params)
{
	(void)srv;
	(void)usr;
	(void)params;
	std::cout << "mode command called" << std::endl;
}
