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

/*
 * I don't know how to use theses :
 * ERR_NOSUCHCHANNEL
 * RPL_TOPIC
 * ERR_BADCHANNELKEY
 * ERR_BADCHANMASK
 * ERR_TOOMANYCHANNELS
 * ERR_UNAVAILRESOURCE
 */

/* to do :
 * keys are coming with a virgule, need to parse it
 * check the symbol before the name of the channel for setting its mode
 */

void	join_cmd(Server * srv, User * usr, vector<string> params)
{
	if (params[0] == "JOIN")
	{
		if (params.size() < 1)
		{
			return ;//ERR_NEEDMOREPARAMS
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
					if (existing->getInviteOnlyMode())
					{
						//ERR_INVITEONLYCHAN
						return ;
					}
					else if (existing->isMaxUsers())
					{
						//ERR_CHANNELISFULL
						return ;
					}
					else if (existing->getBanned(usr->getNickName()))
					{
						//ERR_BANNEDFROMCHAN
						return ;
					}
					//join channel
					existing->addUser(usr);
					usr->addChannel(existing);
					return ;
				}
				else// > starts with one of the channel symbols
				{
					if (srv->isMaxChannel())
					{
						//ERR_TOOMANYCHANNELS
						return ;
					}
					//create channel
					Channel * new_chan = srv->addChannel(params[1]);
					new_chan->addUser(usr);
					usr->addChannel(new_chan);
					//got channel operator mode
					return ;

				}

			}

		}
	}
	cout << "join command called" << endl;
}
