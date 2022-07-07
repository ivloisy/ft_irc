//
// Created by antoine on 05/07/22.
//

#include "../../includes/User.hpp"
#include "../../includes/Server.hpp"
#include "../../includes/Command.hpp"

using namespace irc;
using namespace std;

//DONT DO THIS COMMAND

/**************** OPERATOR COMMAND *******************/

void	rehash_cmd(Server * srv, User * usr, std::vector<std::string> params)
{
	(void)srv;
	(void)usr;
	(void)params;
}
