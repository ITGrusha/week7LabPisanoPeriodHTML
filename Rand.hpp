//
// Created by MrGra on 10/25/2019.
//

#ifndef WEEK6LABFIBRANDOMIZER_FIB_HPP

#include "FibX.hpp"

#endif

#ifndef WEEK6LABFIBRANDOMIZER_R_HPP
#define WEEK6LABFIBRANDOMIZER_R_HPP

#endif //WEEK6LABFIBRANDOMIZER_R_HPP

class Rand {

public:
    Rand(long long, long long);

    long long operator()();

    void setRM(long long);

    void reset();

private:
    long long _M = 20;
    FibX fibSeq = FibX(1);
};