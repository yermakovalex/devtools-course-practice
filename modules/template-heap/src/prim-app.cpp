// Copyright 2018 Kamelina Julia

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <cstdlib>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>

#include "include/heap.hpp"
#include "include/prim-app.hpp"
#include "include/prim.hpp"

using std::vector;

PrimApp::PrimApp() : message_("") {}

void PrimApp::help(const char* message) {
  message_ =
    std::string(message) +
    "This application implements Prim's algorithm to find" +
    " minimum spanning tree based on binary heap.\n\n" +
    "Please provide arguments in the following format:\n\n" +

    "  $ template-heap -[h] [help] -[p] [path to file] -[d] [demention]\n\n" +
    "\t-h    show help message\n" +
    "\t-p    path to .txt file, contains adjacency matrix for grapth\n" +
    "\t-d    heap demention (optional, default is 2)\n";
}

bool PrimApp::validateArguments(int argc, const char** argv) {
  if (argc == 1) {
    message_ = std::string("This application implements Prim's algorithm\n") +
      "Usage:  template-heap -[h] help -[p] [path to file] -[d] [demention]\n";
    return false;
  } else if (argv[1][0] == '-' && argv[1][1] == 'h') {
    help("");
    return false;
  } else if (argc > 1 && (argv[1][0] != '-' || argv[1][1] != 'p')) {
    help("ERROR: Wrong argument format\n\n");
    return false;
  }
  return true;
}

int parseInt(const char* arg) {
  char* end;
  int val = strtol(arg, &end, 10);

  if (end[0]) {
    throw std::string("Wrong number format!");
  }

  return val;
}

vector<vector<int> > parseFile(const char* arg) {
  std::ifstream f;
  f.open(arg);
  if (!f) {
    throw std::string("FILE NOT FOUND!");
  }

  vector<vector<int> > g;
  vector<int> v;

  while (!f.eof()) {
    char ch = f.get();
    if (ch != ' ') {
      if (ch == '\n') {
        g.push_back(v);
        v.resize(0);
      } else {
        v.push_back(ch - '0');
      }
    }
  }
  g.push_back(v);
  f.close();

  return g;
}

std::string PrimApp::operator()(int argc, const char** argv) {
  Arguments arg;
  std::ostringstream stream;

  if (!validateArguments(argc, argv)) {
    return message_;
  }

  try {
    arg.graph = parseFile(argv[2]);
    if (argc == 3) {
      arg.dem = 2;
    } else {
      if (argv[3][0] == '-' && argv[3][1] == 'd') {
        arg.dem = parseInt(argv[4]);
      } else {
        help();
        return message_;
      }
    }

    vector<Node> core = Prim(arg.graph, arg.dem);
    int size = core.size();
    for (int i = 0; i < size; i++) {
      stream << "Distance " << core[i].dist << " First " << core[i].first
             << " Second " << core[i].second << std::endl;
    }
  } catch (std::string& str) {
    return str;
  }
  message_ = stream.str();
  return message_;
}
