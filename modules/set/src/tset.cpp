#include "include/tset.h"

TSet::TSet(int mp) : BitField(-1)
{
}

TSet::TSet(const TSet &s) : BitField(-1)
{
}

TSet::TSet(const TBitField &bf) : BitField(-1)
{
}

int TSet::IsMember(const int Elem) const
{
    return 0;
}

void TSet::InsElem(const int Elem)
{
}

TSet& TSet::operator=(const TSet &s)
{
}

int TSet::operator==(const TSet &s) const
{
    return 0;
}

int TSet::operator!=(const TSet &s) const
{
}

TSet TSet::operator+(const TSet &s)
{
}

TSet TSet::operator+(const int Elem)
{
}

TSet TSet::operator-(const int Elem)
{
}

TSet TSet::operator*(const TSet &s)
{
}

TSet TSet::operator~(void)
{
}


istream &operator>>(istream &istr, TSet &s)
{
}

ostream& operator<<(ostream &ostr, const TSet &s)
{
}
