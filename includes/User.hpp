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
#include "Message.hpp"
#include "Command.hpp"
#include "Server.hpp"

namespace irc
{
	class Command;
	class Server;

	class User
	{
		//friend class Server;

	private:
		static int					_nbUser;
		//int						_idUser;
		int 						_fd;
		//struct sockaddr_in 		_serverAddr;
		std::string					_hostname;
		std::string 				_nickname;
		std::vector<std::string>	_waitingToSend;
		//std::map<std::string, Command *>	_commands;
		//std::string				_prefix;
		std::string 				buffer;
		int 						bufsize;
		Command						*_command;
		Server						*server;

		//if client send a cap command, ignore it

	public:
		User();
		User(int fd, struct sockaddr_in address);
		//virtual ~User();
		//User(User const &src);
		User &operator=(User const &rhs);

		//void						establishConnection(void);
		int 						getFdUser(void) const;
		int 						getIdUser(void) const;


		ssize_t 					send_buf(Server &serv, std::string const &msg);
		void						write_buf(User &user, std::string const &msg);

		std::string 				getPrefix() const;
		std::string 				getHostname() const;
		std::string 				getNickName() const;

		std::string					&getBuffer();
		int 						getBufsize() const;

		void 						setFdUser(int & fd);

		//void						send_message(int nb_command, Server server);

		void						connection_replies(Server & server);
	};
}



#endif //FT_IRC_CLIENT_HPP
