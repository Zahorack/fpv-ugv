//
// Created by oholly on 28. 2. 2020.
//

//#include "../include/Socket.h"
#include "Socket.h"

using namespace std;

WSADATA g_wsda;

Socket::Socket()
{}

Socket::Socket(SOCKET fd):
    m_socketFd(fd)
{}

Socket::~Socket()
{
    close();
}


void Socket::connects(char *ip, int port)
{

    m_ipAddress.sin_family = AF_INET;
    m_ipAddress.sin_port = htons(port);
    m_ipAddress.sin_addr.s_addr = inet_addr(ip);

    if(connect(m_socketFd, (struct sockaddr *)&m_ipAddress, sizeof(m_ipAddress)) < 0) {
        cout<<("\n Error : Connect Failed \n");
        exit(0);
    }
    else{
        cout<<"Connected\n";
    }
}


void Socket::binds(int port)
{
    cout<<"Binding socket...";
    m_ipAddress.sin_family = AF_INET;
    m_ipAddress.sin_port = htons(port);
    m_ipAddress.sin_addr.s_addr = INADDR_ANY;
//    m_ipAddress.sin_addr.s_addr =inet_addr("192.168.66.110");

    if(bind(m_socketFd, (struct sockaddr *) &m_ipAddress, sizeof(m_ipAddress)) == SOCKET_ERROR) {
        cout<<("Error\nCall to bind(s, (struct sockaddr *) &addr, sizeof(addr)); failed with:\n%d\n", WSAGetLastError());
        exit(1);
    }
    cout<<("OK\n");

}

int Socket::receive(char *data, int size)
{
    int targetAddrLen = sizeof(m_ipAddress);

    int ret = recvfrom(m_socketFd, data, size, 0, (struct sockaddr *)&m_ipAddress, &targetAddrLen);

    if(ret < 0) {
        cout <<"Server: recvfrom() failed with error code:"<<WSAGetLastError()<<"\n";
    }
    else if(ret > 0) {
        data[ret] = '\0';        // Convert to cstring
    }

    return ret;
}

void Socket::send( char *data, int size)
{
    int targetAddrLen = sizeof(m_ipAddress);
    sendto(m_socketFd, data, size, 0, (struct sockaddr *) &m_ipAddress, targetAddrLen);
}

void Socket::close()
{
    closesocket(m_socketFd);
    WSACleanup();
}

SOCKADDR_IN Socket::getIP()
{
    return  m_ipAddress;
}

SOCKET Socket::getFileDescriptor()
{
    return m_socketFd;
}