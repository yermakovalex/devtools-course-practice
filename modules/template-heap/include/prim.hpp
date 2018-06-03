// Copyright 2018 Kamelina Julia

#ifndef MODULES_TEMPLATE_HEAP_INCLUDE_PRIM_HPP_
#define MODULES_TEMPLATE_HEAP_INCLUDE_PRIM_HPP_

#include <vector>

using std::vector;

struct Node {
  int dist;
  int first;
  int second;

  explicit Node(int _d, int _f, int _s) {
    dist = _d;
    first = _f;
    second = _s;
  }
};

struct NodeCompare {
  bool operator() (const Node& x, const Node& y) const {
      return (x.dist > y.dist);
  }
};

vector<Node> Prim(vector<vector<int> >g, int d);

#endif  //  MODULES_TEMPLATE_HEAP_INCLUDE_PRIM_HPP_
