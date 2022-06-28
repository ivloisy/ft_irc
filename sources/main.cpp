#include <ft_irc.hpp>

//using namespace std;
using namespace irc;

int main(void)
{
	//int client, server;
	int portNum = 6697; // default port for irc
	bool isExit = false;
	int bufsize = 1024;
	char buffer[bufsize];

	//struct sockaddr_in server_addr;
	socklen_t size;

	irc::Server serv;
	irc::User user;

	user.establishConnection();

	serv.createServerAddr(portNum);
	serv.bindServer(user);

	size = sizeof(serv.getServerAddr());
	std::cout << "Looking for clients..." << std::endl;

	serv.listenUser(user);

	//serv.acceptUser(user, size);

	while (1)
	{
		strcpy(buffer, "Connect to server...");
		send(serv.getFdServer(), buffer, bufsize, 0);

		fd_set read_set, err_set;
		struct timeval timeout;

		FD_ZERO(&read_set);
		FD_SET(user.getFdUser(), &read_set);
		FD_ZERO(&err_set);
		FD_SET(user.getFdUser(), &err_set);
		timeout.tv_sec = 10;
		timeout.tv_usec = 0;

		int select_ret = select(user.getFdUser() + 1, &read_set, NULL, &err_set, &timeout);

		if (select_ret < 0)
		{
			perror("Select failed :");
            break ;
		}

		if ((select_ret > 0) && (FD_ISSET(user.getFdUser(), &read_set)) && (!FD_ISSET(user.getFdUser(), &err_set)))
		{
			if ((serv.acceptUser(user, size)) < 0)
			{
				perror("Accept failed: ");
                break ;
			}
			else
			{
				if (recv(serv.getFdServer(), buffer, 255, 0) >= 1)
				{
					std::cout << "MESSAGE: " << buffer << std::endl;
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
            break ;
		}

		//example
		//std::vector<irc::Command *> commands;
		std::string message(":irc.sample.com 001 yoka :Welcome to the Internet Relay Network yoka");
		send(serv.getFdServer(), message.c_str(), message.length(), 0);
		message.clear();
		message = ":irc.sample.com 002 yoka :Your host is irc.sample.com, running version 12";
		send(serv.getFdServer(), message.c_str(), message.length(), 0);
		message.clear();
		message = ":irc.sample.com 003 yoka :This server was created today";
		send(serv.getFdServer(), message.c_str(), message.length(), 0);
		message.clear();
		message = ":irc.sample.com 004 yoka :localhost 12 2i1j4oi jwer";
		send(serv.getFdServer(), message.c_str(), message.length(), 0);
		message.clear();

		std::cout << "Connected with client..." << std::endl;
		std::cout << "Enter # to end the connection" << std::endl;

		std::cout << "Client" << std::endl;
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
	}
	serv.closeUser(user);

	std::cout << "ft_irc" << std::endl;
	return 0;
}
