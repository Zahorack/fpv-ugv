//
// Created by oholly on 28. 2. 2020.
//

//#include "../include/TcpSocket.h"
#include "TcpSocket.h"

using namespace std;


TcpSocket::TcpSocket()
{}


TcpSocket::TcpSocket(SOCKET fd):
    Socket(fd)
{}

TcpSocket::~TcpSocket()
{
    close();
}

void TcpSocket::beginServer(int port)
{
    create();
    binds(port);
}

void TcpSocket::beginClient(char *ip, int port)
{
    create();
    connects(ip, port);
}

void TcpSocket::create()
{
    WSAStartup(MAKEWORD(1,1), &g_wsda);
    cout<<"Creating socket...";

    m_socketFd = socket(AF_INET, SOCK_STREAM , IPPROTO_TCP);

    if(m_socketFd == SOCKET_ERROR) {
        cout<<"Error\nCall to socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP); failed with:" << WSAGetLastError()<<"\n";
        exit(1);
    }
    cout<<("OK\n");
}

void TcpSocket::listens(int num)
{
    if (listen(m_socketFd, num) == SOCKET_ERROR) {
        wprintf(L"listen failed with error: %ld\n", WSAGetLastError());
        closesocket(m_socketFd);
        WSACleanup();
    }
}

SOCKET TcpSocket::accepts()
{
    SOCKET newSocket;
    int addrlen = sizeof(m_ipAddress);

    newSocket = accept(m_socketFd,  NULL, NULL);

    if(newSocket == INVALID_SOCKET) {
        wprintf(L"accept failed with error: %ld\n", WSAGetLastError());
        closesocket(newSocket);
    }
    else {
        cout<<("accept ok\n");
    }

    return newSocket;
}