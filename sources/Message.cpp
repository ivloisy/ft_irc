//
// Created by antoine on 20/06/22.
//


//************************* USELESS FOR THE MOMENT *******************************

#include "../includes/Message.hpp"

using namespace irc;

/************** CONSTRUCTORS **************/
/*
Message::Message()
{
    ;
}

Message::Message(Message const & src)
{
    ;
}
*/
/*************** DESTRUCTOR ***************/
/*
Message::~Message()
{
    ;
}
*/
/********** ASSIGNMENT OPERATOR ***********/
/*
Message &Message::operator=(Message const &rhs)
{
    return (*this);
}
*/
/**************** GETTERS *****************/

std::string                 Message::getPrefix()
{
    return (this->_prefix);
}

//Command			    Message::getCommand()
//{
//   return (this->_command);
//}

std::vector<std::string>    Message::getParameters()
{
    return (this->_parameters);
}

/*************** FUNCTIONS ****************/

void                       	Message::send_message(std::string prefix, Command command, std::vector<std::string> parameters)
{
	;
}
