// Copyright 2018 Batanina Liubov

#include <iostream>
#include <string>
#include "include/matrix_operation.hpp"

int main(int argc, const char** argv) {
  MatrixOperation app;
  std::string output = app(argc, argv);
  std::cout << output << std::endl;
  return 0;
}
