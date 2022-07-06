//
// Created by blyzance on 18/06/22.
//

#ifndef FT_IRC_SERVER_HPP
#define FT_IRC_SERVER_HPP

#include <netinet/in.h>
#include <sys/socket.h>
#include "User.hpp"
#include "Config.hpp"
#include "Message.hpp"

namespace irc
{
	class User;

	class Server {

	public:
		//typedef void (*pointer_function)(string &buf, User *it_user, Server &serv);
		//typedef void (*pointer_function)(void);
		//typedef std::map<std::string, pointer_function>		map_cmd;

	private:
		int 												_fd;
		int													_fdMax;
		struct sockaddr_in									_serverAddr;
		std::string											_serverName; //identify the server, has a max length of 63 chars. servername = hostname
		socklen_t 											_size;
		std::vector<User *>									_user; //we're going to delete it for the instanciation with set
		//std::vector<Channel *>							_channels;
		int													_portNum; //default port 6667
		//Command											_commands;
		//std::set<User *>									user; *Store the different users
		//Config											_config; *I don't know if we're gonna use a config file. if yes, we're going to store it there
		//std::string										_upTime;
		bool												_state;

	public:
		Server();
		Server(Server const & src);
		virtual ~Server();

		//Server operator=(Server const & src);

		//Config											&getConfig();
		//std::string										getUpTime();

		//void												add_user(User user);

		void												establishConnection(void);
		void												bindServer(void);
		void												createServerAddr(int portNum);
		//void												listenUser(void);
		int													acceptUser(socklen_t size);
		void												closeUser(User * user);

		int													getFdMax( void ) const;
		int													getFdServer() const;
		struct sockaddr_in									getServerAddr() const;
		User												*getUser();
		socklen_t											getSize() const;
		int													getPortNum() const;
		std::string											getServerName() const;
		bool												getState() const;

		void												setState(bool st);
		void												setFdServer(int fd);
		void												setUpFdMax(int fdCurrent);
		// void												setDownFdMax(int fdCurrent);

		bool												isUserEmpty();
	};
}

#endif //FT_IRC_SERVER_HPP
