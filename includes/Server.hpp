//
// Created by blyzance on 18/06/22.
//

#ifndef FT_IRC_SERVER_HPP
#define FT_IRC_SERVER_HPP

# include <netinet/in.h>
# include <sys/socket.h>
# include "User.hpp"
# include "Config.hpp"
# include "Command.hpp"
# include <map>
# include <sstream>

// # define BUFFERSIZE 512
using namespace std;

namespace irc
{
	class User;

	class Server
	{

	public:
		//typedef void (*pointer_function)(string &buf, User *it_user, Server &serv);
		//typedef void (*pointer_function)(void);
		//typedef map<string, pointer_function>		map_cmd;
		// typedef void (* Server::pointer_function)(/*Command * com*/);
		// typedef map<string, pointer_function>		map_cmd;

	private:
		int 												_fd;
		int													_fdMax;
		int*												_fds;
		struct sockaddr_in									_serverAddr;
		string												_serverName; //identify the server, has a max length of 63 chars. servername = hostname
		socklen_t 											_size;
		map<int, User *>									_user; //we're going to delete it for the instanciation with set
		//vector<Channel *>							_channels;
		int													_portNum; //default port 6667
		//Command											_commands;
		//set<User *>									user; *Store the different users
		//Config											_config; *I don't know if we're gonna use a config file. if yes, we're going to store it there
		//string										_upTime;
		bool												_state;
		// map_cmd												_cmap;
		// string 										_buffer[BUFFERSIZE];
		vector<vector<string> >								_param;

	public:
		Server();
		Server(Server const & src);
		virtual ~Server();

		//Server operator=(Server const & src);

		//Config											&getConfig();
		//string										getUpTime();

		//void												add_user(User user);

		void							establishConnection(void);
		void							createServerAddr(int portNum);
		void							bindServer(void);
		//void							listenUser(void);
		int								acceptUser(socklen_t size);
		void							closeUser(User * user);
		// void							init_map_cmd();
		void							parse_buffer_command(string buffer);
		void							tokenize(string const & str);
		void							print_param();

		int								getFdMax( void ) const;
		int								getFdServer() const;
		struct sockaddr_in				getServerAddr() const;
		User							*getUser();
		socklen_t						getSize() const;
		int								getPortNum() const;
		string							getServerName() const;
		bool							getState() const;

		void							setState(bool st);
		void							setFdServer(int fd);
		void							setUpFdMax(int fdCurrent);
		// void							setDownFdMax(int fdCurrent);

		bool							isUserEmpty();

		void	cap_cmd(/*Command * cmd*/);
		void	die_cmd(/*Command * cmd*/);
		void	join_cmd(/*Command * cmd*/);
		void	list_cmd(/*Command * cmd*/);
		void	mode_cmd(/*Command * cmd*/);
		void	msg_cmd(/*Command * cmd*/);
		void	names_cmd(/*Command * cmd*/);
		void	nick_cmd(/*Command * cmd*/);
		void	notice_cmd(/*Command * cmd*/);
		void	oper_cmd(/*Command * cmd*/);
		void	part_cmd(/*Command * cmd*/);
		void	pass_cmd(/*Command * cmd*/);
		void	ping_cmd(/*Command * cmd*/);
		void	pong_cmd(/*Command * cmd*/);
		void	privmsg_cmd(/*Command * cmd*/);
		void	quit_cmd(/*Command * cmd*/);
		void	rehash_cmd(/*Command * cmd*/);
		void	restart_cmd(/*Command * cmd*/);
		void	squit_cmd(/*Command * cmd*/);
		void	user_cmd(/*Command * cmd*/);
		void	wallops_cmd(/*Command * cmd*/);
	};
}

#endif //FT_IRC_SERVER_HPP
