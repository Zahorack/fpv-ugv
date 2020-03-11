//
// Created by oholly on 11. 3. 2020.
//

#include "Timer.h"


static uint32_t getMillis()
{
    return (uint32_t)(clock());
}

Timer::Timer()
{}

Timer::~Timer()
{}

void Timer::start(int period)
{
    m_period = period;
    m_lastTrigger = getMillis();
    m_isRunnning = true;
}

void Timer::stop()
{
    m_isRunnning = false;
}

bool Timer::run()
{
    if(m_isRunnning && getMillis() > (m_lastTrigger + m_period)) {
        m_lastTrigger = getMillis();
        return true;
    }

    return false;
}