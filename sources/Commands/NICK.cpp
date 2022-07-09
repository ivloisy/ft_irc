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
		buf = ft_reply(srv.getServerName(), ERR_NONICKNAMEGIVEN, usr.getNickName(), ":No nickname given");
		//cout << buf << endl;
		send(usr.getFdUser(), buf.c_str(), buf.length(), 0);
		return ;
	}
	if (params.size() > 2 || params[1].length() > 9)
	{
		buf = ft_reply(srv.getServerName(), ERR_ERRONEUSNICKNAME, usr.getNickName(), params[1] + " :Erroneous nickname");
		//cout << buf << endl;
		send(usr.getFdUser(), buf.c_str(), buf.length(), 0);
		return ;
	}
	//cout << "NICKNAME FOUND = " << srv->getUser(usr->getFdUser())->getNickName() << endl;
	if (srv.searchNick(params[1]))
	{
		buf = ft_reply(srv.getServerName(), ERR_NICKNAMEINUSE, usr.getNickName(), params[1] + " :Nickname is already in use");
		//cout << buf << endl;
		send(usr.getFdUser(), buf.c_str(), buf.length(), 0);
		return ;
	}
	srv.getUser(usr.getFdUser())->setNickName(params[1]);
	//std::cout << tmp << "'s nickname become " << usr->getNickName() << std::endl;
	cout << "nick command called" << endl;
}
