//
// Created by antoine on 06/07/22.
//

#ifndef FT_IRC_CHANNEL_HPP
#define FT_IRC_CHANNEL_HPP

#include "ft_irc.hpp"

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
		string					_topic;
		//channel modes, the modes affect the way servers manage the channels
		//privilegied members (operators?)


	public:
		Channel(string name);

		vector<User *>			getChannelUsers() const;
		User					*getUser(string const & nickname);
		vector<User *>			getChannelOpers() const;
		User					*getOper(string const & nickname);
		vector<User *>			getChannelInvite() const;
		User					*getInvite(string const & nickname);
		vector<User *>			getBanned() const;
		User					*getBanned(string const & nickname);
		map<User *, bitset<3> >	getChannelUserMode() const;
		bitset<3>				getUserMode(User * user);
		bitset<2>				getMode() const;
		string 					getKey() const;
		string 					getChannelName() const;
		bool					getInviteOnlyMode() const;
		string					getTopic() const;

		bool 					isMaxUsers();
		bool					isUserHere(User const * usr);

		void					setUserMode(User * user, bitset<3> const & mode);
		void					setInviteOnlyMode(bool const & set);
		void					setMode(bitset<2> const & mode);
		void					setKey(string const & key);
		void					setChannelName(string const & name);
		void					setTopic(string const & topic);

		void					addUserMode(User * user, bitset<3> const & mode);
		void					addUser(User * user);
		void					addOper(User * user);
		void					addInvite(User * user);
		void					addBanned(User * user);

		void					delUserMode(User * user);
		void					delUser(User * user);
		void					delOper(User * user);
		void					delInvite(User * user);
		void					delBanned(User * user);

		string const 			printAllUsers();

	};
}

#endif //FT_IRC_CHANNEL_HPP
