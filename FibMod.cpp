//
// Created by MrGra on 10/25/2019.
//

#include <cstdio>
#include "FibMod.hpp"

static int F0 = 0,
        F1 = 1;

static int m = 1;

void setMod(int M) {
    m = M;
}

int FibMod() {
    F0 = F1 + F0;
    F1 = (F0 - F1) % m;
    F0 = F0 % m;
    return F0;
}


void resetFib() {
    F0 = 0;
    F1 = 1;
}