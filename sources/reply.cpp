//
// Created by user42 on 27/06/22.
//

#include "../includes/ft_irc.hpp"

/************* USELESS FOR THE MOMENT *********************/

using namespace std;
using namespace irc;

//usr == from
string ft_RPL_WELCOME(string arg1, string arg2, string arg3, string arg4, string arg5) { (void)arg2; (void)arg3; (void)arg4; (void)arg5; return (":Welcome to the Internet Relay Network " + arg1); } // arg 1 = from->getPrefix()
string ft_RPL_YOURHOST(string arg1, string arg2, string arg3, string arg4, string arg5) { (void)arg3; (void)arg4; (void)arg5; return (":Your host is " + arg1 + ", running version " + arg2); } // arg1 = srv->getServerName(), arg2 = srv->getVersion()
string ft_RPL_CREATED(string arg1, string arg2, string arg3, string arg4, string arg5) { (void)arg2; (void)arg3; (void)arg4; (void)arg5; return (":This server was created " + arg1); } // arg1 = srv->getDate()
string ft_RPL_MYINFO(string arg1, string arg2, string arg3, string arg4, string arg5) { (void)arg5; return (arg1 + " " + arg2 + " " + arg3 + " " + arg4); }// arg1 = srv->getServerName(), arg2 = srv->getVersion, arg3 = srv->available user modes, arg4 = srv->arvailable channel modes
string ft_RPL_WHOISUSER(string arg1, string arg2, string arg3, string arg4, string arg5) { (void)arg5; return (arg1 + " " + arg2 + " " + arg3 + " * :" + arg4); } //arg1 = from->getNickName(). arg2 = from->getUserName(), arg3 = from->getHostname(), arg4 = from->getRealName()
//string ft_RPL_WHOISSERVER(string arg1, string arg2, string arg3, string arg4, string arg5) { return (usr->getNickname() + " " + srv->getServername() + " :" + server info); }
//string ft_RPL_WHOISOPERATOR(string arg1, string arg2, string arg3, string arg4, string arg5) { return (usr->getNickName() + " :is an IRC operator"); }
//string ft_RPL_WHOISIDLE(string arg1, string arg2, string arg3, string arg4, string arg5) { return (usr->getNickName() + " " + integer + " :seconds idle"); }
//string ft_RPL_ENDOFWHOIS(string arg1, string arg2, string arg3, string arg4, string arg5) { return (usr->getNickName() + " :End of /WHOIS list"); }
//string ft_RPL_WHOISCHANNELS(string arg1, string arg2, string arg3, string arg4, string arg5) {}
//string ft_RPL_UNIQOPIS(string arg1, string arg2, string arg3, string arg4, string arg5) { return (usr->getChannelName() + " " + usr->getNickName()); }
//string ft_RPL_CHANNELMODEIS(string arg1, string arg2, string arg3, string arg4, string arg5) { return (usr->getChannelName() + " +" + usr->getMode()); }
string ft_RPL_NAMREPLY(string arg1, string arg2, string arg3, string arg4, string arg5) { (void)arg3; (void)arg4; (void)arg5; return (arg1 + " :" + arg2); } //arg1 = target, arg2 = list
string ft_RPL_ENDOFNAMES(string arg1, string arg2, string arg3, string arg4, string arg5) { (void)arg2; (void)arg3; (void)arg4; (void)arg5; return (arg1 + " :End of /NAMES list"); } //arg2 = target
//string RPL_BANLIST(string arg1, string arg2, string arg3, string arg4, string arg5) { return (channel + " " + banip); }
//string RPL_ENDOFBANLIST(string arg1, string arg2, string arg3, string arg4, string arg5) { return (channel + " :End of channel ban list"); }
//string RPL_YOUREOPER(string arg1, string arg2, string arg3, string arg4, string arg5) { return (":You are now an IRC operator"); }

void 	Server::initReplyTree()
{
	map_rep[RPL_WELCOME] = ft_RPL_WELCOME;
	map_rep[RPL_YOURHOST] = ft_RPL_YOURHOST;
	map_rep[RPL_CREATED] = ft_RPL_CREATED;
	map_rep[RPL_MYINFO] = ft_RPL_MYINFO;
	map_rep[RPL_WHOISUSER] = ft_RPL_WHOISUSER;
	map_rep[RPL_NAMREPLY] = ft_RPL_NAMREPLY;
	map_rep[RPL_ENDOFNAMES] = ft_RPL_ENDOFNAMES;
}

void	Server::initErrorTree()
{
	map_err[ERR_NOSUCHNICK] = ":No such nick/channel";
	map_err[ERR_NOSUCHSERVER] = ":No such server";
	map_err[ERR_NOSUCHCHANNEL] = ":No such channel";
	map_err[ERR_CANNOTSENDTOCHAN] = ":Cannot send to channel";
	map_err[ERR_TOOMANYCHANNELS] = ":You have joined too many channels";
	map_err[ERR_WASNOSUCHNICK] =  ":There was no such nickname";
	map_err[ERR_TOOMANYTARGETS] = ":Duplicate recipients. No message delivered";
	map_err[ERR_NOORIGIN] = ":No origin specified";
	map_err[ERR_NORECIPIENT] = ":No recipient given";
	map_err[ERR_NOTEXTTOSEND] = ":No text to send";
	map_err[ERR_NOTOPLEVEL] = ":No toplevel domain specified";
	map_err[ERR_WILDTOPLEVEL] = ":Wildcard in toplevel domain";
	map_err[ERR_BADMASK] = ":Bad Server/host mask";
	map_err[ERR_UNKNOWNCOMMAND] = ":Unknown command";
	map_err[ERR_NOMOTD] = ":MOTD File is missing";
	map_err[ERR_NOADMININFO] = ":No administrative info available";
	map_err[ERR_NONICKNAMEGIVEN] = ":No nickname given";
	map_err[ERR_ERRONEUSNICKNAME] = ":Erroneus nickname";
	map_err[ERR_NICKNAMEINUSE] = ":Nickname is already in use";
	map_err[ERR_NICKCOLLISION] = ":Nickname collision KILL";
	map_err[ERR_USERNOTINCHANNEL] = ":You're not on that channel";
	map_err[ERR_NOTONCHANNEL] = ":You're not on that channel";
	map_err[ERR_USERONCHANNEL] = ":is already on channel";
	map_err[ERR_NOLOGIN] = ":User not logged in";
	map_err[ERR_SUMMONDISABLED] = ":SUMMON has been disabled";
	map_err[ERR_USERSDISABLED] = ":USERS has been disabled";
	map_err[ERR_NOTREGISTERED] = ":You have not registered";
	map_err[ERR_NEEDMOREPARAMS] = ":Not enough parameters";
	map_err[ERR_ALREADYREGISTRED] = ":You may not reregister";
	map_err[ERR_NOPERMFORHOST] = ":Your host isn't among the privileged";
	map_err[ERR_PASSWDMISMATCH] = ":Password incorrect";
	map_err[ERR_YOUREBANNEDCREEP] = ":You are banned from this server";
	map_err[ERR_KEYSET] = ":Channel key already set";
	map_err[ERR_CHANNELISFULL] = ":Cannot join channel (+l)";
	map_err[ERR_UNKNOWNMODE] = ":is unknown mode char to me";
	map_err[ERR_INVITEONLYCHAN] = ":Cannot join channel (+i)";
	map_err[ERR_BANNEDFROMCHAN] = ":Cannot join channel (+b)";
	map_err[ERR_BADCHANNELKEY] = ":Cannot join channel (+k)";
	map_err[ERR_BADCHANMASK] = ":Bad Channel Mask";
	map_err[ERR_NOCHANMODES] = ":Channel doesn't support modes";
	map_err[ERR_BANLISTFULL] = ":Channel list is full";
	map_err[ERR_NOPRIVILEGES] = ":Permission Denied- You're not an IRC operator";
	map_err[ERR_CANTKILLSERVER] = ":You cant kill a server!";
	map_err[ERR_RESTRICTED] = ":Your connection is restricted!";
	map_err[ERR_CHANOPRIVSNEEDED] = ":You're not channel operator";
	map_err[ERR_UNIQOPPRIVSNEEDED] = ":You're not the original channel operator";
	map_err[ERR_NOOPERHOST] = ":No O-lines for your host";
	map_err[ERR_UMODEUNKNOWNFLAG] = ":Unknown MODE flag";
	map_err[ERR_USERSDONTMATCH] = ":Cant change mode for other users";
}

void 	Server::ft_reply(User * from, string code, string arg1, string arg2, string arg3, string arg4, string arg5)
{
	string ret = ":";
	ret += _serverName;
	ret += " ";
	ret += code;
	ret += " ";
	ret += from->getNickName();
	ret += " ";
	ret += map_rep.find(code)->second(arg1, arg2, arg3, arg4, arg5);
	ret += "\r\n";
	sendBuffer(from, ret);
}

void	Server::ft_error(User * from, string code, string arg)
{
	string ret = ":";
	ret += _serverName;
	ret += " ";
	ret += code;
	ret += " * ";
	ret += arg;
	ret += " ";
	ret += map_err.find(code)->second;
	ret += "\r\n";
	sendBuffer(from, ret);
}

void	Server::ft_notice(User * from, User * to, string notice)
{
	string ret = ":";
	ret += from->getPrefix();
	ret += " ";
	ret += notice;
	ret += "\r\n";
	sendBuffer(to, ret);
}

void	Server::ft_notice_chan(User * from, Channel * to, string notice)
{
	string ret = ":";
	ret += from->getPrefix();
	ret += " ";
	ret += notice;
	ret += "\r\n";
	vector<User *> tousr = to->getChannelUsers();
	for (vector<User *>::iterator it = tousr.begin(); it != tousr.end(); it++)
	{
		if ((*it)->getNickName() != from->getNickName())
			sendBuffer(*it, ret);
	}
}
