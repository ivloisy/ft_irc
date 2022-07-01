//
// Created by antoine on 01/07/22.
//

#include "../includes/Command.hpp"
#include <list>
#include "../includes/Server.hpp"

Command::Command() {

}

Command::~Command() {

}

void	pong_cmd(std::string &buf, std::list<User>::iterator it_user, Server & serv);
void	cap_cmd(std::string &buf, std::list<User>::iterator it_user, Server & serv)
{
	std::cout << "cap command called" << std::endl;
}
void	user_cmd(std::string &buf, std::list<User>::iterator it_user, Server & serv);
void	nick_cmd(std::string &buf, std::list<User>::iterator it_user, Server & serv);