#include "set.h"


set::set(int mp)
{
	MaxPow = mp;
	BF = bitfield(mp);
}


set::set(set& x)
{
	MaxPow = x.MaxPow;
	BF = x.BF;
}


// Добавление элемента
void set::Insert(int k)
{
	if (k <= 0 || k > MaxPow)
		return;

	BF.setbit(k);
}


// Удаление элемента
void set::Del(int k)
{
	BF.Clearbit(k);
}


// Определяет принадлежность данного элемента множеству
int set::Get(int k)
{
	return BF.getbit(k);
}


// Операция объединения
set set :: operator+(set& x)
{
	if (MaxPow>x.MaxPow)
	{
		set tmp(MaxPow);
		tmp.BF = BF | x.BF;
		return(tmp);
	}
	else
	{
		set tmp(x.MaxPow);
		tmp.BF = BF | x.BF;
		return(tmp);
	}

}


// Операция пересечения
set set :: operator*(set& x)
{
	if (MaxPow<x.MaxPow)
	{
		set tmp(MaxPow);
		tmp.BF = BF&x.BF;
		return(tmp);
	}
	else
	{
		set tmp(x.MaxPow);
		tmp.BF = BF&x.BF;
		return(tmp);
	}
}


// дополнение множества
set set :: operator~()
{
	set tmp(MaxPow);
	tmp.BF = ~BF;
	return tmp;
}


set& set :: operator=(set& x)
{
	if (MaxPow != x.MaxPow)
	{
		BF = bitfield(x.MaxPow);
		MaxPow = x.MaxPow;
	}
	BF = x.BF;
	return *this;
}


set set :: operator ==(set& x)
{
	for (int i = 0; i<MaxPow; i++)
	{
		if (Get(i) != x.Get(i))
		{
			return 0;
		}
	}
	return 1;
}