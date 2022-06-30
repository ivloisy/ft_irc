//
// Created by alangloi on 6/23/22.
//

/****************************** USELESS FOR THE MOMENT ************************************/

#include "../includes/Config.hpp"

using namespace irc;

Config::Config()
{
	;
}

Config::Config(std::string config)
{
	;
}

std::string Config::get(std::string key)
{
	return (values[key]);
}
