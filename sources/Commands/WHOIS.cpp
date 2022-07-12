#include "../../includes/User.hpp"
#include "../../includes/Server.hpp"
#include <list>
# include "../../includes/reply.hpp"
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


void	who_user(Server & srv, User & usr, vector<string> params, bool wild)
{
	(void)usr;
	if (params.size() == 1 || (params.size() == 2 && params[1][0] == '#'))
	{
		vector<User *> users = srv.getUsers();
		for (vector<User *>::iterator it = users.begin(); it != users.end(); it++)
			if ( (*it)->getNickName() == params[0] || (*it)->getHostname() == params[0] || (*it)->getServerName() == params[0] || (*it)->getRealName() == params[0] )
				srv.ft_reply(&usr, "352", (*it)->getCurrentChannelName(), (*it)->getUserName(), (*it)->getHostname(), (*it)->getServerName(), (*it)->getNickName(), (*it)->getRealName());
	}
	if (wild == true)
		srv.ft_reply(&usr, "315", "*");
	else
		srv.ft_reply(&usr, "315", params[0]);
}

void	who_chan(Server & srv, User & usr, vector<string> params, bool wild)
{
	// Channel *chan = srv.getChannelByName(params[1]);
	if (usr.getChannelByName(params[1]))
	{
		if (params.size() == 1 || (params.size() == 2 && params[1][0] == '#'))
		{
			vector<User *> users = srv.getUsers();
			for (vector<User *>::iterator it = users.begin(); it != users.end(); it++)
				srv.ft_reply(&usr, "352", (*it)->getCurrentChannelName(), (*it)->getUserName(), (*it)->getHostname(), (*it)->getServerName(), (*it)->getNickName(), (*it)->getRealName());

		}
	}
	srv.ft_reply(&usr, "315",(wild == true ? "*" : params[0]));
	// if (wild == true)
	// 	srv.ft_reply(&usr, "315", "*");
	// else
	// 	srv.ft_reply(&usr, "315", params[0]);
}

void				who_wildcard(Server &srv, User &usr, vector<string> params)
{
	if (usr.getCurrentChannel() != NULL)
	{
		params[0] = usr.getCurrentChannelName();
		who_chan(srv, usr, params, true);
	}
	else
	{
		params[0] = usr.getNickName();
		who_user(srv, usr, params, true);
	}
}

void	whois_cmd(Server & srv, User & usr, vector<string> params)
{
	if (params[0][0] == '#')
		who_chan(srv, usr, params, false); // chan
	else if (params[0] == "*")
		who_wildcard(srv, usr, params);
	else
		who_user(srv, usr, params, false);
	std::cout << "whois command called" << std::endl;
}
