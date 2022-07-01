//
// Created by alangloi on 6/23/22.
//


#ifndef FT_IRC_MESSAGE_HPP
#define FT_IRC_MESSAGE_HPP

#include <sstream>
#include <string>
#include <vector>
#include "User.hpp"
#include "Server.hpp"

//using namespace irc;

namespace irc
{
	class User;
	class Server;

	class Message {

	private:
		User			*user;
		//Server		server;

		std::string			query;

		std::string			get_reply(unsigned short code, std::string servername, std::string nickname);

	public:
		//Message(User *user, Server *server, std::string message);
		//~Message();

		//User			getUser();
		//Server		getServer();

		void				reply(Server & serv, User &user, unsigned short code, std::string nickname);
	};
}

#endif //FT_IRC_MESSAGE_HPP
