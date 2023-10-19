//
// Created by radom on 18.10.2023.
//

#include "Time.h"

void Time::start() {
    czasPoczatkowy = high_resolution_clock::now();
}

void Time::stop() {
    czasKoncowy = high_resolution_clock::now();
}

long Time::getTime() {
    return duration_cast<milliseconds>(czasKoncowy - czasPoczatkowy).count();
}
