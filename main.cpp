#include "./includes/ft_irc.hpp"
#include <signal.h>

using namespace std;
using namespace irc;

void	sighand(int sig)
{
	if (sig == SIGINT)
		exit(0);
}

bool check_buffer(string buf)
{
	cout << "checkinbuffer " << endl;
	size_t x = 0;
	while (x <= buf.size())
	{
		cout << "check this char : " << static_cast<int>(buf[x]) << endl;
		if (!isprint(buf[x]) && buf[x] != '\n' && buf[x] != '\r' && buf[x] != '\0')
		{
			cout << "this char is nonprintable : " << static_cast<int>(buf[x]) << endl;
			return false;
		}

		x++;
	}
	return true;
}

void exit_error(string msg, Server & serv)
{
	cout << msg << endl;
	close(serv.getFdServer());
	exit(1);
}

void ft_run(int port, string password)
{
	char buffer[512];
	string save = "";
	Server serv(port, password);
	int poll_ret, fd, creation, receive;
	int fd_count = 1;
	struct pollfd			_poll[1025];
	_poll[0].fd = serv.getFdServer();
	_poll[0].events = POLLIN;

	signal(SIGINT, sighand);

	while (serv.getState())
	{
		creation = 0;

		if ((poll_ret = poll(_poll, fd_count, -1)) < 0)
			exit_error("poll failed :", serv);
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
							creation = 1;
							serv.setUpFdMax(fd);
							fd_count++;
						}
						else
							exit_error("Accept failed: ", serv);
					}
					if ((receive = recv(fd, &buffer, 255, 0)) >= 1)
					{
						if (buffer[strlen(buffer) - 1] == '\n')
						{
							save += buffer;
							if (check_buffer(save))
							{
								serv.parse_buffer_command(save);
								serv.execCommand(fd);
								serv.welcome(fd);
							}
							else
								serv.ft_error(*serv.getUser(fd), ERR_ERRSYNTAX, "");
							save.clear();
						}
						else
							save += buffer;
					}
					if (creation != 1 && (receive < 1 || (*(serv.getUser(fd)))->getToClose() == 1))
					{
						_poll[x] = _poll[fd_count - 1];
						_poll[x].events = POLLIN;
						serv.deleteUser(serv.getUser(fd));
						close(fd);
						fd_count--;
					}
					if (creation == 1)
						break ;
				}
			}
		}
		else
			exit_error("There were poll failures: ", serv);
	}
	close(serv.getFdServer());
}

int main(int argc, char **argv)
{
	int port;
	if (argc == 3)
	{
		string password = argv[2];
		if ((port = atoi(argv[1])) > 0)
			ft_run(port, password);
	}
	else
		cout << "error wrong number arguments" << endl;
	return 0;
}
