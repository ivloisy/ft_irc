#ifndef FT_IRC_HPP
# define FT_IRC_HPP


# include <algorithm>
# include <bitset>
# include <iostream>
# include <string>
# include <sys/types.h>
# include <sys/socket.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <stdlib.h>
# include <map>
# include <netinet/ip.h>
# include <poll.h>
# include <string.h>
# include <sstream>
# include <stdio.h>
# include <unistd.h>
# include <vector>

# include "Channel.hpp"
# include "reply.hpp"
# include "Server.hpp"
# include "User.hpp"

#define OPER_PASS	"hackme"
#define OPER_NAME	"admin"

using namespace std;
using namespace irc;

void	cap_cmd(Server * srv, User * usr, vector<string> params);
void	die_cmd(Server * srv, User * usr, vector<string> params);
void	join_cmd(Server * srv, User * usr, vector<string> params);
void	list_cmd(Server * srv, User * usr, vector<string> params);
void	mode_cmd(Server * srv, User * usr, vector<string> params);
void	msg_cmd(Server * srv, User * usr, vector<string> params);
void	names_cmd(Server * srv, User * usr, vector<string> params);
void	nick_cmd(Server * srv, User * usr, vector<string> params);
void	notice_cmd(Server * srv, User * usr, vector<string> params);
void	oper_cmd(Server * srv, User * usr, vector<string> params);
void	part_cmd(Server * srv, User * usr, vector<string> params);
void	pass_cmd(Server * srv, User * usr, vector<string> params);
void	ping_cmd(Server * srv, User * usr, vector<string> params);
void	pong_cmd(Server * srv, User * usr, vector<string> params);
void	privmsg_cmd(Server * srv, User * usr, vector<string> params);
void	quit_cmd(Server * srv, User * usr, vector<string> params);
void	user_cmd(Server * srv, User * usr, vector<string> params);
void	wallops_cmd(Server * srv, User * usr, vector<string> params);
void	whois_cmd(Server * srv, User * usr, vector<string> params);

// void	cap_cmd();
// void	die_cmd();
// void	join_cmd();
// void	list_cmd();
// void	mode_cmd();
// void	msg_cmd();
// void	names_cmd();
// void	nick_cmd();
// void	notice_cmd();
// void	oper_cmd();
// void	part_cmd();
// void	pass_cmd();
// void	ping_cmd();
// void	pong_cmd();
// void	privmsg_cmd();
// void	quit_cmd();
// void	rehash_cmd();
// void	restart_cmd();
// void	squit_cmd();
// void	user_cmd();
// void	wallops_cmd();
string ft_reply(string servername, string code, string nick, string message);


#endif
