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
// # include "Message.hpp"
# include "Config.hpp"
# include "Command.hpp"

void	cap_cmd();
void	die_cmd();
void	join_cmd();
void	list_cmd();
void	mode_cmd();
void	msg_cmd();
void	names_cmd();
void	nick_cmd();
void	notice_cmd();
void	oper_cmd();
void	part_cmd();
void	pass_cmd();
void	ping_cmd();
void	pong_cmd();
void	privmsg_cmd();
void	quit_cmd();
void	rehash_cmd();
void	restart_cmd();
void	squit_cmd();
void	user_cmd();
void	wallops_cmd();
string ft_reply(string code, string message);


#endif
