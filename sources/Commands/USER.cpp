//
// Created by alangloi on 6/24/22.
//

#include "../../includes/ft_irc.hpp"

using namespace irc;
using namespace std;

/********************* USER COMMAND **********************/

void	user_cmd(Server & srv, User & usr, std::vector<std::string> params)
{
	if (params.size() < 5)
	{
		string buf;
		buf = ft_reply(srv.getServerName(), ERR_NEEDMOREPARAMS, usr.getNickName(), params[0] + " :Not enough parameters");
		cout << buf << endl;
		send(usr.getFdUser(), buf.c_str(), buf.length(), 0);
		return ;
	}
	usr.setUserName(params[1]);
	usr.setHostName(params[2]);
	usr.setServerName(params[3]);
	/*
	string	real = params[4].substr(1, params[4].length() - 1);
	for (vector<string>::iterator it = params.begin() + 5; it != params.end(); it++)
	{
		real += " ";
		real += *it;
	}
	usr->setUserName(real);
	*/
	usr.setPrefix();
	std::cout << "user command called = " << usr.getUserName() << std::endl;
}

/*
 * Command: 	USER
 * Parameters:	<user> <mode> <unused> <realname>
 * The USER command is used at the beginning of connection to specify
 * the username, hostname and realname of a new user.
 *  ERR_NEEDMOREPARAMS      ERR_ALREADYREGISTRED
 */
