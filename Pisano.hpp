//
// Created by MrGra on 10/26/2019.
//

#ifndef WEEK7LABPISANOPERIODHTML_PISANO_HPP
#define WEEK7LABPISANOPERIODHTML_PISANO_HPP

#endif //WEEK7LABPISANOPERIODHTML_PISANO_HPP

#include <vector>

class Sequence;

class SequenceMember;

class Sequence {
public:
    Sequence(int);

    int getPeriodLength();

    std::vector<int> getPeriod();

    SequenceMember getFirstElement();

    SequenceMember getElement(int);

    bool operator==(Sequence &);

private:
    int mod;
    std::vector<int> sequence;
};


class SequenceMember {
public:
    SequenceMember(int number, int value, Sequence &sequence);

    SequenceMember getNext();

    int GetValue();

    SequenceMember operator++(int);

    SequenceMember &operator++();

    bool operator!=(const SequenceMember &);

private:
    Sequence *sequence;
    int number = 0;
    int value = 0;
};
