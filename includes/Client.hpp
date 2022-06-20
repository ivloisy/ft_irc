//
// Created by antoine on 20/06/22.
//

#ifndef FT_IRC_CLIENT_HPP
#define FT_IRC_CLIENT_HPP


class Client {
private:
	static int			_nbClient;
	int					_idClient;
	int 				_fdClient;
	//struct sockaddr_in 	_serverAddr;

public:
	Client();
	virtual ~Client();
	Client(Client const &src);
	Client &operator=(Client const &rhs);

	void		establishConnection(void);
	int 		getFdClient(void);
	int 		getIdClient(void);
};


#endif //FT_IRC_CLIENT_HPP
