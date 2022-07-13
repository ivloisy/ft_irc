//
// Created by antoine on 04/07/22.
//

#include "../../includes/ft_irc.hpp"


using namespace irc;
using namespace std;

/********************* USER COMMAND **********************/

/*
 * MODE
 * parameters <nickname> *( ( "+" / "-" ) *( "i" / "w" / "o" / "O" / "r" ) )
 *
USER MODES :						ADD IF WE HAVE TIME
	//- a : away
	- i : invisible
	//- w : wallops
	//- r : restricted
	- o : operator

CHANNEL MODES :
for users :
    - O : channel creator
    //- o : channel operator			//i : invited
    //- v : voice						b : banned
for channels :
    //- i : invite only
    //- m : moderated
    //- n : outside privmsg
disabled
    //- p : private
    //- t : topic locked
    //- k : key locked
    //- l : user limit
 */


string			chanMode(Server & srv, User & usr, string mode)
{
	(void)mode;
	(void)srv;
	(void)usr;
	//Channel * chan;
	//if ((chan = srv.getChannelByName()))
	//{
		//ERR_USERNOTINCHANNEL
		//RPL_CHANNELMODEIS
		//RPL_BANLIST
		//if ((usr->getChannlByName))
		//bitset<2> chn_mode = chanMode(usr, params[2]);
		//chan->setMode(chn_mode);
	//}
	return (0);
}

char				isUnknown(string content)
{
	if (content[0] != '+' && content[0] != '-')
		return (true);
	content.erase(content.begin());
	string check("io");
	string::iterator last_m = content.end();
	string::iterator last = check.end();
	for (string::iterator it_m = content.begin(); it_m != last_m; it_m++)
	{
		for (string::iterator it = check.begin(); it != last; it++)
		{
			if (*it != *it_m)
				return (*it) ;
		}
	}
	return (0);
}

string	userMode(Server & srv, User & usr, string mode)
{
	char c;
	if ((c = isUnknown(mode)))
	{
		//ERR_UNKNOWNMODE
		string ret(1, c);
		srv.ft_error(&usr, ERR_UNKNOWNMODE, ret);
		return (0);
	}
	if (mode[0] == '+')
	{

	}
	//if (mode[0] == '-')
	return ("usr_mode");
}

void	mode_cmd(Server & srv, User & usr, std::vector<std::string> params)
{
	cout << "mode before = " << usr.getMode() << endl;
	if (params.size() < 3)
	{
		//ERR_NEEDMOREPARAMS
		srv.ft_error(&usr, ERR_NEEDMOREPARAMS, params[0]);
		return ;
	}
	else
	{
		if (params[2].size() > 3 || (params[2][0] != '+' && params[2][0] != '-'))
		{
			srv.ft_error(&usr, ERR_UNKNOWNMODE, params[2]);
			return ;
		}
		if (params[1][0] == '#')
		{
			string chan_mode = chanMode(srv, usr, params[2]);
			Channel * chan = srv.getChannelByName(params[1]);
			chan->setUserMode(&usr, chan_mode);
		}
		if (usr.getNickName() == params[1])
		{
			string usr_mode = userMode(srv, usr, params[2]);
			usr.setMode(usr_mode);
			//srv.ft_reply(RPL_)
			//USR MODE SET
		}
		else
		{
			//ERR_USERDONTMATCH
			srv.ft_error(&usr, ERR_USERSDONTMATCH, NULL);
			return ;
		}

	}
	//cout << "mode after = " << usr.getModeString() << " " << usr.getModeBitset().test(0) << usr.getModeBitset().test(1) << endl;
}
