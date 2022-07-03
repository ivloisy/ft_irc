//
// Created by antoine on 01/07/22.
//

#ifndef FT_IRC_COMMAND_HPP
#define FT_IRC_COMMAND_HPP

#include "User.hpp"


using namespace irc;

class Command
{
public:
	Command();
	virtual ~Command();

	void	pong_cmd(std::string &buf, std::list<User>::iterator it_user, Server & serv);
	void	cap_cmd(std::string &buf, std::list<User>::iterator it_user, Server & serv);
	void	user_cmd(std::string &buf, std::list<User>::iterator it_user, Server & serv);
	void	nick_cmd(std::string &buf, std::list<User>::iterator it_user, Server & serv);
};


#endif //FT_IRC_COMMAND_HPP
