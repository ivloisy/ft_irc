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

int adding_user(Server *serv)
{
	char buffer[512];
	if ((serv->acceptUser(serv->getUser(), serv->getSize())) < 0)
		perror("Accept failed: ");
	else
	{
		if (recv(serv->getUser().getFdUser(), &buffer, 255, 0) >= 1)
		{
			//change the bufbuf string for testing the parser
			std::string bufbuf("USER blabla");
			//launch parser
			serv->getUser().parse_buffer_command(bufbuf);
			//change for buffer for testing with the real buffer
			cout << "MESSAGE: " << bufbuf << endl;
			cout << serv->getUser().getNickName() << endl;
			serv->setUpFdMax(serv->getUser().getFdUser());
		}
		else
		{
			perror("recv failure: ");
			return (1);
		}
	}
	serv->getUser().connection_replies(*serv);
	return (0);
}

void ft_run()
{
	Server serv;
	fd_set read_set, err_set, write_set, tmp_set;
	string str, buf;
	int select_ret, x;
	struct timeval timeout;

	FD_ZERO(&tmp_set);
	FD_ZERO(&read_set);
	FD_ZERO(&write_set);
	FD_ZERO(&err_set);
	FD_SET(serv.getFdServer(), &read_set);
	FD_SET(serv.getFdServer(), &write_set);
	FD_SET(serv.getFdServer(), &err_set);

	while (1)
	{
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
					if (adding_user(&serv))
						break;
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
