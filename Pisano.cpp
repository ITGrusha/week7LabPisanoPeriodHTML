//
// Created by MrGra on 10/26/2019.
//
#include <cstdio>
#include "FibMod.hpp"
#include "Pisano.hpp"


int Sequence::getPeriod() {
    SequenceMember firstElement = this->getFirstElement();
    SequenceMember tortoise = firstElement.getNext();
    int lam = 1;
    if (this->mod == 1)
        return 1;
    while (tortoise.GetValue() != 0 || tortoise.getNext().GetValue() != 1) {
        ++tortoise;
        lam++;
    }
    return lam;
}

SequenceMember SequenceMember::getNext() {
    return this->sequence->getElement(this->number + 1);
}

SequenceMember::SequenceMember(int number, int value, Sequence &sequence) {
    this->number = number;
    this->value = value;
    this->sequence = &sequence;
}

int SequenceMember::GetValue() {
    return this->value;
}

SequenceMember SequenceMember::operator++(int) {
    SequenceMember temp = *this;
    ++*this;
    return temp;
}

SequenceMember &SequenceMember::operator++() {
    *this = this->sequence->getElement(this->number + 1);
    return *this;
}

bool SequenceMember::operator!=(const SequenceMember &b) {
    if (this->number == b.number && this->sequence == b.sequence)
        return true;
}

SequenceMember Sequence::getFirstElement() {
    return Sequence::getElement(0);
}

SequenceMember Sequence::getElement(int number) {
    int seqSize = this->sequence.size();
    if (number >= seqSize) {
        for (int i = seqSize; i <= number + 1; ++i) {
            this->sequence.push_back(FibMod());
//            printf("_%i*%i_", this->sequence[i], this->sequence.size());
        }
    }
    SequenceMember element(number, this->sequence[number], *this);
    return element;
}

Sequence::Sequence(int mod) {
    this->mod = mod;
    resetFib();
    setMod(mod);
    this->sequence = std::vector<int>(1, 0);
}

bool Sequence::operator==(Sequence &b) {
    return this->mod = b.mod;
}
