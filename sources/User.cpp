//
// Created by antoine on 20/06/22.
//

#include "../includes/ft_irc.hpp"

using namespace irc;
using namespace std;

/**************************** CONSTRUCTORS ****************************/

User::User(int fd) :
		_fd(fd),
		_hostname(""),
		_realname(""),
		_username(""),
		_nickname(""),
		_password(""),
		_serverName(""),
		_prefix(""),
		_channel(),
		_currChan(NULL),
		_mode(string("01")),
		_acceptConnect(1),
		_isOper(0),
		_toClose(0),
		_rdySend(0)
{
	this->setPrefix();
	return;
}

/***************************** DESTRUCTORS ****************************/


User::~User()
{
	return;
}


/************************* ASSIGNMENT OPERATOR ************************/

User &User::operator=(User const &rhs)
{
	if (this != &rhs)
		this->_fd = rhs._fd;
	return (*this);
}

/********************** FUNCTIONS ****************************/

void					User::addChannel(Channel * chan)
{
	this->_channel.push_back(chan);
}

void					User::clearAllChannels()
{
	this->_channel.clear();
}

void					User::quitChannel(Channel * chan)
{
	vector<Channel *>::iterator last = this->_channel.end();
	for (vector<Channel *>::iterator it = this->_channel.begin(); it != last; it++)
		if (chan->getChannelName() == (*it)->getChannelName())
			this->_channel.erase(it);
}

/********************* GETTERS ***********************/

int 					User::getFdUser(void) const
{
	return (this->_fd);
}

string 					User::getPrefix() const
{
	return (this->_prefix);
}

string 					User::getHostname() const
{
	return (this->_hostname);
}

string 					User::getNickName() const
{
	return (this->_nickname);
}

string 					User::getPassWord() const
{
	return (this->_password);
}

string 					User::getUserName() const
{
	return (this->_username);
}

string					User::getRealName() const
{
	return (this->_realname);
}

vector<Channel *>		User::getChannel() const
{
	return (this->_channel);
}

Channel*				User::getChannelByName(string name)
{
	vector<Channel *>::iterator last = this->_channel.end();
	for (vector<Channel *>::iterator it = this->_channel.begin(); it != last; it++)
		if ((*it)->getChannelName() == name)
			return (*it);
	return (NULL);
}

bool					User::getAcceptConnect() const
{
	return (this->_acceptConnect);
}

bool					User::getOper() const
{
	return (this->_isOper);
}

int 					User::getRdySend() const
{
	return this->_rdySend;
}

bitset<2>				User::getMode() const
{
	return (this->_mode);
}

bool					User::getInvisible() const
{
	return (this->_isInv);
}

Channel*				User::getCurrentChannel()
{
	return (this->_currChan);
}

bool 				User::getToClose()
{
	return (this->_toClose);
}

/********************** SETTERS ***********************/

void					User::setPrefix()
{
	this->_prefix = ":" + _nickname + "!" + _username + "@" + _hostname;
}

void					User::setInvisible(bool const & inv)
{
	this->_isInv = inv;
}

void					User::setMode(bitset<2> const & mode)
{
	this->_mode = mode;
}

void					User::setOper(bool const & op)
{
	this->_isOper = op;
}

void					User::setAcceptConnect(bool const & ac)
{
	this->_acceptConnect = ac;
}

void 					User::setFdUser(int const & fd)
{
	this->_fd = fd;
}

void					User::setNickName(string const & nickname)
{
	this->_nickname = nickname;
}

void					User::setUserName(string const & username)
{
	this->_username = username;
}

void					User::setRealName(string const & realname)
{
	this->_realname = realname;
}

void					User::setHostName(string const & hostname)
{
	this->_hostname = hostname;
}

void					User::setPassWord(string const & password)
{
	this->_password = password;
}

void 					User::setRdySend()
{
	if (this->_rdySend < 5)
		this->_rdySend++;
}

void 					User::setToClose(int const & x)
{
	this->_toClose = x;
}

void					User::setCurrentChannel(Channel * chan)
{
	this->_currChan = chan;
}

void					User::setServerName(string const & name)
{
	this->_serverName = name;
}
