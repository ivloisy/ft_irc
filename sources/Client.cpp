//
// Created by antoine on 20/06/22.
//

// #include <sys/socket.h>
// #include <iostream>
// #include <stdlib.h>

#include <Client.hpp>

/**************************** CONSTRUCTORS ****************************/

Client::Client()
{

}

Client::Client(Client const &src)
{
	;
}

/***************************** DESTRUCTORS ****************************/

Client::~Client()
{

}

/************************* ASSIGNMENT OPERATOR ************************/

Client &Client::operator=(Client const &rhs)
{
	return (*this);
}

/*************************** MEMBER FUNCTIONS **************************/

void Client::establishConnection(void)
{
	this->_fdClient = socket(AF_INET, SOCK_STREAM, 0);
	if (this->_fdClient < 0)
	{
		std::cout << "Error establishing connection..." << std::endl;
		exit(1);
	}
	std::cout << "Server Socket connection created..." << std::endl;
}

void Client::sendMessage(std::string str) const
{
	std::cout << str << std::endl;
	// send(this->_fdClient, (str + "\r\n").c_str(), (str + "\r\n").length(), 0);
	return ;
}

/******************************* GETTERS *******************************/

int 		Client::getFdClient(void) const
{
	return (this->_fdClient);
}

int 		Client::getIdClient(void) const
{
	return (this->_idClient);
}
