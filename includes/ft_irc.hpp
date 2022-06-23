#ifndef FT_IRC_HPP
# define FT_IRC_HPP

# include <iostream>
# include <string>
# include <cstring>
# include <sys/types.h>
# include <sys/socket.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <cstdlib>
# include <unistd.h>
# include <sstream>

using namespace std;

# include <Server.hpp>
# include <Client.hpp>
# include <rpl_err.hpp>

# define RESET			"\033[0m"
# define BOLD			"\033[1m"
# define LINE			"\033[4m"
# define BLACK			"\033[30m"			/* Black */
# define RED			"\033[31m"			/* Red */
# define GREEN			"\033[32m"			/* Green */
# define YELLOW			"\033[33m"			/* Yellow */
# define BLUE			"\033[34m"			/* Blue */
# define MAGENTA		"\033[35m"			/* Magenta */
# define CYAN			"\033[36m"			/* Cyan */
# define WHITE			"\033[37m"			/* White */
# define BOLDBLACK		"\033[1m\033[30m"	/* Bold Black */
# define BOLDRED		"\033[1m\033[31m"	/* Bold Red */
# define BOLDGREEN		"\033[1m\033[32m"	/* Bold Green */
# define BOLDYELLOW		"\033[1m\033[33m"	/* Bold Yellow */
# define BOLDBLUE		"\033[1m\033[34m"	/* Bold Blue */
# define BOLDMAGENTA	"\033[1m\033[35m"	/* Bold Magenta */
# define BOLDCYAN		"\033[1m\033[36m"	/* Bold Cyan */
# define BOLDWHITE		"\033[1m\033[37m"	/* Bold White */

class	usageException : public std::exception
{
public:
	virtual const char	*what() const throw()
	{
		return "Usage: ./ircserv <port> <password>";
	}
};

#endif
