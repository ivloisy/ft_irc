//
// Created by blyzance on 18/06/22.
//

#ifndef FT_IRC_SERVER_HPP
#define FT_IRC_SERVER_HPP

#include <netinet/in.h>
#include <sys/socket.h>
#include "Client.hpp"

class Server {
    //int client; //(instantiation client)
	int _fdServer;
    //int nbClients; (client class, static variable)
    //int channels; //(instantiation channels)
    int portNum;
	struct sockaddr_in _serverAddr;
	//Client client;
	socklen_t size;

public:
    Server();
    Server(Server const & src);
    virtual ~Server();

    Server operator=(Server const & src);


    void				bindServer(Client client);
	void				createServerAddr(int portNum);
	void				listenClient(Client client);
	void				acceptClient(Client client, int size);
	void				closeClient(Client client);

	int 				getFdServer();
	struct sockaddr_in	getServerAddr();
};


#endif //FT_IRC_SERVER_HPP
