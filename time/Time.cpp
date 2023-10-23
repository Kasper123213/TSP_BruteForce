//
// Created by radom on 18.10.2023.
//

#include "Time.h"

//włączanie "stopera", zapisywanie obecnego czasu do zmiennej startTime
void Time::start() {
    startTime = high_resolution_clock::now();
}
//wyłączanie "stopera", zapisywanie obecnego czasu do zmiennej stopTime
void Time::stop() {
    stopTime = high_resolution_clock::now();
}

//odejmowanie czasu początkowego i koncowego w celu obliczenia różnicy w milisekundach
long Time::getTime() {
    return duration_cast<milliseconds>(stopTime - startTime).count();
}
