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

#include <sys/select.h>
#include <sys/time.h>
#include <map>
#include <string>
#include <vector>

#include "./includes/Server.hpp"
#include "./includes/User.hpp"
#include "./includes/Message.hpp"
#include "./includes/Config.hpp"
#include "./includes/Command.hpp"
//#include "../includes/Message.hpp"

using namespace std;
using namespace irc;

/*
void copy_buffer(string &dest, string const &src)
{
	for (int i = 0; i < src.length(); i++)
		dest.push_back(src.at(i));
}*/

std::string char_to_str(char *buf)
{
	std::string result;

	for (int i = 0; i < strlen(buf); i++)
		result.push_back(buf[i]);
	//std::cout << "result = " << result << std::endl;
	return (result);
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



// void print_fds(fd_set &to_print, int fdMax)
// {
// 	int x = 0;
// 	while (x <= fdMax)
// 	{
// 		if (FD_ISSET(x, &to_print))
// 			cout << "fds : " << x << "   : " << to_print.fds_bits[x] << ", ";
// 		x++;
// 	}
// 	cout << endl;
// }



int adding_user(Server *serv, fd_set *read_set)//, char *buffer)
{
	char buffer[512];

	if ((serv->acceptUser(serv->getSize())) < 0)
		perror("Accept failed: ");
	else
	{
		FD_SET(serv->getUser()->getFdUser(), read_set);
		if (recv(serv->getUser()->getFdUser(), &buffer, 512, 0) >= 1)
		{
			std::cout << "BUFFER: = " << buffer << std::endl;
			serv->getUser()->setBuffer(char_to_str(buffer));
			cout << "MESSAGE: " << serv->getUser()->getBuffer() << endl;
			serv->getUser()->parse_buffer_command(serv);
			//bzero(buffer, 512);
			//change for buffer for testing with the real buffer
			serv->setUpFdMax(serv->getUser()->getFdUser());
		}
		else
		{
			perror("recv failure: ");
			return (1);
		}
	}
	//std::cout << "exit adding user function" << std::endl;
	return (0);
}

void ft_run()
{
	//char buffer[512];
	Server serv;

	fd_set read_set, err_set, write_set, tmp_set;
	string str, buf;
	int select_ret, x;
	struct timeval timeout;
	//char buffer[512] = "\0";
	FD_ZERO(&tmp_set);
	FD_ZERO(&read_set);
	FD_ZERO(&write_set);
	FD_ZERO(&err_set);
	FD_SET(serv.getFdServer(), &read_set);
	FD_SET(serv.getFdServer(), &write_set);
	FD_SET(serv.getFdServer(), &err_set);


	while (serv.getState())
	{

		//for (int i = 0; i < 510; i++)
		//	buffer[i] = 'a';
		//buffer[511] = '\n';
		//std::cout << "JE VAIS PRINT CE QUI EST DANS LE BUFFER " << buffer << std::endl;
		//bzero(&buffer, 512);
		//buffer[0] = '\0';
		//std::cout << "JE VAIS PRINT CE QUI Est DANS LE BUFFER " << buffer << std::endl;
		timeout.tv_sec = 15;
		//str = "Connect to server...";
		//copy_buffer(buf, str);
		//cout << "fdserver = " << serv.getFdServer() << " " << buf.c_str() << endl;

		save_sets(&read_set, &tmp_set, serv.getFdMax());
		select_ret = select(serv.getFdMax() + 1, &read_set, &write_set, &err_set, &timeout);

		if (select_ret < 0)
		{
			perror("Select failed :");
			break ;
		}
		if ((select_ret > 0))
		{
			for (x = 0; x <= serv.getFdMax(); x++)
			{
				if (FD_ISSET(x, &read_set) && x == serv.getFdServer())
				{
					if (adding_user(&serv, &read_set))//, buffer))
						break;
					//if (FD_ISSET(serv.getUser()->getFdUser(), &read_set))
					//	std::cout << "fd is readable" << std::endl;
				}
			}
		}
		else
			perror("There were select failures: ");
		reinit_set(read_set, write_set, err_set, tmp_set, serv.getFdMax());
	}
	serv.closeUser(serv.getUser());
}

int main(int argc, char **argv)
{
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
