//
// Created by user42 on 27/06/22.
//

#include "ft_irc.hpp"
#include "Server.hpp"

/************* USELESS FOR THE MOMENT *********************/

#ifndef FT_IRC_REPLY_HPP
#define FT_IRC_REPLY_HPP

using namespace irc;
using namespace std;

/*Command responses */

# define RPL_WELCOME "001"
# define RPL_YOURHOST "002"
# define RPL_CREATED "003"
# define RPL_MYINFO "004"
# define RPL_NOTOPIC "331"
# define RPL_NAMREPLY "353"
# define RPL_ENDOFNAMES "366"

/* Error Replies */

# define ERR_NOSUCHNICK "401"
# define ERR_NOSUCHSERVER "402"
# define ERR_NOSUCHCHANNEL "403"
# define ERR_CANNOTSENDTOCHAN "404"
# define ERR_TOOMANYCHANNELS "405"
# define ERR_WASNOSUCHNICK "406"
# define ERR_TOOMANYTARGETS "407"
# define ERR_NOSUCHSERVICE "408"
# define ERR_NOORIGIN "409"
# define ERR_NORECIPIENT "411"
# define ERR_NOTEXTTOSEND "412"
# define ERR_NOTOPLEVEL "413"
# define ERR_WILDTOPLEVEL "414"
# define ERR_BADMASK "415"
# define ERR_UNKNOWNCOMMAND "421"
# define ERR_NOMOTD "422"
# define ERR_NOADMININFO "423"
# define ERR_FILEERROR "424"
# define ERR_NONICKNAMEGIVEN "431"
# define ERR_ERRONEUSNICKNAME "432"
# define ERR_NICKNAMEINUSE "433"
# define ERR_NICKCOLLISION "436"
# define ERR_UNAVAILRESOURCE "437"
# define ERR_USERNOTINCHANNEL "441"
# define ERR_NOTONCHANNEL "442"
# define ERR_USERONCHANNEL "443"
# define ERR_NOLOGIN "444"
# define ERR_SUMMONDISABLED "445"
# define ERR_USERSDISABLED "446"
# define ERR_NOTREGISTERED "451"
# define ERR_NEEDMOREPARAMS "461"
# define ERR_ALREADYREGISTRED "462"
# define ERR_NOPERMFORHOST "463"
# define ERR_PASSWDMISMATCH "464"
# define ERR_YOUREBANNEDCREEP "465"
# define ERR_YOUWILLBEBANNED "466"
# define ERR_KEYSET "467"
# define ERR_CHANNELISFULL "471"
# define ERR_UNKNOWNMODE "472"
# define ERR_INVITEONLYCHAN "473"
# define ERR_BANNEDFROMCHAN "474"
# define ERR_BADCHANNELKEY "475"
# define ERR_BADCHANMASK "476"
# define ERR_NOCHANMODES "477"
# define ERR_BANLISTFULL "478"
# define ERR_NOPRIVILEGES "481"
# define ERR_CHANOPRIVSNEEDED "482"
# define ERR_CANTKILLSERVER "483"
# define ERR_RESTRICTED "484"
# define ERR_UNIQOPPRIVSNEEDED "485"
# define ERR_NOOPERHOST "491"
# define ERR_UMODEUNKNOWNFLAG "501"
# define ERR_USERSDONTMATCH "502"

# define NTC_NICK(to) ("NICK :" + from->getNickName())
# define NTC_MODE(from) ("MODE " + from->getNickName() + " :" /*+ from->getModeString()*/); }
# define NTC_JOIN(from)  ("JOIN :" + from->getCurrentChannelName()); }
# define NTC_PART(from) ("PART :" + from->getCurrentChannelName()); }
# define NTC_PART_MSG(from) ("PART " + from->getCurrentChannelName() + " :" + from->getMsg()); }
# define NTC_PRIVMSG(from) ("PRIVMSG " + to->getNickName() + " " + from->getMsg()); }
# define NTC_NOTICE(from) ("NOTICE " + to->getNickName() + " " + from->getMsg()); }
# define NTC_QUIT(to) (" QUIT :Quit: " + from->getMsg()); }
# define NTC_TOPIC(to) ("TOPIC " + from->getCurrentChannelName() + " :" + "topic"); }
# define NTC_CHANMODE(to) ("MODE " + from->getCurrentChannelName() + " :" + "mode"); }
# define NTC_KICK(to) ("MODE " + from->getCurrentChannelName() + " " + "mode" + " :" + "arg"); }
# define NTC_INVITE(to) ("KICK " + from->getCurrentChannelName()  + " " + "usr" + " " + "reason"); }
# define NTC_CHANMODE_ARG(to) ("INVITE usr :channel"); }

string 	ft_RPL_WELCOME(Server * srv, User * from, User * to);
string 	ft_RPL_YOURHOST(Server * srv, User * from, User * to);
string 	ft_RPL_CREATED(Server * srv, User * from, User * to);
string 	ft_RPL_MYINFO(Server * srv, User * from, User * to);

#endif //FT_IRC_REPLY_HPP
