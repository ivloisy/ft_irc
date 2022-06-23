//
// Created by alangloi on 6/23/22.
//

#include "../includes/Config.hpp"

irc::Config::Config()
{
	;
}

irc::Config::Config(std::string config)
{
	;
}

std::string irc::Config::get(std::string key)
{
	return (values[key]);
}