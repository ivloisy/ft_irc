//
// Created by antoine on 05/07/22.
//

#include "../../includes/User.hpp"
#include "../../includes/Server.hpp"
#include "../../includes/Command.hpp"

using namespace irc;
using namespace std;

/******************** OPERATOR COMMAND ***********************/

void	die_cmd(Server * srv, User * usr, std::vector<std::string> params)
{
	(void)usr;
	(void)params;
	srv->setState(0);
	std::cout << "die command called" << std::endl;
}
