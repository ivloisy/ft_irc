//
// Created by antoine on 06/07/22.
//

#include "../includes/Channel.hpp"

using namespace irc;
using namespace std;

/******************** CONSTRUCTORS ***********************/

Channel::Channel(string name) :
	_name(name)
{
	return ;
}

/********************** GETTERS **************************/

vector<User *>		Channel::getChannelUsers() const
{
	return (this->_user);
}

User					*Channel::getUser(string nickname)
{
	vector<User *>::iterator last = this->_user.end();
	for (vector<User *>::iterator it = this->_user.begin(); it != last; it++)
	{
		if ((*it)->getNickName() == nickname)
			return (*it);
	}
	return (NULL);
}

string 			Channel::getChannelName() const
{
	return (this->_name);
}

/********************** SETTERS **************************/

void					Channel::setChannelName(string name)
{
	this->_name = name;
}

/******************** FUNCTIONS **************************/

