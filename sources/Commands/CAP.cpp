//
// Created by alangloi on 6/24/22.
//

#include "../../includes/User.hpp"
#include "../../includes/Server.hpp"
#include "../../includes/Command.hpp"

using namespace irc;

//optional for the moment

/********************* USER COMMAND **********************/

#include "../../includes/Command.hpp"
#include "../../includes/User.hpp"
#include "../../includes/Server.hpp"
#include <list>

//void	Command::cap_cmd(std::string &buf, std::list<User>::iterator it_user, Server & serv)
//{
//	std::cout << "cap command called" << std::endl;
//}

void	cap_cmd(Server * srv, User * usr, std::vector<std::string> params)
{
	(void)srv;
	(void)usr;
	(void)params;
	std::cout << "cap command called" << std::endl;
}
