#include "client.h"
#include"chatgui.h"

Client::Client(/* args */)
{
}

void Client::client_start ()
{
 
using namespace std;
 

    //	Create a socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1)
    {
        //return 1;
    }

    //	Create a hint structure for the server we're connecting with
    int port = 54000;
    string ipAddress = "127.0.0.1";

    sockaddr_in hint;
    hint.sin_family = AF_INET;
    hint.sin_port = htons(port);
    inet_pton(AF_INET, ipAddress.c_str(), &hint.sin_addr);

    //	Connect to the server on the socket
    int connectRes = connect(sock, (sockaddr*)&hint, sizeof(hint));
    if (connectRes == -1)
    {
        cout<<"failed to connect to server\n";
    }
    else
    {
        cout<<"connected to server\n";
        connection_state = true;
    }
    

    //	While loop:
    char buf[4096];
    string userInput;


    /*do {
        //		Enter lines of text
        cout << "> ";
        getline(cin, userInput);

        //		Send to server
        int sendRes = send(sock, userInput.c_str(), userInput.size() + 1, 0);
        if (sendRes == -1)
        {
            cout << "Could not send to server! Whoops!\r\n";
            continue;
        }

        //		Wait for response
        memset(buf, 0, 4096);
        int bytesReceived = recv(sock, buf, 4096, 0);
        if (bytesReceived == -1)
        {
            cout << "There was an error getting response from server\r\n";
        }
        else
        {
            //		Display response
            cout << "SERVER> " << string(buf, bytesReceived) << "\r\n";
        }
    } while(true);*/

}

void Client::client_send(std::string text)
{
    if(connection_state == true)
    {
        int sendRes = send(sock, text.c_str(), text.size() + 1, 0);
        if (sendRes == -1)
        {
            std::cout << "Could not send to server! Whoops!\r\n";
        }
    }
    
}

void Client::client_recieve()
{
    while(1)
    {
        std::cout<<"thread active\n";
    if(connection_state == true)
    {
        char buf[4096];
        memset(buf, 0, 4096);
        int bytesReceived = recv(sock, buf, 4096, 0);
        if (bytesReceived == -1)
        {
        //std::cout << "There was an error getting response from server\r\n";
        }
        else
        {
        //text = std::string(buf, bytesReceived);
        }
    }
    }
}

Client::~Client()
{
    //	Close the socket
    close(sock);
}