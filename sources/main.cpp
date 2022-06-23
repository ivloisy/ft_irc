#include <ft_irc.hpp>



int main(void)
{
	//int client, server;
	int portNum = 6667; // default port for irc
	bool isExit = false;
	int bufsize = 1024;
	char buffer[bufsize];

	//struct sockaddr_in server_addr;
	socklen_t size;

	Server serv;
	Client cli;

	cli.establishConnection();

	serv.createServerAddr(portNum);
	serv.bindServer(cli);

	size = sizeof(serv.getServerAddr());
	cout << "Looking for clients..." << endl;

	serv.listenClient(cli);

	serv.acceptClient(cli, size);

	// while(1);
	while (serv.getFdServer() > 0)
	{
		// strcpy(buffer, "Server connected...\n");
		// send(serv.getFdServer(), buffer, bufsize, 0);

		cout << "Conected with client..." << endl;
		cout << "Enter # to end the connection" << endl;

		// cout << "Client" << endl;
		// do {
		// 	recv(serv.getFdServer(), buffer, bufsize, 0);
		// 	cout << buffer << " ";
		// 	if (!strncmp(buffer, "MODE", 4))
		// 	{
		// 		*buffer = '*';
		// 	}
		// } while (*buffer != '*');

		do {
			// cout << "\nSever: ";
			// do {
			// 	cin >> buffer;
			// 	send(serv.getFdServer(), buffer, bufsize, 0);
			// 	cout << buffer << " ";
			// 	if (strncmp(buffer, "test", 4))
			// 	{
			// 		*buffer = '*';
			// 			isExit = true;
			// 	}
			// 	// if (*buffer == '#')
			// 	// {
			// 	// 	send(serv.getFdServer(), buffer, bufsize, 0);
			// 	// 	*buffer = '*';
			// 	// }
			// } while (*buffer != '*');
			cout << "Client: ";
			do {
				recv(serv.getFdServer(), buffer, bufsize, 0);
				cout << buffer << " " << endl;
				if (!strncmp(buffer, "QUIT", 4))
				{

					*buffer = '*';
					isExit = true;
				}
			} while (*buffer != '*');
			cli.sendMessage(":server 001 ivloisy :Welcome to the ircserv Network, ivloisy");
		} while (!isExit);
		// if (isExit)
		// {
			cout << "Connection terminated..." << endl;
			cout << "Goodbye..." << endl;
			isExit = false;
			// break ;
			exit(1);
		// }
	}
	// serv.closeClient(cli);

	cout << "Bye ft_irc" << endl;
	return 0;
}
