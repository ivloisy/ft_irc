#include <ft_irc.hpp>

using namespace std;

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
	cout << "Looking for clients..." << endl;

	serv.listenUser(user);

	serv.acceptUser(user, size);

	while (serv.getFdServer() > 0)
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
		}

		if ((select_ret > 0) && (FD_ISSET(user.getFdUser(), &read_set)) && (!FD_ISSET(user.getFdUser(), &err_set)))
		{
			if ((serv.acceptUser(user, size)) < 0)
			{
				perror("Accept failed: ");
			}
			else
			{
				if (recv(serv.getFdServer(), buffer, 255, 0) >= 1)
				{
					cout << "MESSAGE: " << buffer << std::endl;
				}
				else
				{
					perror("recv failure: ");
				}
			}
		}
		else
		{
			perror("There were select failures: ");
		}

		//example
		//std::vector<irc::Command *> commands;
		std::string message(":toto!antoine@127.0.0.1 001 :Welcome to the Internet Relay Network baba!antoine@127.0.0.1");
		send(serv.getFdServer(), message.c_str(), message.length(), 0);
		message.clear();
		message = ":toto!antoine@127.0.0.1 002 :Your host is localhost, running version 12";
		send(serv.getFdServer(), message.c_str(), message.length(), 0);
		message.clear();
		message = ":toto!antoine@127.0.0.1 003 :This server was created today";
		send(serv.getFdServer(), message.c_str(), message.length(), 0);
		message.clear();
		message = ":toto!antoine@127.0.0.1 004 :localhost 12 2i1j4oi jwer";
		send(serv.getFdServer(), message.c_str(), message.length(), 0);
		message.clear();

		cout << "Connected with client..." << endl;
		cout << "Enter # to end the connection" << endl;

		cout << "Client" << endl;
		do {
			recv(serv.getFdServer(), buffer, bufsize, 0);
			cout << "buff3r" << " ";
			if (*buffer == '#')
			{
				*buffer = '*';
				isExit = true;
			}
		} while (*buffer != '*');

		do {
			cout << "\nSever: ";
			do {
				cin >> buffer;
				send(serv.getFdServer(), buffer, bufsize, 0);
				if (*buffer == '#')
				{
					send(serv.getFdServer(), buffer, bufsize, 0);
					*buffer = '*';
					isExit = true;
				}
			} while (*buffer != '*');
			cout << "Client: ";
			do {
				recv(serv.getFdServer(), buffer, bufsize, 0);
				cout << buffer << " ";
				if (*buffer == '#')
				{
					*buffer = '*';
					isExit = true;
				}
			} while (*buffer != '*');
		} while (!isExit);
		cout << "Connection terminated..." << endl;
		cout << "Goodbye..." << endl;
		isExit = false;
		exit(1);
	}
	serv.closeUser(user);

	cout << "ft_irc" << endl;
	return 0;
}
