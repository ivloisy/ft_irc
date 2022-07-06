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

#include "Command.hpp"
#include "Server.hpp"

namespace irc
{
	//class Message;
	class Server;
	class Command;

	class User
	{
		//friend class Server;

	private:
		typedef void (*pointer_function)(Command * com);
		typedef std::map<std::string, pointer_function>		map_cmd;
		map_cmd												cmap;

		static int											_nbUser;
		//int												_idUser;
		int 												_fd;
		//struct sockaddr_in 								_serverAddr;
		std::string											_hostname; //name or ip address of the machine
		std::string 										_realname; //name with spaces
		std::string 										_username; //name used on the machine
		std::string 										_nickname; //name used on the server
		std::string 										_password;
		//std::vector<std::string>							_waitingToSend;
		//std::string										_prefix;
		std::string 										buffer;
		std::vector<std::string>							parameters;
		int 												bufsize;
		//Message											*_msg;
		//Server											*server;
		std::vector<Command *>								_command;
		bool												_acceptConnect;
		bool												_isOper;

		//if client send a cap command, ignore it

	public:
		//User();
		User(int fd, struct sockaddr_in address);
		//virtual ~User();
		//User(User const &src);
		User &operator=(User const &rhs);

		//void												establishConnection(void);

		void												init_map_cmd(void);

		ssize_t 											send_buf(Server &serv, std::string const &msg);
		void												write_buf(User * user, std::string const &msg);

		void												tokenize(std::string const &str, Server *serv);
		void												parse_buffer_command(Server * serv);

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
		std::vector<Command *>								getCommand() const;
		bool												getAcceptConnect() const;
		bool												getOper() const;

		void												setOper(bool op);
		void												setAcceptConnect(bool ac);
		void 												setFdUser(int fd);
		void												setNickName(std::string nickname);
		void												setUserName(std::string username);
		void												setRealName(std::string realname);
		void												setHostName(std::string hostname);
		void												setPassWord(std::string password);
		void												setBuffer(std::string buf);

		//void												send_message(int nb_command, Server server);

		void												connection_replies(Command * com);
	};
}

#endif //FT_IRC_CLIENT_HPP
