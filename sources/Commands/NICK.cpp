//
// Created by alangloi on 6/24/22.
//

#include "../../includes/Command.hpp"
#include "../../includes/User.hpp"
#include "../../includes/Server.hpp"
#include <list>
#include "../../includes/Command.hpp"

using namespace irc;
using namespace std;

/********************* USER COMMAND **********************/

/* Gives a nickname to given user or change the existing one:
 * Erreurs:
 *	ERR_NONICKNAMEGIVEN ERR_ERRONEUSNICKNAME  ERR_NICKNAMEINUSE    ERR_NICKCOLLISION ERR_RESTRICTED ERR_UNAVAILRESOURCE
 */

void	nick_cmd(Server * srv, User * usr, std::vector<std::string> params)
{
	// user.setNickName(*(buffer.begin() + 1));
	(void)srv;
	(void)usr;
	(void)params;
	std::cout << "nick command called" << std::endl;
}
