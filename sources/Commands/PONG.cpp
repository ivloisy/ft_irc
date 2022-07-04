//
// Created by alangloi on 6/24/22.
//

/********************* USER COMMAND **********************/

#include "../../includes/Command.hpp"
#include "../../includes/User.hpp"
#include "../../includes/Server.hpp"
#include <list>

using namespace irc;

//void	Command::pong_cmd(std::string &buf, std::list<User>::iterator it_user, Server & serv)
//{
//	std::cout << "pong command called" << std::endl;
//}

void	pong_cmd(User & user, Server & server, std::vector<std::string> & buffer)
{
	std::cout << "pong command called" << std::endl;
}