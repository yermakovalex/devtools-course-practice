// Copyright 2018 Mayachkin Arseny

#include "include/batcher_merge.h"
#include <stdexcept>
#include <vector>
#include <algorithm>
BatcherMerge::BatcherMerge(std::vector<int> a) {
    array = a;
}

void BatcherMerge::compexch(int a, int b) {
  if (array[b] < array[a])
    std::swap(array[a], array[b]);
}

void BatcherMerge::shuffle(int l, int r) {
  std::vector<int> tmp(array.size());
  int i, j, m = (l + r) / 2;

  for (i = l, j = 0; i <= r; i += 2, j++) {
    tmp[i] = a[l + j];
    tmp[i + 1] = a[m + j + 1];
  }

  for (int i = l; i <= r; i++)
    a[i] = tmp[i];
}

void BatcherSort::unshuffle(int l, int r) {
  std::vector<int> tmp(array.size());
  int i, j, m = (l + r) / 2;

  for (i = l, j = 0; i <= r; i += 2, j++) {
    tmp[l + j] = a[i];
    tmp[m + j + 1] = a[i + 1];
  }

  for (int i = l; i <= r; i++)
    a[i] = tmp[i];
}

void BatcherMerge::merge(int l, int r) {
  if (l > r)
    throw std::logic_error("Left index can't be > right index");
  if ((r < 0) || (l < 0))
    throw std::logic_error("Index can't be < 0");
  if (r == l + 1)
    compexch(l, r);
  if (r < l + 2)
    return;

  unshuffle(l, r);
  int m = (l + r) / 2;

  BatcherMerge(l, m);
  BatcherMerge(m + 1, r);

  unshaffle(l, r);
  shuffle(l, r);
  for (int i = l + 1; i < r; i += 1)
    compexch(i, i + 1);
}
