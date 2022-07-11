#include "../../includes/User.hpp"
#include "../../includes/Server.hpp"
#include <list>
#include "../../includes/ft_irc.hpp"

using namespace irc;
using namespace std;

//optional connection command

/********************* USER COMMAND **********************/

/*
Gives a nickname to given user or change the existing one:
Command: WHOIS
	Parameters: [ <target> ] <mask> *( "," <mask> )

	This command is used to query information about particular user.
	The server will answer this command with several numeric messages
	indicating different statuses of each user which matches the mask (if
	you are entitled to see them).  If no wildcard is present in the
	<mask>, any information about that nick which you are allowed to see
	is presented.

	If the <target> parameter is specified, it sends the query to a
	specific server.  It is useful if you want to know how long the user
	in question has been idle as only local server (i.e., the server the
	user is directly connected to) knows that information, while
	everything else is globally known.

	Wildcards are allowed in the <target> parameter.

	Numeric Replies:

		ERR_NOSUCHSERVER              ERR_NONICKNAMEGIVEN
		RPL_WHOISUSER                 RPL_WHOISCHANNELS
		RPL_WHOISCHANNELS             RPL_WHOISSERVER
		RPL_AWAY                      RPL_WHOISOPERATOR
		RPL_WHOISIDLE                 ERR_NOSUCHNICK
		RPL_ENDOFWHOIS
*/


// irssi syntax :<server> 352 <user> <*|u.curr_channel> <u.realname> <u.hostname> <u.servername>
//									 <u.nickname> <H|G>[*][@|+] :<hopcount> <u.realname>


void	who_user(Server & srv, User & usr, vector<string> params)
{
	(void)usr;
	if (params.size() == 1 || (params.size() == 2 && params[1][0] == '#'))
	{
		vector<User *> users = srv.getUsers();
		for (vector<User *>::iterator it = users.begin(); it != users.end(); it++)
		{
			// if ( ((*it)->getNickname() == args[0] || (*it)->getHostname() == args[0] || (*it)->getServername() == args[0] || (*it)->getRealName() == args[0] ))
			// send_reply(usr, 352, RPL_WHOREPLY((u->getCurrChan() ? u->getCurrChan()->getName() : "*"),
			// 					u->getUsername(), u->getHostname(), u->getServername(), u->getNick(),
			// 					(u->isIRCOper() ? "*" : ""), (u->isChanOper() ? "@" : ""), u->getRealName()));
		}
	}

	// 	if (wild == true)
	// 		send_reply(usr, 315, RPL_ENDOFWHO(string("*")));
	// 	else
	// 		send_reply(usr, 315, RPL_ENDOFWHO(args[0]));
}


void	whois_cmd(Server & srv, User & usr, vector<string> params)
{
	(void)srv;
	// (void)usr;
	// (void)params;
	if (params.size() == 1)
	{
		// srv.sending(usr.getFdUser(), ft_reply(/*usr.getPrefix(), */srv.getServerName(), ERR_NONICKNAMEGIVEN, usr.getNickName(), ":No nickname given"));
		return ;
	}
	//check if target_user exist

	// if (params[0][0] == '#')
	// 	who_chan(); // chan
	// else if (params[0] == "*")
	// 	who_wildcard();
	// else
		who_user(srv, usr, params);
	// srv.ft_reply(NULL, &usr, RPL_WHOISUSER);
	//std::cout << "whois command called" << std::endl;
}

// 	// I had to divide it in two because the ternary broke the output
// 	if (wild == true)
// 		send_reply(usr, 315, RPL_ENDOFWHO(string("*")));
// 	else
// 		send_reply(usr, 315, RPL_ENDOFWHO(args[0]));
//
// 	return 1;
// }
//
// int				who_channel( const vector<string> args, User &usr, Server &srv, bool wild ) {
//
// 	ostringstream	s;
//
// 	vector<Channel*>	chans = srv.getChannels();
// 	Channel				*c = NULL;
//
// 	for (vector<Channel*>::iterator it = chans.begin(); it != chans.end(); it++)
// 		if ((*it)->getName() == args[0])
// 		{
// 			c = *it;
// 			break;
// 		}
//
// 	// Works only if is only <channel> or <channel> + <channel2> (<channel2> is ignored)
// 	if ( (args.size() == 1 || (args.size() == 2 && args[1][0] == '#')) && c
// 		&& usr.isRegisteredToChan(*c) )
// 	{
// 		vector<User*>	users = c->getMembers();
//
// 		for ( vector<User*>::iterator it = users.begin(); it != users.end(); ++it )
// 		{
// 			User u = *(*it);
// 			send_reply(usr, 352, RPL_WHOREPLY((u.getCurrChan() ? u.getCurrChan()->getName() : "*"),
// 				u.getUsername(), u.getHostname(), u.getServername(), u.getNick(),
// 				(u.isIRCOper() ? "*" : ""), (u.isChanOper() ? "@" : ""), u.getRealName()));
// 		}
// 	}
//
// 	send_reply(usr, 315, RPL_ENDOFWHO(wild == true ? "*" : args[0]));
// 	return 1;
// }
//
// int				who_wildcard( vector<string> args, User &usr, Server &srv)
// {
// 	Channel		*chan = usr.getCurrChan();
//
// 	if (chan != NULL)
// 	{
// 		args[0] = chan->getName();
// 		who_channel(args, usr, srv, true);
// 	}
// 	else
// 	{
// 		args[0] = usr.getNick();
// 		who_user(args, usr, srv, true);
// 	}
//
// 	return 1;
// }
