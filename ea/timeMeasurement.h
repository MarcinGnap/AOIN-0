#pragma once
#include <Windows.h>
#include <iostream>

class timeMeasurement
{
    double PCFreq = 0.0;
    __int64 CounterStart = 0;
    LARGE_INTEGER li{};

    void reset()
    {
        PCFreq = 0.0;
        CounterStart = 0;
    }

public:

    timeMeasurement() = default;

    void start();
    double stop();
};

