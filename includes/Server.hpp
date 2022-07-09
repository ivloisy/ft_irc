//
// Created by blyzance on 18/06/22.
//

#ifndef FT_IRC_SERVER_HPP
#define FT_IRC_SERVER_HPP

#include "ft_irc.hpp"

using namespace std;

namespace irc
{
	class User;
	class Channel;

	class Server
	{

	public:
		typedef void (*pointer_function)(Server & srv, User & usr, std::vector<std::string> params);
		map<string, pointer_function>					map_cmd;

	private:
		int 											_fd;
		int												_fdMax;
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


		/******************** CONNECTION **********************/
		void 											initServer(void);
		void											establishConnection(void);
		void											createServerAddr(int const & portNum);
		//void											listenUser(void);
		int												acceptUser(socklen_t size);
		void											closeUser(User const &  user);
		// void											init_map_cmd();
		int												bindServer(void);

		void											initCommand();
		void 											welcome(int const & fd);
		void											parse_buffer_command(string const &  buffer, int const &  fd);
		void											tokenize(string const & str, int const & fd);
		void											printParam();
		void 											execCommand(int const & fd);
		int												searchNick(string const & nick);
		void											sendToChan(string const & name, string const & msg);
		void											sendToUser(string const & name, string const & msg);
		void											sendBuffer(User const & dest, string const & content);

		Channel*										addChannel(string const & name);

		Channel*										searchChannel(string const & name);

		void											delUserAllChannel(User * user);


		/******************** ACCESSORS **********************/
		int												getFdMax( void ) const;
		int												getFdServer() const;
		struct sockaddr_in								getServerAddr() const;
		vector<User *>									getUser() const;
		User*											getUser(int const & fd);
		User*											getUser(string const & nick);
		Channel*										getChannel(string const & name);
		socklen_t										getSize() const;
		int												getPortNum() const;
		vector<User *>									getOper() const;
		User*											getOper(string const & name);
		int 											getMaxChannel() const;
		bool											getState() const;
		string											getServerName() const;
		string											getPassword() const;

		/********************* MUTATORS *************************/
		void											setFdServer(int const & fd);
		void											setState(bool const & st);
		void											setUpFdMax(int const & fdCurrent);
		// void											setDownFdMax(int const & fdCurrent);


		/******************* CHECKERS **********************/
		bool											isMaxChannel();
		bool											isUserEmpty();
	};
}



#endif //FT_IRC_SERVER_HPP
