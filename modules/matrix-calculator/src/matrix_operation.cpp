//
// Copyright 2018 Batanina Liubov
//

#include <stdexcept>
#include <random>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include "include/matrix_operation.hpp"


MatrixOperation::MatrixOperation() : message_("") {}

void MatrixOperation::help(const char* appname, const char* message) {
    message_ = std::string(message) +
          "\n This is a matrix calculator application.\n\n" +
          "Please provide arguments in the following format:\n\n" +

          "  $ " + appname + " <rows> " + "<columns> " +
          "<operation>\n\n" +

          "Where 1 and 2 arguments are int numbers, " +
          "and <operation> is one of" +
              " '+', '-', '*', 'Transpon', 'InverseMatrix'.\n" +
          "Matrix will be filled randomly.\n";
}

int MatrixOperation::find_operation(std::string operation) {
  std::vector<std::string> ops = {"+", "-", "*",
                                          "Transpon", "InverseMatrix"};
  auto it_pos = find(ops.begin(), ops.end(), operation);
  return it_pos - ops.begin();
}

bool MatrixOperation::validate_data(int argc, const char** argv) {
  if (argc != 4) {
    std::string msg = std::string("ERROR: Should be 4 arguments: ") +
    std::string("<application name> <rows> <columns> <operation>");
    help(argv[0], msg.c_str());
    return false;
  }
  if (atoi(argv[1]) <= 0) {
    help(argv[0], "Wrong rows format!");
    return false;
  }
  if (atoi(argv[2]) <= 0) {
    help(argv[0], "Wrong cols format!");
    return false;
  }
  if (find_operation(argv[3]) == 5) {
    help(argv[0], "Wrong operation format!");
    return false;
  }
  if (find_operation(argv[3]) == 3 && atoi(argv[1]) != atoi(argv[2])) {
    help(argv[0], "Number of rows must be equal number of cols!");
    return false;
  }
  return true;
}

std::vector<matrix_type> MatrixOperation::getInputMatrixes() {
  return inputs;
}

matrix_type MatrixOperation::create_random_matrix(int rows, int cols) {
  matrix_type matrix(rows, std::vector<double>(cols));

  std::uniform_real_distribution<double> distribution;
  std::mt19937 num_generator{std::random_device()()};
  for (auto& vec : matrix) {
    for (auto& elem : vec) {
         elem = distribution(num_generator);
        }
      }
  return matrix;
}

std::string MatrixOperation::operator()(int argc, const char** argv) {
  if ( !validate_data(argc, argv) ) {
    return message_;
  }
  int rows = atoi(argv[1]);
  int cols = atoi(argv[2]);
  MatrixCalculator mat1;
  inputs.push_back(create_random_matrix(rows, cols));
  mat1.SetMatrix(inputs[0]);

  MatrixCalculator mat2;
  inputs.push_back(create_random_matrix(rows, cols));
  mat2.SetMatrix(inputs[1]);
  MatrixCalculator result(rows, cols);
  int pos = find_operation(argv[3]);

  std::string s;

  switch (pos) {
    case 0: {
      result = mat1 + mat2;
      s = result.matrix_to_string();
      break;
    }
    case 1: {
      result = mat1 - mat2;
      s = result.matrix_to_string();
      break;
    }
    case 2: {
      result = mat1 * mat2;
      s = result.matrix_to_string();
      break;
    }
    case 3: {
      result = mat1.Transpon(rows);
      s = result.matrix_to_string();
      break;
    }
    case 4: {
      result = mat1.InverseMatrix();
      s = result.matrix_to_string();
      break;
    }
  }
  message_ = s;
  return message_;
}
