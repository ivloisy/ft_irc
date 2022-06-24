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
		strcpy(buffer, "Server connected...\n");
		send(serv.getFdServer(), buffer, bufsize, 0);
		//example
		//user.post_registration();

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
