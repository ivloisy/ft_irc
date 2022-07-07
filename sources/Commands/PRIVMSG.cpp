//
// Created by antoine on 04/07/22.
//

#include "../../includes/User.hpp"
#include "../../includes/Server.hpp"
#include "../../includes/Command.hpp"

using namespace irc;
using namespace std;

/********* SENDING MESSAGES ************/

/*
 * PRIVMSG
 * <msgtarget> <text to be sent>
 */

void	privmsg_cmd(Server * srv, User * usr, std::vector<std::string> params)
{
	if (srv->getChannel(params[1]))
	{
		srv->sendToChan(usr->getNickName());
	}
	else if (srv->getUser(params[1]))
	{
		srv->sendToUser(params[1]);
	}
	std::cout << "privmsg command called" << std::endl;
}
