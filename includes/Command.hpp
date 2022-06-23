//
// Created by alangloi on 6/23/22.
//

#ifndef FT_IRC_COMMAND_HPP
#define FT_IRC_COMMAND_HPP

#include <sstream>
#include "User.hpp"

namespace irc
{
	class User;
	class Server;

	class Command {

	private:
		User		*user;
		Server		*server;

		std::string query;

		std::string	getReplies(unsigned short code, std::string arg1, std::string arg2, std::string arg3, std::string arg4, std::string arg5, std::string arg6, std::string arg7);

	public:
		Command(User *user, Server *server, std::string message);
		~Command();

		User		&getUser();
		Server		&getServer();

		void		reply(User &user, unsigned short code, std::string arg1 = "", std::string arg2 = "", std::string arg3 = "", std::string arg4 = "", std::string arg5 = "", std::string arg6 = "", std::string arg7 = "");
		void		reply(unsigned short code, std::string arg1 = "", std::string arg2 = "", std::string arg3 = "", std::string arg4 = "", std::string arg5 = "", std::string arg6 = "", std::string arg7 = "");
	};
}



#endif //FT_IRC_COMMAND_HPP
