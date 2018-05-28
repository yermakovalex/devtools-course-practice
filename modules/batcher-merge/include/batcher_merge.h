// Copyright 2018 Mayachkin Arseny

#ifndef MODULES_BATCHER_MERGE_INCLUDE_BATCHER_MERGE_H_

#define MODULES_BATCHER_MERGE_INCLUDE_BATCHER_MERGE_H_

#include <vector>

class BatcherMerge{
 private:
  std::vector<int> array;

  void compexch(int a, int b);
  void shuffle(int l, int r);
  void unshuffle(int l, int r);
 public:
  BatcherMerge() {}
  BatcherMerge(std::vector<int> a);
  void merge(int l, int r);
};

#endif  // MODULES_BATCHER_MERGE_INCLUDE_BATCHER_MERGE_H_
