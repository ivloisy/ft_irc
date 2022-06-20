//
// Created by antoine on 20/06/22.
//

#include "../includes/Client.hpp"
#include <sys/socket.h>
#include <iostream>
#include <stdlib.h>

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

/******************************* GETTERS *******************************/

int 		Client::getFdClient(void) const
{
	return (this->_fdClient);
}

int 		Client::getIdClient(void) const
{
	return (this->_idClient);
}