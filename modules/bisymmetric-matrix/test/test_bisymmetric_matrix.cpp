// Copyright 2018 Ioanu Daniel

#include <gtest/gtest.h>
#include <fstream>

#include "include/bisymmetric_matrix.h"

// Paths to the test files
#define MATRIX "../../../../../modules/bisymmetric-matrix/test/matrix1.txt"
#define MATRIX2 "../../../../../modules/bisymmetric-matrix/test/matrix2.txt"
#define MATRIX3 "../../../../../modules/bisymmetric-matrix/test/matrix3.txt"
#define ADD_RES "../../../../../modules/bisymmetric-matrix/test/add_matrix.txt"
#define SUB_RES "../../../../../modules/bisymmetric-matrix/test/sub_mat.txt"

TEST(Bisymmetric_Matrix, Can_Create) {
    // Arrange & Act
    Matrix m;
    std::ifstream is(MATRIX);
    is >> m;
    is.close();

    // Assert
    EXPECT_EQ(1, m.GetElem(1, 1));
}

TEST(Bisymmetric_Matrix, Can_Copy) {
    // Arrange
    Matrix a;

    std::ifstream is(MATRIX);
    is >> a;
    is.close();

    Matrix b(a);

    // Act & Assert
    EXPECT_EQ(a, b);
}

TEST(Bisymmetric_Matrix, Can_Add) {
    // Arrange
    Matrix a;
    Matrix b;
    Matrix res;

    std::ifstream is(MATRIX);
    is >> a;
    is.close();

    std::ifstream ist(MATRIX);
    ist >> b;
    ist.close();

    std::ifstream resIs(ADD_RES);
    resIs >> res;
    resIs.close();

    // Act & Assert
    EXPECT_EQ(a + b, res);
}

TEST(Bisymmetric_Matrix, Can_Subtract) {
    // Arrange
    Matrix a;
    Matrix b;
    Matrix res;

    std::ifstream is(MATRIX);
    is >> a;
    is.close();

    std::ifstream ist(MATRIX);
    ist >> b;
    ist.close();

    std::ifstream resIs(SUB_RES);
    resIs >> res;
    resIs.close();

    // Act & Assert
    EXPECT_EQ(a - b, res);
}

TEST(Bisymmetric_Matrix, Can_Multiply_With_Number) {
    // Arrange
    Matrix a;
    Matrix res;

    std::ifstream is(MATRIX);
    is >> a;
    is.close();

    std::ifstream resIs(ADD_RES);
    resIs >> res;
    resIs.close();

    // Act & Assert
    EXPECT_EQ(a * 2, res);
}

TEST(Bisymmetric_Matrix, Not_Equal_Matrix) {
    // Arrange
    Matrix a;
    Matrix b;

    std::ifstream is(MATRIX);
    is >> a;
    is.close();

    std::ifstream ist(MATRIX2);
    ist >> b;
    ist.close();

    // Act & Assert
    EXPECT_FALSE(a == b);
}

TEST(Bisymmetric_Matrix, Subtract_Matrix_with_Different_Sizes) {
    // Arrange
    Matrix a;
    Matrix b;

    std::ifstream is(MATRIX);
    is >> a;
    is.close();

    std::ifstream ist(MATRIX3);
    ist >> b;
    ist.close();

    // Act & Assert
    EXPECT_ANY_THROW(a - b);
}

TEST(Bisymmetric_Matrix, Out_of_Index_Element) {
    // Arrange
    Matrix a;

    std::ifstream is(MATRIX);
    is >> a;
    is.close();

    // Act & Assert
    EXPECT_ANY_THROW(a.GetElem(10, 10));
}

TEST(Bisymmetric_Matrix, Add_Matrix_with_Different_Size) {
    // Arrange
    Matrix a;
    Matrix b;

    std::ifstream is(MATRIX);
    is >> a;
    is.close();

    std::ifstream ist(MATRIX3);
    ist >> b;
    ist.close();

    // Act & Assert
    EXPECT_ANY_THROW(a + b);
}

TEST(Bisymmetric_Matrix, Can_Copy_Numbers) {
    // Arrange
    Matrix a;
    Matrix b;

    std::ifstream is(MATRIX);
    is >> a;
    is.close();

    b = a;

    // Act & Assert
    EXPECT_EQ(a, b);
}
