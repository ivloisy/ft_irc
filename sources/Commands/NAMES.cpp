//
// Created by antoine on 04/07/22.
//

#include "../../includes/ft_irc.hpp"

using namespace irc;
using namespace std;

/********************* CHANNEL COMMAND **********************/

//not mandatory but usefull for bebugging

/*
 * NAMES
 * parameters: [ <channel> *( "," <channel> ) [ <target> ] ]
 */

void		names_cmd(Server & srv, User & usr, std::vector<std::string> params)
{
	(void)srv;
	(void)usr;
	(void)params;
	std::cout << "names command called" << std::endl;
}
