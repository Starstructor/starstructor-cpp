/*
Starstructor, the Starbound Toolet
Copyright (C) 2013-2014 Chris Stamford

Source file contributers:
    Chris Stamford      contact: cstamford@gmail.com

Licensed under the terms of the GPL.
Contact: starstructor@gmail.com
*/

#ifndef STTIMER_HPP
#define STTIMER_HPP

#include <chrono>

namespace Starstructor { namespace Utility {

enum class TimerPrecision
{
    NANOSECONDS,
    MICROSECONDS,
    MILLISECONDS,
    SECONDS
};

class Timer
{
public:
    Timer(const TimerPrecision& precision = TimerPrecision::MILLISECONDS);
    void setPrecision(const TimerPrecision& precision);
    void reset();
    long long getTime() const;

private:
    std::chrono::high_resolution_clock::time_point m_initialTime;
    TimerPrecision m_precision;
};

}

}

#endif // STTIMER_HPP