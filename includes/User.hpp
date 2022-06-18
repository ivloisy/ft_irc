#ifndef USER_HPP
# define USER_HPP
# include "ft_irc.hpp"

class User
{
	private:
		std::string	_nickname;
		std::string	_password;
		std::string	_status;
		std::string	_channel;
		vetcor<string>	_ban;
		bool		_operator;
		bool		_actif;

	public:
		User();
		User(User const & src);
		~User();

		std::string getNickname() const;
		std::string getPassword() const;
		std::string getStatus() const;
		std::string getChannel() const;
		bool		isOperator() const;
		bool		isActif() const;
}

#endif
