#include <iostream>

#include "../communication/include/TcpSocket.h"


using namespace std;

TcpSocket listener;

int main() {

    listener.beginServer(TARGET_PORT);
    listener.listens(5);

    TcpSocket tcp = listener.accepts();

    while(1) {
        char data[32];

        int ret = tcp.receive(data, 32);
        if(ret > 0) {
            cout << data << "\n";

            char message[] = "Message";
            tcp.send(message, strlen(message));
        }
    }
}