#ifndef CLIENT_H_
#define CLIENT_H_

#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>
#include <string>

class Client
{
private:
    /* data */
    int sock;
    bool connection_state{false};

public:

    Client(/* args */);
    void client_start ();
    void client_send(std::string text);
    void client_recieve();
    ~Client();
};



#endif