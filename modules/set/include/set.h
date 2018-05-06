// Copyright 2018 Levitsky Ilya
#include <iostream>
#include "include/bitfield.h"
#ifndef MODULES_SET_INCLUDE_SET_H_

class set{
    int MaxPow;
    bitfield BF;

 public:
    set(int mp = 10);
    set(set&);
    ~set(void) {}

    void Insert(int);
    void Del(int);
    int Get(int);

    set operator+(set&);
    set operator*(set&);
    set operator~();
    set& operator=(set&);
    set operator==(set&);
};
#endif //MODULES_SET_INCLUDE_SET_H_