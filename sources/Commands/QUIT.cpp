//
// Created by antoine on 04/07/22.
//

#include "../../includes/ft_irc.hpp"

using namespace irc;
using namespace std;

/********************* USER COMMAND **********************/

/*
 * QUIT
 * Parameters <quit message>
 */

void	quit_cmd(Server & srv, User & usr, std::vector<std::string> params)
{
	cout << "*** Quit command called ***" << endl;
	if (!srv.check_command(&usr, 1, params))
		return ;
	usr.setToClose(1);
	//std::cout << "quit command called" << std::endl;
}
