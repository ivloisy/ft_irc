//
// Created by antoine on 04/07/22.
//

#include "../../includes/User.hpp"
#include "../../includes/Server.hpp"
#include "../../includes/Command.hpp"

using namespace irc;
using namespace std;

//DONT DO THIS COMMAND
/*
The SQUIT command is available only to operators.  >>>> It is used to disconnect server links.
*/
/********************* OPERATOR COMMAND **********************/

/*
 * Operator command for disonnecting the server
 * parameters <server> <comment>
 */

void squit_cmd(Server * srv, User * usr, std::vector<std::string> params)
{
	(void)srv;
	(void)usr;
	(void)params;
	std::cout << "squit command called" << std::endl;
}
