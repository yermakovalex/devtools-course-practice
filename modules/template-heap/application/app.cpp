// Copyright 2018 Kamelina Julia

#include <stdlib.h>
#include <stdio.h>
#include <string>

#include "include/prim-app.hpp"

int main(int argc, const char** argv) {
  PrimApp app;
  std::string output = app(argc, argv);
  printf("%s\n", output.c_str());
  return 0;
}
