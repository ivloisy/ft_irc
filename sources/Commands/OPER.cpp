//
// Created by antoine on 04/07/22.
//


#include "../../includes/ft_irc.hpp"

using namespace irc;
using namespace std;

/********************* OPERATOR COMMAND **********************/

/*
 * OPER
 * A normal user uses the OPER command to obtain operator privileges.
 * The combination of name and password are required to gain operator privileges.
 *  ERR_NEEDMOREPARAMS  RPL_YOUREOPER ERR_NOOPERHOST   ERR_PASSWDMISMATCH
 */

void	oper_cmd(Server & srv, User & usr, std::vector<std::string> params)
{
	(void)srv;
	(void)usr;
	(void)params;
	if (params.size() < 3)
	{
		return ;//ERR_NEEDMOREPARAMS
	}
	else
	{
		//IRCOperator
		if (params[1] == usr.getNickName() && params[1] == OPER_NAME)
		{
			if (params[2] == OPER_PASS)
			{
				usr.setOper(1);
				//RPL_YOUREOPER
				return ;
			}
			//ERR_PASSWDMISMATCH
		}
		//ERR_NOOPERHOST
		//srv->reply()

		//Channel Operator
		//if (srv->getUser(params[1]) == srv->getChannel())
		//{
			//if (params[2])
		//}
	}
	//std::cout << "oper command called" << std::endl;
}
