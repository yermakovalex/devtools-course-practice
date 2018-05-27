// Copyright 2018 Mayachkin Arseny

#ifndef MODULES_BATCHER_MERGE_INCLUDE_BATCHER_MERGE_H_

#define MODULES_BATCHER_MERGE_INCLUDE_BATCHER_MERGE_H_

#include <vector>

//void shuffle(std::vector<int> *a, int l, int r);
//void unshuffle(std::vector<int> *a, int l, int r);

struct merge {

   static void BatcherMerge(std::vector<int> *array, int first, int last);

};

#endif  // MODULES_BATCHER_MERGE_INCLUDE_BATCHER_MERGE_H_
  
