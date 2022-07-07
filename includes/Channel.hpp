//
// Created by antoine on 06/07/22.
//

#ifndef FT_IRC_CHANNEL_HPP
#define FT_IRC_CHANNEL_HPP

#include "User.hpp"
#include <iostream>

using namespace std;

namespace irc
{
	class User;

	class Channel {

		vector<User *>		_user; //current users present in the channel
		string 				_name; //begining with &#+| 50 char max and case insensitive, no spaces, no ^G, no coma, : is used for channel mask
		//channel modes, the modes affect the way servers manage the channels
		//privilegied members (operators?)


	public:
		Channel(string name);
		//virtual ~Channel();
		//Channel(Channel const &src);
		//Channel	operator=(Channel const &rhs);

		vector<User *>		getChannelUsers() const;
		User				*getUser(string nickname);
		string 				getChannelName() const;

		void				setChannelName(string name);

	};
}

#endif //FT_IRC_CHANNEL_HPP
