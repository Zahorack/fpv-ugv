import socket
import time
import threading
import sys, os


HOST = '192.168.100.10'
PORT = 54321

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

forward = backward = right = left = 0


def getch():
    import termios
    import sys, tty
    def _getch():
        fd = sys.stdin.fileno()
        old_settings = termios.tcgetattr(fd)
        try:
            tty.setraw(fd)
            ch = sys.stdin.read(1)
        finally:
            termios.tcsetattr(fd, termios.TCSADRAIN, old_settings)
        return ch
    return _getch()


def input_thread_function(name):
    global forward, backward, right, left
    while True:
        # cmd = input()
        # cmd = sys.stdin.read()
        cmd = getch()
        # print(cmd)

        if cmd == 'w':
            forward = 1
        if cmd == 'a':
            left = 1
        if cmd == 's':
            backward = 1
        if cmd == 'd':
            right = 1


def begin():
    HOST = input("Type esp32 ip address ")
    print(HOST)
    s.connect((HOST, PORT))

    x = threading.Thread(target=input_thread_function, args=(1,))
    x.start()
    sender()


def sender():
    global forward, backward, right, left

    my_bytes = bytearray()
    my_bytes.append(0x4C)
    my_bytes.append(0x4B)
    my_bytes.append(forward)
    my_bytes.append(backward)
    my_bytes.append(right)
    my_bytes.append(left)

    s.send(my_bytes)

    forward = 0
    backward = 0
    right = 0
    left = 0

    threading.Timer(0.1, sender).start()


def run():
    while True:
        content = s.recv(32)

        if len(content) == 0:
            break
        else:
            print(content)


def destroy():
    s.close()


if __name__ == '__main__':
    begin()
    try:
        run()
    except KeyboardInterrupt:
        destroy()
