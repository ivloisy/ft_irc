//
// Created by alangloi on 6/24/22.
//

#include "../../includes/Command.hpp"
#include "../../includes/User.hpp"
#include "../../includes/Server.hpp"
#include <list>
#include "../../includes/Command.hpp"

using namespace irc;

//optional connection command

/********************* USER COMMAND **********************/

//void	Command::nick_cmd(std::string &buf, std::list<User>::iterator it_user, Server & serv)
//{
//	std::cout << "nick command called" << std::endl;
//}

/* Gives a nickname to given user or change the existing one:
 * Erreurs:
 *	ERR_NONICKNAMEGIVEN ERR_ERRONEUSNICKNAME  ERR_NICKNAMEINUSE    ERR_NICKCOLLISION ERR_RESTRICTED ERR_UNAVAILRESOURCE
 */

void	nick_cmd(Command * cmd)
{
	// user.setNickName(*(buffer.begin() + 1));
	(void)cmd;
	std::cout << "nick command called" << std::endl;
}
