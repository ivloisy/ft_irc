//
// Created by antoine on 06/07/22.
//

#include "../includes/Channel.hpp"

using namespace irc;
using namespace std;

/******************** CONSTRUCTORS ***********************/

Channel::Channel(string name) :
	_user(),
	_oper(),
	_invite(),
	_name(name)
{
	//string 				_key;
	//string 				_mode;
	return ;
}

/********************** GETTERS **************************/

vector<User *>		Channel::getChannelUsers() const
{
	return (this->_user);
}

User				*Channel::getUser(string nickname)
{
	vector<User *>::iterator last = this->_user.end();
	for (vector<User *>::iterator it = this->_user.begin(); it != last; it++)
	{
		if ((*it)->getNickName() == nickname)
			return (*it);
	}
	return (NULL);
}

string 				Channel::getChannelName() const
{
	return (this->_name);
}

vector<User *>		Channel::getChannelOpers() const
{
	return (this->_oper);
}

User				*Channel::getOper(string nickname)
{
	vector<User *>::iterator last = this->_oper.end();
	for (vector<User *>::iterator it = this->_oper.begin(); it != last; it++)
	{
		if ((*it)->getNickName() == nickname)
			return (*it);
	}
	return (NULL);
}

vector<User *>		Channel::getChannelInvite() const
{
	return (this->_invite);
}

User				*Channel::getInvite(string nickname)
{
	vector<User *>::iterator last = this->_invite.end();
	for (vector<User *>::iterator it = this->_invite.begin(); it != last; it++)
	{
		if ((*it)->getNickName() == nickname)
			return (*it);
	}
	return (NULL);
}

string 				Channel::getMode() const
{
	return (this->_mode);
}

string 				Channel::getKey() const
{
	return (this->_key);
}



/********************** SETTERS **************************/

void				Channel::setChannelName(string name)
{
	this->_name = name;
}

void				Channel::setMode(string mode)
{
	this->_mode = mode;
}

void				Channel::setKey(string key)
{
	this->_key = key;
}

/******************** FUNCTIONS **************************/

void				Channel::addUser(User * user)
{
	this->_user.push_back(user);
}

void				Channel::addOper(User * user)
{
	this->_oper.push_back(user);
}

void				Channel::addInvite(User * user)
{
	this->_invite.push_back(user);
}

void				Channel::delUser(User * user)
{
	vector<User *>::iterator last = this->_user.end();
	for (vector<User *>::iterator it = this->_user.begin(); it != last; it++)
	{
		if (user->getNickName() == (*it)->getNickName())
			this->_user.erase(it);
	}
}

void				Channel::delOper(User * user)
{
	vector<User *>::iterator last = this->_oper.end();
	for (vector<User *>::iterator it = this->_oper.begin(); it != last; it++)
	{
		if (user->getNickName() == (*it)->getNickName())
			this->_oper.erase(it);
	}
}

void				Channel::delInvite(User * user)
{
	vector<User *>::iterator last = this->_invite.end();
	for (vector<User *>::iterator it = this->_invite.begin(); it != last; it++)
	{
		if (user->getNickName() == (*it)->getNickName())
			this->_invite.erase(it);
	}
}