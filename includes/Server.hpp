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
		typedef string (*function_reply)(Server * srv, User * from, User * to);
		typedef void (*function_command)(Server & srv, User & usr, std::vector<std::string> params);

	private:
		map<string, function_command>					map_cmd;
		map<string, function_reply>						map_rep;
		map<string, string>								map_err;

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
		string 											_date;
		string 											_ver;

	public:
		Server(int const & portNum);
		Server(int const & portNum, string const & passw);
		virtual ~Server();

		/******************** CONNECTION **********************/
		void 											initServer(void);
		void											establishConnection(void);
		void											createServerAddr(int const & portNum);
		int												acceptUser(socklen_t size);
		void											closeUser(User const &  user);
		int												bindServer(void);
		void											sendBuffer(User * dest, string const & content);
		void											printParam();
		void											initCommand();
		void 											welcome(int const & fd);
		void											parse_buffer_command(string const &  buffer, int const &  fd);
		void 											execCommand(int const & fd);
		int												searchNick(string const & nick);
		void											sendToChan(string const & name, string const & msg);
		void											sendToUser(string const & name, string const & msg);
		void											sending(int fd, string toSend);
		Channel*										addChannel(string const & name);
		Channel*										searchChannel(string const & name);
		void											delUserAllChannel(User * user);
		//string const									getDate() const;
		//string const									getVersion() const;

		/******************** ACCESSORS **********************/
		int												getFdMax( void ) const;
		int												getFdServer() const;
		struct sockaddr_in								getServerAddr() const;
		vector<User *>									getUsers() const;
		User*											getUser(int const & fd);
		User*											getUser(string const & nick);
		Channel*										getChannelByName(string const & name);
		vector<Channel *>								getChannels() const;
		string 											getVersion() const;
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

		/********************* REPLIES **************************/
		void											initReplyTree();
		void											initErrorTree();
		void											ft_notice(User * from, User * to, string notice);
		void											ft_notice_chan(User * from, Channel * to, string notice);
		void 											ft_reply(User * from, User * to, string code);
		void											ft_error(User * from, string code, string arg);
	};
}

#endif //FT_IRC_SERVER_HPP
