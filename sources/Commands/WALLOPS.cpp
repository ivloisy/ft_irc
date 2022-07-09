//
// Created by antoine on 05/07/22.
//

#include "../../includes/ft_irc.hpp"

using namespace irc;
using namespace std;

//DONT DO THIS COMMAND

/*********************** OPERATOR COMMAND ************************/

void	wallops_cmd(Server & srv, User & usr, std::vector<std::string> params)
{
	(void)srv;
	(void)usr;
	(void)params;
	std::cout << "wallops command called" << std::cout;
}
