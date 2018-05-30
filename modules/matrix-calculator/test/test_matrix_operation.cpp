// Copyright 2018 Batanina Liubov

#include <gtest/gtest.h>
#include <vector>
#include <string>
#include "include/matrix_operation.hpp"

using ::testing::internal::RE;

TEST(MatrixOperationTest, create_mat_operation) {
  // Arrange & Act & Assert
  ASSERT_NO_THROW(MatrixOperation mc);
}

TEST(MatrixOperationTest, can_sum_matrixes) {
    // Arrange
    int argc = 4;
    std::vector<const char*> v = {"Tests", "3", "3", "+" };
    const char** argv = v.data();
    MatrixOperation sum;

    // Act
    std::string res = sum(argc, argv);
    auto ins = sum.getInputMatrixes();
    MatrixCalculator mc1;
    mc1.SetMatrix(ins[0]);
    MatrixCalculator mc2;
    mc2.SetMatrix(ins[1]);
    auto sumMat = mc1 + mc2;
    std::string resSum = sumMat.matrix_to_string();

    // Assert
    EXPECT_EQ(res, resSum);
}

TEST(MatrixOperationTest, can_subtract_matrixes) {
    // Arrange
    int argc = 4;
    std::vector<const char*> v = {"Tests", "3", "3", "-"};
    const char** argv = v.data();
    MatrixOperation sub;

    // Act
    std::string res = sub(argc, argv);
    auto ins = sub.getInputMatrixes();
    MatrixCalculator mc1;
    mc1.SetMatrix(ins[0]);
    MatrixCalculator mc2;
    mc2.SetMatrix(ins[1]);
    auto subMat = mc1 - mc2;
    std::string resSub = subMat.matrix_to_string();

    // Assert
    EXPECT_EQ(res, resSub);
}

TEST(MatrixOperationTest, can_multiply_matrixes) {
    // Arrange
    int argc = 4;
    std::vector<const char*> v = {"Tests", "3", "3", "*" };
    const char** argv = v.data();
    MatrixOperation mult;

    // Act
    std::string res = mult(argc, argv);
    auto ins = mult.getInputMatrixes();
    MatrixCalculator mc1;
    mc1.SetMatrix(ins[0]);
    MatrixCalculator mc2;
    mc2.SetMatrix(ins[1]);
    auto multMat = mc1 * mc2;
    std::string resMult = multMat.matrix_to_string();

    // Assert
    EXPECT_EQ(res, resMult);
}

TEST(MatrixOperationTest, can_transpon_matrix) {
    // Arrange
    int argc = 4;
    std::vector<const char*> v = {"Tests", "3", "3", "Transpon" };
    const char** argv = v.data();
    MatrixOperation transpon;

    // Act
    std::string res = transpon(argc, argv);
    auto ins = transpon.getInputMatrixes();
    MatrixCalculator mc1;
    mc1.SetMatrix(ins[0]);
    auto transponMat = mc1.Transpon(3);
    std::string resMult = transponMat.matrix_to_string();
    // Assert
    EXPECT_EQ(res, resMult);
}

TEST(MatrixOperationTest, can_inverse_matrix) {
    // Arrange
    int argc = 4;
    std::vector<const char*> v = {"Tests", "3", "3", "InverseMatrix" };
    const char** argv = v.data();
    MatrixOperation inverse;

    // Act
    std::string res = inverse(argc, argv);
    auto ins = inverse.getInputMatrixes();
    MatrixCalculator mc1;
    mc1.SetMatrix(ins[0]);
    auto inverseMat = mc1.InverseMatrix();
    std::string resInv = inverseMat.matrix_to_string();

    // Assert
    EXPECT_EQ(res, resInv);
}

TEST(MatrixOperationTest, invalide_size_of_arguments) {
  // Arrange
  int argc = 3;
  std::vector<const char*> v = {"Tests", "3", "+"};
  const char** argv = v.data();
  MatrixOperation mc;

  // Act
  std::string output = mc(argc, argv);

  // Assert
  EXPECT_TRUE(RE::PartialMatch(output, RE("ERROR: Should be 4 arguments:*")));
}

TEST(MatrixOperationTest, invalide_operation) {
  // Arrange
  int argc = 4;
  std::vector<const char*> v = {"Tests", "3", "3", "/"};
  const char** argv = v.data();
  MatrixOperation mc;

  // Act
  std::string output = mc(argc, argv);

  // Assert
  EXPECT_TRUE(RE::PartialMatch(output, RE("Wrong operation format")));
}
