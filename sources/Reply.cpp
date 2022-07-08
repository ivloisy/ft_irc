//
// Created by user42 on 27/06/22.
//

/************* USELESS FOR THE MOMENT *********************/

using namespace std;

#include "../includes/Reply.hpp"
#include "../includes/ft_irc.hpp"

string ft_reply(string code, string nick, string message)
{
	string ret = "";
	ret += ":server ";
	ret += code;
	ret += " ";
	ret += nick;
	ret += " :";
	ret += message;
	ret += "\r\n";
	return (ret);
}
