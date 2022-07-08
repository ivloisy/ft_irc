//
// Created by alangloi on 6/24/22.
//

#include "../../includes/ft_irc.hpp"

using namespace irc;
using namespace std;

/********************* USER COMMAND **********************/

void	user_cmd(Server * srv, User * usr, std::vector<std::string> params)
{
	(void)srv;
	if (params.size() < 4)
	{
		//ERR_NEEDMOREPARAMS
		return ;
	}
	usr->setUserName(params[1]);
	usr->setHostName(params[2]);
	usr->setServerName(params[3]);

	usr->setPrefix();
	std::cout << "user command called" << std::endl;
}

/*
 * Command: 	USER
 * Parameters:	<user> <mode> <unused> <realname>
 * The USER command is used at the beginning of connection to specify
 * the username, hostname and realname of a new user.
 *  ERR_NEEDMOREPARAMS      ERR_ALREADYREGISTRED
 */
