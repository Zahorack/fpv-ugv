//
// Created by oholly on 28. 2. 2020.
//

#ifndef IOT_CONTROLLER_SOCKET_H
#define IOT_CONTROLLER_SOCKET_H

#include <winsock.h>
#include <iostream>
#include <string>

#define TARGET_PORT 54321

extern WSADATA g_wsda;


class Socket {

protected:
    SOCKET m_socketFd;
    SOCKADDR_IN m_ipAddress;

    virtual void create() = 0;

    void binds(int port);
    void connects(char *ip, int);
    void close();
public:
    Socket();
    Socket(SOCKET);
    ~Socket();

    SOCKADDR_IN getIP();
    SOCKET getFileDescriptor();

    void send( char *data, int size);
    int receive(char *data, int size);


};


#endif //IOT_CONTROLLER_SOCKET_H
