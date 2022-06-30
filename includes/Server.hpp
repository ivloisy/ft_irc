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
		int 				_fdServer;
		//int nbClients; (client class, static variable)
		//std::map<int, Channel> channels; (instantiation channels)
		//int portNum;
		struct sockaddr_in	_serverAddr;
		std::string			_servername; //identify the server, has a max length of 63 chars. servername = hostname
		//std::map<int, User *> user;
		socklen_t 			size;
		Config 				_config;
		std::string 		_upTime;
		irc::User 			*user;
		//int 				bufsize;
		//char				*buffer;
		std::string 		buffer;
		int					portNum;

	public:
		Server();
		Server(Server const & src);
		virtual ~Server();

		Server operator=(Server const & src);

		Config 				&getConfig();
		std::string 		getUpTime();

		void				add_user(User user);

		void				bindServer(User const & user);
		void				createServerAddr(int portNum);
		void				listenUser(User const & user);
		int 				acceptUser(User const & user, int size);
		void				closeUser(User const & user);

		int 				getFdServer() const;
		struct sockaddr_in	getServerAddr() const;
		irc::User			*getUser() const;
		socklen_t			getSize() const;
		int 				getPortNum() const;
		std::string 		getBuffer() const;
		int 				getBufsize() const;
		std::string 		getServerName() const;
	};
}

#endif //FT_IRC_SERVER_HPP
