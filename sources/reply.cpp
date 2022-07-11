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

string ft_RPL_WELCOME(Server * srv, User * from, User * to) { (void)srv; (void)to; return (":Welcome to the Internet Relay Network " + from->getPrefix()); }
string ft_RPL_YOURHOST(Server * srv, User * from, User * to) { (void)from; (void)to; return (":Your host is " + srv->getServerName() + ", running version " /*+ srv->getVersion()*/); }
string ft_RPL_CREATED(Server * srv, User * from, User * to) { (void)srv; (void)to; (void)from; return (":This server was created ");} //function to get date); }
string ft_RPL_MYINFO(Server * srv, User * from, User * to) { (void)from; (void)to; return (srv->getServerName() + " " /*+ srv->getVersion()*/  + " io 0o"); }// + //availables user modes + " " + //available channel modes); }

string	ft_RPL_WHOISUSER(Server * srv, User * from, User * to) { (void)srv; (void)to; return (from->getNickName() + " " + from->getUserName() + " " + from->getHostname() + " * :" + from->getRealName()); }
//string RPL_WHOISSERVER(User * usr) { return (usr->getNickname() + " " + srv->getServername() + " :" + server info); }
//string RPL_WHOISOPERATOR(User * usr) { return (usr->getNickName() + " :is an IRC operator"); }
//string RPL_WHOISIDLE(User * usr) { return (usr->getNickName() + " " + integer + " :seconds idle"); }
//string RPL_ENDOFWHOIS(User * usr) { return (usr->getNickName() + " :End of /WHOIS list"); }
//string RPL_WHOISCHANNELS(User * usr) {
//		result += usr->getNickName() + " :" + (*it)->getChannelName() + "\n";
//}
