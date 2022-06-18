//
// Created by blyzance on 18/06/22.
//

#include "../includes/Server.hpp"
#include <iostream>

Server::Server()
{

}

Server::Server(Server const & src)
{

}

Server::~Server()
{

}

Client Server::establishConnection(void)
{
	Client client;

	client.sockaddr = socket(AF_INET, SOCK_STREAM, 0);
	if (client < 0)
	{
		std::cout << "Error establishing connection..." << std::endl;
		exit(1);
	}
	return (client);
}

serverAddress Server::createServerAddr()
{
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = htons(INADDR_ANY);
	server_addr.sin_port = htons(portNum);
}

void	Server::bind(int client, int server_addr, int size)
{
	if ( bind(client, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0 )
	{
		std::cout << "Erro binding socket..." << std::endl;
		exit(1);
	}
}

Server Server::listenClient(int client)
{
	listen(client, 1);
}

Server Server::acceptClient(int client, server_addr, size)
{
	server = accept(client, (struct sockaddr*)&server_addr, &size);

	if (server < 0)
	{
		std::cout << "Error on accepting..." << std::endl;
		exit(1);
	}
}

void Server::closeClient(int client)
{
	close(client);
}