//
// Created by antoine on 05/07/22.
//

#include "../../includes/ft_irc.hpp"

using namespace irc;
using namespace std;

/******************** OPERATOR COMMAND ***********************/

void	die_cmd(Server & srv, User & usr, std::vector<std::string> params)
{
	(void)usr;
	(void)params;
	srv.setState(0);
	//quitter proprement (kick all users)
	std::cout << "die command called" << std::endl;
}
