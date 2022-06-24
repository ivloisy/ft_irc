//
// Created by antoine on 20/06/22.
//

#ifndef FT_IRC_CLIENT_HPP
#define FT_IRC_CLIENT_HPP

#include <vector>
#include <string>

#include <netinet/in.h>
#include <sys/socket.h>
#include <iostream>
#include <ostream>

namespace irc
{
	class Command;
	class Server;

	class User
	{
		friend class Server;

	private:
		static int					_nbUser;
		int							_idUser;
		int 						_fdUser;
		//struct sockaddr_in 		_serverAddr;
		std::string					_hostname;
		std::vector<std::string>	_waitingToSend;
		std::vector<Command *>		_commands;
		//std::string				_prefix;
		std::string 				buffer;

		//if client send a cap command, ignore it

	public:
		User();
		User(int fd, struct sockaddr_in address);
		virtual ~User();
		User(User const &src);
		User &operator=(User const &rhs);

		void						establishConnection(void);
		int 						getFdUser(void) const;
		int 						getIdUser(void) const;

		ssize_t 					send_buf(User &user, std::string const &msg);
		void						write_buf(User &user, std::string const &msg);

		std::string 				getPrefix();
		std::string 				getHostname();

		void						post_registration(Command *command);
	};
}



#endif //FT_IRC_CLIENT_HPP
