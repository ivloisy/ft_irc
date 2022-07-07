//
// Created by antoine on 01/07/22.
//

#ifndef FT_IRC_COMMAND_HPP
#define FT_IRC_COMMAND_HPP

#include "User.hpp"
#include <map>
#include <string>

using namespace std;

namespace irc
{
	class User;
	class Server;

	class Command
	{
		//typedef void (*pointer_function)(string &buf, User *it_user, Server &serv);
	private:
		//typedef void (*pointer_function)(void);
		//typedef map<string, pointer_function> map_cmd;

		User 									*user;
		Server 									*server;
		vector<string> 							parameters;

	public:
		Command(Server * serv, User * user, vector<string> & params);
		virtual ~Command();

		string									get_reply(unsigned short code, string servername, string nickname);
		//void									reply(Server & serv, User & user, unsigned short code, string nickname);

		Server									&getServer();
		User									&getUser();
		vector<string>							getParameters();

		void									print_parameters();
	};
}

#endif //FT_IRC_COMMAND_HPP
