//
// Created by oholly on 11. 3. 2020.
//

#ifndef SERVER_BACKEND_CONTROL_H
#define SERVER_BACKEND_CONTROL_H

#include "TcpSocket.h"
#include "Timer.h"
#include <conio.h>

#define	PACKET_MARK	0x4B4C

#pragma pack(push,1)
typedef struct {
    uint8_t forward;
    uint8_t backward;
    uint8_t right;
    uint8_t left;
} controlData_t;
#pragma pack(pop)


#pragma pack(push,1)
typedef struct {
    uint16_t mark;
    controlData_t data;
} controlPacket_t;
#pragma pack(pop)

class Control {

    Timer m_timer;
    TcpSocket m_socket;
public:
    Control(SOCKET);
    ~Control();

    void begin();
    void update();

    void stop();
};

#endif //SERVER_BACKEND_CONTROL_H
