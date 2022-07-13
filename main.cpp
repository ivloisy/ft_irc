#include "./includes/ft_irc.hpp"
#include <signal.h>

using namespace std;
using namespace irc;

void	sighand(int sig)
{
	if (sig == SIGINT)
	{
		exit(0);
	}
}

bool check_buffer(string buf)
{
	size_t x = 0;
	while (x < buf.size())
	{
		cout << "is print : " << isprint(buf[x]) << " : " << buf[x] << endl;
		if (!isprint(buf[x]) && buf[x] != '\n' && (buf[x - 1] != '\r' && buf[x] != '\n'))
		{
			cout << "FAAAALSE" << endl;
			return false;
		}
		x++;
	}
	return true;
}

void ft_run(int port, string password)
{
	char buffer[512];
	string save = "";
	Server serv(port, password);
	int poll_ret, fd, test, receive;
	int fd_count = 1;
	struct pollfd			_poll[1025];
	_poll[0].fd = serv.getFdServer();
	_poll[0].events = POLLIN;

	signal(SIGINT, sighand);

	while (serv.getState())
	{
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

							if (buffer[strlen(buffer) - 1] == '\n')
							{
								cout << "=============ENVOI COMMANDE===============" << endl;
								save += buffer;
								// if (check_buffer(save))
								// {
									serv.parse_buffer_command(save);
									serv.execCommand(fd);
									serv.welcome(fd);
								// }
								// else
								// {
								// 	cout << "OOOOOOOKKKKKKKK" << endl;
								// 	serv.ft_error(*serv.getUser(fd), ERR_ERRSYNTAX, "");
								// }
								save.clear();
							}
							else
							{
								save += buffer;
								cout << "in wait : " << save << endl;
							}

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
	cout << "finallllll" << endl;
	close(serv.getFdServer());
}

int main(int argc, char **argv)
{
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
