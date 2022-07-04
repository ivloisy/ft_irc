//
// Created by alangloi on 6/24/22.
//

#include "../../includes/User.hpp"
#include "../../includes/Server.hpp"

using namespace irc;

//optional connection command

/********************* USER COMMAND **********************/

#include "../../includes/Command.hpp"
#include "../../includes/User.hpp"
#include "../../includes/Server.hpp"
#include <list>

//void	Command::nick_cmd(std::string &buf, std::list<User>::iterator it_user, Server & serv)
//{
//	std::cout << "nick command called" << std::endl;
//}

/* Gives a nickname to given user or change the existing one:
 * Erreurs:
 *	ERR_NONICKNAMEGIVEN ERR_ERRONEUSNICKNAME  ERR_NICKNAMEINUSE    ERR_NICKCOLLISION ERR_RESTRICTED ERR_UNAVAILRESOURCE
 */

void	nick_cmd(User & user, Server & server, std::vector<std::string> & buffer)
{
	std::cout << "nick command called" << std::endl;
}