//
// Created by antoine on 20/06/22.
//

#include "../includes/ft_irc.hpp"

using namespace irc;
using namespace std;

/**************************** CONSTRUCTORS ****************************/

User::User(int fd) :
		// cmap(),
		_fd(fd),
		_hostname(),
		_nickname("lala"),
		// bufsize(512),
		_command(),
		_currChan(NULL),
		_mode(string("01")),
		_acceptConnect(1),
		_isOper(0),
		_toClose(0),
		_rdySend(0)
{
	// (void) address;
	// init_map_cmd();
}



User::User(int fd, struct sockaddr_in address) :
		// cmap(),
		_fd(fd),
		_hostname(),
		_nickname("lala"),
		// bufsize(512),
		_command(),
		_currChan(NULL),
		_mode(1),
		_acceptConnect(1),
		_isOper(0),
		_toClose(0),
		_rdySend(0)
{
	(void) address;
	// init_map_cmd();
}

/*
User::User(User const &src)
{
	;
}
*/

/***************************** DESTRUCTORS ****************************/


User::~User()
{
	;
}


/************************* ASSIGNMENT OPERATOR ************************/

User &User::operator=(User const &rhs)
{
	if (this != &rhs)
	{
		this->_fd = rhs._fd;
	}
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
	{
		if (chan->getChannelName() == (*it)->getChannelName())
		{
			this->_channel.erase(it);
		}
	}
}

/********************* GETTERS ***********************/

int 					User::getFdUser(void) const
{
	return (this->_fd);
}

string 					User::getPrefix() const
{
	string prefix = "prefix";
	return (prefix);
}
//
// string 			&User::getBuffer()
// {
// 	return (this->buffer);
// }


// int 					User::getBufsize() const
// {
// 	return (this->bufsize);
// }

vector<Command *>	User::getCommand() const
{
	return (this->_command);
}

string 				User::getPassWord() const
{
	return (this->_password);
}

string 				User::getUserName() const
{
	return (this->_username);
}

string				User::getRealName() const
{
	return (this->_realname);
}

string 				User::getHostname() const
{
	return (this->_hostname);
}

string 				User::getNickName() const
{
	return (this->_nickname);
}

bool				User::getAcceptConnect() const
{
	return (this->_acceptConnect);
}

bool				User::getOper() const
{
	return (this->_isOper);
}

int 				User::getRdySend() const
{
	return this->_rdySend;
}

vector<Channel *>	User::getChannel() const
{
	return (this->_channel);
}

Channel				*User::getChannelByName(string name)
{
	vector<Channel *>::iterator last = this->_channel.end();
	for (vector<Channel *>::iterator it = this->_channel.begin(); it != last; it++)
	{
		if ((*it)->getChannelName() == name)
		{
			return (*it);
		}
	}
	return (NULL);
}

bitset<2>			User::getMode() const
{
	return (this->_mode);
}

bool				User::getInvisible() const
{
	return (this->_isInv);
}

Channel*			User::getCurrentChannel()
{
	return (this->_currChan);
}

bool 				User::getToClose()
{
	return (this->_toClose);
}


/********************** SETTERS ***********************/

void				User::setInvisible(bool inv)
{
	this->_isInv = inv;
}



void				User::setMode(bitset<2> mode)
{
	this->_mode = mode;
}

void				User::setOper(bool op)
{
	this->_isOper = op;
}

void 				User::setFdUser(int fd)
{
	this->_fd = fd;
}
//
// void					User::setBuffer(string buf)
// {
// 	this->buffer = buf;
// }

void				User::setNickName(string nickname)
{
	this->_nickname = nickname;
}

void				User::setUserName(string username)
{
	this->_username = username;
}

void				User::setRealName(string realname)
{
	this->_realname = realname;
}

void				User::setHostName(string hostname)
{
	this->_hostname = hostname;
}

void				User::setPassWord(string password)
{
	this->_password = password;
}

void				User::setAcceptConnect(bool ac)
{
	this->_acceptConnect = ac;
}

void 					User::setRdySend()
{
	if (this->_rdySend < 5)
		this->_rdySend++;
}

void 					User::setToClose(int x)
{
	this->_toClose = x;
}
