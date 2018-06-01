// Copyright 2018 Ioanu Daniel

#include <gtest/gtest.h>
#include <fstream>

#include "include/bisymmetric_matrix.h"

TEST(Bisymmetric_Matrix, Can_Create) {
    // Arrange
	Matrix m(5);
	std::ifstream is("matrix1.txt");
	is >> m;
	is.close();

    // Act
	m.Output();

    // Assert

}

