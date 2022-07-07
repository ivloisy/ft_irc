//
// Created by user42 on 27/06/22.
//

/************* USELESS FOR THE MOMENT *********************/

using namespace std;

#include "../includes/Reply.hpp"
#include "../includes/ft_irc.hpp"

string ft_reply(string code, string message)
{
	string ret = "";
	ret += code;
	ret += " ";
	ret += message;
	return (ret);
}

/*
string RPL_WELCOME(string prefix) {                           //001
	return (":Welcome to the Internet Relay Network " + prefix);
}

string RPL_YOURHOST(string servername, string ver) {     //002
	return (":Your host is " + servername + ", running version " + ver);
}

string RPL_CREATED(string date) {                             //003
	return (":This server was created " + date);
}

string RPL_MYINFO(string servername, string version,
					   string umodes, string cmodes) {        //004
	return (servername + " " + version + " " + umodes + " " + cmodes);
}
*/
