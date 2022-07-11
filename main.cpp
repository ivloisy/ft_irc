#include "./includes/ft_irc.hpp"

using namespace std;
using namespace irc;

void ft_run(int port, string password)
{
	char buffer[512];
	Server serv(port, password);
	int poll_ret, fd, test, receive;
	int fd_count = 1;
	struct pollfd			_poll[1025];
	_poll[0].fd = serv.getFdServer();
	_poll[0].events = POLLIN;
	// int fin = 0;

	while (serv.getState())
	{
		// fin++;
		//cout << "fdserver = " << serv.getFdServer() << " " << "Connect to server..." << endl;

		// list all users in the server
		/*
		vector<User *> users = serv.getUser();
		vector<User *>::iterator last = users.end();
		for (vector<User *>::iterator it = users.begin(); it != last; it++)
		{
			cout << (*it)->getNickName() << endl;
		}
		 */
		// ----------------------------

		test = 0;

		poll_ret = poll(_poll, fd_count, -1);

		if (poll_ret < 0)
		{
			perror("Select failed :");
			break ;
		}
		if ((poll_ret > 0))
		{
			for (int x = 0; x < fd_count; x++)
			{
				bzero(buffer, 512);
				if (_poll[x].revents & POLLIN)
				{
					fd = _poll[x].fd;
					if (_poll[x].fd == serv.getFdServer())
					{
						if ((fd = serv.acceptUser(serv.getSize())))
						{
							_poll[fd_count].fd = fd;
							_poll[fd_count].events = POLLIN;
							test = 1;
							serv.setUpFdMax(fd);
							fd_count++;
						}
						else
						{
							perror("Accept failed: ");
							break;
						}
					}
					if ((receive = recv(fd, &buffer, 255, 0)) >= 1)
					{
						cout << "BUFFER RECEIVE = " << buffer << endl;
						serv.parse_buffer_command(buffer, fd);
						serv.printParam();
						serv.execCommand(fd);
						serv.welcome(fd);
					}
					if (test != 1 && (receive < 1 || (*(serv.getUser(fd)))->getToClose() == 1))
					{
						cout << "CLOSE FD" << endl;
						_poll[x] = _poll[fd_count - 1];
						_poll[x].events = POLLIN;
						serv.deleteUser(serv.getUser(fd));
						close(fd);
						fd_count--;
					}
					if (test == 1)
						break ;
				}
			}
		}
		else
			perror("There were select failures: ");
	}
	close(serv.getFdServer());
}

int main(int argc, char **argv)
{
	// (void)argv;
	// if (argc == 2) // without password
	// {
	// 	// if ((port = atoi(argv[1])) > 0)
	// 	ft_run(6667);
	// 	cout << "sortie propre" << endl;
	// }
	int port;
	if (argc == 3) //with password
	{
		string password = argv[2];
		if ((port = atoi(argv[1])) > 0)
			ft_run(port, password);
	}
	else
	{
		cout << "error wrong number arguments" << endl;
	}
	return 0;
}
