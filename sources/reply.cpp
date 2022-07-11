//
// Created by user42 on 27/06/22.
//

#include "../includes/ft_irc.hpp"

/************* USELESS FOR THE MOMENT *********************/

using namespace std;
using namespace irc;

/*
 * 1 / Trouver reply correspondante dans la liste ci dessous, decommenter, modifier avec les bonnes variables (checker RFC pour + de details):
 * prototype		string RPL_NAMEOFREPLY(Server * srv, User * from, User * to)
 * 		rajouter prototype fonction dans ft_irc.hpp ( tout en bas )
 * 		rajouter array assignation dans server.cpp > initReplyTree
 *		problem : le nom des fonctions rentre en conflit avec le nom des define, rajouter ft_ devant
 *
 */

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
