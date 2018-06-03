// Copyright 2018 TolyaTalamanov
#include <iostream>
#include <string>
#include "include/polynom_calculator.hpp"
#include "include/monom.h"

int main(int argc, const char** argv) {
  PolynomCalculator app;
  std::string output = app(argc, argv);
  std::cout << output << std::endl;
  return 0;
}
