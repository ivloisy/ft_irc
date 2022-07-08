//
// Created by antoine on 04/07/22.
//

#include "../../includes/User.hpp"
#include "../../includes/Server.hpp"
#include "../../includes/Command.hpp"
#include <cstring>

using namespace irc;
using namespace std;

/********************* USER COMMAND **********************/

/*
 * MODE
 * parameters <nickname> *( ( "+" / "-" ) *( "i" / "w" / "o" / "O" / "r" ) )
 *
USER MODES :
	- a : away
	- i : invisible
	- w : wallops
	- r : restricted
	- o : operator

CHANNEL MODES :
for users :
    - O : channel creator
    - o : channel operator
    - v : voice
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

bool	isUnknown(string content)
{
	if (content[0] != '+' && content[0] != '-')
		return (true);
	content.erase(content.begin());
	string check("aiwro");
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
			if (isUnknown(params[1]))
			{
				//ERR_UNKNOWNMODEFLAG
				return ;
			}
			usr->setMode(params[1]);
			//...
		}
		Channel * chan;
		if ((chan = srv->getChannel(params[1])))
		{
			//if ((usr->getChannlByName))
			return ;
		}

		//ERR_USERDONTMATCH
		return ;

	}
	std::cout << "mode command called" << std::endl;
}
