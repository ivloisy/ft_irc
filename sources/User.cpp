#include "User.hpp"

User::User()
{
	return;
}

User::User(User const & src)
{
	return;
}

User::~User()
{
	return;
}

void User::setBan(User sender)
{
	ban = push_back();
}

std::string User::getNickname() const
{
	return this->_nickname;
}

std::string User::getPassword() const
{
	return this->_password;
}

std::string User::getStatus() const
{
	return this->_status;
}

std::string User::getChannel() const
{
	return this->_channel;
}

bool User::isOperator() const
{
	return this->_operator;
}

bool User::isActif() const
{
	return this->_actif;
}
