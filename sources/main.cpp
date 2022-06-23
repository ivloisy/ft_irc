#include <ft_irc.hpp>

int main(int ac, char **av)
{
	try
	{
		if (ac != 3)
			throw usageException();
		Server	serv(av[1], av[2]);
		// Client cli;

		// cli.establishConnection();
		//
		// serv.createServerAddr(portNum);
		// serv.bindServer(cli);
		//
		// size = sizeof(serv.getServerAddr());
		// cout << "Looking for clients..." << endl;
		//
		// serv.listenClient(cli);
		//
		// serv.acceptClient(cli, size);
	}
	catch (const exception & e)
	{
		cerr << LINE << BOLDRED << "Error:" << endl << RESET << RED
		<< e.what() << RESET << endl;
		return 1;
	}

	return 0;
}
