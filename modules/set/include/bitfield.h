// Copyright 2018 Levitsky Ilya
#pragma once
#include <iostream>
using namespace std;
class bitfield{
    int* arr;
    int n;
    int sizeU;
	int k;
    int Mem_index(int k);
    int Mask(int k);

 public:
    bitfield(int _SizeU = 100);
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

