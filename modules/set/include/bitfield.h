#pragma once
#include <iostream>
using namespace std;
class bitfield{
    int* arr;
    int n;
    int sizeU;
    int Mem_index(int);
    int Mask(int);

 public:
    bitfield(int _SizeU = 100);
    bitfield(bitfield&);
    ~bitfield(void);

    void setbit(int);
    int getbit(int);
    void Clearbit(int);

    bitfield operator ~();
    bitfield operator &(bitfield&);
    bitfield operator |(bitfield&);
    bitfield& operator =(bitfield&);
};

