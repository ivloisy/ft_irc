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

void	mode_cmd(Server & srv, User & usr, std::vector<std::string> params)
{
	(void)srv;
	(void)usr;
	(void)params;
	/*
	cout << "mode before = " << usr.getMode() << endl;
	if (params.size() < 2)
	{
		//ERR_NEEDMOREPARAMS
		srv.ft_error(&usr, ERR_NEEDMOREPARAMS, params[0]);
		return ;
	}
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




		if (params[1][0] == '#')
		{
			Channel * chan;
			if ((chan = srv.getChannelByName(params[1])))
			{
				if (params.size() > 3)
				{
					User * to;
					if ((to = chan->getUser(params[3])))
					{
						if (!chan->isOperator(&usr))
							;//ERR NO RIGHTS
						bool set;
						if (params[2][0] == '-') {
							set = false;
							if (params[2][1] == 'o')
							{
								chan->setUserOperator(to, set);
								srv.ft_notice(&usr, &usr, NTC_MODE(usr.getNickName(), '-' + chan->getUserMode(to)));
							}
							if (params[2][1] == 'b')
							{
								chan->setUserBanned(to, set);
								srv.ft_notice(&usr, &usr, NTC_MODE(usr.getNickName(), '-' + chan->getUserMode(to)));
							}
						}
						if (params[2][0] == '+')
						{
							set = true;
							if (params[2][1] == 'o')
							{
								chan->setUserOperator(to, set);
								srv.ft_notice(&usr, &usr, NTC_MODE(usr.getNickName(), '+' + chan->getUserMode(to)));
							}
							if (params[2][1] == 'b')
							{
								chan->setUserBanned(to, set);
								srv.ft_notice(&usr, &usr, NTC_MODE(usr.getNickName(), '+' + chan->getUserMode(to)));
							}
						}
					}
					else
					{
						//ERR NO NICKNAME
					}
				}
				else
				{
					//ERR NO NICKNAME
				}
			}
			else
			{
				//ERR_NOSUCHCHANNEL
				srv.ft_reply(&usr, ERR_NOSUCHCHANNEL, params[3]);
				return ;
			}
		}


		if (srv.isUserReal(params[1]))
		{
			if (params.size() < 3)
			{
				srv.ft_reply(&usr, RPL_UMODEIS, usr.getMode());
				return ;
			}
			char c;
			if ((c = isUnknown(params[2])))
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
					srv.ft_notice(&usr, &usr, NTC_MODE(usr.getNickName(), '-' + usr.getMode()));
				}
				if (params[2][1] == 'i')
				{
					usr.setInvisible(set);
					srv.ft_notice(&usr, &usr, NTC_MODE(usr.getNickName(), '-' + usr.getMode()));
				}
			}
			if (params[2][0] == '+')
			{
				set = true;
				if (params[2][1] == 'o')
				{
					usr.setOperator(set);
					srv.ft_notice(&usr, &usr, NTC_MODE(usr.getNickName(), '+' + usr.getMode()));
				}
				if (params[2][1] == 'i')
				{
					usr.setInvisible(set);
					srv.ft_notice(&usr, &usr, NTC_MODE(usr.getNickName(), '+' + usr.getMode()));

				}
			}



		}
		else
		{
			//ERR_USERDONTMATCH
			srv.ft_error(&usr, ERR_USERSDONTMATCH, NULL);
			return ;
		}

	}
	*/
	//cout << "mode after = " << usr.getModeString() << " " << usr.getModeBitset().test(0) << usr.getModeBitset().test(1) << endl;
}
