// Copyright 2018 Kamelina Julia

#ifndef MODULES_TEMPLATE_HEAP_INCLUDE_PRIM_APP_HPP_
#define MODULES_TEMPLATE_HEAP_INCLUDE_PRIM_APP_HPP_

#include <string>
#include <vector>

using std::vector;

class PrimApp {
 public:
    PrimApp();
    std::string operator()(int argc, const char** argv);

 private:
    void help(const char* message = "");
    bool validateArguments(int argc, const char** argv);
    std::string message_;

  typedef struct {
    vector<vector<int> > graph;
    int dem;
  } Arguments;
};

#endif  //  MODULES_TEMPLATE_HEAP_INCLUDE_PRIM_APP_HPP_
