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
		typedef void (*pointer_function)(Server & srv, User & usr, std::vector<std::string> params);
		map<string, pointer_function>					map_cmd;

	private:
		int 											_fd;
		int												_fdMax;
		int*											_fds;
		struct sockaddr_in								_serverAddr;
		string											_serverName; //identify the server, has a max length of 63 chars. servername = hostname
		socklen_t										_size;			//_user; //we're going to delete it for the instanciation with set
		vector<User *>									_user;
		vector<User *>									_oper;
		vector<Channel *>								_channel;
		int												_portNum; //default port 6667
		bool											_state;
		string											_password;
		vector<vector<string> >							_param;
		int 											_maxChannels;

	public:
		Server(int const & portNum);
		Server(int const & portNum, string const & passw);
		Server(Server const & src);
		virtual ~Server();


		void											establishConnection(void);
		void											createServerAddr(int const & portNum);
		//void											listenUser(void);
		int												acceptUser(socklen_t size);
		void											closeUser(User const &  user);
		// void											init_map_cmd();
		void											parse_buffer_command(string const &  buffer, int const &  fd);
		void											sendToChan(string const & name, string const & msg);
		void											tokenize(string const & str, int const & fd);
		void											sendToUser(string const & name, string const & msg);

		void											sendBuffer(User const & dest, string const & content);
		void											printParam();
		void											initCommand();
		void 											execCommand(int const & fd);
		void 											welcome(int const & fd);
		int												searchNick(string const & nick);

		Channel*										addChannel(string const & name);

		Channel*										searchChannel(string const & name);

		void											delUserAllChannel(User * user);

		int												bindServer(void);
		int												getFdMax( void ) const;
		int												getFdServer() const;
		struct sockaddr_in								getServerAddr() const;
		vector<User *>									getUser() const;
		vector<User *>									getOper() const;
		User*											getOper(string const & name);
		User*											getUser(int const & fd);
		User*											getUser(string const & nick);
		Channel*										getChannel(string const & name);
		socklen_t										getSize() const;
		int												getPortNum() const;
		string											getServerName() const;
		string											getPassword() const;
		bool											getState() const;
		int 											getMaxChannel() const;

		void											setState(bool const & st);
		void											setFdServer(int const & fd);
		void											setUpFdMax(int const & fdCurrent);
		// void											setDownFdMax(int const & fdCurrent);


		bool											isMaxChannel();
		bool											isUserEmpty();
	};
}



#endif //FT_IRC_SERVER_HPP
