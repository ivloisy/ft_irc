//
// Created by blyzance on 18/06/22.
//

#include "../includes/Server.hpp"
#include "../includes/User.hpp"
#include <iostream>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <fcntl.h>
#include "../includes/Reply.hpp"
#include <utility>
#include "../includes/ft_irc.hpp"

using namespace irc;
using namespace std;

/******************** CONSTRUCTORS **********************/

Server::Server() :
	_serverName("irc.sample.com"),
	_portNum(6667),
	_state(1)
	// _cmap()
{
	// socklen_t size;

	this->establishConnection();

	this->_fdMax = this->_fd;

	this->createServerAddr(this->_portNum);

	/*
	int optval = 1;
	if (setsockopt(this->_fd, SOL_SOCKET, SO_REUSEADDR,&optval, sizeof(optval)) < 0)
	{
		cout << "error setting socket option..." << endl;
	}
	*/

	this->bindServer();


	this->_size = sizeof(this->getServerAddr());

	if (listen(this->_fd, this->getServerAddr().sin_port) < 0)
	{
		//error
		;
	}
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

/******************** FUNCTIONS **********************/

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


void					Server::exec_command()
{
	typedef void (*pointer_function)(void);
	map<string, pointer_function>		map_cmd;

	map_cmd["CAP"] 		= 	cap_cmd;
	map_cmd["DIE"] 		= 	user_cmd;
	map_cmd["JOIN"] 	= 	join_cmd;
	map_cmd["LIST"] 	= 	list_cmd;
	map_cmd["MODE"] 	= 	mode_cmd;
	map_cmd["MSG"] 		= 	msg_cmd;
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
}

void 					Server::welcome(int fd)
{
	string buf = ft_reply(RPL_WELCOME, "WELCOME");
	send(fd, buf.c_str(), buf.length(), 0);
	buf = ft_reply(RPL_YOURHOST, "YOURHOST");
	send(fd, buf.c_str(), buf.length(), 0);
	buf = ft_reply(RPL_CREATED, "CREATED");
	send(fd, buf.c_str(), buf.length(), 0);
	buf = ft_reply(RPL_MYINFO, "MYINFO");
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

	/*			Uncomment this for executing commands
	cmap.find(*this->parameters.begin())->second(this->_command[0]);
	for (vector<Command *>::iterator itc = this->_command.begin(); itc != this->_command.end(); itc++)
	{
		cmap.find(*(*itc)->getParameters().begin())->second(*itc);
	}
	*/

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

void	Server::print_param()
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

socklen_t			Server::getSize() const
{
	return (this->_size);
}

int 				Server::getPortNum() const
{
	return (this->_portNum);
}

string 		Server::getServerName() const
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
