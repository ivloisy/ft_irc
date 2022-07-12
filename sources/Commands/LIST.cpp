//
// Created by antoine on 04/07/22.
//

#include "../../includes/ft_irc.hpp"

using namespace irc;
using namespace std;

//DONT DO THIS COMMAND

/********************* CHANNEL COMMAND **********************/

//not mandatory but usefull for debugging

/*
 * LIST
 * parameters : [ <channel> *( "," <channel> ) [ <target> ] ]
 */

void		list_cmd(Server & srv, User & usr, std::vector<std::string> params)
{
	if (params.size() == 1)
	{
		vector<Channel *> chans = srv.getChannels();
		for (vector<Channel *>::iterator it = chans.begin(); it != chans.end(); it++)
		{
			srv.ft_reply(&usr, RPL_LIST, (*it)->getChannelName(), "1", "no topic");
		}
		srv.ft_reply(&usr, RPL_LISTEND);
	}
	//std::cout << "list command called " << std::endl;
}
