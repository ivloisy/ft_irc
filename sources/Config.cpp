//
// Created by alangloi on 6/23/22.
//

/****************************** USELESS FOR THE MOMENT ************************************/

#include "../includes/Config.hpp"

using namespace irc;
using namespace std;

Config::Config()
{
	;
}

Config::Config(string config)
{
	(void)config;
	return ;
}

string Config::get(string key)
{
	return (values[key]);
}
