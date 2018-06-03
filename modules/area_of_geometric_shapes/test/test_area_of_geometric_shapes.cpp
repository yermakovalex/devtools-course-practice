// Copyright 2018 Generalov Aleksandr

#include <gtest/gtest.h>

#include <string>

#include "include/Cone.h"
#include "include/Cube.h"
#include "include/Cylinder.h"
#include "include/Sphere.h"

TEST(AreaOfGeometricShapes, Get_Radius_From_Cone) {
    // Arrange
    double radius = 2.5;
    double h = 5.3;
    Cone cone(radius, h);

    // Act & Assert
    EXPECT_EQ(radius, cone.getRad());
}

TEST(AreaOfGeometricShapes, Get_H_From_Cone) {
    // Arrange
    double radius = 7.1;
    double h = 15.9;
    Cone cone(radius, h);

    // Act & Assert
    EXPECT_EQ(h, cone.getH());
}

TEST(AreaOfGeometricShapes, Set_Radius_And_H_From_Cone) {
    // Arrange
    Cone cone;
    double radius = 3.8;
    double h = 7.4;

    // Act
    cone.setRad(radius);
    cone.setH(h);

    // Assert
    EXPECT_EQ(radius, cone.getRad());
    EXPECT_EQ(h, cone.getH());
}

TEST(AreaOfGeometricShapes, Comparison_Operator) {
    // Arrange
    double radius = 7.9;
    double h = 15.2;
    Cone cone1(3.1, 6.5);
    Cone cone2(radius, h);

    // Act
    cone1 = cone2;

    // Assert
    EXPECT_EQ(cone1.getRad(), cone2.getRad());
    EXPECT_EQ(cone1.getH(), cone2.getH());
}

TEST(AreaOfGeometricShapes, Negative_Rad_Cone) {
    // Arrange
    double radius = -7.1;
    double h = 15.9;

    // Act & Assert
    ASSERT_ANY_THROW(Cone cone(radius, h));
}

TEST(AreaOfGeometricShapes, Negative_H_Cone) {
    // Arrange
    double radius = 7.1;
    double h = -15.9;

    // Act & Assert
    ASSERT_ANY_THROW(Cone cone(radius, h));
}

TEST(AreaOfGeometricShapes, Area_Calculation_Cone) {
    // Arrange
    double res = 0;
    Cone cone(2.1, 4.5);

    // Act
    res = cone.areaCone();

    // Assert
    EXPECT_NEAR(res, 43.5204, 0.0001);
}

TEST(AreaOfGeometricShapes, Copy_Cone) {
    // Arrange
    Cone cone1(2.1, 4.5);

    // Act
    Cone cone2(cone1);

    // Assert
    EXPECT_EQ(cone1.getRad(), cone2.getRad());
    EXPECT_EQ(cone1.getH(), cone2.getH());
}

TEST(AreaOfGeometricShapes, Equal_Test_Cone) {
    // Arrange
    double radius = 7.1;
    double h = 15.9;
    Cone cone1(radius, h);
    Cone cone2(cone1);

    // Act & Assert
    EXPECT_TRUE(cone1 == cone2);
}
TEST(AreaOfGeometricShapes, Not_Equal_Test_Cone) {
    // Arrange
    double radius = 7.1;
    double h = 15.9;
    Cone cone1(2.1, 4.5);
    Cone cone2(radius, h);

    // Act & Assert
    EXPECT_TRUE(cone1 != cone2);
}
