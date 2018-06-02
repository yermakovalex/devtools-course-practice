// Copyright 2018 Levitsky Ilya

#include <gtest/gtest.h>

#include <string>

#include "include/Sphere.h"

TEST(AreaOfGeometricShapes, Get_Radius_From_Sphere) {
    // Arrange
    double radius = 2.5;
    Sphere sphere(radius);

    // Act & Assert
    EXPECT_EQ(radius, sphere.getRad());
}

TEST(AreaOfGeometricShapes, Set_Radius_And_H_From_Sphere) {
    // Arrange
    Sphere sphere;
    double radius = 3.8;

    // Act
    sphere.setRad(radius);

    // Assert
    EXPECT_EQ(radius, sphere.getRad());
}

TEST(AreaOfGeometricShapes, Comparison_Operator) {
    // Arrange
    double radius = 7.9;
    Sphere sphere1(3.1);
    Sphere sphere2(radius);

    // Act
    sphere1 = sphere2;

    // Assert
    EXPECT_EQ(sphere1.getRad(), sphere2.getRad());
}

TEST(AreaOfGeometricShapes, Negative_Rad_Sphere) {
    // Arrange
    double radius = -7.1;

    // Act & Assert
    ASSERT_ANY_THROW(Sphere sphere(radius));
}

TEST(AreaOfGeometricShapes, Negative_H_Sphere) {
    // Arrange
    double radius = 7.1;

    // Act & Assert
    ASSERT_ANY_THROW(Sphere sphere(radius));
}

TEST(AreaOfGeometricShapes, Area_Calculation_Sphere) {
    // Arrange
    double res = 0;
    Sphere sphere(2);

    // Act
    res = sphere.areaSph();

    // Assert
    EXPECT_EQ(res, 50.24);
}

TEST(AreaOfGeometricShapes, Copy_Sphere) {
    // Arrange
    Sphere sphere1(4.5);

    // Act
    Sphere sphere2(sphere1);

    // Assert
    EXPECT_EQ(sphere1.getRad(), sphere2.getRad());
}

TEST(AreaOfGeometricShapes, Equal_Test_Sphere) {
    // Arrange
    double radius = 7.1;
    Sphere sphere1(radius);
    Sphere sphere2(sphere1);

    // Act & Assert
    EXPECT_TRUE(sphere1 == sphere2);
}
TEST(AreaOfGeometricShapes, Not_Equal_Test_Sphere) {
    // Arrange
    double radius = 7.1;
    Sphere sphere1(2.1);
    Sphere sphere2(radius);

    // Act & Assert
    EXPECT_TRUE(sphere1 != sphere2);
}
