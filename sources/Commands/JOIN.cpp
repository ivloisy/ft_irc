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

void	user_join_channel(Server & srv, User & usr, Channel & existing)
{
	(void)srv;
	cout << "USER JOIN CHANNEL UFNCTION\n";
	if (existing.getInviteOnlyMode())
	{
		string msg = existing.getChannelName() + " :Cannot join channel (+i)";
	//	ft_reply(srv.getServerName(), ERR_INVITEONLYCHAN, usr.getNickName(), msg);
		return ;
	}
	else if (existing.isMaxUsers())
	{
		string msg = existing.getChannelName() + " :Cannot join channel (+l)";
		// ft_reply(srv.getServerName(), ERR_CHANNELISFULL, usr.getNickName(), msg);
		return ;
	}
	else if (existing.getBanned(usr.getNickName()))
	{

		string msg = existing.getChannelName() + " :Cannot join channel (+b)";
		// ft_reply(srv.getServerName(), ERR_BANNEDFROMCHAN, usr.getNickName(), msg);
		return ;
	}
	//join channel
	bitset<3> dflt(string("101"));
	bitset<2> mode(string("10"));

	usr.setMode(mode);
	existing.addUser(&usr);
	existing.addUserMode(&usr, dflt);
	usr.addChannel(&existing);
	usr.setCurrentChannel(&existing);
}

Channel*	user_create_channel(Server &srv, User &usr, string &name)
{
	if (srv.isMaxChannel())
	{
		//ERR_TOOMANYCHANNELS
		string msg = name + " :You have joined too many channels";
		// ft_reply(srv.getServerName(), ERR_TOOMANYCHANNELS, usr.getNickName(), msg);
		return (NULL);
	}
	//create channel
	Channel * new_chan = srv.addChannel(name);
	bitset<3> creator(string("101"));
	bitset<2> mode(string("10"));

	usr.setMode(mode);
	new_chan->addUser(&usr);
	new_chan->addOper(&usr);
	new_chan->addUserMode(&usr, creator);
	usr.addChannel(new_chan);
	usr.setCurrentChannel(new_chan);
	//got channel operator mode
	return (new_chan);
}

bool	quit_all_chan(Server &srv, User &usr, vector<string> &params)
{
	if (params[1] == "0" && params.size() < 2)
	{
		//quit all joined channels
		string msg(params[1] + " left!");
		// ft_reply(srv.getServerName(), 0, usr.getNickName(), msg);
		msg.clear();
		msg = usr.getNickName() + " left " + params[1];
		srv.sendToChan(params[1], msg);
		usr.clearAllChannels();
		srv.delUserAllChannel(&usr);
		return (true);
	}
	return (false);
}

void	reply_channel_joined(Server & srv, User & usr, Channel & chan)
{
	string msg = usr.getPrefix() + " JOIN " + chan.getChannelName() + "\r\n";
	//srv->sendBuffer(usr, msg);
	//srv.sendToUser(usr.getNickName(), msg);
	if (srv.searchChannel(chan.getChannelName())) {

	}
	else
		cout << "error channel not found" << endl;
	//cout << msg << endl;
	vector<User *> chan_usr = chan.getChannelUsers();
	//cout << "USER NAMES = " << (*chan_usr.begin())->getNickName() << " " << usr->getNickName() << endl;
	vector<User *>::iterator lst = chan_usr.end();
	for (vector<User *>::iterator it = chan_usr.begin(); it != lst; it++) {
		srv.ft_reply(&usr, *it, RPL_NAMREPLY);
	}
	srv.ft_reply(&usr, NULL, RPL_ENDOFNAMES);
}

void	join_cmd(Server & srv, User & usr, vector<string> params)
{
	//need to implement key
	if (params[0] == "JOIN")
	{
		if (params.size() < 1)
		{
			string msg = params[0] + " :Not enough parameters";
			// ft_reply(srv.getServerName(), ERR_NEEDMOREPARAMS, usr.getNickName(), msg);
			return ; //ERR_NEEDMOREPARAMS
		}
		else
		{
			if (quit_all_chan(srv, usr,params))
				return ;
			unsigned long x = 1;
			while (x < params.size())
			{
				if (x >= 1 && srv.getChannelByName(params[x - 1]))
				{
					for (string::iterator i = params[x].begin(); i != params[x].end(); i++)
					{
						if ((*i) == ',')
						{
							string key;
							for (; i != params[x].end(); i++)
							{
								if (*i != ' ' && *i != ',')
									key.push_back(*i);
							}
							srv.getChannelByName(params[x - 1])->setKey(key);
						}
					}
				}
				Channel *existing;
				if ((existing = srv.searchChannel(params[x])))
				{
					user_join_channel(srv, usr, *existing);
					reply_channel_joined(srv, usr, *existing);
					//string msg = params[1] + " joined!";
					//srv->sendToUser(usr->getNickName(), msg);
					//msg.clear();
					//msg = usr->getNickName() + " joined " + params[1];
					//srv->sendToChan(params[1], msg);
				}
				else
				{
					Channel * new_chan = user_create_channel(srv, usr, params[1]);
					//user_create_channel(srv, usr, params[x]);
					if (new_chan)
						reply_channel_joined(srv, usr, *new_chan);
					//string msg = "";
					//srv.sendBuffer(&usr, ft_reply(srv.getServerName(), RPL_NAMREPLY, usr.getNickName(), msg));
					//srv.sendBuffer(&usr, ft_reply(srv.getServerName(), RPL_ENDOFNAMES, usr.getNickName(), msg));
					//string msg = params[1] + " created!";
					//srv->sendToUser(usr->getNickName(), msg);
				}
				x++;
			}
		}
	}
	//cout << "join command called" << endl;
}
