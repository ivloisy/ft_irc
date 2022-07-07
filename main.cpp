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
//#include "../includes/Message.hpp"

using namespace std;
using namespace irc;

std::string char_to_str(char *buf)
{
	std::string result;
	size_t len = strlen(buf);

	for (size_t i = 0; i < len; i++)
		result.push_back(buf[i]);
	//std::cout << "result = " << result << std::endl;
	return (result);
}

int adding_user(Server *serv)
{
	char buffer[512];
	int fd;
	if ((fd = serv->acceptUser(serv->getSize())) < 0)
		perror("Accept failed: ");
	else
	{
		if (recv(fd, &buffer, 512, 0) >= 1)
		{
			std::cout << "BUFFER: = " << buffer << std::endl;
			// serv->getUser()->setBuffer(char_to_str(buffer));
			//cout << "1 MESSAGE: " << serv->getUser()->getBuffer() << endl;
			serv->parseBufferCommand(buffer);
			serv->printParam();
			//bzero(buffer, 512);
			//change for buffer for testing with the real buffer
			serv->setUpFdMax(fd);
		}
		else
		{
			perror("recv failure: ");
			return (0);
		}
	}
	//std::cout << "exit adding user function" << std::endl;
	return (fd);
}

void ft_run(int port)
{
	char			buffer[512];
	Server			serv(port);
	int				select_ret, fd;
	int				fd_count = 1;
	struct pollfd	_poll[1025];
	_poll[0].fd = serv.getFdServer();
	_poll[0].events = POLLIN;


	while (serv.getState())
	{
		cout << "fdserver = " << serv.getFdServer() << " " << "Connect to server..." << endl;

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
					if (_poll[x].fd == serv.getFdServer())
					{
						if ((fd = adding_user(&serv)))
						{
							_poll[fd_count].fd = fd;
							_poll[fd_count].events = POLLIN;
							fd_count++;
						}
						break;
					}
					else
					{
						//bzero(buffer, 512);
						if (recv(_poll[x].fd, &buffer, 255, 0) >= 1)
						{
							std::cout << "BUFFER: = " << buffer << std::endl;
							serv.parseBufferCommand(buffer);
							serv.printParam();
							// serv.getUser()->setBuffer(char_to_str(buffer));
							// //cout << "2 MESSAGE: " << serv.getUser()->getBuffer() << endl;
							// serv.getUser()->parse_buffer_command(&serv);
						}
					}
				}
			}
		}
		else
			perror("There were select failures: ");
	}
	// serv.closeUser(serv.getUser());
}

int main(int argc, char **argv)
{
	(void)argv;
	if (argc == 2) // without password
	{
		// if ((port = atoi(argv[1])) > 0)
		ft_run(6667);
		cout << "sortie propre" << endl;
	}
	// else if (argc == 3) //with password
	// {
	//if ((port = atoi(argv[1])) > 0)
		// ft_run(port);
	// }
	else
	{
		cout << "error wrong number arguments" << endl;
	}
	return 0;
}
