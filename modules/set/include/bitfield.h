// Copyright 2018 Levitsky Ilya
#ifndef __BITFIELD_H__
#define __BITFIELD_H__

#pragma once
#include <iostream>
class bitfield{
    int* arr;
    int n;
    int sizeU;
    int k;
    int Mem_index(int k);
    int Mask(int k);

 public:
    explict bitfield(int _SizeU = 100);
    bitfield(bitfield&);
    ~bitfield(void);

    void setbit(int k);
    int getbit(int k);
    void Clearbit(int k);

    bitfield operator ~();
    bitfield operator &(bitfield&);
    bitfield operator |(bitfield&);
    bitfield& operator =(bitfield&);
};
#endif  // __BITFIELD_H__
