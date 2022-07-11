//
// Created by antoine on 04/07/22.
//

#include "../../includes/ft_irc.hpp"

using namespace irc;
using namespace std;

/********* SENDING MESSAGES ************/

/*
 * PRIVMSG
 * <msgtarget> <text to be sent>
 *
           ERR_NORECIPIENT                 ERR_NOTEXTTOSEND
           ERR_CANNOTSENDTOCHAN            ERR_NOTOPLEVEL
           ERR_WILDTOPLEVEL                ERR_TOOMANYTARGETS
           ERR_NOSUCHNICK
           RPL_AWAY
 */

void	privmsg_cmd(Server & srv, User & usr, vector<string> params)
{
	//cout << "PRIVMSG COMMAND LAUNCHED\n" << "MESSAGE FROM USER FD = " << usr.getFdUser() << endl;
	(void)usr;
	//if paramisize ERR_NOTEXTTOSEND
	if (params.size() < 2)
	{
		//ERR_NORECIPIENT
		//srv.ft_error(&usr, ERR_NEEDMOREPARAMS, params[0]);
		return ;
	}
	else
	{
		// convert vector into params
		string msg;
		vector<string>::iterator last = params.end();
		for (vector<string>::iterator it = params.begin() + 2; it != last; it++)
		{
			string::iterator last_char = (*it).end();
			for (string::iterator it_char = (*it).begin(); it_char != last_char; it_char++)
				msg.push_back(*it_char);
			msg.push_back(' ');
		}

		//loop in many users, channels in params
		//find dupricates ERR_TOOMANYTARGETS
		//what happen if user,,user
		Channel * dstc;
		User * dstu;
		if ((dstc = srv.getChannelByName(params[1])))
		{
			srv.ft_notice_chan(&usr, dstc, NTC_PRIVMSG(dstc->getChannelName(), msg), false);
		}
		else if ((dstu = *srv.getUser(params[1])))
		{
			srv.ft_notice(&usr, dstu, NTC_PRIVMSG(dstu->getNickName(), msg));
		}
		else
		{
			//srv.ft_error(&usr, ERR_NORECIPIENT, )
		}
	}
	//cout << "privmsg command called" << endl;
}
