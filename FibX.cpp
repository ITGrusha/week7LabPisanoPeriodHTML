//
// Created by MrGra on 11/25/2019.
//

#include "FibX.hpp"

FibX::FibX(long long keyLength) {
    if (keyLength < 1) {
        throw SEQUENCE_DEPTH_EXCEPTION();
    }
    this->keyLength = keyLength;
    fibVector = std::vector<long long>(keyLength - 1LL, 0LL);
    fibVector.emplace_back(1LL);
}

long long FibX::GetNextElement() {
    fibVector.emplace_back(std::accumulate(fibVector.begin(), fibVector.end(), 0LL));
    fibVector.erase(fibVector.begin());
    return *fibVector.begin();
}

void FibX::reset() {
    fibVector = std::vector<long long>(keyLength - 1LL, 0LL);
    fibVector.emplace_back(1LL);
}