//
// Created by antoine on 06/07/22.
//

#include "../includes/Channel.hpp"

/******************** CONSTRUCTORS ***********************/

Channel::Channel(std::string name) :
	_name(name)
{
	return ;
}

/********************** GETTERS **************************/

User					*Channel::getUser(std::string nickname)
{
	std::vector<User *>::iterator last = this->_user.end();
	for (std::vector<User *>::iterator it = this->_user.begin(); it != last; it++)
	{
		if ((*it)->getNickName() == nickname)
			return (*it);
	}
	return (NULL);
}

std::string 			Channel::getChannelName() const
{
	return (this->_name);
}

/********************** SETTERS **************************/

void					Channel::setChannelName(std::string name)
{
	this->_name = name;
}