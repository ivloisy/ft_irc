//
// Created by antoine on 01/07/22.
//

#ifndef FT_IRC_COMMAND_HPP
#define FT_IRC_COMMAND_HPP

#include "User.hpp"
#include <map>
#include <string>

namespace irc
{
	class User;
	class Server;

	class Command
	{
		//typedef void (*pointer_function)(string &buf, User *it_user, Server &serv);
	private:
		//typedef void (*pointer_function)(void);
		//typedef std::map<std::string, pointer_function> map_cmd;

		User 									*user;
		Server 									*server;
		std::vector<std::string> 				parameters;

	public:
		Command(Server * serv, User * user, std::vector<std::string> & params);
		virtual ~Command();

		std::string								get_reply(unsigned short code, std::string servername, std::string nickname);
		void									reply(Server & serv, User & user, unsigned short code, std::string nickname);

		Server									&getServer();
		User									&getUser();
		std::vector<std::string>				getParameters();

		void									print_parameters();
	};
}

#endif //FT_IRC_COMMAND_HPP
