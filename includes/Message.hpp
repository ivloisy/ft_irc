//
// Created by antoine on 20/06/22.
//

//************************* USELESS FOR THE MOMENT *******************************

#ifndef FT_IRC_MESSAGE_HPP
#define FT_IRC_MESSAGE_HPP

#include "Command.hpp"

namespace irc
{
	//class Command;

	class Message
	{
		//sender, receiver, payload, command called
		//variable PASS, 1 if nick and password defined, 0 if not

		std::string                 _prefix;
		Command                     _command;
		std::vector<std::string>    _parameters;

	public:
		//Message();
		//virtual ~Message();
		//Message(Message const &src);
		//Message &operator=(Message const &rhs);

		void                        send_message(std::string prefix, Command command, std::vector<std::string> parameters);

		std::string                 getPrefix();
		Command                     getCommand();
		std::vector<std::string>    getParameters();
	};
}



#endif //FT_IRC_MESSAGE_HPP
