//
// Created by antoine on 04/07/22.
//


#include "../../includes/User.hpp"
#include "../../includes/Server.hpp"
#include "../../includes/Command.hpp"
#include "../../includes/Channel.hpp"
#include <bitset>

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

void	user_join_channel(User * usr, Channel * existing)
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
	bitset<3> dflt(string("101"));
	existing->addUser(usr);
	existing->addUserMode(usr, dflt);
	usr->addChannel(existing);
}

void	user_create_channel(Server *srv, User *usr, string name)
{
	if (srv->isMaxChannel())
	{
		//ERR_TOOMANYCHANNELS
		return ;
	}
	//create channel
	Channel * new_chan = srv->addChannel(name);
	bitset<3> creator(string("101"));

	new_chan->addUser(usr);
	new_chan->addOper(usr);
	new_chan->addUserMode(usr, creator);
	usr->addChannel(new_chan);
	//got channel operator mode
}

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
					user_join_channel(usr, existing);
					return ;
				}
				else// > starts with one of the channel symbols
				{

					user_create_channel(srv, usr, params[1]);
					return ;

				}

			}

		}
	}
	cout << "join command called" << endl;
}
