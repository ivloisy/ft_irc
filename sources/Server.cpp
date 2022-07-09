//
// Created by blyzance on 18/06/22.
//


#include "../includes/ft_irc.hpp"

using namespace irc;
using namespace std;

/******************** CONSTRUCTORS **********************/

Server::Server(int const & portNum) :
	map_cmd(),
	_fd(-1),
	_fdMax(-1),
	_serverName("irc.sample.com"),
	_size(0),
	_user(),
	_oper(),
	_channel(),
	_portNum(portNum),
	_state(1),
	_password(),
	_param(),
	_maxChannels(10)
{
	this->initServer();
}

Server::Server(int const & portNum, string const & passw) :
	_serverName("irc.sample.com"),
	_portNum(portNum),
	_state(1),
	_password(passw)
{
	this->initServer();
}

Server::~Server()
{
	this->_user.clear();
	return;
}

/******************** CONNECTION **********************/

void 					Server::initServer()
{
	this->establishConnection();
	this->_fdMax = this->_fd;
	this->createServerAddr(this->_portNum);

	int optval = 1;
	if (setsockopt(this->_fd, SOL_SOCKET, SO_REUSEADDR,&optval, sizeof(optval)) < 0)
		cout << "error setting socket option..." << endl;
	this->bindServer();
	this->_size = sizeof(this->getServerAddr());
	if (listen(this->_fd, this->getServerAddr().sin_port) < 0)
	{
		//===========================error //////////////////////////
		;
	}
	this->initCommand();
}

void					 Server::establishConnection(void)
{
	this->_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (this->_fd < 0)
	{
		cout << "Error establishing connection..." << endl;
		//=======================exit(1); //////////////////////////
		return ;
	}
	cout << "Server Socket connection created..." << endl;
}

void					Server::createServerAddr(int const & portNum)
{
	this->_serverAddr.sin_family = AF_INET;
	this->_serverAddr.sin_addr.s_addr = htons(INADDR_ANY);
	this->_serverAddr.sin_port = htons(portNum);
}

int						Server::acceptUser(socklen_t size)
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
	_user.insert(it, new User(fd));
	return (fd);
}

void					Server::closeUser(User const &  user)
{
	close(user.getFdUser());
}


int						Server::bindServer()
{
	if (bind(this->_fd, (struct sockaddr*)&this->_serverAddr, sizeof(this->_serverAddr)) < 0 )
	{
		cout << "Error binding socket..." << endl;
		return (0);
	}
	return (1);
}

void					Server::initCommand()
{
	map_cmd["CAP"] 		= 	cap_cmd;
	map_cmd["DIE"] 		= 	die_cmd;
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
	map_cmd["PRIVMSG"] 	=	privmsg_cmd;
	map_cmd["QUIT"] 	=	quit_cmd;
	map_cmd["USER"] 	= 	user_cmd;
	map_cmd["WALLOPS"] 	= 	wallops_cmd;
	map_cmd["WHOIS"] 	= 	whois_cmd;
}

void 					Server::welcome(int const & fd)
{
	if (this->getUser(fd)->getRdySend() != 3 || this->getUser(fd)->getToClose())
		return;
	sending(fd, ft_reply(this->_serverName, RPL_WELCOME, this->getUser(fd)->getNickName(), "Welcome to the Internet Relay Network"));
	sending(fd, ft_reply(this->_serverName, RPL_YOURHOST, this->getUser(fd)->getNickName(), "Your host is localhost running version osef"));
	sending(fd, ft_reply(this->_serverName, RPL_CREATED, this->getUser(fd)->getNickName(), "This server was created now"));
	sending(fd, ft_reply(this->_serverName, RPL_MYINFO, this->getUser(fd)->getNickName(), "MYINFO"));
}

void					Server::parse_buffer_command(string const & str, int const & fd)
{
	// for(vector<vector<string> >::iterator it = this->_param.begin(); it != this->_param.end(); it++)
	// 	(*it).clear();
	this->_param.clear();
	stringstream 			ss(str);
	string					s;
	vector<string>			tmp;

	while (getline(ss, s, '\r'))
	{
		this->getUser(fd)->setRdySend();
		stringstream o(s);
		string u;
		while (getline(o, u, ' '))
			tmp.push_back(u);
		this->_param.push_back(tmp);
		tmp.clear();
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
			cout << *jt << "; ";
		cout << " }" << endl;
		i++;
	}
}

void 				Server::execCommand(int const & fd)
{
	vector<string> test;
	test.push_back("CAP");
	test.push_back("DIE");
	test.push_back("JOIN");
	test.push_back("LIST");
	test.push_back("MODE");
	test.push_back("NAMES");
	test.push_back("NICK");
	test.push_back("NOTICE");
	test.push_back("OPER");
	test.push_back("PART");
	test.push_back("PASS");
	test.push_back("PING");
	test.push_back("PRIVMSG");
	test.push_back("QUIT");
	test.push_back("RESTART");
	test.push_back("SQUIT");
	test.push_back("USER");
	test.push_back("WALLOPS");

	for (size_t x = 0; x < this->_param.size(); x++)
	{
		transform(this->_param[x][0].begin(), this->_param[x][0].end(), this->_param[x][0].begin(), ::toupper);
		for (size_t y = 0; y < test.size(); y++)
			if (this->_param[x][0] == test[y])
			{
				this->map_cmd.find(this->_param[x][0])->second(*this, *this->getUser(fd), this->_param[x]);
				break;
			}
		// cout << _param[x][0] << endl;
	}
}

int					Server::searchNick(string const & nick)
{
	vector<User *>::iterator last = this->_user.end();
	for (vector<User *>::iterator it = this->_user.begin(); it != last; it++)
		if ((*it)->getNickName() == nick)
			return ((*it)->getFdUser());
	return (0);
}

void				Server::sendToChan(string const & name, string const & msg)
{
	vector<User *> chan_usr = this->getChannel(name)->getChannelUsers();
	vector<User *>::iterator last = chan_usr.end();
	for (vector<User *>::iterator it = chan_usr.begin(); it != last; it++)
		sendBuffer(*(*it), msg);
}

void				Server::sendToUser(string const & name, string const &  msg)
{
	sendBuffer(*this->getUser(name), msg);
}

void				Server::sendBuffer(User const & dest, string const & content)
{
	sending(dest.getFdUser(), content);
}

void				Server::sending(int fd, string toSend)
{
	cout << "Sending : " << toSend << endl;
	send(fd, toSend.c_str(), toSend.length(), 0);
}

Channel*			Server::addChannel(string const & name)
{
	this->_channel.push_back(new Channel(name));
	return *(this->_channel.end() - 1);
}

Channel*			Server::searchChannel(string const & name)
{
	vector<Channel *>::iterator last = this->_channel.end();
	for (vector<Channel *>::iterator it = this->_channel.begin(); it != last; it++)
		if ((*it)->getChannelName() == name)
			return (*it);
	return (NULL);
}

void				Server::delUserAllChannel(User * user)
{
	vector<Channel *>::iterator last = this->_channel.end();
	for (vector<Channel *>::iterator it = this->_channel.begin(); it != last; it++)
	{
		(*it)->delUser(user);
		(*it)->delOper(user);
		(*it)->delUserMode(user);
		(*it)->delInvite(user);
	}
}

/******************** ACCESSORS **********************/

int 				Server::getFdMax() const
{
	return this->_fdMax;
}

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

User*				Server::getUser(int const & fd)
{
	vector<User *>::iterator it = this->_user.begin();
	while (it != _user.end() && (*it)->getFdUser() != fd)
		it++;
	return (*it);
}

User*				Server::getUser(string const & nick)
{
	vector<User *>::iterator it = this->_user.begin();
	while (it != _user.end() && (*it)->getNickName() != nick)
		it++;
	return (*it);
}

Channel*			Server::getChannel(string const & name)
{
	vector<Channel *>::iterator last = this->_channel.end();
	for (vector<Channel *>::iterator it = this->_channel.begin(); it != last; it++)
		if ((*it)->getChannelName() == name)
			return (*it);
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

User*				Server::getOper(string const & name)
{
	vector<User *>::iterator last = this->_oper.end();
	for (vector<User *>::iterator it = this->_oper.begin(); it != last; it++)
		if ((*it)->getUserName() == name)
			return (*it);
	return (NULL);
}

int 				Server::getMaxChannel() const
{
	return (this->_maxChannels);
}

bool				Server::getState() const
{
	return	(this->_state);
}

string 				Server::getServerName() const
{
	return (this->_serverName);
}

string				Server::getPassword() const
{
	return (this->_password);
}

/********************* MUTATORS *************************/

void				Server::setFdServer(int const & fd)
{
	this->_fd = fd;
}

void				Server::setState(bool const & st)
{
	this->_state = st;
}

void 				Server::setUpFdMax(int const & fdCurrent)
{
	if (fdCurrent > this->_fdMax)
		this->_fdMax = fdCurrent;
}


/******************* CHECKERS **********************/

bool				Server::isMaxChannel()
{
	int nb = 0;
	vector<Channel *>::iterator last = this->_channel.end();
	for (vector<Channel *>::iterator it = this->_channel.begin(); it != last; it++)
		nb++;
	return (nb >= this->_maxChannels);
}

bool				Server::isUserEmpty()
{
	return (this->_user.empty());
}
