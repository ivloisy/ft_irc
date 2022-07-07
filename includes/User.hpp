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
#include "Channel.hpp"

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
		typedef map<string, pointer_function>				map_cmd;
		// map_cmd											cmap;

		static int											_nbUser;
		//int												_idUser;
		int 												_fd;
		//struct sockaddr_in 								_serverAddr;
		string												_hostname; //name or ip address of the machine
		string 												_realname; //name with spaces
		string 												_username; //name used on the machine
		string 												_nickname; //name used on the server
		string 												_password;
		//vector<string>									_waitingToSend;
		//string											_prefix;
		string 												buffer;
		vector<string>										parameters;
		int 												bufsize;
		//Message											*_msg;
		//Server											*server;
		vector<Command *>									_command;
		vector<Channel *>									_channel;
		bool												_acceptConnect;
		bool												_isOper;
		//vector<Channel *>									_channel;

		//if client send a cap command, ignore it

	public:
		//User();
		User(int fd, struct sockaddr_in address);
		User(int fd);
		//virtual ~User();
		//User(User const &src);
		User &operator=(User const &rhs);

		//void												establishConnection(void);

		//void												init_map_cmd(void);

		// ssize_t 											send_buf(Server &serv, string const &msg);
		// void												write_buf(User * user, string const &msg);
		//
		// void												tokenize(string const &str, Server *serv);
		// void												parse_buffer_command(Server * serv);

		void												clearAllChannels();
		void												quitChannel(Channel * chan);
		void												addChannel(Channel * chan);

		//int 												getIdUser(void) const;
		int 												getFdUser(void) const;
		string 												getPrefix() const;
		string 												getHostname() const;
		string 												getNickName() const;
		string 												getPassWord() const;
		string 												getUserName() const;
		string												getRealName() const;
		vector<Command *>									getCommand() const;
		vector<Channel *>									getChannel() const;
		Channel												*getChannelByName(string name);
		bool												getAcceptConnect() const;
		bool												getOper() const;

		void												setOper(bool op);
		void												setAcceptConnect(bool ac);
		void 												setFdUser(int fd);
		void												setNickName(string nickname);
		void												setUserName(string username);
		void												setRealName(string realname);
		void												setHostName(string hostname);
		void												setPassWord(string password);

		//void												send_message(int nb_command, Server server);

	};
	// bool	operator<(const User & lhs, const User & rhs);
	// bool	operator>(const User & lhs, const User & rhs);
}



#endif //FT_IRC_CLIENT_HPP
