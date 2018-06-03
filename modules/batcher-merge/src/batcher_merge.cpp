// Copyright 2018 Mayachkin Arseny

#include "include/batcher_merge.h"
#include <stdexcept>
#include <vector>
#include <algorithm>

void BatcherMerge::compexch(int a, int b) {
  if (array[b] < array[a])
    std::swap(array[a], array[b]);
}

void BatcherMerge::shuffle(int l, int r) {
  std::vector<int> tmp(array.size());
  int i, j, m = (l + r) / 2;

  for (i = l, j = 0; i <= r; i += 2, j++) {
    tmp[i] = array[l + j];
    tmp[i + 1] = array[m + j + 1];
  }

  for (int i = l; i <= r; i++)
    array[i] = tmp[i];
}

void BatcherMerge::unshuffle(int l, int r) {
  std::vector<int> tmp(array.size());
  int i, j, m = (l + r) / 2;

  for (i = l, j = 0; i <= r; i += 2, j++) {
    tmp[l + j] = array[i];
    tmp[m + j + 1] = array[i + 1];
  }

  for (int i = l; i <= r; i++)
    array[i] = tmp[i];
}

void BatcherMerge::merge(int l, int r) {
  if (l > r)
    throw std::logic_error("Left index can't be > right index");
  if ((r < 0) || (l < 0))
    throw std::logic_error("Index can't be < 0");
  if ((unsigned)r >= array.size())
    throw std::logic_error("Right index is out of range");
  if (r == l + 1)
    compexch(l, r);
  if (r < l + 2)
    return;

  unshuffle(l, r);
  int m = (l + r) / 2;

  merge(l, m);
  merge(m + 1, r);

  shuffle(l, r);
  for (int i = l + 1; i < r; i += 1)
    compexch(i, i + 1);
}

std::vector<int> BatcherMerge::getArray() {
  return array;
}
