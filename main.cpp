#include "../includes/ft_irc.hpp"

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

#include <sys/select.h>
#include <sys/time.h>

#include "./includes/Server.hpp"
#include "./includes/User.hpp"
#include "./includes/Message.hpp"
#include "./includes/Config.hpp"
#include "./includes/Command.hpp"
//#include "../includes/Message.hpp"

//using namespace std;
using namespace irc;
/*
typedef void (*func_cmd)(void); //

std::map<std::string, func_cmd> init_map()
{
	std::map<std::string, func_cmd> result;

	result.push_back()
}*/
/*
typedef struct	s_commands
{
	std::string	command;
	void	(*func_cmd)(std::string &buf, std::list<User>::iterator it_user);
}				t_commands;*/
/*
typedef std::map<std::string, void (*)(std::string &buf, User *it_user, Server &serv)> map_cmd;

map_cmd init_map_cmd(void)
{
	map_cmd cmd;

	//cmd["CAP"] = cap_cmd();
	//cmd["NICK"] = nick_cmd();
	//cmd["PONG"] = pong_cmd();
	//cmd["USER"] = user_cmd();


	return (cmd);
}*/

void copy_buffer(std::string &dest, std::string const &src)
{
	for (int i = 0; i < src.length(); i++)
		dest.push_back(src.at(i));
}

void save_sets(fd_set *src, fd_set *dst, int fdMax)
{
	int x = 0;
	while (x <= fdMax)
	{
		if (FD_ISSET(x, src) && !FD_ISSET(x, dst))
			FD_SET(x, dst);
		x++;
	}
}

void reinit_set(fd_set &read, fd_set &write, fd_set &err, fd_set &tmp, int fdMax)
{
	int x = 0;
	while (x <= fdMax)
	{
		if (FD_ISSET(x, &tmp))
		{
			if (!FD_ISSET(x, &read))
				FD_SET(x, &read);
			if (!FD_ISSET(x, &write))
				FD_SET(x, &write);
			if (!FD_ISSET(x, &err))
				FD_SET(x, &err);
		}
		x++;
	}
}

void print_fds(fd_set &to_print, int fdMax)
{
	int x = 0;
	while (x <= fdMax)
	{
		if (FD_ISSET(x, &to_print))
			std::cout << "fds : " << x << "   : " << to_print.fds_bits[x] << ", ";
		x++;
	}
	std::cout << std::endl;
}

int main(void)
{
	//std::map<std::string, func_cmd> com;
	//com = init_map();
	//map_cmd cmap;
	//init_map_cmd();
	//cmap.push_back(pong_cmd);

	/*************** INITIALIZING SERVER ****************/
	// typedef Server::getUser()  &cUser;

	Server serv;
	fd_set read_set, err_set, write_set, tmp_set;
	FD_ZERO(&tmp_set);
	FD_ZERO(&read_set);
	FD_ZERO(&write_set);
	FD_ZERO(&err_set);
	FD_SET(serv.getFdServer(), &read_set);
	FD_SET(serv.getFdServer(), &write_set);
	FD_SET(serv.getFdServer(), &err_set);
	//serv.acceptUser(user, size);


	while (1)
	{
		//will need to change strcpy because it just takes a const string buf we want to access the buffer of user
		//strcpy(const_cast<char *>(serv.getUser().getBuffer().c_str()), "Connect to server...");
		std::string str("Connect to server...");
		//str.copy(serv.getUser().getBuffer(), str.length(), 0);
		std::string buf;
		copy_buffer(buf, str);
		std::cout << "fdserver = " << serv.getFdServer() << " " << buf.c_str() << std::endl;
		//send(serv.getFdServer(), buf.c_str(), 512, 0);

		struct timeval timeout;


		timeout.tv_sec = 15;
		timeout.tv_usec = 0;

		std::cout << serv.getFdMax() << std::endl;
		print_fds(read_set, serv.getFdMax());
		save_sets(&read_set, &tmp_set, serv.getFdMax());
		int select_ret = select(serv.getFdMax() + 1, &read_set, &write_set, &err_set, &timeout);

		if (select_ret < 0)
		{
			perror("Select failed :");
            break ;
		}
		std::cout << "arrrr" << std::endl;
		char buffer[512];


		if ((select_ret > 0) && (FD_ISSET(serv.getFdServer(), &read_set)) &&
			(!FD_ISSET(serv.getFdServer(), &err_set)))
		{
			if ((serv.acceptUser(serv.getUser(), serv.getSize())) < 0)
			{
				perror("Accept failed: ");
                // break ;
			}
			else
			{
				//we're gonna to have to change this buffer thing
				// FD_SET(serv.getUser().getFdUser(), &read_set);
				serv.listenUser(); //put into an if condition
				if (recv(serv.getUser().getFdUser(), &buffer, 255, 0) >= 1)
				{

					std::cout << "MESSAGE: " << serv.getUser().getBuffer() << std::endl;
					serv.setUpFdMax(serv.getUser().getFdUser());
                    //break ;
				}
				else
				{
					perror("recv failure: ");
                    break ;
				}
			}
		}
		else
		{
			perror("There were select failures: ");
            // break ;
		}

		if (select_ret > 0) //pansement
			serv.getUser().connection_replies(serv);
		//if (recv(serv.getUser().getFdUser(), &buffer, 255, 0) >= 1)
		//{
	//		std::cout << "BUFFER = " << serv.getUser().getBuffer() << std::endl;
	//	}


		//std::cout << "Connected with client..." << std::endl;
		//std::cout << "Enter # to end the connection" << std::endl;

		//std::cout << "Client" << std::endl;
		/*
		do {
			recv(serv.getFdServer(), buffer, bufsize, 0);
			std::cout << "buff3r" << " ";
			if (*buffer == '#')
			{
				*buffer = '*';
				isExit = true;
			}
		} while (*buffer != '*');

		do {
			std::cout << "\nSever: ";
			do {
				std::cin >> buffer;
				send(serv.getFdServer(), buffer, bufsize, 0);
				if (*buffer == '#')
				{
					send(serv.getFdServer(), buffer, bufsize, 0);
					*buffer = '*';
					isExit = true;
				}
			} while (*buffer != '*');
			std::cout << "Client: ";
			do {
				recv(serv.getFdServer(), buffer, bufsize, 0);
				std::cout << buffer << " ";
				if (*buffer == '#')
				{
					*buffer = '*';
					isExit = true;
				}
			} while (*buffer != '*');
		} while (!isExit);
		std::cout << "Connection terminated..." << std::endl;
		std::cout << "Goodbye..." << std::endl;
		isExit = false;
		exit(1);
		 */
	 reinit_set(read_set, write_set, err_set, tmp_set, serv.getFdMax());

	}
	std::cout << "sortie" << std::endl;
	// serv.closeUser(serv.getUser());

	std::cout << "ft_irc" << std::endl;
	return 0;
}
