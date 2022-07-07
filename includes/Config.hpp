//
// Created by alangloi on 6/23/22.
//

/****************************** USELESS FOR THE MOMENT ************************************/

#ifndef FT_IRC_CONFIG_HPP
#define FT_IRC_CONFIG_HPP

#include <string>
#include <map>

using namespace std;

namespace irc
{
	class Config
	{
	private:
		map<string, string>		values;

	public:
		Config();
		Config(string config);

		string					get(string key);
	};
}

#endif //FT_IRC_CONFIG_HPP
