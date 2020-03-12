//
// Created by oholly on 11. 3. 2020.
//

#include "Control.h"
#include "string.h"

static HANDLE s_inputThreadHandle, s_receiveThreadHandle;
static controlData_t s_controlData;


LPTHREAD_START_ROUTINE input_thread_function()
{
    while(1) {
        char cmd;
        cmd = getch();
//        memset(&s_controlData, 0, sizeof(s_controlData));

        switch(cmd) {
            case 'w': s_controlData.forward = 1; break;
            case 'a': s_controlData.left = 1; break;
            case 's': s_controlData.backward = 1; break;
            case 'd': s_controlData.right = 1; break;
            default:  memset(&s_controlData, 0, sizeof(s_controlData)); break;
        }
    }
}

LPTHREAD_START_ROUTINE receive_thread_function(SOCKET fd)
{
    char data[512];
    TcpSocket socket(fd);

    while(1) {
        int ret = socket.receive(data, 512);
        if(ret > 0) {
            std::cout << data << "\n";

//            char message[] = "Message";
//            m_socket.send(message, strlen(message));
        }
    }
}

Control::Control(SOCKET fd):
    m_socket(fd)
{}

Control::~Control()
{
    stop();
}

void Control::begin()
{
    s_inputThreadHandle = CreateThread(
            NULL,                                              // default security attributes
            0,                                                 // use default stack size
            (LPTHREAD_START_ROUTINE)input_thread_function,     // thread function name
            NULL,                                              // argument to thread function
            0,                                                 // use default creation flags
            NULL
    );

    SOCKET fd = m_socket.getFileDescriptor();

    s_receiveThreadHandle = CreateThread(
            NULL,                                              // default security attributes
            0,                                                 // use default stack size
            (LPTHREAD_START_ROUTINE)receive_thread_function,     // thread function name
            (LPVOID)fd,                                              // argument to thread function
            0,                                                 // use default creation flags
            NULL
    );

    m_timer.start(100);

}

void Control::stop()
{
    CloseHandle(s_inputThreadHandle);
    CloseHandle(s_receiveThreadHandle);
    m_timer.stop();
}

void Control::update()
{
    if(m_timer.run()) {

        controlPacket_t packet = {
                .mark = PACKET_MARK,
                .data = s_controlData
        };

        m_socket.send((char*)&packet, sizeof(packet));

        std::cout<<"forward: "<<s_controlData.forward;
        std::cout<<"    backward: "<<s_controlData.backward;
        std::cout<<"    right: "<<s_controlData.right;
        std::cout<<"    left: "<<s_controlData.left<<"\n";


        memset(&s_controlData, 0, sizeof(s_controlData));
    }

}