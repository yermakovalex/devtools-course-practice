#include "include/tbitfield.h"

TBitField::TBitField(int len)
{
}

TBitField::TBitField(const TBitField &bf)
{
}

TBitField::~TBitField()
{
}

int TBitField::GetMemIndex(const int n) const
{
}

TELEM TBitField::GetMemMask(const int n) const 
{
}


int TBitField::GetLength(void) const
{
  return 0;
}

void TBitField::SetBit(const int n)
{
}

void TBitField::ClrBit(const int n)
{
}

int TBitField::GetBit(const int n) const
{
  return 0;
}


TBitField& TBitField::operator=(const TBitField &bf)
{
}

int TBitField::operator==(const TBitField &bf) const
{
  return 0;
}

int TBitField::operator!=(const TBitField &bf) const
{
  return 0;
}

TBitField TBitField::operator|(const TBitField &bf)
{
}

TBitField TBitField::operator&(const TBitField &bf)
{
}

TBitField TBitField::operator~(void)
{
}


istream &operator>>(istream &istr, TBitField &bf)
{
}

ostream &operator<<(ostream &ostr, const TBitField &bf)
{
}
