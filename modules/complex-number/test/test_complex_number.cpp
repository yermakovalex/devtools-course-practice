// Copyright 2017 Korniakov Kirill

#include <gtest/gtest.h>

#include <string>

#include "include/complex_number.h"

class ComplexNumberTest : public ::testing::Test {
 protected:
    double epsilon = 0.001;
};

TEST_F(ComplexNumberTest, Can_Create_With_Real_And_Imaginary) {
    // Arrange
    double re = 26.0;
    double im = 20.0;

    // Act
    ComplexNumber z(re, im);

    // Assert
    EXPECT_NEAR(re, z.getRe(), ComplexNumberTest::epsilon);
    EXPECT_NEAR(im, z.getIm(), ComplexNumberTest::epsilon);
}

TEST_F(ComplexNumberTest, Can_Create_Via_Copying) {
    // Arrange
    ComplexNumber z(26.0, 20.0);

    // Act
    ComplexNumber expected_z = z;

    // Assert
    EXPECT_EQ(expected_z, z);
}

TEST_F(ComplexNumberTest, Can_Set_Real) {
    // Arrange
    ComplexNumber z;
    double re = 20.0;

    // Act
    z.setRe(re);

    // Assert
    EXPECT_NEAR(re, z.getRe(), ComplexNumberTest::epsilon);
}

TEST_F(ComplexNumberTest, Can_Set_Imaginary) {
    // Arrange
    ComplexNumber z;
    double im = 26.0;

    // Act
    z.setIm(im);

    // Assert
    EXPECT_NEAR(im, z.getIm(), ComplexNumberTest::epsilon);
}

TEST_F(ComplexNumberTest, Can_Add_Complex) {
    // Arrange
    ComplexNumber z1(26.0, 14.0);
    ComplexNumber z2(1.0, 7.0);

    // Act
    ComplexNumber z = z1 + z2;

    // Assert
    ComplexNumber expected_z(27.0, 21.0);
    EXPECT_EQ(expected_z, z);
}

TEST_F(ComplexNumberTest, Can_Difference_Complex) {
    // Arrange
    ComplexNumber z1(26.0, 14.0);
    ComplexNumber z2(1.0, 1.0);

    // Act
    ComplexNumber z = z2 - z1;

    // Assert
    ComplexNumber expected_z(-25.0, -13.0);
    EXPECT_EQ(expected_z, z);
}

TEST_F(ComplexNumberTest, Can_Multiplication_Complex) {
    // Arrange
    ComplexNumber z1(5.0, 3.0);
    ComplexNumber z2(4.0, 6.0);

    // Act
    ComplexNumber z = z1 * z2;

    // Assert
    ComplexNumber expected_z(2.0, 42.0);
    EXPECT_EQ(expected_z, z);
}

TEST_F(ComplexNumberTest, Can_Division_Complex) {
    // Arrange
    ComplexNumber z1(15.0, 20.0);
    ComplexNumber z2(27.0, 30.0);

    // Act
    ComplexNumber z = z2 / z1;

    // Assert
    ComplexNumber expected_z(1.608, -0.144);
    EXPECT_EQ(expected_z, z);
}

TEST_F(ComplexNumberTest, Do_Throw_When_Division_By_Zero) {
    // Arrange
    ComplexNumber z1(0.0, 0.0);
    ComplexNumber z2(26.0, 14.0);

    // Act & Assert
    EXPECT_THROW(z2 / z1, std::string);
}

TEST_F(ComplexNumberTest, Number_Is_Equal_To_Itself) {
    // Arrange
    ComplexNumber z(26.0, 14.0);

    // Act & Assert
    EXPECT_TRUE(z == z);
}

TEST_F(ComplexNumberTest, Equal_Numbers_Are_Equal) {
    // Arrange
    ComplexNumber z1(26.0, 14.0);
    ComplexNumber z2(26.0, 14.0);

    // Act & Assert
    EXPECT_EQ(z1, z2);
}

TEST_F(ComplexNumberTest, Different_Numbers_Not_Equal) {
    // Arrange
    ComplexNumber z1(26.0, 14.0);
    ComplexNumber z2(26.1, 14.1);

    // Act & Assert
    EXPECT_TRUE(z1 != z2);
}
