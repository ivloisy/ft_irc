//
// Created by user42 on 27/06/22.
//

/************* USELESS FOR THE MOMENT *********************/

#ifndef FT_IRC_REPLY_HPP
# define FT_IRC_REPLY_HPP

# include "Server.hpp"
# include "User.hpp"

using namespace std;
using namespace irc;

string RPL_WELCOME(User * usr);// { return (":Welcome to the Internet Relay Network " + usr->getNickName()); }
string RPL_YOURHOST(User * usr, Server * srv);// { return (":Your host is " + srv->servername + ", running version " + srv->getVersion()); }
string RPL_CREATED(User * usr, Server * srv);// { return (":This server was created " + srv->getDate()); }
string RPL_MYINFO(User * usr );// { return (srv->getServerName() + " " + srv->getVersion() + " ");}// + //availables user modes + " " + //available channel modes); }

string RPL_BOUNCE(Server * srv);//) { return (":Try server " + srv->getServerName() + ", port ");}// + //int to string > srv->getPortNum()); }
string RPL_USERHOST(string reply_list);// { return (":");}// + //print all replies); }
string RPL_ISON(string nick_list);// { return (":" + nick_list); }
string RPL_AWAY(User * usr, Server * srv);// { return (usr->nickName() + " :" + usr->getAwayMsg()); }
string RPL_UNAWAY();// { return (":You are no longer marked as being away"); }
string RPL_NOWAWAY();// { return (":You have been marked as being away"); }
string RPL_WHOISUSER(User * usr);// { return (usr->getNickName() + " " + user (usr->getUserName())? + " " + usr->getHostName() + " * :" + usr->getRealname()); }
string RPL_WHOISSERVER(User * usr);// { return (usr->getNickname() + " " + srv->getServername() + " :" + server info); }
string RPL_WHOISOPERATOR(User * usr);// { return (usr->getNickName() + " :is an IRC operator"); }
string RPL_WHOISIDLE(User * usr);// { return (usr->getNickName() + " " + integer + " :seconds idle"); }
string RPL_ENDOFWHOIS(User * usr);// { return (usr->getNickName() + " :End of /WHOIS list"); }
string RPL_WHOISCHANNELS(User * usr, string channel);// { return (usr->getNickName() + " :" + channel names ?); }
string RPL_WHOWASUSER(string nick, string user, string host, string real);// { return (usr->getMickName() + " " + usr->getUserName() + " " + usr->getHostName() + " * :" + usr->getRealName()); }
string RPL_ENDOFWHOWAS(string nick);// { return (usr->getNickName() + " :End of WHOWAS"); }
string RPL_LISTSTART();// { return ("Channel :Users  Name"); }
string RPL_LIST(string channel, string nbrUser, string topic);// {
	// string result;
	// vector<Channel *> chans = srv->getChannels()
	// for (vector<Channel *>::iterator it = chans.begin(); it != chans.end(); it++)
	// 	result += (it*)->getChannelName() + " #" + (*it)->getNbUsers() + " :" + (*it)->getTopic() + "\n"
	// return (result); }
string RPL_LISTEND();// { return (":End of /LIST"); }
string RPL_UNIQOPIS(string channel, string nick);// { return (channel + " " + nick); }
string RPL_CHANNELMODEIS(string channel, string mode, string params);// { return (channel + " " + mode + " " + params); }
string RPL_NOTOPIC(string channel);// { return (channel + " :No topic is set"); }
string RPL_TOPIC(string channel, string topic);// { return (channel + " :" + topic); }
string RPL_INVITING(string channel, string nick);// { return (nick + " " + channel); })
string RPL_SUMMONING(string user);// { return (user + " :Summoning user to IRC"); }
string RPL_INVITELIST(string channel, string inviter);// { return (channel + " " + inviter); }
string RPL_ENDOFINVITELIST(string channel);// { return (channel + " :End of channel invite list"); }
string RPL_EXCEPTLIST(string channel, string mask);// { return (channel + " " + mask); }
string RPL_ENDOFEXCEPTLIST(string channel);// { return (channel + " :End of channel exception list"); }
string RPL_VERSION(string version, string server, string comments);// { return (version + " " + server + " :" + comments); }
string RPL_WHOREPLY(string channel, string user, string host, string server, string nick, string state, string real);// { return (channel + " " + user + " " + host + " " + server + " " + nick + " " + state + " :0 " + real; }
string RPL_ENDOFWHO(string name);// { return (name + " :End of /WHO list"); }
string RPL_NAMREPLY(string chan_mod, string channel, string nick_list);// { return chan_mod + " " + channel + " :" + nick_list); }
string RPL_ENDOFNAMES(string channel);// { return (channel + " :End of /NAMES list"); }
string RPL_LINKS(string mask, string server, string hopcount, string info);// { return (mask + " " + server + " :" + hopcount + " " + info); }
string RPL_ENDOFLINKS(string mask);// { return (mask + " :End of /LINKS list"); }
string RPL_BANLIST(string channel, string banip);// { return (channel + " " + banip); }
string RPL_ENDOFBANLIST(string channel);// { return (channel + " :End of channel ban list"); }
string RPL_INFO(string string);// { return (":" + string); }
string RPL_ENDOFINFO();// { return (":End of /INFO list"); }
string RPL_MOTDSTART(string server);// { return (":- " + server + " Message of the day - "); }
string RPL_MOTD(string text);// { return (":- " + text); }
string RPL_ENDOFMOTD();// { return (":End of /MOTD command"); }
string RPL_YOUREOPER();// { return (":You are now an IRC operator"); }
string RPL_REHASHING(string file);// { return (file + " :Rehashing"); }
string RPL_YOURESERVICE(string nick);// { return (":You are service " + nick); }
string RPL_TIME(string server, string time);// { return (server + " :" + time); }
string RPL_USERSSTART();// { return (":UserID Terminal Host"); }
string RPL_USERS();// { return (":%-8s %-9s %-8s"); }
string RPL_ENDOFUSERS();// { return (":End of users"); }
string RPL_NOUSERS();// { return (":Nobody logged in"); }
string RPL_TRACELINK(string version, string destination, string server);// { return ("Link " + srv->getVersion() + " " + destination + " " + server); }
string RPL_TRACECONNECTING(string class1, string server);// { return ("Try. " + class1 + " " + server); }
string RPL_TRACEHANDSHAKE(string class1, string server);// { return ("H.S. " + class1 + " " + server); }
string RPL_TRACEUNKNOWN(string class1, string ip);// { return ("???? " + class1 + " " + ip); }
string RPL_TRACEOPERATOR(string class1, string nick);// { return ("Oper " + class1 + " " + nick); }
string RPL_TRACEUSER(string class1, string nick);// { return ("User " + class1 + " " + nick); }
string RPL_TRACESERVER(string class1, string int1, string int2, string server, string nick, string user, string host);// { return ("Serv " + class1 + " " + int1 + "S " + int2 + "C " + server + " " + nick + "!" + user + "@ " + host); }
string RPL_TRACESERVICE();// return ("Service <class> <name> <type> <active type>")
string RPL_TRACENEWTYPE(string type, string name);// { return (type + " 0 " + name); }
string RPL_TRACECLASS( "Class <class> <count>");//
string RPL_TRACELOG(string file, string level);// { return "File " + file + " " + level); }
string RPL_TRACEEND(string server, string version);// { return server + " " + version + " :End of TRACE"); }
string RPL_STATSLINKINFO(string name, string q, string smessages, string sbytes, string rsmessages, string rbytes, string time);// { return (name + " " + q + " " + smessages + " " + sbytes + " " + rsmessages + " " + rbytes + " " + time); }
string RPL_STATSCOMMANDS(string command, string count);// { return (command + " " + count); }
string RPL_ENDOFSTATS(string letter);// { return (letter + " :End of /STATS report"); }
string RPL_STATSUPTIME();// { return (":Server Up %d days %d:%02d:%02d"); }
string RPL_STATSOLINE(string mask, string name);// { return ("O " + mask + " * " + name); }
string RPL_UMODEIS(string mode);// { return (mode); }
string RPL_LUSERCLIENT(string int1, string int2, string int3);// { return (":There are " + int1 + " users and " + int2 + " invisible on " + int3 + " servers"); }
string RPL_LUSEROP(string int1);// { return (int1 + " :operator(s) online"); }
string RPL_LUSERUNKNOWN(string int1);// { return (int1 + " :unknown connection(s)"); }
string RPL_LUSERCHANNELS(string int1);// { return (int1 + " :channels formed"); }
string RPL_LUSERME(string int1, string int2);// { return (":I have " + int1 + " clients and " + int2 + " servers"); }
string RPL_ADMINME(string server);// { return (server + " :Administrative info"); }
string RPL_ADMINLOC1(string info);// { return (":" + info); }
string RPL_ADMINLOC2(string info);// { return (":" + info); }
string RPL_ADMINEMAIL(string info);// { return (":" + info); }
string RPL_TRYAGAIN(string cmd);// { return (cmd + " :Please wait a while and try again."); }
string RPL_NONE();// { return (""); }

/******************************************************************************/
/*                                   4**                                      */
/******************************************************************************/
string ERR_NOSUCHNICK(string nickname);// { return (nickname + " :No such nick/channel"); }
string ERR_NOSUCHSERVER(string server);// { return (server + " :No such server"); }
string ERR_NOSUCHCHANNEL(string channel);// { return (channel + " :No such channel"); }
string ERR_CANNOTSENDTOCHAN(string channel);// { return (channel + " :Cannot send to channel"); }
string ERR_TOOMANYCHANNELS(string channel);// { return (channel + " :You have joined too many channels"); }
string ERR_WASNOSUCHNICK(string nickname);// { return (nickname + " :There was no such nickname"); }
string ERR_TOOMANYTARGETS(string target);// { return (target + " :Duplicate recipients. No message delivered"); }
string ERR_NOSUCHSERVICE(string service);// { return (service + " :No such service"); }
string ERR_NOORIGIN();// { return (":No origin specified"; }
string ERR_NORECIPIENT(string command);// { return (":No recipient given (" + command + ")"); }
string ERR_NOTEXTTOSEND();// { return (":No text to send"); }
string ERR_NOTOPLEVEL(string mask);// { return (mask + " :No toplevel domain specified"); }
string ERR_WILDTOPLEVEL(string mask);// { return (mask + " :Wildcard in toplevel domain"); }
string ERR_BADMASK(string mask);// { return (mask + " :Bad Server/host mask"); }
string ERR_UNKNOWNCOMMAND(string command);// { return (command + " :Unknown command"); }
string ERR_NOMOTD();// { return (":MOTD File is missing"); }
string ERR_NOADMININFO(string server);// { return (server + " :No administrative info available"); }
string ERR_FILEERROR(string op, string file);// { return (":File error doing " + op + " on " + file); }
string ERR_NONICKNAMEGIVEN();// { return (":No nickname given"); }
string ERR_ERRONEUSNICKNAME(string nick);// { return (nick + " :Erroneus nickname"); }
string ERR_NICKNAMEINUSE(string nick);// { return (nick + " :Nickname is already in use"); }
string ERR_NICKCOLLISION(string nick);// { return (nick + " :Nickname collision KILL"); }
string ERR_USERNOTINCHANNEL(string nick, string channel);// { return (nick + " " + channel + " :They aren't on that channel"); }
string ERR_NOTONCHANNEL(string channel);// { return (channel + " :You're not on that channel"); }
string ERR_USERONCHANNEL(string user, string channel);// { return (user + " " + channel + " :is already on channel"); }
string ERR_NOLOGIN(string user);// { return (user + " :User not logged in"); }
string ERR_SUMMONDISABLED();// { return (":SUMMON has been disabled"); }
string ERR_USERSDISABLED();// { return (":USERS has been disabled"); }
string ERR_NOTREGISTERED();// { return (":You have not registered"); }
string ERR_NEEDMOREPARAMS(string command);// { return (command + " :Not enough parameters"); }
string ERR_ALREADYREGISTRED();// { return (":You may not reregister"); }
string ERR_NOPERMFORHOST();// { return (":Your host isn't among the privileged"); }
string ERR_PASSWDMISMATCH();// { return (":Password incorrect"); }
string ERR_YOUREBANNEDCREEP();// { return (":You are banned from this server"); }
string ERR_KEYSET(string channel);// { return (channel + " :Channel key already set"); }
string ERR_CHANNELISFULL(string channel);// { return (channel + " :Cannot join channel (+l)"); }
string ERR_UNKNOWNMODE(string c);// { return (c + " :is unknown mode char to me"); }
string ERR_INVITEONLYCHAN(string channel);// { return (channel + " :Cannot join channel (+i)"); }
string ERR_BANNEDFROMCHAN(string channel);// { return (channel + " :Cannot join channel (+b)"); }
string ERR_BADCHANNELKEY(string channel);// { return (channel + " :Cannot join channel (+k)"); }
string ERR_BADCHANMASK(string channel);// { return (channel + " :Bad Channel Mask"); }
string ERR_NOCHANMODES(string channel);// { return (channel + " :Channel doesn't support modes"); }
string ERR_BANLISTFULL(string channel);// { return (channel + " :Channel list is full"); }
string ERR_NOPRIVILEGES();// { return (":Permission Denied- You're not an IRC operator"); }
string ERR_CANTKILLSERVER();// { return (":You cant kill a server!"); }
string ERR_RESTRICTED();// { return (":Your connection is restricted!"); }
string ERR_CHANOPRIVSNEEDED(string channel);// { return (channel + " :You're not channel operator"); }
string ERR_UNIQOPPRIVSNEEDED();// { return (":You're not the original channel operator"); }
string ERR_NOOPERHOST();// { return (":No O-lines for your host"); }
string ERR_UMODEUNKNOWNFLAG();// { return (":Unknown MODE flag"); }
string ERR_USERSDONTMATCH();// { return (":Cant change mode for other users"); }


/*Command responses */
//
// # define RPL_WELCOME "001"
// # define RPL_YOURHOST "002"
// # define RPL_CREATED "003"
// # define RPL_MYINFO "004"
// # define RPL_NOTOPIC "331"
// # define RPL_NAMREPLY "353"
// # define RPL_ENDOFNAMES "366"
//
// /* Error Replies */
//
// # define ERR_NOSUCHNICK "401"
// # define ERR_NOSUCHSERVER "402"
// # define ERR_NOSUCHCHANNEL "403"
// # define ERR_CANNOTSENDTOCHAN "404"
// # define ERR_TOOMANYCHANNELS "405"
// # define ERR_WASNOSUCHNICK "406"
// # define ERR_TOOMANYTARGETS "407"
// # define ERR_NOSUCHSERVICE "408"
// # define ERR_NOORIGIN "409"
// # define ERR_NORECIPIENT "411"
// # define ERR_NOTEXTTOSEND "412"
// # define ERR_NOTOPLEVEL "413"
// # define ERR_WILDTOPLEVEL "414"
// # define ERR_BADMASK "415"
// # define ERR_UNKNOWNCOMMAND "421"
// # define ERR_NOMOTD "422"
// # define ERR_NOADMININFO "423"
// # define ERR_FILEERROR "424"
// # define ERR_NONICKNAMEGIVEN "431"
// # define ERR_ERRONEUSNICKNAME "432"
// # define ERR_NICKNAMEINUSE "433"
// # define ERR_NICKCOLLISION "436"
// # define ERR_UNAVAILRESOURCE "437"
// # define ERR_USERNOTINCHANNEL "441"
// # define ERR_NOTONCHANNEL "442"
// # define ERR_USERONCHANNEL "443"
// # define ERR_NOLOGIN "444"
// # define ERR_SUMMONDISABLED "445"
// # define ERR_USERSDISABLED "446"
// # define ERR_NOTREGISTERED "451"
// # define ERR_NEEDMOREPARAMS "461"
// # define ERR_ALREADYREGISTRED "462"
// # define ERR_NOPERMFORHOST "463"
// # define ERR_PASSWDMISMATCH "464"
// # define ERR_YOUREBANNEDCREEP "465"
// # define ERR_YOUWILLBEBANNED "466"
// # define ERR_KEYSET "467"
// # define ERR_CHANNELISFULL "471"
// # define ERR_UNKNOWNMODE "472"
// # define ERR_INVITEONLYCHAN "473"
// # define ERR_BANNEDFROMCHAN "474"
// # define ERR_BADCHANNELKEY "475"
// # define ERR_BADCHANMASK "476"
// # define ERR_NOCHANMODES "477"
// # define ERR_BANLISTFULL "478"
// # define ERR_NOPRIVILEGES "481"
// # define ERR_CHANOPRIVSNEEDED "482"
// # define ERR_CANTKILLSERVER "483"
// # define ERR_RESTRICTED "484"
// # define ERR_UNIQOPPRIVSNEEDED "485"
// # define ERR_NOOPERHOST "491"
// # define ERR_UMODEUNKNOWNFLAG "501"
// # define ERR_USERSDONTMATCH "502"

// namespace irc
// {
// 	class Reply {
//
// 	private:
// 		User                        _user;
// 		Server                      _server;
//
// 		std::string                 _prefix;
// 		std::vector<std::string>    _parameters;
// 		std::string                 _trailer;
// 		std::string                 _query;
//
// 	public:
// 		Reply(User user, Server server, std::string msg);
//
// 		User                        getUser();
// 		Server                      getServer();
// 		std::string                 getPrefix();
// 		std::vector<std::string>    getParameters();
// 		std::string                 getTrailer();
// 		std::string                 getQuery();
//
// 	};
// }

#endif //FT_IRC_REPLY_HPP
