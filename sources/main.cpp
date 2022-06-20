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

	Server serv;
	Client cli;

	cli.establishConnection();

	serv.createServerAddr(portNum);
	serv.bindServer(cli);

	size = sizeof(serv.getServerAddr());
	cout << "Looking for clients..." << endl;

	serv.listenClient(cli);

	serv.acceptClient(cli, size);

	while (serv.getFdServer() > 0)
	{
		strcpy(buffer, "Server connected...\n");
		send(serv.getFdServer(), buffer, bufsize, 0);

		cout << "Conected with client..." << endl;
		cout << "Enter # to end the connection" << endl;

		cout << "Client" << endl;
		do {
			recv(serv.getFdServer(), buffer, bufsize, 0);
			cout << "buffer" << " ";
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
	serv.closeClient(cli);

	cout << "ft_irc" << endl;
	return 0;
}
