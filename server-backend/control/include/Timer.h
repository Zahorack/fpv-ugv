//
// Created by oholly on 11. 3. 2020.
//

#ifndef SERVER_BACKEND_TIMER_H
#define SERVER_BACKEND_TIMER_H

#include "stdint.h"
#include <time.h>

class Timer {

    bool m_isRunnning;
    int m_period, m_lastTrigger;

public:
    Timer();
    ~Timer();

    void start(int);
    void stop();
    bool run();
};

#endif //SERVER_BACKEND_TIMER_H
