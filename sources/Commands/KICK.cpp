//
// Created by alangloi on 6/24/22.
//

#include "../../includes/ft_irc.hpp"

using namespace irc;
using namespace std;

/********************* USER COMMAND **********************/

/* Gives a nickname to given user or change the existing one:
 * Erreurs:
 *	ERR_NONICKNAMEGIVEN ERR_ERRONEUSNICKNAME  ERR_NICKNAMEINUSE    ERR_NICKCOLLISION ERR_RESTRICTED ERR_UNAVAILRESOURCE
 */

void	kick_cmd(Server & srv, User & usr, vector<string> params)
{
	(void)srv;
	(void)usr;
	(void)params;
	if (!srv.check_command(&usr, 3, params))
		return ;
	cout << "command kick called" << endl;
}
