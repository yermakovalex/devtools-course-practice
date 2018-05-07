// Copyright 2018 Levitsky Ilya
#ifndef __SET_H__
#define __SET_H__

#include <iostream>
#include "include/bitfield.h"

class set{
    int MaxPow;
    bitfield BF;
    int k;

 public:
    explict set(int mp = 10);
    set(set&);
    ~set(void) {}

    void Insert(int k);
    void Del(int k);
    int Get(int k);

    set operator+(set&);
    set operator*(set&);
    set operator~();
    set& operator=(set&);
    set operator==(set&);
};
#endif  // __SET_H__
