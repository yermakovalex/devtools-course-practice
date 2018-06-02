// Copyright 2018 Levitsky Ilya
#include <gtest/gtest.h>

#include <string>

#include "include/Cube.h"

TEST(AreaOfGeometricShapes, Get_H_From_Cube) {
    // Arrange
    double radius = 7.1;
    double h = 15.9;
    Cube cube(h);

    // Act & Assert
    EXPECT_EQ(h, cube.getH());
}

TEST(AreaOfGeometricShapes, Set_Radius_And_H_From_Cube) {
    // Arrange
    Cube cube;
    double h = 7.4;

    // Act
    cube.setH(h);

    // Assert
    EXPECT_EQ(h, cube.getH());
}

TEST(AreaOfGeometricShapes, Comparison_Operator) {
    // Arrange
    double h = 15.2;
    Cube cube1(6.5);
    Cube cube2(h);

    // Act
    cube1 = cube2;

    // Assert
    EXPECT_EQ(cube1.getH(), cube2.getH());
}

TEST(AreaOfGeometricShapes, Negative_Rad_Cube) {
    // Arrange
    double h = 15.9;

    // Act & Assert
    ASSERT_ANY_THROW(Cube cube(h));
}

TEST(AreaOfGeometricShapes, Negative_H_Cube) {
    // Arrange
    double h = -15.9;

    // Act & Assert
    ASSERT_ANY_THROW(Cube cube(h));
}

TEST(AreaOfGeometricShapes, Area_Calculation_Cube) {
    // Arrange
    double res = 0;
    Cube cube(4);

    // Act
    res = cube.areaCube();

    // Assert
    EXPECT_EQ(res, 24);
}

TEST(AreaOfGeometricShapes, Copy_Cube) {
    // Arrange
    Cube cube1(2);

    // Act
    Cube cube2(cube1);

    // Assert
    EXPECT_EQ(cube1.getH(), cube2.getH());
}

TEST(AreaOfGeometricShapes, Equal_Test_Cube) {
    // Arrange
    double h = 15.9;
    Cube cube1(h);
    Cube coub2(cube1);

    // Act & Assert
    EXPECT_TRUE(cube1 == cube2);
}
TEST(AreaOfGeometricShapes, Not_Equal_Test_Cube) {
    // Arrange
    double h = 15.9;
    Cube cube1(2.1, 4.5);
    Cube cube2(h);

    // Act & Assert
    EXPECT_TRUE(cube1 != cube2);
}
