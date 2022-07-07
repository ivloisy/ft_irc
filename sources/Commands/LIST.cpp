//
// Created by antoine on 04/07/22.
//

#include "../../includes/User.hpp"
#include "../../includes/Server.hpp"
#include "../../includes/Command.hpp"

using namespace irc;
using namespace std;

/********************* CHANNEL COMMAND **********************/

//not mandatory but usefull for debugging

/*
 * LIST
 * parameters : [ <channel> *( "," <channel> ) [ <target> ] ]
 */

void		list_cmd(Server * srv, User * usr, std::vector<std::string> params)
{
	(void)srv;
	(void)usr;
	(void)params;
	std::cout << "list command called " << std::endl;
}
