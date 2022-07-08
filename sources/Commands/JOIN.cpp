//
// Created by antoine on 04/07/22.
//

#include "../../includes/ft_irc.hpp"

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

void	user_join_channel(Server * srv, User * usr, Channel * existing)
{
	if (existing->getInviteOnlyMode())
	{
		//ERR_INVITEONLYCHAN
		string msg(existing->getChannelName() + " :Cannot join channel (+i)");
		ft_reply(srv->getServerName(), ERR_INVITEONLYCHAN, usr->getNickName(), msg);
		return ;
	}
	else if (existing->isMaxUsers())
	{
		//ERR_CHANNELISFULL
		string msg(existing->getChannelName() + " :Cannot join channel (+l)");
		ft_reply(srv->getServerName(), ERR_CHANNELISFULL, usr->getNickName(), msg);
		return ;
	}
	else if (existing->getBanned(usr->getNickName()))
	{
		//ERR_BANNEDFROMCHAN
		string msg(existing->getChannelName() + " :Cannot join channel (+b)");
		ft_reply(srv->getServerName(), ERR_BANNEDFROMCHAN, usr->getNickName(), msg);
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
		string msg(name + " :You have joined too many channels");
		ft_reply(srv->getServerName(), ERR_TOOMANYCHANNELS, usr->getNickName(), msg);
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
	//need to implement key
	if (params[0] == "JOIN")
	{
		if (params.size() < 1)
		{
			string msg(params[0] + " :Not enough parameters");
			ft_reply(srv->getServerName(), ERR_NEEDMOREPARAMS, usr->getNickName(), msg);
			return ; //ERR_NEEDMOREPARAMS
		}
		else
		{
			vector<string> tmp;

			vector<string>::iterator last = params.end();
			for (vector<string>::iterator it = params.begin(); it != last; it++)
			{
				Channel *existing;
				if (params[1] == "0" && params.size() < 2)
				{
					//quit all joined channels
					string msg(params[1] + " left!");
					ft_reply(srv->getServerName(), 0, usr->getNickName(), msg);
					msg.clear();
					msg = usr->getNickName() + " left " + params[1];
					srv->sendToChan(params[1], msg);
					usr->clearAllChannels();
					srv->delUserAllChannel(usr);
					return ;
				}
				unsigned long x = 1;
				while (x < params.size())
				{
					if (x > 1 && srv->getChannel(params[x - 1]))
					{
						for (string::iterator it = params[x].begin(); it != params[x].end(); it++)
						{
							if ((*it) == ',')
							{
								string key;
								for (; it != params[x].end(); it++)
								{
									if (*it != ' ' && *it != ',')
										key.push_back(*it);
								}
								srv->getChannel(params[x - 1])->setKey(key);
							}
						}
					}

					if ((existing = srv->searchChannel(params[x])))
					{
						user_join_channel(srv, usr, existing);
						//optionnal
						string msg(params[1] + " joined!");
						ft_reply(srv->getServerName(), 0, usr->getNickName(), msg);
						msg.clear();
						msg = usr->getNickName() + " joined " + params[1];
						srv->sendToChan(params[1], msg);
						return ;
					}
					else if (params[x][0] == '#' || params[x][0] == '&' )// > starts with one of the channel symbols
					{

						user_create_channel(srv, usr, params[1]);
						//optionnal
						string msg(params[1] + " created!");
						ft_reply(srv->getServerName(), 0, usr->getNickName(), msg);
						return ;

					}
					x++;
				}


			}

		}
	}
	cout << "join command called" << endl;
}
