#include <iostream>

#include "../communication/include/TcpSocket.h"
#include "../control/include/Control.h"


using namespace std;


int main() {

    TcpSocket listener;
    listener.beginServer(TARGET_PORT);
    listener.listens(5);


    Control controller(listener.accepts());

    controller.begin();

    while(1) {
        controller.update();
    }
}