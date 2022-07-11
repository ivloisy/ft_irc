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

//usr == from
string ft_RPL_WELCOME(Server * srv, User * from, User * to) { (void)srv; (void)to; return (":Welcome to the Internet Relay Network " + from->getPrefix()); }
string ft_RPL_YOURHOST(Server * srv, User * from, User * to) { (void)from; (void)to; return (":Your host is " + srv->getServerName() + ", running version " /*+ srv->getVersion()*/); }
string ft_RPL_CREATED(Server * srv, User * from, User * to) { (void)srv; (void)to; (void)from; return (":This server was created ");} //function to get date); }
string ft_RPL_MYINFO(Server * srv, User * from, User * to) { (void)from; (void)to; return (srv->getServerName() + " " /*+ srv->getVersion()*/  + " io 0o"); }// + //availables user modes + " " + //available channel modes); }
// string ft_RPL_WELCOME(Server * srv, User * from, User * to) { (void)srv; (void)to; return (from->getNickName() + " :Welcome to the Internet Relay Network " + from->getNickName()); }
// string ft_RPL_YOURHOST(Server * srv, User * from, User * to) { (void)from; (void)to; return (from->getNickName() + " :Your host is " + srv->getServerName() + ", running version " /*+ srv->getVersion()*/); }
// string ft_RPL_CREATED(Server * srv, User * from, User * to) { (void)srv; (void)to; (void)from; return (from->getNickName() + " :This server was created ");} //function to get date); }
// string ft_RPL_MYINFO(Server * srv, User * from, User * to) { (void)from; (void)to; return (from->getNickName() + " :" + srv->getServerName() + " " /*+ srv->getVersion()*/  + " io 0o"); }// + //availables user modes + " " + //available channel modes); }

//USELESS string RPL_BOUNCE(Server * srv) { return (":Try server " + srv->getServerName() + ", port " + //int to string > srv->getPortNum()); }
//USELESS string RPL_USERHOST(string reply_list) { return (":" + //print all replies); }
//USELESS string RPL_ISON(string nick_list) { return (":" + nick_list); }
//USELESS string RPL_AWAY(User * usr, Server * srv) { return (usr->nickName() + " :" + usr->getAwayMsg()); }
//USELESS string RPL_UNAWAY() { return (":You are no longer marked as being away"); }
//USELESS string RPL_NOWAWAY() { return (":You have been marked as being away"); }
string	ft_RPL_WHOISUSER(Server * srv, User * from, User * to) { (void)srv; (void)to; return (from->getNickName() + " " + from->getUserName() + " " + from->getHostname() + " * :" + from->getRealName()); }
//string RPL_WHOISSERVER(User * usr) { return (usr->getNickname() + " " + srv->getServername() + " :" + server info); }
//string RPL_WHOISOPERATOR(User * usr) { return (usr->getNickName() + " :is an IRC operator"); }
//string RPL_WHOISIDLE(User * usr) { return (usr->getNickName() + " " + integer + " :seconds idle"); }
//string RPL_ENDOFWHOIS(User * usr) { return (usr->getNickName() + " :End of /WHOIS list"); }
//string RPL_WHOISCHANNELS(User * usr) {
//		result += usr->getNickName() + " :" + (*it)->getChannelName() + "\n";
//}
//USELESS string RPL_WHOWASUSER(User * usr) { return (usr->getMickName() + " " + usr->getUserName() + " " + usr->getHostName() + " * :" + usr->getRealName()); }
//USELESS string RPL_ENDOFWHOWAS(User * usr) { return (usr->getNickName() + " :End of WHOWAS"); }
//USELESS string RPL_LISTSTART() { return ("Channel :Users  Name"); }
//USELESS string RPL_LIST(Server * srv) {
//	string result;
//	vector<Channel *> chans = srv->getChannels();
//	for (vector<Channel *>::iterator it = chans.begin(); it != chans.end(); it++)
//		result += (it*)->getChannelName() + " #" + (*it)->getNbUsers() + " :" + (*it)->getTopic() + "\n"
//	return (result); }
//USELESS string RPL_LISTEND() { return (":End of /LIST"); }
//string RPL_UNIQOPIS(User * usr) { return (usr->getChannelName() + " " + usr->getNickName()); }
//string RPL_CHANNELMODEIS(User * usr) { return (usr->getChannelName() + " +" + usr->getMode()); }
//USELESS string RPL_NOTOPIC(User * user) { return (usr->getCurrentChannel()->getChannelName() + " :No topic is set"); }
//USELESS string RPL_TOPIC(User * usr) { return (usr->getCurrentChannel()->getChannelName() + " :" + usr->getTopic()); }
//USELESS string RPL_INVITING(User * usr) { return (usr->getNickName() + " " + // invited nick); })
//USELESS string RPL_SUMMONING(User * usr) { return (//summoned user + " :Summoning user to IRC"); }
//USELESS string RPL_INVITELIST(User * usr) {
//	string result;
//	vector<Channel *>::iterator chans = srv->getChannels();
//	for (vector<Channel *>::iterator it = chans.begin(); it != chans.end(); it++)
//		result += srv->getChannels() + " " + invite mask) + "\n";
//	return (result);
//}
//USELESS string RPL_ENDOFINVITELIST(string channel) { return (channel + " :End of channel invite list"); }
//USELESS string RPL_EXCEPTLIST(string channel, string mask) { return (channel + " " + mask); }
//USELESS string RPL_ENDOFEXCEPTLIST(string channel) { return (channel + " :End of channel exception list"); }
//USELESS string RPL_VERSION(Server * srv) { return (srv->getVersion() + " " + srv->getServerName + " :" + comments); }
//USELESS string RPL_WHOREPLY(string channel, string user, string host, string server, string nick, string state, string real) { return (channel + " " + user + " " + host + " " + server + " " + nick + " " + state + " :0 " + real; }
//USELESS string RPL_ENDOFWHO(string name) { return (name + " :End of /WHO list"); }
//string RPL_NAMREPLY(User * usr) {
//
//	return (chan_mod + " " + channel + " :" + nick_list);
//}
//string RPL_ENDOFNAMES() { return (channel + " :End of /NAMES list"); }
//USELESS string RPL_LINKS(string mask, string server, string hopcount, string info) { return (mask + " " + server + " :" + hopcount + " " + info); }
//USELESS string RPL_ENDOFLINKS(string mask) { return (mask + " :End of /LINKS list"); }
//string RPL_BANLIST() { return (channel + " " + banip); }
//string RPL_ENDOFBANLIST() { return (channel + " :End of channel ban list"); }
//USELESS string RPL_INFO(string string) { return (":" + string); }
//USELESS string RPL_ENDOFINFO() { return (":End of /INFO list"); }
//USELESS string RPL_MOTDSTART(string server) { return (":- " + server + " Message of the day - "); }
//USELESS string RPL_MOTD(string text) { return (":- " + text); }
//USELESS string RPL_ENDOFMOTD() { return (":End of /MOTD command"); }
//string RPL_YOUREOPER() { return (":You are now an IRC operator"); }
//USELESS string RPL_REHASHING(string file) { return (file + " :Rehashing"); }
//USELESS string RPL_YOURESERVICE(string nick) { return (":You are service " + nick); }
//USELESS string RPL_TIME(string server, string time) { return (server + " :" + time); }
//USELESS string RPL_USERSSTART() { return (":UserID Terminal Host"); }
//USELESS string RPL_USERS() { return (":%-8s %-9s %-8s"); }
//USELESS string RPL_ENDOFUSERS() { return (":End of users"); }
//USELESS string RPL_NOUSERS() { return (":Nobody logged in"); }
//USELESS string RPL_TRACELINK(string version, string destination, string server) { return ("Link " + srv->getVersion() + " " + destination + " " + server); }
//USELESS string RPL_TRACECONNECTING(string class1, string server) { return ("Try. " + class1 + " " + server); }
//USELESS string RPL_TRACEHANDSHAKE(string class1, string server) { return ("H.S. " + class1 + " " + server); }
//USELESS string RPL_TRACEUNKNOWN(string class1, string ip) { return ("???? " + class1 + " " + ip); }
//USELESS string RPL_TRACEOPERATOR(string class1, string nick) { return ("Oper " + class1 + " " + nick); }
//USELESS string RPL_TRACEUSER(string class1, string nick) { return ("User " + class1 + " " + nick); }
//USELESS string RPL_TRACESERVER(string class1, string int1, string int2, string server, string nick, string user, string host) { return ("Serv " + class1 + " " + int1 + "S " + int2 + "C " + server + " " + nick + "!" + user + "@ " + host); }
//USELESS string RPL_TRACESERVICE() return ("Service <class> <name> <type> <active type>")
//USELESS string RPL_TRACENEWTYPE(string type, string name) { return (type + " 0 " + name); }
//USELESS string RPL_TRACECLASS( "Class <class> <count>")
//USELESS string RPL_TRACELOG(string file, string level) { return "File " + file + " " + level); }
//USELESS string RPL_TRACEEND(string server, string version) { return server + " " + version + " :End of TRACE"); }



void 	Server::initReplyTree()
{
	map_rep[RPL_WELCOME] = ft_RPL_WELCOME;
	map_rep[RPL_YOURHOST] = ft_RPL_YOURHOST;
	map_rep[RPL_CREATED] = ft_RPL_CREATED;
	map_rep[RPL_MYINFO] = ft_RPL_MYINFO;

}

void	Server::initErrorTree()
{
	map_err[ERR_NOSUCHNICK] = " :No such nick/channel";
	map_err[ERR_NOSUCHSERVER] = " :No such server";
	map_err[ERR_NOSUCHCHANNEL] = " :No such channel";
	map_err[ERR_CANNOTSENDTOCHAN] = " :Cannot send to channel";
	map_err[ERR_TOOMANYCHANNELS] = " :You have joined too many channels";
	map_err[ERR_WASNOSUCHNICK] =  " :There was no such nickname";
	map_err[ERR_TOOMANYTARGETS] = " :Duplicate recipients. No message delivered";
	map_err[ERR_NOORIGIN] = ":No origin specified";
	map_err[ERR_NORECIPIENT] = ":No recipient given";
	map_err[ERR_NOTEXTTOSEND] = ":No text to send";
	map_err[ERR_NOTOPLEVEL] = " :No toplevel domain specified";
	map_err[ERR_WILDTOPLEVEL] = " :Wildcard in toplevel domain";
	map_err[ERR_BADMASK] = " :Bad Server/host mask";
	map_err[ERR_UNKNOWNCOMMAND] = " :Unknown command";
	map_err[ERR_NOMOTD] = ":MOTD File is missing";
	map_err[ERR_NOADMININFO] = " :No administrative info available";
	map_err[ERR_NONICKNAMEGIVEN] = ":No nickname given";
	map_err[ERR_ERRONEUSNICKNAME] = " :Erroneus nickname";
	map_err[ERR_NICKNAMEINUSE] = " :Nickname is already in use";
	map_err[ERR_NICKCOLLISION] = " :Nickname collision KILL";
	map_err[ERR_USERNOTINCHANNEL] = " :You're not on that channel";
	map_err[ERR_NOTONCHANNEL] = " :You're not on that channel";
	map_err[ERR_USERONCHANNEL] = " :is already on channel";
	map_err[ERR_NOLOGIN] = " :User not logged in";
	map_err[ERR_SUMMONDISABLED] = ":SUMMON has been disabled";
	map_err[ERR_USERSDISABLED] = ":USERS has been disabled";
	map_err[ERR_NOTREGISTERED] = ":You have not registered";
	map_err[ERR_NEEDMOREPARAMS] = " :Not enough parameters";
	map_err[ERR_ALREADYREGISTRED] = ":You may not reregister";
	map_err[ERR_NOPERMFORHOST] = ":Your host isn't among the privileged";
	map_err[ERR_PASSWDMISMATCH] = ":Password incorrect";
	map_err[ERR_YOUREBANNEDCREEP] = ":You are banned from this server";
	map_err[ERR_KEYSET] = " :Channel key already set";
	map_err[ERR_CHANNELISFULL] = " :Cannot join channel (+l)";
	map_err[ERR_UNKNOWNMODE] = " :is unknown mode char to me";
	map_err[ERR_INVITEONLYCHAN] = " :Cannot join channel (+i)";
	map_err[ERR_BANNEDFROMCHAN] = " :Cannot join channel (+b)";
	map_err[ERR_BADCHANNELKEY] = " :Cannot join channel (+k)";
	map_err[ERR_BADCHANMASK] = " :Bad Channel Mask";
	map_err[ERR_NOCHANMODES] = " :Channel doesn't support modes";
	map_err[ERR_BANLISTFULL] = " :Channel list is full";
	map_err[ERR_NOPRIVILEGES] = ":Permission Denied- You're not an IRC operator";
	map_err[ERR_CANTKILLSERVER] = ":You cant kill a server!";
	map_err[ERR_RESTRICTED] = ":Your connection is restricted!";
	map_err[ERR_CHANOPRIVSNEEDED] = " :You're not channel operator";
	map_err[ERR_UNIQOPPRIVSNEEDED] = ":You're not the original channel operator";
	map_err[ERR_NOOPERHOST] = ":No O-lines for your host";
	map_err[ERR_UMODEUNKNOWNFLAG] = ":Unknown MODE flag";
	map_err[ERR_USERSDONTMATCH] = ":Cant change mode for other users";
}

void 	Server::ft_reply(User * from, User * to, string code)
{
	string ret = ":";
	ret += _serverName;
	ret += " ";
	ret += code;
	ret += " ";
	ret += from->getNickName();
	ret += " ";
	ret += map_rep.find(code)->second(this, from, to);
	ret += "\r\n";
	sendBuffer(from, ret);
}

void	Server::ft_error(User * from, string code, string arg)
{
	string ret = ":";
	ret += _serverName;
	ret += " * "; // arg err[errn]
	ret += code;
	ret += " ";
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
	sendBuffer(to, ret);
}
