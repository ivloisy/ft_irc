//
// Created by antoine on 04/07/22.
//

#include "../../includes/ft_irc.hpp"

using namespace irc;
using namespace std;

//NEVER SEND AUTOMATIC REPLIES TO THIS

/*********************** SEND MESSAGES ********************/

void	notice_cmd(Server & srv, User & usr, std::vector<std::string> params)
{
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
		if (srv.getChannel(params[1]))
		{
			srv.sendToChan(usr.getNickName(), msg);
		}
		else if (srv.getUser(params[1]))
		{
			srv.sendToUser(params[1], msg);
		}
	}
	//std::cout << "notice command called" << std::endl;
}
