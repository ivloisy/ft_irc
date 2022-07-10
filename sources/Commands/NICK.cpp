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

	// if (ERR_RESTRICTED)////////////////////////////
	if (params.size() == 1)
	{
		// srv.sending(usr.getFdUser(), ft_reply(/*usr.getPrefix(), */srv.getServerName(), ERR_NONICKNAMEGIVEN, usr.getNickName(), ":No nickname given"));
		return ;
	}
	if (/*params.size() > 2 || */params[1].length() > 9)
	{
		// srv.sending(usr.getFdUser(), ft_reply(/*usr.getPrefix(), */srv.getServerName(), ERR_ERRONEUSNICKNAME, usr.getNickName(), params[1] + " :Erroneous nickname"));
		return ;
	}
	//cout << "NICKNAME FOUND = " << srv.getUser(usr.getFdUser())->getNickName() << endl;
	if (srv.searchNick(params[1]))
	{
		//srv.sending(usr.getFdUser(), ft_reply(srv.getServerName(), ERR_NICKNAMEINUSE, usr.getNickName(), params[1] + " :Nickname is already in use"));
		// srv.sending(usr.getFdUser(), ft_reply(/*usr.getPrefix(), */srv.getServerName(), ERR_NICKNAMEINUSE, "* " + params[1], params[1] + " :Nickname is already in use"));
		return ;
	}
	//srv.getUser(usr.getFdUser())->setNickName(params[1]);
	usr.setNickName(params[1]);
	std::cout << tmp << "'s nickname becomes " << usr.getNickName() << std::endl;
	//cout << "nick command called" << endl;
}
