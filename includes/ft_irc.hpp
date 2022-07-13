#ifndef FT_IRC_HPP
# define FT_IRC_HPP

# include <algorithm>
# include <arpa/inet.h>
# include <bitset>
# include <iostream>
# include <string>
# include <sys/types.h>
# include <sys/socket.h>
# include <netinet/in.h>
# include <stdlib.h>
# include <map>
# include <netinet/ip.h>
# include <fcntl.h>
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

# define OPER_PASS		"hackme"
# define OPER_NAME		"admin"
# define SERVER_NAME	"surLeFil"

# define RESET			"\033[0m"
# define BLACK			"\033[30m"
# define RED			"\033[31m"
# define GREEN			"\033[32m"
# define YELLOW			"\033[33m"
# define BLUE			"\033[34m"
# define MAGENTA		"\033[35m"
# define LMAGENTA		"\033[45m"
# define CYAN			"\033[36m"
# define WHITE			"\033[37m"
# define BOLDBLACK		"\033[1m\033[30m"
# define BOLDRED		"\033[1m\033[31m"
# define BOLDGREEN		"\033[1m\033[32m"
# define BOLDYELLOW		"\033[1m\033[33m"
# define BOLDBLUE		"\033[1m\033[34m"
# define BOLDMAGENTA	"\033[1m\033[35m"
# define BOLDCYAN		"\033[1m\033[36m"
# define BOLDWHITE		"\033[1m\033[37m"

using namespace std;
using namespace irc;

void	cap_cmd(Server & srv, User & usr, vector<string> params);
void	die_cmd(Server & srv, User & usr, vector<string> params);
void	join_cmd(Server & srv, User & usr, vector<string> params);
void	kick_cmd(Server & srv, User & usr, vector<string> params);
void	list_cmd(Server & srv, User & usr, vector<string> params);
void	mode_cmd(Server & srv, User & usr, vector<string> params);
void	msg_cmd(Server & srv, User & usr, vector<string> params);
void	names_cmd(Server & srv, User & usr, vector<string> params);
void	nick_cmd(Server & srv, User & usr, vector<string> params);
void	notice_cmd(Server & srv, User & usr, vector<string> params);
void	oper_cmd(Server & srv, User & usr, vector<string> params);
void	part_cmd(Server & srv, User & usr, vector<string> params);
void	pass_cmd(Server & srv, User & usr, vector<string> params);
void	ping_cmd(Server & srv, User & usr, vector<string> params);
void	pong_cmd(Server & srv, User & usr, vector<string> params);
void	privmsg_cmd(Server & srv, User & usr, vector<string> params);
void	quit_cmd(Server & srv, User & usr, vector<string> params);
//void	squery_cmd(Server & srv, User & usr, vector<string> params);
void	user_cmd(Server & srv, User & usr, vector<string> params);
void	topic_cmd(Server & srv, User & usr, vector<string> params);
void	wallops_cmd(Server & srv, User & usr, vector<string> params);
void	whois_cmd(Server & srv, User & usr, vector<string> params);
void	invite_cmd(Server & srv, User & usr, vector<string> params);

string	isDouble(vector<string> str);

#endif
