//
// Created by blyzance on 18/06/22.
//

#ifndef FT_IRC_SERVER_HPP
#define FT_IRC_SERVER_HPP

#include <netinet/in.h>
#include <sys/socket.h>

class Server {
    int client; //(instantiation client)
    int server;
    //int nbClients; (client class, static variable)
    int channels; //(instantiation channels)
    int portNum;
	struct sockaddr_in server_addr;
	socklen_t size;

public:
    Server();
    Server(Server const & src);
    virtual ~Server();

    Server operator=(Server const & src);

    //Client	establishConnection(void);
    //void		bind(client, server_addr, size < 0);
	//Server	listenClient(client, n);
	//Server	acceptClient(client, server_addr, size);
	//void		closeClient(client);
};


#endif //FT_IRC_SERVER_HPP
