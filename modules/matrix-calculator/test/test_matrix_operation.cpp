// Copyright 2018 Batanina Liubov

#include <gtest/gtest.h>
#include "include/matrix_operation.hpp"

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
    MatrixCalculator res = sum(argc, argv);
    auto ins = sum.getInputMatrix();
    MatrixCalculator mc1;
    mc1.SetMatrix(ins[0]);
    MatrixCalculator mc2;
    mc2.SetMatrix(ins[1]);
    auto sumMat = mc1 + mc2;

    // Assert
    EXPECT_EQ(res, sumMat);
}

TEST(MatrixOperationTest, can_subtract_matrixes) {
    // Arrange
    int argc = 4;
    std::vector<const char*> v = {"Tests","3", "3", "-" };
    const char** argv = v.data();
    MatrixOperation sub;

    // Act
    MatrixCalculator res = sub(argc, argv);
    auto ins = sub.getInputMatrix();
    MatrixCalculator mc1;
    mc1.SetMatrix(ins[0]);
    MatrixCalculator mc2;
    mc2.SetMatrix(ins[1]);
    auto subMat = mc1 - mc2;

    // Assert
    EXPECT_EQ(res, subMat);
}

TEST(MatrixOperationTest, can_multiply_matrixes) {
    // Arrange
    int argc = 4;
    std::vector<const char*> v = {"Tests", "3", "3", "*" };
    const char** argv = v.data();
    MatrixOperation mult;

    // Act
    MatrixCalculator res = mult(argc, argv);
    auto ins = mult.getInputMatrix();
    MatrixCalculator mc1;
    mc1.SetMatrix(ins[0]);
    MatrixCalculator mc2;
    mc2.SetMatrix(ins[1]);
    auto multMat = mc1 * mc2;

    // Assert
    EXPECT_EQ(res, multMat);
}

TEST(MatrixOperationTest, can_transpon_matrix) {
    // Arrange
    int argc = 4;
    std::vector<const char*> v = {"Tests", "3", "3", "Transpon" };
    const char** argv = v.data();
    MatrixOperation transpon;

    // Act
    MatrixCalculator res = transpon(argc, argv);
    auto ins = transpon.getInputMatrix();
    MatrixCalculator mc1;
    mc1.SetMatrix(ins[0]);
    auto transponMat = mc1.Transpon(3);

    // Assert
    EXPECT_EQ(res, transponMat);
}

TEST(MatrixOperationTest, invalide_size_of_arguments) {
  // Arrange
  int argc = 3;
  std::vector<const char*> v = {"Tests", "3", "+"};
  const char** argv = v.data();
  MatrixOperation mc;
  // Act & Assert
  EXPECT_THROW(mc(argc, argv), std::logic_error);
}

TEST(MatrixOperationTest, invalide_operation) {
  // Arrange
  int argc = 4;
  std::vector<const char*> v = {"Tests", "3", "3", "/"};
  const char** argv = v.data();
  MatrixOperation mc;
  // Act & Assert
  EXPECT_THROW(mc(argc, argv), std::logic_error);
}
