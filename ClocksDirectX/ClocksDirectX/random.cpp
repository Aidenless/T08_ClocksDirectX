#include <ctime>
#include <iostream>

#include "random.h"

void random::seedGetRandom() {
    srand(static_cast<unsigned>(time(0)));
}

int random::getRandomNum(int min, int max) {
    return (rand() % (max + 1 - min) + min);
}