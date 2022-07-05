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
	class Message;
	class Server;
	//class Command;

	class User
	{
		//friend class Server;

	private:
		typedef void (*pointer_function)(Server & serv, User & user, std::vector<std::string> & out);
		typedef std::map<std::string, pointer_function>		map_cmd;

		map_cmd												cmap;

		static int											_nbUser;
		//int												_idUser;
		int 												_fd;
		//struct sockaddr_in 								_serverAddr;
		std::string											_hostname;
		std::string 										_realname;
		std::string 										_username;
		std::string 										_nickname;
		std::string 										_password;
		//std::string 										_buffer;
		//std::vector<std::string>							_waitingToSend;
		//std::map<std::string, Message *>					_commands;
		//std::string										_prefix;
		std::string 										buffer;
		std::vector<std::string>							parameters;
		int 												bufsize;
		Message												*_msg;
		Server												*server;
		//Command											_command;

		//if client send a cap command, ignore it

	public:
		User();
		User(int fd, struct sockaddr_in address);
		//virtual ~User();
		//User(User const &src);
		User &operator=(User const &rhs);

		//void												establishConnection(void);

		void												init_map_cmd(void);

		ssize_t 											send_buf(Server &serv, std::string const &msg);
		void												write_buf(User &user, std::string const &msg);

		void												tokenize(std::string const &str, const char delim, std::vector<std::string> &out);
		void												parse_buffer_command(Server & serv);

		//int 												getIdUser(void) const;
		int 												getFdUser(void) const;
		std::string 										getPrefix() const;
		std::string 										getHostname() const;
		std::string 										getNickName() const;
		std::string 										getPassWord() const;
		std::string 										getUserName() const;
		std::string											getRealName() const;
		std::string 										&getBuffer();
		int 												getBufsize() const;
		map_cmd												getCommand() const;

		void 												setFdUser(int & fd);
		void												setNickName(std::string nickname);
		void												setUserName(std::string username);
		void												setRealName(std::string realname);
		void												setHostName(std::string hostname);
		void												setPassWord(std::string password);
		void												setBuffer(std::string & buf);

		//void												send_message(int nb_command, Server server);

		void												connection_replies(Server & server);
	};
}



#endif //FT_IRC_CLIENT_HPP
