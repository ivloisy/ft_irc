//
// Created by blyzance on 18/06/22.
//

#include "../includes/Server.hpp"
#include "../includes/User.hpp"
#include "../includes/Channel.hpp"
#include <iostream>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <fcntl.h>
#include "../includes/Reply.hpp"
#include <utility>
#include <map>
#include <string>
#include <algorithm>
#include "../includes/ft_irc.hpp"

using namespace irc;
using namespace std;

/******************** CONSTRUCTORS **********************/

Server::Server(int portNum) :
	_serverName("irc.sample.com"),
	_portNum(portNum),
	_state(1)
	// _cmap()
{
	// socklen_t size;

	this->establishConnection();

	this->_fdMax = this->_fd;

	this->createServerAddr(this->_portNum);


	int optval = 1;
	if (setsockopt(this->_fd, SOL_SOCKET, SO_REUSEADDR,&optval, sizeof(optval)) < 0)
	{
		cout << "error setting socket option..." << endl;
	}


	this->bindServer();


	this->_size = sizeof(this->getServerAddr());

	if (listen(this->_fd, this->getServerAddr().sin_port) < 0)
	{
		//error
		;
	}
	this->initCommand();

	// this->init_map_cmd();

}

Server::Server(Server const & src)
{
	*this = src;
	return;
}

Server::~Server()
{
	this->_user.clear();
	return;
}

/******************** CONNECTION **********************/

void				 Server::establishConnection(void)
{
	this->_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (this->_fd < 0)
	{
		cout << "Error establishing connection..." << endl;
		//exit(1);
		return ;
	}
	cout << "Server Socket connection created..." << endl;
}

void				Server::createServerAddr(int portNum)
{
	this->_serverAddr.sin_family = AF_INET;
	this->_serverAddr.sin_addr.s_addr = htons(INADDR_ANY);
	this->_serverAddr.sin_port = htons(portNum);
}

int				Server::bindServer()
{
	if (bind(this->_fd, (struct sockaddr*)&this->_serverAddr, sizeof(this->_serverAddr)) < 0 )
	{
		cout << "Error binding socket..." << endl;
		return (0);
	}
	return (1);
}

int					Server::acceptUser(socklen_t  size)
{
	int fd = accept(this->_fd, (struct sockaddr*)&this->_serverAddr,
						  reinterpret_cast<socklen_t *>(&size));
	if (fd < 0)
	{
		cout << "Error on accepting..." << endl;
		return (-1);
	}
	vector<User *>::iterator it = _user.begin();
	while (it != _user.end() && (*it)->getFdUser() > fd)
		it++;
	_user.insert(it, new User(fd, this->_serverAddr));
	return (fd);
}

void				Server::closeUser(User * user)
{
	close(user->getFdUser());
}


void					Server::initCommand()
{


	map_cmd["CAP"] 		= 	cap_cmd;
	map_cmd["DIE"] 		= 	user_cmd;
	map_cmd["JOIN"] 	= 	join_cmd;
	map_cmd["LIST"] 	= 	list_cmd;
	map_cmd["MODE"] 	= 	mode_cmd;
	map_cmd["NAMES"] 	= 	names_cmd;
	map_cmd["NICK"] 	=	nick_cmd;
	map_cmd["NOTICE"] 	= 	notice_cmd;
	map_cmd["OPER"] 	= 	oper_cmd;
	map_cmd["PART"] 	=	part_cmd;
	map_cmd["PASS"] 	= 	pass_cmd;
	map_cmd["PING"] 	= 	ping_cmd;
	map_cmd["PONG"] 	= 	pong_cmd;
	map_cmd["PRIVMSG"] 	=	privmsg_cmd;
	map_cmd["QUIT"] 	=	quit_cmd;
	map_cmd["REHASH"] 	= 	rehash_cmd;
	map_cmd["RESTART"] 	= 	restart_cmd;
	map_cmd["SQUIT"] 	= 	squit_cmd;
	map_cmd["USER"] 	= 	user_cmd;
	map_cmd["WALLOPS"] 	= 	wallops_cmd;
	map_cmd["WHOIS"] 	= 	whois_cmd;
}

void 					Server::welcome(int fd)
{
	if (this->getUser(fd)->getRdySend() != 3)
		return;
	string buf = ft_reply(this->_serverName, RPL_WELCOME, this->getUser(fd)->getNickName(), "Welcome to the Internet Relay Network");
	cout << buf << endl;
	send(fd, buf.c_str(), buf.length(), 0);
	buf = ft_reply(this->_serverName, RPL_YOURHOST, this->getUser(fd)->getNickName(), "Your host is localhost running version osef");
	cout << buf << endl;
	send(fd, buf.c_str(), buf.length(), 0);
	buf = ft_reply(this->_serverName, RPL_CREATED, this->getUser(fd)->getNickName(), "This server was created now");
	cout << buf << endl;
	send(fd, buf.c_str(), buf.length(), 0);
	buf = ft_reply(this->_serverName, RPL_MYINFO, this->getUser(fd)->getNickName(), "MYINFO");
	send(fd, buf.c_str(), buf.length(), 0);

}

void					Server::parse_buffer_command(string buffer, int fd)
{
	this->_param.clear();
	this->tokenize(/*this->*/buffer/*,  serv*/, fd); //this splits the buffer into different vectors of parameters
	// Uncomment this for printing parameters
	// for(vector<Command *>::iterator itc = this->_command.begin(); itc != this->_command.end(); itc++)
	// {
	// 	(*itc)->print_parameters();
	// 	cout << "nl" << endl;
	// }

	// for (size_t i = 0; i < this->_param.size(); i++)
	// {
	// 	cout << "param[" << i << "] = { ";
	// 	for (size_t j = 0; j < this->_param[i].size(); j++)
	// 	{
	// 	 	cout << this->_param[i][j];
	// 		if (j + 1 != this->_param[i].size())
	// 			cout << "; ";
	// 		else
	// 			cout << " }" << endl;
	// 	}
	// }
	// cout << endl;

	// cout << this->_param[0][0] << endl;

	//			Uncomment this for executing commands
	// for (vector<Command *>::iterator itc = this->_command.begin(); itc != this->_command.end(); itc++)
	// {
	// 	cmap.find(*(*itc)->getParameters().begin())->second(*itc);
	// }


	// if (this->getAcceptConnect()) // connection ok
	// {
	// 	this->connection_replies(*this->_command.begin());
	// 	this->setAcceptConnect(0);
	// }
}

void					Server::tokenize(string const & str, int fd)
{
	stringstream 			ss(str);
	string					s;
	vector<string>	tmp;

	int	i = 0;

	while (getline(ss, s, '\r'))
	{
		this->getUser(fd)->setRdySend();
		stringstream o(s);
		string u;
		while (getline(o, u, ' '))
			tmp.push_back(u);
		this->_param.push_back(tmp);
		tmp.clear();
		i++;
		getline(ss, s, '\n');
	}
}

void				Server::printParam()
{
	int	i = 0;

	for (vector<vector<string> >::iterator it = this->_param.begin(); it != this->_param.end(); it++)
	{
		cout << "param[" << i << "] = { ";
		for (vector<string>::iterator jt = (*it).begin(); jt != (*it).end(); jt++)
		{
			cout << *jt << "; ";
		}
		cout << " }" << endl;
		i++;
	}
}

void 				Server::execCommand(int fd)
{
	for (int x = 0; x < static_cast<int>(this->_param.size()); x++)
		this->map_cmd.find(this->_param[x][0])->second(this, this->getUser(fd), this->_param[x]);
}

int					Server::searchNick(string nick)
{
	vector<User *>::iterator last = this->_user.end();
	for (vector<User *>::iterator it = this->_user.begin(); it != last; it++)
	{
		if ((*it)->getNickName() == nick)
		{
			return ((*it)->getFdUser());
		}
	}
	return (0);
}

void				Server::sendToChan(string name, string msg)
{
	vector<User *> chan_usr = this->getChannel(name)->getChannelUsers();
	vector<User *>::iterator last = chan_usr.end();
	for (vector<User *>::iterator it = chan_usr.begin(); it != last; it++)
		sendBuffer(*it, msg);
}

void				Server::sendToUser(string name, string msg)
{
	sendBuffer(this->getUser(name), msg);
}

void				Server::sendBuffer(User * dest, string content)
{
	(void)content;
	send(dest->getFdUser(), content.c_str(), content.length(), 0);
}

Channel				*Server::addChannel(string name)
{
	this->_channel.push_back(new Channel(name));
	return *(this->_channel.end() - 1);
}

Channel				*Server::searchChannel(string name)
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

void				Server::delUserAllChannel(User * user)
{
	vector<Channel *>::iterator last = this->_channel.end();
	for (vector<Channel *>::iterator it = this->_channel.begin(); it != last; it++)
	{
		(*it)->delUser(user);
	}
}

/******************** ACCESSORS **********************/

int 				Server::getFdMax() const
{
	return this->_fdMax;
}


void 				Server::setUpFdMax(int fdCurrent)
{
	if (fdCurrent > this->_fdMax)
		this->_fdMax = fdCurrent;
}

/*
void 				Server::setDownFdMax(int fdCurrent)
{
}
*/

int					Server::getFdServer(void) const
{
	return (this->_fd);
}

struct sockaddr_in	Server::getServerAddr() const
{
	return (this->_serverAddr);
}

vector<User *>		Server::getUser() const
{
	return (this->_user);
}

User 				*Server::getUser(int fd)
{
	vector<User *>::iterator it = this->_user.begin();
	while (it != _user.end() && (*it)->getFdUser() != fd)
		it++;
	return (*it);
}

User 				*Server::getUser(string nick)
{
	vector<User *>::iterator it = this->_user.begin();
	while (it != _user.end() && (*it)->getNickName() != nick)
		it++;
	return (*it);
}

// User 				*Server::getUser(string nickname)
// {
// 	vector<User *>::iterator last = this->_user.end();
// 	for (vector<User *>::iterator it = this->_user.begin(); it != last; it++)
// 	{
// 		if ((*it)->getNickName() == nickname)
// 		{
// 			return (*it);
// 		}
// 	}
// 	return (NULL);
// }

Channel				*Server::getChannel(string name)
{
	vector<Channel *>::iterator last = this->_channel.end();
	for (vector<Channel *>::iterator it = this->_channel.begin(); it != last; it++)
	{
		if ((*it)->getChannelName() == name)
			return (*it);
	}
	return (NULL);
}

socklen_t			Server::getSize() const
{
	return (this->_size);
}

int 				Server::getPortNum() const
{
	return (this->_portNum);
}

vector<User *>		Server::getOper() const
{
	return (this->_oper);
}

User				*Server::getOper(string name)
{
	vector<User *>::iterator last = this->_oper.end();
	for (vector<User *>::iterator it = this->_oper.begin(); it != last; it++)
	{
		if ((*it)->getUserName() == name)
			return (*it);
	}
	return (NULL);
}

/********************* MUTATORS *************************/

string 				Server::getServerName() const
{
	return (this->_serverName);
}

void				Server::setFdServer(int fd)
{
	this->_fd = fd;
}

bool				Server::isUserEmpty()
{
	return (this->_user.empty());
}

bool				Server::getState() const
{
	return	(this->_state);
}

void				Server::setState(bool st)
{
	this->_state = st;
}
