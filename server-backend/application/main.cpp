#include <iostream>

#include "../communication/include/TcpSocket.h"
#include "../control/include/Control.h"

using namespace std;


int main() {

    char ip_string[] = "192.168.100.10";
    cout<<"Type ESP32 IP address: ";
    scanf("%s", ip_string);

/*Tcp server socket implementation*/
//    TcpSocket listener;
//    listener.beginServer(TARGET_PORT);
//    listener.listens(5);
//    Control controller(listener.accepts());


/*Tcp client socket implementation*/
    TcpSocket tcp;
    tcp.beginClient(ip_string, TARGET_PORT);
    Control controller(tcp.getFileDescriptor());


    controller.begin();

    while(1) {
        controller.update();
    }
}