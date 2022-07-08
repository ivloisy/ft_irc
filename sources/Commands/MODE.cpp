//
// Created by antoine on 04/07/22.
//

#include "../../includes/User.hpp"
#include "../../includes/Server.hpp"
#include "../../includes/Command.hpp"
#include <cstring>
#include <bitset>

#define OPERATOR	2
#define INVISIBLE	1

using namespace irc;
using namespace std;

/********************* USER COMMAND **********************/

/*
 * MODE
 * parameters <nickname> *( ( "+" / "-" ) *( "i" / "w" / "o" / "O" / "r" ) )
 *
USER MODES :						ADD IF WE HAVE TIME
	- a : away
	- i : invisible
	- w : wallops
	- r : restricted
	- o : operator

CHANNEL MODES :
for users :
    - O : channel creator
    - o : channel operator				i : invited
    - v : voice							b : banned
for channels :
    - i : invite only
    - m : moderated
    - n : outside privmsg
disabled
    - p : private
    - t : topic locked
    - k : key locked
    - l : user limit
 */


bitset<2>			chanMode(User * user, string mode)
{
	(void)user;
	(void)mode;
	return (0);
}

bool				isUnknown(string content)
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
				return (true) ;
		}
	}
	return (false);
}

bitset<2>			setBitset(string mode)
{
	bitset<2> bitset(string("00"));

	for (string::iterator it = mode.begin() + 1; it != mode.end(); it++)
	{
		if (*it == 'o')
			bitset |= OPERATOR;
		if (*it == 'i')
			bitset |= INVISIBLE;
	}
	return (bitset);
}

bitset<2>	userMode(User * usr, string mode)
{
	if (isUnknown(mode))
	{
		//ERR_UNKNOWNMODEFLAG
		return (0);
	}
	bitset<2> usr_mode = usr->getMode();
	bitset<2> bitset = setBitset(mode);
	if (mode[0] == '-')
		bitset.flip();
	usr_mode |= bitset;
	usr->setInvisible(usr_mode.test(2));
	if (usr_mode.test(1))
	{
		;//dire au client qu'il n'a pas les droits necessaires
	}
	else
		usr->setOper(usr_mode.test(1));
	return (usr_mode);
}

void	mode_cmd(Server * srv, User * usr, std::vector<std::string> params)
{
	(void)srv;
	(void)usr;
	(void)params;
	if (params.size() < 2)
	{
		//ERR_NEEDMOREPARAMS
		return ;
	}
	else
	{
		if (usr->getNickName() == params[1])
		{
			bitset<2> usr_mode = userMode(usr, params[2]);
			usr->setMode(usr_mode);
			//USR MODE SET
			return ;
		}
		Channel * chan;
		if ((chan = srv->getChannel(params[1])))
		{
			//if ((usr->getChannlByName))
			bitset<2> chn_mode = chanMode(usr, params[2]);
			chan->setMode(chn_mode);
			return ;
		}
		//ERR_USERDONTMATCH
		return ;

	}
	std::cout << "mode command called" << std::endl;
}
