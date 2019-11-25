//
// Created by MrGra on 10/25/2019.
//

#include "Rand.hpp"

long long Rand::operator()() {
    return fibSeq.GetNextElement() % _M;
}

Rand::Rand(long long module, long long keyLength = 2) {
    _M = module;
    this->fibSeq = FibX(keyLength);
}

void Rand::reset() {
    fibSeq.reset();
}

void Rand::setRM(long long module) {
    fibSeq.reset();
    _M = module;
}
