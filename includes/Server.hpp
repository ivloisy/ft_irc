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
		//int client; //(instantiation client)
		int 					_fd;
		//int nbClients; (client class, static variable)
		//std::map<int, Channel> channels; (instantiation channels)
		//int portNum;
		struct sockaddr_in		_serverAddr;
		std::string				_serverName; //identify the server, has a max length of 63 chars. servername = hostname
		//std::set<User *> 		user; *Store the different users
		socklen_t 				_size;
		//Config 				_config; *I don't know if we're gonna use a config file. if yes, we're going to store it there
		//std::string 			_upTime;
		std::vector<irc::User>	_user; //we're going to delete it for the instanciation with set
		//int 					bufsize; //is 512
		//std::string 			buffer;//we're going to instanciate it in user, but server is gonna send message too so mayke keep it
		int						_portNum; //default port 6667

	public:
		Server();
		Server(Server const & src);
		virtual ~Server();

		Server operator=(Server const & src);

		Config 				&getConfig();
		std::string 		getUpTime();

		void				add_user(irc::User user);

		void				establishConnection(void);
		void				bindServer(void);
		void				createServerAddr(int portNum);
		void				listenUser(void);
		int 				acceptUser(irc::User & user, socklen_t size);
		void				closeUser(irc::User & user);

		int 				&getFdServer();
		struct sockaddr_in	getServerAddr() const;
		irc::User 			&getUser();
		socklen_t			getSize() const;
		int 				getPortNum() const;

		std::string 		getServerName() const;
	};
}

#endif //FT_IRC_SERVER_HPP
