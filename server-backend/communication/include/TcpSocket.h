//
// Created by oholly on 28. 2. 2020.
//

#ifndef IOT_SERVICER_TCPSOCKET_H
#define IOT_SERVICER_TCPSOCKET_H


#include "Socket.h"

class TcpSocket: public Socket {

    void create();
public:
    TcpSocket();
    TcpSocket(SOCKET);
    ~TcpSocket();

    void listens(int);


    void beginServer(int port);
    void beginClient(char *ip, int port);

    SOCKET accepts();
};

#endif //IOT_SERVICER_TCPSOCKET_H
