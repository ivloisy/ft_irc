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
 */

void	privmsg_cmd(Server & srv, User & usr, vector<string> params)
{
	cout << "PRIVMSG COMMAND LAUNCHED\n" << "MESSAGE FROM USER FD = " << usr.getFdUser() << endl;
	(void)usr;
	if (params.size() < 2)
	{
		//ERR wrong number arguments
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
		if (srv.getChannelByName(params[1]))
		{
			//cout << "SEND TO CHAN = " << msg << "\n";
			srv.sendToChan(params[1], msg);
		}
		else if (srv.getUser(params[1]))
		{
			//cout << "SEND TO USER = " << msg << "\n";
			srv.sendToUser(params[1], msg);
		}
	}
	//cout << "privmsg command called" << endl;
}
