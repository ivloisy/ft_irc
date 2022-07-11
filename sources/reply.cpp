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

// string ft_ERR_NOSUCHNICK() { return (nickname + " :No such nick/channel"); }
// string ft_ERR_NOSUCHSERVER() { return (server + " :No such server"); }
// string ft_ERR_NOSUCHCHANNEL() { return (channel + " :No such channel"); }
// string ft_ERR_CANNOTSENDTOCHAN() { return (channel + " :Cannot send to channel"); }
// string ft_ERR_TOOMANYCHANNELS() { return (channel + " :You have joined too many channels"); }
// string ft_ERR_WASNOSUCHNICK() { return (nickname + " :There was no such nickname"); }
// string ft_ERR_TOOMANYTARGETS() { return (target + " :Duplicate recipients. No message delivered"); }
// string ft_ERR_NOSUCHSERVICE() { return (service + " :No such service"); }
// string ft_ERR_NOORIGIN() { return (":No origin specified"; }
// string ft_ERR_NORECIPIENT() { return (":No recipient given (" + command + ")"); }
// string ft_ERR_NOTEXTTOSEND() { return (":No text to send"); }
// string ft_ERR_NOTOPLEVEL() { return (mask + " :No toplevel domain specified"); }
// string ft_ERR_WILDTOPLEVEL() { return (mask + " :Wildcard in toplevel domain"); }
// string ft_ERR_BADMASK() { return (mask + " :Bad Server/host mask"); }
// string ft_ERR_UNKNOWNCOMMAND() { return (command + " :Unknown command"); }
// string ft_ERR_NOMOTD() { return (":MOTD File is missing"); }
// string ft_ERR_NOADMININFO() { return (server + " :No administrative info available"); }
// string ft_ERR_FILEERROR() { return (":File error doing " + op + " on " + file); }
// string ft_ERR_NONICKNAMEGIVEN() { return (":No nickname given"); }
// string ft_ERR_ERRONEUSNICKNAME() { return (srv->getNickName() + " :Erroneus nickname"); }
string ft_ERR_NICKNAMEINUSE(Server *srv, User *from, User *to) { (void)srv; (void)to; return (from->getNickName() + " :Nickname is already in use"); }
// string ft_ERR_NICKCOLLISION() { return (nick + " :Nickname collision KILL"); }
// string ft_ERR_USERNOTINCHANNEL() { return (nick + " " + channel + " :They aren't on that channel"); }
// string ft_ERR_NOTONCHANNEL() { return (channel + " :You're not on that channel"); }
// string ft_ERR_USERONCHANNEL() { return (user + " " + channel + " :is already on channel"); }
// string ft_ERR_NOLOGIN() { return (user + " :User not logged in"); }
// string ft_ERR_SUMMONDISABLED() { return (":SUMMON has been disabled"); }
// string ft_ERR_USERSDISABLED() { return (":USERS has been disabled"); }
// string ft_ERR_NOTREGISTERED() { return (":You have not registered"); }
// string ft_ERR_NEEDMOREPARAMS() { return (command + " :Not enough parameters"); }
// string ft_ERR_ALREADYREGISTRED() { return (":You may not reregister"); }
// string ft_ERR_NOPERMFORHOST() { return (":Your host isn't among the privileged"); }
// string ft_ERR_PASSWDMISMATCH() { return (":Password incorrect"); }
// string ft_ERR_YOUREBANNEDCREEP() { return (":You are banned from this server"); }
// string ft_ERR_KEYSET() { return (channel + " :Channel key already set"); }
// string ft_ERR_CHANNELISFULL() { return (channel + " :Cannot join channel (+l)"); }
// string ft_ERR_UNKNOWNMODE() { return (c + " :is unknown mode char to me"); }
// string ft_ERR_INVITEONLYCHAN() { return (channel + " :Cannot join channel (+i)"); }
// string ft_ERR_BANNEDFROMCHAN() { return (channel + " :Cannot join channel (+b)"); }
// string ft_ERR_BADCHANNELKEY() { return (channel + " :Cannot join channel (+k)"); }
// string ft_ERR_BADCHANMASK() { return (channel + " :Bad Channel Mask"); }
// string ft_ERR_NOCHANMODES() { return (channel + " :Channel doesn't support modes"); }
// string ft_ERR_BANLISTFULL() { return (channel + " :Channel list is full"); }
// string ft_ERR_NOPRIVILEGES() { return (":Permission Denied- You're not an IRC operator"); }
// string ft_ERR_CANTKILLSERVER() { return (":You cant kill a server!"); }
// string ft_ERR_RESTRICTED() { return (":Your connection is restricted!"); }
// string ft_ERR_CHANOPRIVSNEEDED() { return (channel + " :You're not channel operator"); }
// string ft_ERR_UNIQOPPRIVSNEEDED() { return (":You're not the original channel operator"); }
// string ft_ERR_NOOPERHOST() { return (":No O-lines for your host"); }
// string ft_ERR_UMODEUNKNOWNFLAG() { return (":Unknown MODE flag"); }
// string ft_ERR_USERSDONTMATCH() { return (":Cant change mode for other users"); }
string ft_NTC_NICK(Server * srv, User * from, User * to) { (void)srv; (void)to; return ("NICK :" + from->getNickName()); }
string ft_NTC_MODE(Server * srv, User * from, User * to) { (void)srv; (void)to; return ("MODE " + from->getNickName() + " :" /*+ from->getModeString()*/); }
string ft_NTC_JOIN(Server * srv, User * from, User * to) { (void)srv; (void)to; return ("JOIN :" + from->getCurrentChannelName()); }
string ft_NTC_PART(Server * srv, User * from, User * to) { (void)srv; (void)to; return ("PART :" + from->getCurrentChannelName()); }
string ft_NTC_PART_MSG(Server * srv, User * from, User * to) { (void)srv; (void)to; return ("PART " + from->getCurrentChannelName() + " :" + from->getMsg()); }
string ft_NTC_PRIVMSG(Server * srv, User * from, User * to) { (void)srv; (void)to; return ("PRIVMSG " + to->getNickName() + " " + from->getMsg()); }
string ft_NTC_NOTICE(Server * srv, User * from, User * to) { (void)srv; (void)to; return ("NOTICE " + to->getNickName() + " " + from->getMsg()); }
string ft_NTC_QUIT(Server * srv, User * from, User * to) { (void)srv; (void)to; return (" QUIT :Quit: " + from->getMsg()); }
string ft_NTC_TOPIC(Server * srv, User * from, User * to) { (void)srv; (void)to; return ("TOPIC " + from->getCurrentChannelName() + " :" + "topic"); }
string ft_NTC_CHANMODE(Server * srv, User * from, User * to) { (void)srv; (void)to; return ("MODE " + from->getCurrentChannelName() + " :" + "mode"); }
string ft_NTC_CHANMODE_ARG(Server * srv, User * from, User * to) { (void)srv; (void)to; return ("MODE " + from->getCurrentChannelName() + " " + "mode" + " :" + "arg"); }
string ft_NTC_KICK(Server * srv, User * from, User * to) { (void)srv; (void)to; return ("KICK " + from->getCurrentChannelName()  + " " + "usr" + " " + "reason"); }
string ft_NTC_INVITE(Server * srv, User * from, User * to) { (void)srv; (void)from; (void)to; return ("INVITE usr :channel"); }

void 	Server::initReplyTree()
{
	map_rep["001"] = ft_RPL_WELCOME;
	map_rep["002"] = ft_RPL_YOURHOST;
	map_rep["003"] = ft_RPL_CREATED;
	map_rep["004"] = ft_RPL_MYINFO;
	map_rep["311"] = ft_RPL_WHOISUSER;
	map_rep["433"] = ft_ERR_NICKNAMEINUSE;
	map_rep["666"] = ft_NTC_NICK;
	map_rep["667"] = ft_NTC_MODE;
	map_rep["668"] = ft_NTC_JOIN;
	map_rep["669"] = ft_NTC_PART;
	map_rep["670"] = ft_NTC_PART_MSG;
	map_rep["671"] = ft_NTC_PRIVMSG;
	map_rep["672"] = ft_NTC_NOTICE;
	map_rep["673"] = ft_NTC_QUIT;
	map_rep["674"] = ft_NTC_TOPIC;
	map_rep["675"] = ft_NTC_CHANMODE;
	map_rep["676"] = ft_NTC_CHANMODE_ARG;
	map_rep["677"] = ft_NTC_KICK;
	map_rep["678"] = ft_NTC_INVITE;
}

void 	Server::ft_reply(User * from, User * to, string code)
{
	string ret = ":";
	ret += _serverName;
	ret += " ";
	ret += code;
	ret += " ";
	ret += map_rep.find(code)->second(this, from, to);
	ret += "\r\n";
	sendBuffer(from, ret);
}


string ben_reply(/*string prefix, */string servername, string code, string nick, string message)
{
	string ret = /*prefix + */":";
	ret += servername;
	ret += " ";
	ret += code;
	ret += " ";
	ret += nick;
	ret += " :";
	ret += message;
	ret += "\r\n";
	return (ret);
}
