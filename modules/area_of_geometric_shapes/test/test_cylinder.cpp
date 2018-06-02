// Copyright 2018 Levitsky Ilya

#include <gtest/gtest.h>

#include <string>

#include "include/Cylinder.h"

TEST(AreaOfGeometricShapes, Get_Radius_From_Cylinder) {
    // Arrange
    double radius = 2.5;
    double h = 5.3;
    Cylinder cylinder(radius, h);

    // Act & Assert
    EXPECT_EQ(radius, cylinder.getRad());
}

TEST(AreaOfGeometricShapes, Get_H_From_Cylinder) {
    // Arrange
    double radius = 7.1;
    double h = 15.9;
    Cylinder cylinder(radius, h);

    // Act & Assert
    EXPECT_EQ(h, cylinder.getH());
}

TEST(AreaOfGeometricShapes, Set_Radius_And_H_From_Cylinder) {
    // Arrange
    Cylinder cylinder;
    double radius = 3.8;
    double h = 7.4;

    // Act
    cylinder.setRad(radius);
    cylinder.setH(h);

    // Assert
    EXPECT_EQ(radius, cylinder.getRad());
    EXPECT_EQ(h, cylinder.getH());
}

TEST(AreaOfGeometricShapes, Comparison_Operator) {
    // Arrange
    double radius = 7.9;
    double h = 15.2;
    Cylinder cylinder1(3.1, 6.5);
    Cylinder cylinder2(radius, h);

    // Act
    cylinder1 = cylinder2;

    // Assert
    EXPECT_EQ(cylinder1.getRad(), cylinder2.getRad());
    EXPECT_EQ(cylinder1.getH(), cylinder2.getH());
}

TEST(AreaOfGeometricShapes, Negative_Rad_Cylinder) {
    // Arrange
    double radius = -7.1;
    double h = 15.9;

    // Act & Assert
    ASSERT_ANY_THROW(Cylinder cylinder(radius, h));
}

TEST(AreaOfGeometricShapes, Negative_H_Cylinder) {
    // Arrange
    double radius = 7.1;
    double h = -15.9;

    // Act & Assert
    ASSERT_ANY_THROW(Cylinder cylinder(radius, h));
}

TEST(AreaOfGeometricShapes, Area_Calculation_Cylinder) {
    // Arrange
    double res = 0;
    Cylinder cylinder(2, 3);

    // Act
    res = cylinder.areaCyl();

    // Assert
    EXPECT_EQ(res, 37.68);
}

TEST(AreaOfGeometricShapes, Copy_Cylinder) {
    // Arrange
    Cylinder cylinder1(2.1, 4.5);

    // Act
    Cylinder cylinder2(cylinder1);

    // Assert
    EXPECT_EQ(cylinder1.getRad(), cylinder2.getRad());
    EXPECT_EQ(cylinder1.getH(), cylinder2.getH());
}

TEST(AreaOfGeometricShapes, Equal_Test_Cylinder) {
    // Arrange
    double radius = 7.1;
    double h = 15.9;
    Cylinder cylinder1(radius, h);
    Cylinder cylinder2(cylinder1);

    // Act & Assert
    EXPECT_TRUE(cylinder1 == cylinder2);
}
TEST(AreaOfGeometricShapes, Not_Equal_Test_Cylinder) {
    // Arrange
    double radius = 7.1;
    double h = 15.9;
    Cylinder cylinder1(2.1, 4.5);
    Cylinder cylinder2(radius, h);

    // Act & Assert
    EXPECT_TRUE(cylinder1 != cylinder2);
}
