// Copyright 2018 Ioanu Daniel

#include "include/bisymmetric_matrix.h"

#include <gtest/gtest.h>
#include <fstream>
#include <cstdio>

#ifdef WINDOWS
    #include <direct.h>
    #define getWorkingDir _getcwd
#else
    #include <unistd.h>
    #define getWorkingDir getcwd
#endif

TEST(Bisymmetric_Matrix, Can_Create) {
    // Arrange & Act
    Matrix m(1);
    std::ifstream is("../../../../modules/bisymmetric-matrix/test/matrix1.txt");
    is >> m;
    is.close();

    // Assert
    EXPECT_EQ(1, m.GetElem(1,1));
}

TEST(Bisymmetric_Matrix, Can_Copy) {
    // Arrange
    Matrix a(5);
    Matrix b(5);

    std::ifstream is("../../../../modules/bisymmetric-matrix/test/matrix1.txt");
    is >> a;
    is.close();

	char path[FILENAME_MAX];
	getWorkingDir(path, sizeof(path));
	printf("%s", path);
	
    a.Output();
    
    // Act & Assert
    EXPECT_EQ(a, b);
}

TEST(Bisymmetric_Matrix, Can_Add) {
    // Arrange
    Matrix a(5);
    Matrix b(5);
    Matrix res(5);

    // std::ifstream is("../../../../modules/bisymmetric-matrix/test/matrix1.txt");
    std::ifstream is("test/matrix1.txt");
    is >> a;
    is.close();

    a.Output();

    std::ifstream ist("../../../../modules/bisymmetric-matrix/test/matrix1.txt");
    ist >> b;
    ist.close();

    std::ifstream resIs("../../../../modules/bisymmetric-matrix/test/add_matrix.txt");
    resIs >> res;
    resIs.close();

    // Act & Assert
    EXPECT_EQ(a + b, res);
}

TEST(Bisymmetric_Matrix, Can_Subtract) {
    // Arrange
    Matrix a(5);
    Matrix b(5);
    Matrix res(5);

    std::ifstream is("../../../../modules/bisymmetric-matrix/test/matrix1.txt");
    is >> a;
    is.close();

    std::ifstream ist("../../../../modules/bisymmetric-matrix/test/matrix1.txt");
    ist >> b;
    ist.close();

    std::ifstream resIs("../../../../modules/bisymmetric-matrix/test/substract_matrix.txt");
    resIs >> res;
    resIs.close();

    // Act & Assert
    EXPECT_EQ(a - b, res);
}

TEST(Bisymmetric_Matrix, Can_Multiply_With_Number) {
    // Arrange
    Matrix a(5);
    Matrix res(5);

    std::ifstream is("../../../../modules/bisymmetric-matrix/test/matrix1.txt");
    is >> a;
    is.close();

    std::ifstream resIs("../../../../modules/bisymmetric-matrix/test/add_matrix.txt");
    resIs >> res;
    resIs.close();

    // Act & Assert
    EXPECT_EQ(a * 2, res);
}

TEST(Bisymmetric_Matrix, Not_Equal_Matrix) {
    // Arrange
    Matrix a(5);
    Matrix b(5);
    bool equalMatrix = false;

    std::ifstream is("../../../../modules/bisymmetric-matrix/test/matrix1.txt");
    is >> a;
    is.close();

    std::ifstream ist("../../../../modules/bisymmetric-matrix/test/matrix2.txt");
    ist >> b;
    ist.close();

    // Act
    if (a == b)
        equalMatrix = true;

    // Assert
    EXPECT_FALSE(equalMatrix);
}

TEST(Bisymmetric_Matrix, Subtract_Matrix_with_Different_Sizes) {
    // Arrange
    Matrix a(5);
    Matrix b(3);
    Matrix res(5);

    std::ifstream is("../../../../modules/bisymmetric-matrix/test/matrix1.txt");
    is >> a;
    is.close();

    std::ifstream ist("../../../../modules/bisymmetric-matrix/test/matrix1.txt");
    ist >> b;
    ist.close();

    // Act & Assert
    EXPECT_ANY_THROW(a - b);
}
