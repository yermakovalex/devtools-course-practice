// Copyright 2018 Mayachkin Arseny

#include "include/batcher_merge.h"

#include <stdexcept>

#include <vector>

void shuffle(std::vector<int> *a, int l, int r)
{
   std::vector<int> tmp;
   int i, j, m = (l + r) / 2;

   for (i = l, j = 0; i <= r; i += 2, j++)
   {
      tmp.push(a[l + j]);
      tmp.push(a[m + j + 1]);
   }
    
   for (int i = l; i <= r; i++)
      a[i] = tmp[i];
}

void unshuffle(std::vector<int> *a, int l, int r)
{
   std::vector<int> tmp(a->size());
   int i, j, m = (l + r) / 2;
    
   for (i = l, j = 0; i <= r; i += 2, j++)
   {
      tmp.push(a[i]);
      tmp.push(a[i + 1]);
   }
    
   for (int i = 0; i <= r; i++)
      a[i] = tmp[i];
}

void merge::BatcherMerge(std::vector<int> *a, int l, int r)
{
   if (l > r)
      throw std::logic_error("Left index can't be > right index");
   if ((r < 0) || (l < 0))
      throw std::logic_error("Index can't be < 0");
   if (r == l + 1)
      if ((*array)[l] > (*array)[r])
         std::swap((*array)[l], (*array)[r]);
   if (r < l + 2)
      return;
    
   unshuffle(a, l, r);
   int m = (l + r) / 2;
    
   BatcherMerge(a, l, m);
   BatcherMerge(a, m + 1, r);
    
   shuffle(a, l, r);
   for (int i = l + 1; i < r; i += 2)
      if ((*array)[i] > (*array)[i+1])
         std::swap((*array)[i], (*array)[i+1]);

   //int halfSize = (r - l + 1) / 2 - 1;
	
   //for (int i = l + 1; i + halfSize < r; i++)
     // compexch(a[i], a[i + halfSize]);
}
