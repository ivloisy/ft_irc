//
// Created by antoine on 20/06/22.
//

//************************* USELESS FOR THE MOMENT *******************************

#include "../includes/Message.hpp"

/************** CONSTRUCTORS **************/
/*
irc::Message::Message()
{
    ;
}

irc::Message::Message(Message const & src)
{
    ;
}
*/
/*************** DESTRUCTOR ***************/
/*
irc::Message::~Message()
{
    ;
}
*/
/********** ASSIGNMENT OPERATOR ***********/
/*
irc::Message &irc::Message::operator=(Message const &rhs)
{
    return (*this);
}
*/
/**************** GETTERS *****************/

std::string                 irc::Message::getPrefix()
{
    return (this->_prefix);
}

//irc::Command			    irc::Message::getCommand()
//{
//   return (this->_command);
//}

std::vector<std::string>    irc::Message::getParameters()
{
    return (this->_parameters);
}

/*************** FUNCTIONS ****************/

void                       	irc::Message::send_message(std::string prefix, irc::Command command, std::vector<std::string> parameters)
{
	;
}