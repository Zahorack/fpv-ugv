//
// Created by oholly on 28. 2. 2020.
//

#ifndef IOT_CONTROLLER_UDP_SOCKET_H
#define IOT_CONTROLLER_UDP_SOCKET_H

#include <winsock.h>
#include <iostream>

#include "Socket.h"

class UdpSocket: public Socket{

    void create();
public:
    UdpSocket();
    ~UdpSocket();

    void beginServer(int port);
    void beginClient(char *ip, int port);
};

#endif //IOT_CONTROLLER_SOCKET_H
