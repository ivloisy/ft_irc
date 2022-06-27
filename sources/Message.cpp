//
// Created by antoine on 20/06/22.
//

#include "../includes/Message.hpp"

/************** CONSTRUCTORS **************/

Message::Message()
{
    ;
}

Message::Message(Message const & src)
{
    ;
}

/*************** DESTRUCTOR ***************/

Message::~Message()
{
    ;
}

/********** ASSIGNMENT OPERATOR ***********/

Message &Message::operator=(Message const &rhs)
{
    ;
}

/**************** GETTERS *****************/

std::string                 Message::getPrefix()
{
    return (this->_prefix);
}

std::vector<std::string>    Message::getCommand()
{
    return (this->_command);
}

Command                     Message::getParameters()
{
    return (this->_parameters);
}

/*************** FUNCTIONS ****************/

void                        Message::send_message(std::string prefix, std::vector<std::string> commands, std::string parameters)
{

}