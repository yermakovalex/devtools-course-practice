#include <iostream>
#include "BitField.h"
using namespace std;

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