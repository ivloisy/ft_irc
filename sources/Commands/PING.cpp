//
// Created by antoine on 04/07/22.
//

#include "../../includes/ft_irc.hpp"

using namespace irc;
using namespace std;

void	ping_cmd(Server & srv, User & usr, std::vector<std::string> params)
{
	(void)srv;
	(void)params;
	srv.sending(usr.getFdUser(), "PONG\r\n");
	std::cout << "ping command called" << std::endl;
}
