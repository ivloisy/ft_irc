//
// Created by user42 on 27/06/22.
//

#include "../includes/ft_irc.hpp"

/************* USELESS FOR THE MOMENT *********************/

using namespace std;

string ft_reply(/*string prefix, */string servername, string code, string nick, string message)
{
	string ret = /*prefix + */":";
	ret += servername;
	ret += " ";
	ret += code;
	ret += " ";
	ret += nick;
	ret += " :";
	ret += message;
	ret += "\r\n";
	return (ret);
}
