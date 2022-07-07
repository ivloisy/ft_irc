//
// Created by antoine on 04/07/22.
//


#include "../../includes/User.hpp"
#include "../../includes/Server.hpp"
#include "../../includes/Command.hpp"

using namespace irc;

/********************* CHANNEL COMMAND **********************/

/*
 * JOIN command
 * ( <channel> *( "," <channel> ) [ <key> *( "," <key> ) ] )
               / "0"
 */

void	join_cmd(Server * srv, User * usr, std::vector<std::string> params)
{
	(void)usr;
	if (params[0] == "JOIN")
	{
		if (params.size() < 1)
		{
			//reply("wrong number of arguments");
		}
		else
		{
			std::vector<std::string>::iterator last = params.end();
			for (std::vector<std::string>::iterator it = params.begin(); it != last; it++)
			{
				if (params[1] == "0" && params.size() < 2)
				{
					//quit all joined channels
					//return ;
				}
				else if (srv->getChannel(params.at(1)))
				{
					//join channel
				}
				//else start with one of the channel symbols
					//create channel
			}

		}
	}
	std::cout << "join command called" << std::endl;
}
