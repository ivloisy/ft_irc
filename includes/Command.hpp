//
// Created by alangloi on 6/23/22.
//

#ifndef FT_IRC_COMMAND_HPP
#define FT_IRC_COMMAND_HPP

#include <sstream>
#include <string>
#include <vector>
#include "User.hpp"
#include "Server.hpp"

//using namespace irc;

namespace irc
{
	class User;
	//class Server;

	class Command {

	private:
		irc::User		*user;
		//irc::Server	server;

		std::string		query;

		std::string		get_reply(unsigned short code, std::string servername, std::string nickname);

	public:
		//Command(User *user, Server *server, std::string message);
		//~Command();

		//irc::User			getUser();
		//irc::Server			getServer();

		void			reply(irc::User &user, unsigned short code, std::string servername, std::string nickname);
	};
}

#endif //FT_IRC_COMMAND_HPP
