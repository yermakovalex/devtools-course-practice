// Copyright 2018 Mayachkin Arseny

#include "include/batcher_merge.h"

#include <stdexcept>

#include <vector>

void compexch(int& a, int& b)
{
   if (b < a)
      std::swap(a, b);
}

void shuffle(std::vector<int>& a, unsigned int l, unsigned int r)
{
   auto half = (unsigned int)(l + r) / 2;
   std::vector<int> tmp(a.size());
   unsigned int i, j;

   for (i = l, j = 0; i <= r; i += 2, j++)
   {
      tmp[i] = a[l + j];
      tmp[i + 1] = a[half + j + 1];
   }
    
   for (auto i = 0; i < tmp.size(); i++)
      a[i] = tmp[i];
}

void unshuffle(std::vector<int>& a, unsigned int l, unsigned int r)
{
   auto half = (unsigned int)(l + r) / 2;
   std::vector<int> tmp(a.size());
   unsigned int i, j;
    
   for (i = l, j = 0; i <= r; i += 2, j++)
   {
      tmp[l + j] = a[i];
      tmp[half + j + 1] = a[i + 1];
   }
    
   for (auto i = 0; i < tmp.size(); i++)
      a[i] = tmp[i];
}

void merge::BatcherMerge(std::vector<int>& a, unsigned int l, unsigned int r)
{
   if (l > r)
      throw std::logic_error("Left index can't be > right index");
   if ((r < 0) || (l < 0))
      throw std::logic_error("Index can't be < 0");
   if (r == l + 1)
      compexch(a[l], a[r]);
   if (r < l + 2)
      return;
    
   unshuffle(a, l, r);
   auto half = (unsigned int)(l + r) / 2;
    
   OddEvenMergeSort(a, l, half);
   OddEvenMergeSort(a, half + 1, r);
    
   shuffle(a, l, r);
   for (auto i = l + 1; i < r; i += 2)
      compexch(a[i], a[i + 1]);

   auto halfSize = (r - l + 1) / 2 - 1;
	
   for (int i = l + 1; i + halfSize < r; i++)
      compexch(a[i], a[i + halfSize]);
}
