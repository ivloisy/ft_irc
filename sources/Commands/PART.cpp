//
// Created by antoine on 04/07/22.
//

#include "../../includes/ft_irc.hpp"

using namespace irc;
using namespace std;

/********************* CHANNEL COMMAND **********************/

/*
 * PART
 * parameters: <channel> *( "," <channel> ) [ <Part Message> ]
 *         ERR_NEEDMOREPARAMS              ERR_NOSUCHCHANNEL
           ERR_NOTONCHANNEL

 */

void	part_cmd(Server & srv, User & usr, vector<string> params)
{
	if (params.size() < 2)
	{
		srv.ft_reply(&usr, ERR_NEEDMOREPARAMS, params[0]);
	}
	else
	{
		string msg = "";
		if (params.size() >= 3)
		{
			for (vector<string>::iterator it = params.begin() + 2; it != params.end();it++)
			{
				for (size_t i = 0; i < (*it).size(); i++)
					msg.push_back((*it)[i]);
				msg.push_back(' ');
			}
		}
		vector<string> chans;
		stringstream str(params[1]);
		string s;
		while (getline(str, s, ','))
		{
			chans.push_back(s);
		}
		for (vector<string>::iterator it = chans.begin(); it != chans.end(); it++)
		{
			Channel * chan;
			if ((chan = srv.getChannelByName(*it)))
			{
				if (chan->isUserHere(&usr))
				{
					if (msg.empty())
						srv.ft_notice_chan(&usr, chan, NTC_PART(chan->getChannelName()), true);
					else
						srv.ft_notice_chan(&usr, chan, NTC_PART_MSG(chan->getChannelName(), msg), true);
					cout << "bye bye les amis" << endl;
					usr.quitChannel(chan);
					cout << "loulu" << endl;
					chan->delUser(&usr);
					cout << "lalal" << endl;
					if (chan->getChannelUsers().empty())
					{
						cout << "gogo" << endl;
						srv.deleteChannel(chan);
					}
					cout << "c finiiii" << endl;
				}
				else
				{
					srv.ft_reply(&usr, ERR_NOTONCHANNEL, chan->getChannelName());
				}
			}
			else
			{
				srv.ft_reply(&usr, ERR_NOSUCHCHANNEL, *it); //ERR NO SUCH CHANNEL
			}
		}

	}
	//std::cout << "part command called" << std::endl;
}
