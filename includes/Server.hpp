//
// Created by blyzance on 18/06/22.
//

#ifndef FT_IRC_SERVER_HPP
#define FT_IRC_SERVER_HPP

#include "ft_irc.hpp"

// # define BUFFERSIZE 512
using namespace std;

namespace irc
{
	class User;
	class Channel;

	class Server
	{

	public:
		// typedef void (* Server::pointer_function)(/*Command * com*/);
		typedef void (*pointer_function)(Server * srv, User * usr, std::vector<std::string> params);
		map<string, pointer_function>					map_cmd;

	private:
		int 											_fd;
		int												_fdMax;
		int*											_fds;
		struct sockaddr_in								_serverAddr;
		string											_serverName; //identify the server, has a max length of 63 chars. servername = hostname
		socklen_t 										_size;			//_user; //we're going to delete it for the instanciation with set
		vector<User *>									_user;
		vector<User *>									_oper;
		vector<Channel *>								_channel;
		int												_portNum; //default port 6667
		bool											_state;
		string											_password;
		vector<vector<string> >							_param;
		int 											_maxChannels;

	public:
		Server(int portNum);
		Server(int portNum, string passw);
		Server(Server const & src);
		virtual ~Server();


		void											establishConnection(void);
		void											createServerAddr(int portNum);
		//void											listenUser(void);
		int												acceptUser(socklen_t size);
		void											closeUser(User * user);
		// void											init_map_cmd();
		void											parse_buffer_command(string buffer, int fd);
		void											sendToChan(string name, string msg);
		void											tokenize(string const & str, int fd);
		void											sendToUser(string name, string msg);

		void											sendBuffer(User * dest, string content);
		void											printParam();
		void											initCommand();
		void 											execCommand(int fd);
		void 											welcome(int fd);
		int												searchNick(string nick);

		Channel											*addChannel(string name);

		Channel											*searchChannel(string name);

		void											delUserAllChannel(User * user);

		int												bindServer(void);
		int												getFdMax( void ) const;
		int												getFdServer() const;
		struct sockaddr_in								getServerAddr() const;
		vector<User *>									getUser() const;
		vector<User *>									getOper() const;
		User											*getOper(string name);
		User											*getUser(int fd);
		User											*getUser(string nick);
		Channel											*getChannel(string name);
		socklen_t										getSize() const;
		int												getPortNum() const;
		string											getServerName() const;
		string											getPassword() const;
		bool											getState() const;
		int 											getMaxChannel() const;

		void											setState(bool st);
		void											setFdServer(int fd);
		void											setUpFdMax(int fdCurrent);
		// void											setDownFdMax(int fdCurrent);


		bool											isMaxChannel();
		bool											isUserEmpty();
	};
}



#endif //FT_IRC_SERVER_HPP
