#ifndef FT_IRC_HPP
# define FT_IRC_HPP

# include <iostream>
# include <string.h>
# include <sys/types.h>
# include <sys/socket.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <stdlib.h>
# include <unistd.h>

# include <sys/select.h>
# include <sys/time.h>

# include "Server.hpp"
# include "User.hpp"
# include "Config.hpp"
# include "Command.hpp"

using namespace irc;
using namespace std;

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
void	rehash_cmd(Server * srv, User * usr, vector<string> params);
void	restart_cmd(Server * srv, User * usr, vector<string> params);
void	squit_cmd(Server * srv, User * usr, vector<string> params);
void	user_cmd(Server * srv, User * usr, vector<string> params);
void	wallops_cmd(Server * srv, User * usr, vector<string> params);

#endif
