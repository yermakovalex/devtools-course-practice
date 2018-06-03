// Copyright 2018 Levitsky Ilya
#include "include/set.h"

#include <vector>

set::set(int mp) {
    MaxPow = mp;
    BF = bitfield(mp);
}


set::set(set& x) {
    MaxPow = x.MaxPow;
    BF = x.BF;
}

void set::Insert(int k) {
    if (k <= 0 || k > MaxPow)
        return;
    BF.SetBit(k);
}

void set::Insert(const std::vector<int>& vec) {
    for (auto i = vec.begin(); i != vec.end(); i++)
        Insert(*i);
}

int set::GetN(int k) {
    if (Get(k)) {
        return k;
    }
    return 0;
}

int set::Get(int k) {
    return BF.GetBit(k);
}

std::vector<int> set::GetElements() {
    std::vector<int> res;
    for (int i = 0; i < 10; i++)
        if (this->GetN(i) != 0)
            res.emplace_back(i);

    if (res.empty())
        res.emplace_back(0);
    return res;
}

set set :: operator+(const set& x) {
    set tmp(x.MaxPow);
    tmp.BF = BF | x.BF;
    return(tmp);
}


set set :: operator*(const set& x) {
    set tmp(x.MaxPow);
    tmp.BF = BF&x.BF;
    return(tmp);
}

set set :: operator~() {
    set tmp(MaxPow);
    tmp.BF = ~BF;
    return tmp;
}

set& set :: operator=(const set& x) {
    BF = x.BF;
    return *this;
}
