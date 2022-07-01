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

#include <sys/select.h>
#include <sys/time.h>

#include "./includes/Server.hpp"
#include "./includes/User.hpp"
#include "./includes/Command.hpp"
#include "./includes/Config.hpp"
//#include "../includes/Message.hpp"

//using namespace std;
using namespace irc;



void copy_buffer(std::string &dest, std::string const &src)
{
	for (int i = 0; i < src.length(); i++)
		dest.push_back(src.at(i));
}

int main(void)
{


	/*************** INITIALIZING SERVER ****************/
	// typedef Server::getUser()  &cUser;

	Server serv;

	//serv.acceptUser(user, size);
	fd_set read_set, err_set, write_set, save_read_set;
	FD_ZERO(&read_set);
	FD_ZERO(&write_set);
	FD_ZERO(&err_set);
	//FD_SET(serv.getFdServer(), &read_set);
	//FD_SET(serv.getFdServer(), &write_set);
	//FD_SET(serv.getFdServer(), &err_set);

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


		int select_ret = select(serv.getFdMax() + 1, &read_set, &write_set, &err_set, &timeout);

		if (select_ret < 0)
		{
			perror("Select failed :");
            break ;
		}

		if ((select_ret > 0) && (FD_ISSET(serv.getFdServer(), &read_set)) &&
			(!FD_ISSET(serv.getFdServer(), &err_set)))
		{
			if ((serv.acceptUser(serv.getUser(), serv.getSize())) < 0)
			{
				perror("Accept failed: ");
                break ;
			}
			else
			{
				//we're gonna to have to change this buffer thing
				FD_SET(serv.getUser().getFdUser(), &read_set);
				serv.listenUser();
				char buffer[512];
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

		serv.getUser().connection_replies(serv);

		std::cout << "Connected with client..." << std::endl;
		std::cout << "Enter # to end the connection" << std::endl;

		std::cout << "Client" << std::endl;
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
	}
	std::cout << "sortie" << std::endl;
	// serv.closeUser(serv.getUser());

	std::cout << "ft_irc" << std::endl;
	return 0;
}
