//
// Created by MrGra on 11/25/2019.
//

#include <vector>
#include <exception>
#include <numeric>

#ifndef WEEKXLABFIBONACCI_FIBX_HPP
#define WEEKXLABFIBONACCI_FIBX_HPP

#endif //WEEKXLABFIBONACCI_FIBX_HPP

#define SEQUENCE_DEPTH_ERROR "Invalid sequence key length"

struct SEQUENCE_DEPTH_EXCEPTION : std::exception {
    const char *what() const throw() {
        return "Invalid sequence key length exception";
    }
};

class FibX {

public:
    explicit FibX(long long);

    long long GetNextElement();

    void reset();

private:
    long long keyLength;
    std::vector<long long> fibVector;
};