//
// Created by alangloi on 6/24/22.
//

#include "../../includes/ft_irc.hpp"

using namespace irc;
using namespace std;

/********************* USER COMMAND **********************/

/* Gives a nickname to given user or change the existing one:
 * Erreurs:
 *	ERR_NONICKNAMEGIVEN ERR_ERRONEUSNICKNAME  ERR_NICKNAMEINUSE    ERR_NICKCOLLISION ERR_RESTRICTED ERR_UNAVAILRESOURCE
 */

void	nick_cmd(Server & srv, User & usr, vector<string> params)
{
	string	tmp = usr.getNickName();
	string	buf;

	if (params.size() == 1)
	{
		usr.resetRdySend();
		srv.ft_error(&usr, ERR_NONICKNAMEGIVEN, params[1]);
		return ;
	}
	if (params.size() > 2 || params[1].length() > 9)
	{
		usr.resetRdySend();
		srv.ft_error(&usr, ERR_ERRONEUSNICKNAME, params[1]);
		return ;
	}
	if (srv.searchNick(params[1]))
	{
		usr.decreaseRdySend();
		srv.ft_error(&usr, ERR_NICKNAMEINUSE, params[1]);
		return ;
	}
	usr.setNickName(params[1]);
	if (usr.getRdySend() == 2)
		usr.setRdySend();
	std::cout << tmp << "'s nickname becomes " << usr.getNickName() << std::endl;
}
