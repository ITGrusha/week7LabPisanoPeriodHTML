//
// Created by MrGra on 10/26/2019.
//

#ifndef WEEK7LABPISANOPERIODHTML_PISANO_HPP
#define WEEK7LABPISANOPERIODHTML_PISANO_HPP

#endif //WEEK7LABPISANOPERIODHTML_PISANO_HPP

#include <vector>
#include "Rand.hpp"


class Sequence {
public:
    Sequence(long long, long long);

    int FindPeriodByKey();

//    SequenceMember GetFirstElement();

//    SequenceMember GetElement(int);

    bool operator==(Sequence &);

private:
    long long module;
    long long keyLength;
    Rand random = Rand(1, 1);
    std::vector< long long > sequence;
};


//class SequenceMember {
//public:
//    SequenceMember(int number, int value, Sequence &sequence);
//
//    SequenceMember getNext();
//
//    int GetValue();
//
//    SequenceMember operator++(int);
//
//    SequenceMember &operator++();
//
//    bool operator!=(const SequenceMember &);
//
//private:
//    Sequence *sequence;
//    int number = 0;
//    int value = 0;
//};
