//
// Created by radom on 18.10.2023.
//
#include <iostream>
#include <chrono>

#ifndef PEA1_TIME_H
#define PEA1_TIME_H

using namespace std;
using namespace std::chrono;
class Time {
private:
    high_resolution_clock::time_point czasPoczatkowy;
    high_resolution_clock::time_point czasKoncowy;


public:
    void start();

    void stop();

    long getTime();
};


#endif //PEA1_TIME_H
