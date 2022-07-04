//
// Created by alangloi on 6/24/22.
//

#include "../../includes/Command.hpp"
#include "../../includes/User.hpp"
#include "../../includes/Server.hpp"
#include <list>

//void	Command::user_cmd(std::string &buf, std::list<User>::iterator it_user, Server & serv)
//{
//	std::cout << "user command called" << std::endl;
//}

void	user_cmd()
{

	std::cout << "user command called" << std::endl;
}

/*
 * Command: 	USER
 * Parameters:	<user> <mode> <unused> <realname>
 * The USER command is used at the beginning of connection to specify
 * the username, hostname and realname of a new user.
 * The <mode> parameter
 */