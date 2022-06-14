#include <ft_irc.hpp>

using namespace std;

int main(void)
{
	int client, server;
	int portNum = 1500;
	bool isExit = false;
	int bufsize = 1024;
	char buffer[bufsize];

	struct sockaddr_in server_addr;
	socklen_t size;



	client = socket(AF_INET, SOCK_STREAM, 0);
	if ( client < 0)
	{
		cout << "Error etablishing connection." << endl;
		exit(1);
	}

	cout << "Server Socket connection created..." << endl;

	server_addr.sin_family = AF_INET;
	server.addr.sin_addr.s_addr = htons(INNADDER_ANY);
	server.addr.sin_port = htons(portNum);

	if ( bind(client, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0 )
	{
		cout << "Erro binding socket..." << endl;
		exit(1);
	}

	size = sizeof(server_addr);
	cout << "Looking for clients..." << endl;

	listen(client, 1);

	server = accept(client, (struct sockaddr*)&server_addr, &size);

	if (server < 0)
	{
		cout << "Error on accepting..." << endl;
		exit(1);
	}

	while (server > 0)
	{
		strcpy(buffer, "Server connected...\n");
		send(server, buffer, bufsize, 0);

		cout << "Conected with client..." << endl;
		cout << "Enter # to end the connection" << endl;

		cout << "Client" << endl;
		do {
			recv(server, buffer, bufsize, 0);
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
				cin << buffer;
				send(server, buffer, bufsize, 0);
				if (*buffer == '#')
				{
					send(server, buffer, bufsize, 0);
					*buffer = '*';
					isExit = true;
				}
			} while (buffer != '*');
			cout << "Client: ";
			do {
				recv(server, buffer, bufsize, 0);
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
	close(client);

	cout << "ft_irc" << endl;
	return 0;
}
