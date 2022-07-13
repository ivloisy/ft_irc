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

char				isUnknown(string content)
{
	if (content[0] != '+' && content[0] != '-')
		return (0);
	content.erase(content.begin());
	for (size_t i = 0; i < content.size(); i++)
	{
		if (content[i] != 'i' && content[i] != 'o')
			return (content[i]);
	}
	return (0);
}

void	mode_cmd(Server & srv, User & usr, std::vector<std::string> params)
{
	//cout << "mode before = " << usr.getMode() << endl;
	if (!srv.check_command(&usr, 2, params))
		return ;
	else
	{
		//char c;
		//if ((c = isUnknown(params[2])))
		//{
		//	//ERR_UNKNOWNMODE
		//	string ret(1, c);
		//	srv.ft_error(&usr, ERR_UNKNOWNMODE, ret);
		//	return ;
		//}
		//if (params[2].size() > 3 || (params[2][0] != '+' && params[2][0] != '-'))
		//{
		//	srv.ft_error(&usr, ERR_UNKNOWNMODE, params[2]);
		//	return ;
		//}

		if (srv.isUserReal(params[1]))
		{
			if (params.size() < 3)
			{
				vector<User *>::iterator u;
				if ((u = srv.getUser(params[1])) == srv.getUsers().end())
				{
					srv.ft_error(&usr, ERR_USERSDONTMATCH);
					return ;
				}
				srv.ft_reply(&usr, RPL_UMODEIS, (*u)->getMode());
				return ;
			}
			char c;
			if ((c = isUnknown(params[2])) != 0)
			{
				//ERR_UNKNOWNMODE
				string ret(1, c);
				srv.ft_error(&usr, ERR_UNKNOWNMODE, ret);
				return ;
			}
			if (params[2].size() > 3 || (params[2][0] != '+' && params[2][0] != '-'))
			{
				srv.ft_error(&usr, ERR_UNKNOWNMODE, params[2]);
				return ;
			}
			bool set;
			if (params[2][0] == '-')
			{
				set = false;
				if (params[2][1] == 'o')
				{
					usr.setOperator(set);
					srv.ft_notice(&usr, &usr, NTC_MODE(usr.getNickName(), "-o"));
				}
				if (params[2][1] == 'i')
				{
					usr.setInvisible(set);
					srv.ft_notice(&usr, &usr, NTC_MODE(usr.getNickName(), "-i"));
				}
			}
			if (params[2][0] == '+')
			{
				set = true;
				if (params[2][1] == 'o')
				{
					usr.setOperator(set);
					srv.ft_notice(&usr, &usr, NTC_MODE(usr.getNickName(), "+o"));
				}
				if (params[2][1] == 'i')
				{
					usr.setInvisible(set);
					srv.ft_notice(&usr, &usr, NTC_MODE(usr.getNickName(), "+i"));
				}
			}
		}
		else
		{
			//ERR_USERDONTMATCH
			srv.ft_error(&usr, ERR_USERSDONTMATCH);
			return ;
		}

	}
	//cout << "mode after = " << usr.getModeString() << " " << usr.getModeBitset().test(0) << usr.getModeBitset().test(1) << endl;
}
