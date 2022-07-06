//
// Created by antoine on 06/07/22.
//

#ifndef FT_IRC_CHANNEL_HPP
#define FT_IRC_CHANNEL_HPP

#include "User.hpp"
#include <iostream>

namespace irc
{
	class User;

	class Channel {

		std::vector<User *>		_user; //current users present in the channel
		std::string 			_name; //begining with &#+| 50 char max and case insensitive, no spaces, no ^G, no coma, : is used for channel mask
		//channel modes, the modes affect the way servers manage the channels
		//privilegied members (operators?)


	public:
		Channel(std::string name);
		//virtual ~Channel();
		//Channel(Channel const &src);
		//Channel	operator=(Channel const &rhs);

		User					*getUser(std::string nickname);
		std::string 			getChannelName() const;

		void					setChannelName(std::string name);

	};
}

#endif //FT_IRC_CHANNEL_HPP
