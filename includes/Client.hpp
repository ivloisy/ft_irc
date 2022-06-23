//
// Created by antoine on 20/06/22.
//

#ifndef CLIENT_HPP
# define CLIENT_HPP

// # include <ft_irc.hpp>
#include <iostream>
// using namespace std;
#include <sys/socket.h>
#include <iostream>
#include <stdlib.h>

class Client {

private:
	static int				_nbClient;
	int						_idClient;
	int 					_fdClient;
	//struct sockaddr_in 	_serverAddr;

	//if client send a cap command, ignore it

public:
	Client();
	virtual ~Client();
	Client(Client const &src);
	Client &operator=(Client const &rhs);

	void		establishConnection(void);
	void		sendMessage(std::string str) const;

	int 		getFdClient(void) const;
	int 		getIdClient(void) const;
};


#endif //CLIENT_HPP
