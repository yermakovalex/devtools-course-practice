#include <stdexcept>
#include <random>
#include <algorithm>
#include "include/matrix_operation.hpp"

int MatrixOperation::find_operation(std::string operation) {
  std::vector<std::string> operat = {"+", "-", "*",
                                          "Transpon", "InverseMatrix"};
  auto it_pos = find(operat.begin(), operat.end(), operation);
  return it_pos - operat.begin();
}

bool MatrixOperation::validate_data(int argc, const char** argv) {
  return (argc == 4 && atoi(argv[1]) > 0 && atoi(argv[2]) > 0
                                         && find_operation(argv[3]) != 5 );
}

std::vector<matrix_type> MatrixOperation::getInputMatrix() {
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

MatrixCalculator MatrixOperation::operator()(int argc, const char** argv) {
  if ( !validate_data(argc, argv) ) {
    throw std::logic_error("uncorrect data");
  }
  int rows = atoi(argv[1]);
  int cols = atoi(argv[2]);
  MatrixCalculator mat1;
  inputs.push_back(create_random_matrix( rows, cols ));
  mat1.SetMatrix(inputs[0]);

  MatrixCalculator mat2;
  inputs.push_back(create_random_matrix(rows, cols ));
  mat2.SetMatrix(inputs[1]);
  MatrixCalculator result(rows, cols);
  int pos = find_operation(argv[3]);

  switch(pos){
    case 0: {
      result = mat1 + mat2;
      break;
    }
    case 1: {
      result = mat1 - mat2;
      break;
    }
    case 2: {
      result = mat1 * mat2;
      break;
    }
    case 3: {
      if (rows != cols) {
        throw std::logic_error("number of rows must be equal number of cols");
      }
      result = mat1.Transpon(rows);
      break;
    }
    case 4: {
      result = mat1.InverseMatrix();
      break;
    }
  }
  return result;
}
