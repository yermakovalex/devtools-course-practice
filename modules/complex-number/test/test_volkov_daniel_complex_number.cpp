// Copyright 2018 Volkov Daniel
#include <gtest/gtest.h>
#include "include/complex_number.h"
TEST(Volkov_Daniel_ComplexNumberTest, assign_plus_equal) {
  // Arrange
  double re = 42.151;
  double im = 1.21;
  double re2 = 53.151;
  double im2 = 12.51;
  // Act
  ComplexNumber num1(re, im);
  ComplexNumber num2(re, im2);
  ComplexNumber num3(re2, im);
  // Assert
  EXPECT_NO_THROW(num1 = num2 = (num2+num3));
  EXPECT_EQ(num1, num2);
}
TEST(Volkov_Daniel_ComplexNumberTest, additivity_of_plus_minus) {
  // Arrange
  double re = 42;
  double im = 1;
  double re2 = 53;
  double im2 = 12;
  ComplexNumber num1(re, im);
  ComplexNumber num2(re, im2);
  ComplexNumber num3(re2, im);
  // Act
  ComplexNumber res1 = (num1 + num2) - num3;
  ComplexNumber res2 = num1 + (num2 - num3);
  // Assert
  EXPECT_EQ(res1, res2);
}
TEST(Volkov_Daniel_ComplexNumberTest, triple_multiplication_commutativity) {
  // Arrange
  double re = 42;
  double im = 1;
  double re2 = 53;
  double im2 = 12;
  ComplexNumber num1(re, im);
  ComplexNumber num2(re, im2);
  ComplexNumber num3(re2, im);
  // Act
  ComplexNumber res1 = num1 * num2 * num3;
  ComplexNumber res2 = num3 * num1 * num2;
  // Assert
  EXPECT_EQ(res1, res2);
}
TEST(Volkov_Daniel_ComplexNumberTest, division_equal_is_equal_one) {
  // Arrange
  double re = 42.151;
  double im = 1.21;
  double re2 = 1.0;
  double im2 = 0.0;
  ComplexNumber num1(re, im);
  ComplexNumber num2(re, im);
  ComplexNumber num3(re2, im2);
  // Act
  ComplexNumber res = num1 / num2;
  // Assert
  EXPECT_EQ(res, num3);
}
TEST(Volkov_Daniel_ComplexNumberTest, check_addition_by_fields) {
  // Arrange
  double re = -3.415;
  double im = 8.13;
  double re2 = 87.1;
  double im2 = 1.31;
  ComplexNumber num1(re, im);
  ComplexNumber num2(re2, im2);
  ComplexNumber num3;
  // Act
  num3 = num1 + num2;
  // Assert
  EXPECT_EQ(re + re2, num3.getRe());
  EXPECT_EQ(im + im2, num3.getIm());
}
