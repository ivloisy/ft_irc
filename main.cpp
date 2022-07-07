//#include "../includes/ft_irc.hpp"

# include <iostream>
# include <cstring>
# include <string.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/socket.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <stdlib.h>
# include <unistd.h>
# include <string>
# include <list>
# include <fcntl.h>
# include <poll.h>

#include <sys/select.h>
#include <sys/time.h>
#include <map>
#include <string>
#include <vector>

#include "./includes/Server.hpp"
#include "./includes/User.hpp"
#include "./includes/Config.hpp"
#include "./includes/Command.hpp"
#include "./includes/ft_irc.hpp"
//#include "../includes/Message.hpp"

using namespace std;
using namespace irc;


typedef void (*pointer_function)(void);



map<string, pointer_function>					init_map_cmd()
{
	map<string, pointer_function>		map_cmd;

	map_cmd["CAP"] 		= 	cap_cmd;
	map_cmd["DIE"] 		= 	user_cmd;
	map_cmd["JOIN"] 	= 	join_cmd;
	map_cmd["LIST"] 	= 	list_cmd;
	map_cmd["MODE"] 	= 	mode_cmd;
	map_cmd["MSG"] 		= 	msg_cmd;
	map_cmd["NAMES"] 	= 	names_cmd;
	map_cmd["NICK"] 	=	nick_cmd;
	map_cmd["NOTICE"] 	= 	notice_cmd;
	map_cmd["OPER"] 	= 	oper_cmd;
	map_cmd["PART"] 	=	part_cmd;
	map_cmd["PASS"] 	= 	pass_cmd;
	map_cmd["PING"] 	= 	ping_cmd;
	map_cmd["PONG"] 	= 	pong_cmd;
	map_cmd["PRIVMSG"] 	=	privmsg_cmd;
	map_cmd["QUIT"] 	=	quit_cmd;
	map_cmd["REHASH"] 	= 	rehash_cmd;
	map_cmd["RESTART"] 	= 	restart_cmd;
	map_cmd["SQUIT"] 	= 	squit_cmd;
	map_cmd["USER"] 	= 	user_cmd;
	map_cmd["WALLOPS"] 	= 	wallops_cmd;

	return (map_cmd);
}


void ft_run()
{
	char buffer[512];
	Server serv;
	int select_ret, fd, test;
	int fd_count = 1;
	struct pollfd			_poll[1025];
	_poll[0].fd = serv.getFdServer();
	_poll[0].events = POLLIN;
	int fin = 0;


	while (serv.getState() && fin < 10)
	{
		fin++;
		cout << "fdserver = " << serv.getFdServer() << " " << "Connect to server..." << endl;
		test = 0;

		select_ret = poll(_poll, fd_count, -1);

		if (select_ret < 0)
		{
			perror("Select failed :");
			break ;
		}
		if ((select_ret > 0))
		{
			for (int x = 0; x < fd_count; x++)
			{
				if (_poll[x].revents & POLLIN)
				{
					fd = _poll[x].fd;
					if (_poll[x].fd == serv.getFdServer())
					{
						if ((fd = serv.acceptUser(serv.getSize())))
						{
							_poll[fd_count].fd = fd;
							_poll[fd_count].events = POLLIN;
							test = 1;
							serv.setUpFdMax(fd);
							fd_count++;
						}
						else
						{
							perror("Accept failed: ");
							break;
						}
					}
					if (recv(fd, &buffer, 255, 0) >= 1)
					{
						std::cout << "BUFFER: = " << buffer << std::endl;
						serv.parse_buffer_command(buffer, fd);
						serv.print_param();
						// serv.exec_command();
					}
					if (test == 1)
						break ;
				}
			}
		}
		else
			perror("There were select failures: ");
	}
	// serv.closeUser(serv.getUser(4));
	close(serv.getFdServer());
}

int main(int argc, char **argv)
{
	(void)argv;
	map<string, pointer_function>		map_cmd = init_map_cmd();
	if (argc == 2) // without password
	{
		ft_run();
		cout << "sortie propre" << endl;
	}
	// else if (argc == 3) //with password
	// {
	//
	// }
	else
	{
		cout << "error wrong number arguments" << endl;
	}
	return 0;
}
