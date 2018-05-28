//
// Copyright 2018 Batanina Liubov
//

#ifndef MODULES_MATRIX_CALCULATOR_INCLUDE_MATRIX_OPERATION_HPP_
#define MODULES_MATRIX_CALCULATOR_INCLUDE_MATRIX_OPERATION_HPP_

#include <string>
#include <vector>

#include "include/matrix_calculator.h"

class MatrixOperation {
 public:
  MatrixOperation();
  std::string operator()(int argc, const char** argv);
  std::vector<matrix_type> getInputMatrixes();
 private:
  std::vector<matrix_type> inputs;
  std::string message_;
  void help(const char* appname, const char* message = "");
  matrix_type create_random_matrix(int rows, int cols);
  bool validate_data(int argc, const char** argv);
  int find_operation(std::string operation);
};

#endif  // MODULES_MATRIX_CALCULATOR_INCLUDE_MATRIX_OPERATION_HPP_
