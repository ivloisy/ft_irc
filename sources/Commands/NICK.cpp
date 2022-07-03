//
// Created by alangloi on 6/24/22.
//

#include "../../includes/Command.hpp"
#include "../../includes/User.hpp"
#include "../../includes/Server.hpp"
#include <list>

void	nick_cmd(std::string &buf, std::list<User>::iterator it_user, Server & serv)
{
	std::cout << "nick command called" << std::endl;
}