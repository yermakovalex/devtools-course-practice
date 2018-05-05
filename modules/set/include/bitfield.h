#pragma once
#include <iostream>
using namespace std;
class bitfield
{
    int* arr; // память для представления битового поля
    int n; // кол-во элементов для представления битового поля
    int sizeU; // кол-во битов

    int Mem_index(int);
    int Mask(int);

public:
    bitfield(int _SizeU = 100);
    bitfield(bitfield&);
    ~bitfield(void);

    void setbit(int); // установить бит
    int getbit(int);	// получить значение бита
    void Clearbit(int);	// очистить бит

    bitfield operator ~();
    bitfield operator &(bitfield&);
    bitfield operator |(bitfield&);
    bitfield& operator =(bitfield&);
};

