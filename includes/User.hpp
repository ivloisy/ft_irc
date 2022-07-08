//
// Created by antoine on 20/06/22.
//

#ifndef FT_IRC_CLIENT_HPP
#define FT_IRC_CLIENT_HPP

#include "ft_irc.hpp"

using namespace std;

namespace irc
{
	//class Message;
	class Server;
	class Command;

	class User
	{
	private:
		int 												_fd;
		string												_hostname;
		string 												_realname;
		string 												_username;
		string												_nickname;
		string 												_password;
		string 												_serverName;
		string 												_prefix;
		vector<string>										parameters;
		int 												bufsize;
		vector<Channel *>									_channel;
		Channel												*_currChan;
		bitset<2> 											_mode;
		bool												_acceptConnect;
		bool												_isOper;
		bool												_isInv;
		bool												_toClose;
		int													_rdySend;

		//if client send a cap command, ignore it

	public:
		User(int fd, struct sockaddr_in address);
		User(int fd);
		virtual ~User();
		User &operator=(User const &rhs);

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
		vector<Channel *>									getChannel() const;
		Channel												*getChannelByName(string name);
		bool												getAcceptConnect() const;
		bool												getOper() const;
		int 												getRdySend() const;
		bitset<2> 											getMode() const;
		bool												getInvisible() const;
		Channel												*getCurrentChannel();

		void												setPrefix();
		void												setInvisible(bool inv);
		void												setMode(bitset<2> mode);
		void												setOper(bool op);
		void												setAcceptConnect(bool ac);
		void 												setFdUser(int fd);
		void												setNickName(string nickname);
		void												setUserName(string username);
		void												setRealName(string realname);
		void												setHostName(string hostname);
		void												setPassWord(string password);
		void 												setRdySend();
		void 												setToClose(int x);
		void												setCurrentChannel(Channel * chan);
		void												setServerName(string name);

		//void												send_message(int nb_command, Server server);

	};
	// bool	operator<(const User & lhs, const User & rhs);
	// bool	operator>(const User & lhs, const User & rhs);
}



#endif //FT_IRC_CLIENT_HPP
