//
// Created by MrGra on 10/26/2019.
//
#include <cstdio>

#include "Pisano.hpp"


//int Sequence::FindPeriodByKey() {
//    SequenceMember firstElement = this->GetFirstElement();
//    SequenceMember tortoise = firstElement.getNext();
//    int lam = 1;
//    if (this->module == 1)
//        return 1;
//    vector< long long > slice = vector< long  long >()
//    while (tortoise.GetValue() != 0 || tortoise.getNext().GetValue() != 1) {
//        ++tortoise;
//        lam++;
//    }
//    return lam;
//}

//SequenceMember SequenceMember::getNext() {
//    return this->sequence->GetElement(this->number + 1);
//}
//
//SequenceMember::SequenceMember(int number, int value, Sequence &sequence) {
//    this->number = number;
//    this->value = value;
//    this->sequence = &sequence;
//}
//
//int SequenceMember::GetValue() {
//    return this->value;
//}
//
//SequenceMember SequenceMember::operator++(int) {
//    SequenceMember temp = *this;
//    ++*this;
//    return temp;
//}
//
//SequenceMember &SequenceMember::operator++() {
//    *this = this->sequence->GetElement(this->number + 1);
//    return *this;
//}
//
//bool SequenceMember::operator!=(const SequenceMember &b) {
//    if (this->number == b.number && this->sequence == b.sequence)
//        return true;
//}

//SequenceMember Sequence::GetFirstElement() {
//    return Sequence::GetElement(0);
//}
//
//SequenceMember Sequence::GetElement(int number) {
//    int seqSize = this->sequence.size();
//    if (number >= seqSize) {
//        for (int i = seqSize; i <= number + 1; ++i) {
//            this->sequence.push_back(FibMod());
////            printf("_%i*%i_", this->sequence[i], this->sequence.size());
//        }
//    }
//    SequenceMember element(number, this->sequence[number], *this);
//    return element;
//}
//
//Sequence::Sequence(long long module, long long keyLength) {
//    this->module = module;
//    resetFib();
//    setMod(module);
//    this->sequence = std::vector<int>(1, 0);
//}

bool Sequence::operator==(Sequence &b) {
    return this->module = b.module;
}

Sequence::Sequence(long long module, long long keyLength) {
    this->module = module;
    this->keyLength = keyLength;
    this->random = Rand(module, keyLength);
    this->sequence.emplace_back(0);
}

int Sequence::FindPeriodByKey() {
    std::vector< long long > key(1, 0);
    Rand keySeq(module, keyLength);
    for (long long i = 1; i < keyLength; ++i)
        key.emplace_back(keySeq() % module);
//    for (int j = 0; j < key.size(); ++j) {
//        printf("%i, ", key[j]);
//    }
//    printf("%s", "\n");
    int matches = 0;
    while(matches < 2) {
        sequence.emplace_back(random());
        std::vector< long long> slice = std::vector< long long >(sequence.end() - keyLength, sequence.end());
        if (slice == key)
            ++matches;
//        for (int j = 0; j < slice.size(); ++j)
//            printf("_%li_", slice[j]);
//        printf("%s", "LKKKKKKKJ\n");
    }
    return (sequence.size() - keyLength);
}


