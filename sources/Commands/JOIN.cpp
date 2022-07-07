//
// Created by antoine on 04/07/22.
//


#include "../../includes/User.hpp"
#include "../../includes/Server.hpp"
#include "../../includes/Command.hpp"
#include "../../includes/Channel.hpp"

using namespace irc;
using namespace std;

/********************* CHANNEL COMMAND **********************/

/*
 * JOIN command
 * ( <channel> *( "," <channel> ) [ <key> *( "," <key> ) ] )
               / "0"
 */

void	join_cmd(Server * srv, User * usr, vector<string> params)
{
	if (params[0] == "JOIN")
	{
		if (params.size() < 1)
		{
			//ERR_NEEDMOREPARAMS
		}
		else
		{
			vector<string>::iterator last = params.end();
			for (vector<string>::iterator it = params.begin(); it != last; it++)
			{
				Channel *existing;
				if (params[1] == "0" && params.size() < 2)
				{
					//quit all joined channels
					usr->clearAllChannels();
					srv->delUserAllChannel(usr);
					return ;
				}
				else if ((existing = srv->searchChannel(params[1])))
				{
					//join channel
					//std::cout;
					//for (srv->getChannel(existing->getChannelName()))
					existing->addUser(usr);
					usr->addChannel(existing);
					return ;
				}
				else// > starts with one of the channel symbols
				{
					//create channel
					Channel * new_chan = srv->addChannel(params[1]);;
					new_chan->addUser(usr);
					usr->addChannel(new_chan);
					return ;

				}

			}

		}
	}
	cout << "join command called" << endl;
}
