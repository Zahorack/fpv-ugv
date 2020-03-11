//
// Created by oholly on 28. 2. 2020.
//

//#include "../include/UdpSocket.h"
#include "UdpSocket.h"

using namespace std;


UdpSocket::UdpSocket()
{

}

void UdpSocket::create()
{
    WSAStartup(MAKEWORD(1,1), &g_wsda);
    cout<<"Creating socket...";

    m_socketFd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);

    if(m_socketFd == SOCKET_ERROR) {
        cout<<"Error\nCall to socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP); failed with:" << WSAGetLastError()<<"\n";
        exit(1);
    }
    cout<<("OK\n");
}

UdpSocket::~UdpSocket()
{
    close();
}

void UdpSocket::beginServer(int port)
{
    create();
    binds(port);
}

void UdpSocket::beginClient()
{
    create();
    connects();
}


