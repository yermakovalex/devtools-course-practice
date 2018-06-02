/* Copyright 2018 Kamelina Julia */

#include <string>
#include <vector>

#include "include/prim.hpp"
#include "include/heap.hpp"

vector<Node> Prim(vector<vector<int> >g, int d) {
  vector<bool> visited(g.size(), false);
  atal::heap<Node, NodeCompare> h;
  try {
  h.setDim(d);
  } catch (std::logic_error &str) {
    throw std::string(str.what());
  }

  vector<vector<Node> > graph;
  int n = static_cast<int>(g.size());

  for (int i = 0; i < n; i++) {
    vector<Node> gr;
    for (int j = 0; j < n; j++) {
      if (g[i][j] != 0) gr.push_back(Node(g[i][j], i, j));
    }
    graph.push_back(gr);
  }
  vector<Node> core;

  h.push(Node(0, 0, 0));
  int vc = 0;

  while (h.size() != 0 && vc != n) {
    auto v = h.top();
    h.pop();

    if (v.first != v.second && visited[v.second] == false) {
      core.push_back(v);
    }
    for (int i = 0; i < static_cast<int>(graph[v.second].size()); i++) {
      if (visited[i] == false) {
        h.push(graph[v.second][i]);
      }
    }
    visited[v.second] = true;
    vc++;
  }

  return core;
}
