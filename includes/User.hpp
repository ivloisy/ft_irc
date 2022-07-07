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

using namespace std;

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
		typedef map<string, pointer_function>		map_cmd;
		// map_cmd												cmap;

		static int											_nbUser;
		//int												_idUser;
		int 												_fd;
		//struct sockaddr_in 								_serverAddr;
		string												_hostname;
		string 												_realname;
		string 												_username;
	string 													_nickname;
		string 												_password;
		//vector<string>							_waitingToSend;
		//string										_prefix;
		// string 										buffer;
		vector<string>										parameters;
		// int 												bufsize;
		//Message											*_msg;
		//Server											*server;
		vector<Command *>									_command;
		bool												_acceptConnect;
		bool												_isOper;
		int													_rdySend;

		//if client send a cap command, ignore it

	public:
		//User();
		User(int fd, struct sockaddr_in address);
		User(int fd);
		//virtual ~User();
		//User(User const &src);
		User &operator=(User const &rhs);

		//void												establishConnection(void);

		void												init_map_cmd(void);

		// ssize_t 											send_buf(Server &serv, string const &msg);
		// void												write_buf(User * user, string const &msg);
		//
		// void												tokenize(string const &str, Server *serv);
		// void												parse_buffer_command(Server * serv);

		//int 												getIdUser(void) const;
		int 												getFdUser(void) const;
		string 										getPrefix() const;
		string 										getHostname() const;
		string 										getNickName() const;
		string 										getPassWord() const;
		string 										getUserName() const;
		string											getRealName() const;
		string 										&getBuffer();
		int 												getBufsize() const;
		vector<Command *>								getCommand() const;
		bool												getAcceptConnect() const;
		bool												getOper() const;
		int 												getRdySend() const;

		void												setOper(bool op);
		void												setAcceptConnect(bool ac);
		void 												setFdUser(int fd);
		void												setNickName(string nickname);
		void												setUserName(string username);
		void												setRealName(string realname);
		void												setHostName(string hostname);
		void												setPassWord(string password);
		void												setBuffer(string buf);
		void 												setRdySend();

		//void												send_message(int nb_command, Server server);

		void												connection_replies(Command * com);
	};
	// bool	operator<(const User & lhs, const User & rhs);
	// bool	operator>(const User & lhs, const User & rhs);
}



#endif //FT_IRC_CLIENT_HPP
