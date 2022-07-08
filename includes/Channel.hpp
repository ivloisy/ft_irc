//
// Created by antoine on 06/07/22.
//

#ifndef FT_IRC_CHANNEL_HPP
#define FT_IRC_CHANNEL_HPP

#include "User.hpp"
#include <iostream>
#include <bitset>

using namespace std;

namespace irc
{
	class User;

	class Channel {

		int 					_maxUsers;
		vector<User *>			_user; //current users present in the channel
		map<User *, bitset<3> >	_userMode;
		vector<User *>			_oper;
		vector<User *>			_invite;
		vector<User *>			_ban;
		bitset<2>				_mode;
		bool					_inviteOnlyMode;
		string 					_key;
		string 					_name; //begining with &#+| 50 char max and case insensitive, no spaces, no ^G, no coma, : is used for channel mask
		//channel modes, the modes affect the way servers manage the channels
		//privilegied members (operators?)


	public:
		Channel(string name);
		//virtual ~Channel();
		//Channel(Channel const &src);
		//Channel	operator=(Channel const &rhs);

		vector<User *>			getChannelUsers() const;
		User					*getUser(string nickname);
		vector<User *>			getChannelOpers() const;
		User					*getOper(string nickname);
		vector<User *>			getChannelInvite() const;
		User					*getInvite(string nickname);
		vector<User *>			getBanned() const;
		User					*getBanned(string nickname);
		map<User *, bitset<3> >	getChannelUserMode() const;
		bitset<3>				getUserMode(User *user);
		bitset<2>				getMode() const;
		string 					getKey() const;
		string 					getChannelName() const;
		bool					getInviteOnlyMode() const;

		bool 					isMaxUsers();

		void					setUserMode(User * user, bitset<3> mode);
		void					setInviteOnlyMode(bool set);
		void					setMode(bitset<2> mode);
		void					setKey(string key);

		void					addUserMode(User * user, bitset<3> mode);
		void					addUser(User * user);
		void					addOper(User * user);
		void					addInvite(User * user);
		void					addBanned(User * user);

		void					delUserMode(User * user);
		void					delUser(User * user);
		void					delOper(User * user);
		void					delInvite(User * user);
		void					delBanned(User * user);


		void				setChannelName(string name);

	};
}

#endif //FT_IRC_CHANNEL_HPP
