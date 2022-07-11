//
// Created by antoine on 06/07/22.
//

#include "../includes/ft_irc.hpp"

using namespace irc;
using namespace std;

/******************** CONSTRUCTORS ***********************/

Channel::Channel(string name) :
	_maxUsers(10),
	_user(),
	_oper(),
	_invite(),
	_ban(),
	_inviteOnlyMode(0),
	_key(),
	_name(name)
{

	return ;
}

/********************** GETTERS **************************/

vector<User *>			Channel::getChannelUsers() const
{
	return (this->_user);
}

User*					Channel::getUser(string const & nickname)
{
	//into try catch or send null
	vector<User *>::iterator last = this->_user.end();
	for (vector<User *>::iterator it = this->_user.begin(); it != last; it++)
	{
		if ((*it)->getNickName() == nickname)
			return (*it);
	}
	return (NULL);
}

string 					Channel::getChannelName() const
{
	return (this->_name);
}

vector<User *>			Channel::getChannelOpers() const
{
	return (this->_oper);
}

User*					Channel::getOper(string const & nickname)
{
	//into try catch or send null
	vector<User *>::iterator last = this->_oper.end();
	for (vector<User *>::iterator it = this->_oper.begin(); it != last; it++)
	{
		if ((*it)->getNickName() == nickname)
			return (*it);
	}
	return (NULL);
}

vector<User *>			Channel::getChannelInvite() const
{
	return (this->_invite);
}

User*					Channel::getInvite(string const & nickname)
{
	//into try catch or send NULL
	vector<User *>::iterator last = this->_invite.end();
	for (vector<User *>::iterator it = this->_invite.begin(); it != last; it++)
	{
		if ((*it)->getNickName() == nickname)
			return (*it);
	}
	return (NULL);
}

vector<User *>			Channel::getBanned() const
{
	return (this->_ban);
}

User*					Channel::getBanned(string const & nickname)
{
	//into try catch or send NULL
	vector<User *>::iterator last = this->_ban.end();
	for (vector<User *>::iterator it = this->_ban.begin(); it != last; it++)
	{
		if ((*it)->getNickName() == nickname)
			return (*it);
	}
	return (NULL);
}

bitset<2> 				Channel::getMode() const
{
	return (this->_mode);
}

string 					Channel::getKey() const
{
	return (this->_key);
}

bool					Channel::getInviteOnlyMode() const
{
	return (this->_inviteOnlyMode);
}

map<User *, bitset<3> >	Channel::getChannelUserMode() const
{
	return (this->_userMode);
}

bitset<3>				Channel::getUserMode(User * user)
{
	//into try catch of beware to check is user exists before this function
	map<User *, bitset<3> >::iterator lst = _userMode.end();
	for (map<User *, bitset<3> >::iterator it = _userMode.begin(); it != lst; it++)
	{
		if ((*it).first == user)
		{
			return ((*it).second);
		}
	}
	return (0);
}

/******************* CHECKERS ****************************/

bool 					Channel::isMaxUsers()
{
	int cur = 0;

	vector<User *>::iterator last = this->_user.end();
	for (vector<User *>::iterator it = this->_user.begin(); it != last; it++)
	{
		cur++;
	}
	return (cur >= this->_maxUsers);
}

/********************** SETTERS **************************/

void					Channel::setUserMode(User * user, bitset<3> const & mode)
{
	//into try catch
	map<User *, bitset<3> >::iterator lst = _userMode.end();
	for (map<User *, bitset<3> >::iterator it = _userMode.begin(); it != lst; it++)
	{
		if ((*it).first == user)
		{
			(*it).second = mode;
		}
	}
}

void					Channel::setInviteOnlyMode(bool const & set)
{
	this->_inviteOnlyMode = set;
}

void					Channel::setChannelName(string const & name)
{
	this->_name = name;
}

void					Channel::setMode(bitset<2> const & mode)
{
	this->_mode = mode;
}

void					Channel::setKey(string const & key)
{
	this->_key = key;
}

/******************** FUNCTIONS **************************/

void					Channel::addUserMode(User * user, bitset<3> const & mode)
{
	_userMode[user] = mode;
}

void					Channel::addUser(User * user)
{
	this->_user.push_back(user);
}

void					Channel::addOper(User * user)
{
	this->_oper.push_back(user);
}

void					Channel::addInvite(User * user)
{
	this->_invite.push_back(user);
}

void					Channel::addBanned(User * user)
{
	this->_ban.push_back(user);
}

/******************* DELETE FUNCTIONS *************************/

void					Channel::delUserMode(User * user)
{
	this->_userMode.erase(user);
}

void					Channel::delUser(User * user)
{
	//into try catch
	vector<User *>::iterator last = this->_user.end();
	for (vector<User *>::iterator it = this->_user.begin(); it != last; it++)
	{
		if (user->getNickName() == (*it)->getNickName())
			this->_user.erase(it);
	}
}

void					Channel::delOper(User * user)
{
	//into try catch
	vector<User *>::iterator last = this->_oper.end();
	for (vector<User *>::iterator it = this->_oper.begin(); it != last; it++)
	{
		if (user->getNickName() == (*it)->getNickName())
			this->_oper.erase(it);
	}
}

void					Channel::delInvite(User * user)
{
	//into try catch
	vector<User *>::iterator last = this->_invite.end();
	for (vector<User *>::iterator it = this->_invite.begin(); it != last; it++)
	{
		if (user->getNickName() == (*it)->getNickName())
			this->_invite.erase(it);
	}
}

void					Channel::delBanned(User * user)
{
	//into try catch
	vector<User *>::iterator last = this->_ban.end();
	for (vector<User *>::iterator it = this->_ban.begin(); it != last; it++)
	{
		if (user->getNickName() == (*it)->getNickName())
			this->_ban.erase(it);
	}
}

string const 			Channel::printAllUsers()
{
	string result;
	for (vector<User *>::iterator it = _user.begin(); it != _user.end(); it++)
	{
		result += (*it)->getNickName();
		result += " ";
	}
	result.erase(result.size());
	//cout << "MEMBERS = " << result << endl;
	return (result);
}
