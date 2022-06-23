//
// Created by alangloi on 6/23/22.
//

#ifndef FT_IRC_CONFIG_HPP
#define FT_IRC_CONFIG_HPP

#include <string>
#include <map>

namespace irc
{
	class Config
	{
	private:
		std::map<std::string, std::string> values;

	public:
		Config();
		Config(std::string config);

		std::string get(std::string key);
	};
}



#endif //FT_IRC_CONFIG_HPP
