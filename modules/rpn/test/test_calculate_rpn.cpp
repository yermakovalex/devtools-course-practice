// Copyright 2018 Shkenev Petr

#include <gtest/gtest.h>

#include <string>

#include "include/rpn.h"

TEST(Calculate_RPN, Can_Parse_Number) {
    // Arrange
    std::string s("12");

    // Act
    int res = rpn::calculateRpn(s);

    // Assert
    EXPECT_EQ(res, 12);
}

TEST(Calculate_RPN, Can_Add) {
    // Arrange
    std::string s("5 8 +");

    // Act
    int res = rpn::calculateRpn(s);

    // Assert
    EXPECT_EQ(res, 13);
}

TEST(Calculate_RPN, Can_Substract) {
    // Arrange
    std::string s("5 8 -");

    // Act
    int res = rpn::calculateRpn(s);

    // Assert
    EXPECT_EQ(res, -3);
}

TEST(Calculate_RPN, Can_Multiply) {
    // Arrange
    std::string s("3 4 *");

    // Act
    int res = rpn::calculateRpn(s);

    // Assert
    EXPECT_EQ(res, 12);
}

TEST(Calculate_RPN, Can_Divide) {
    // Arrange
    std::string s("12 5 /");

    // Act
    int res = rpn::calculateRpn(s);

    // Assert
    EXPECT_EQ(res, 2);
}

TEST(Calculate_RPN, Exception_on_Division_by_Zero) {
    // Arrange
    std::string s("12 0 /");

    // Act & Assert
    EXPECT_THROW(rpn::calculateRpn(s), int);  // throws DIVISION_BY_ZERO
}

TEST(Calculate_RPN, Can_Exponent) {
    // Arrange
    std::string s("2 3 ^");

    // Act
    int res = rpn::calculateRpn(s);

    // Assert
    EXPECT_EQ(res, 8);
}

TEST(Calculate_RPN, Exponent_Undefined) {
    // Arrange
    std::string s("0 0 ^");

    // Act & Assert
    EXPECT_THROW(rpn::calculateRpn(s), int);  // throws UNDEFINED_OPERATION
}

TEST(Calculate_RPN, Exponent_Base_Zero_Negative) {
    // Arrange
    std::string s("0 0 1 - ^");  // 0 ^ (0 - 1)

    // Act & Assert
    EXPECT_THROW(rpn::calculateRpn(s), int);  // throws DIVISION_BY_ZERO
}

TEST(Calculate_RPN, Exponent_Base_One_Negative) {
    // Arrange
    std::string s("1 0 1 - ^");  // 1 ^ (0 - 1)

    // Act
    int res = rpn::calculateRpn(s);

    // Assert
    EXPECT_EQ(res, 1);
}

TEST(Calculate_RPN, Exponent_Negative) {
    // Arrange
    std::string s("2 0 1 - ^");  // 2 ^ (0 - 1)

    // Act
    int res = rpn::calculateRpn(s);  // 1/2 = 0

    // Assert
    EXPECT_EQ(res, 0);
}

TEST(Calculate_RPN, Throw_On_Invalid_Symbols) {
    // Arrange
    std::string s("2 3 f +");

    // Assert
    EXPECT_THROW(rpn::calculateRpn(s), int);
}

TEST(Calculate_RPN, Skip_Multiple_Spaces) {
    // Arrange
    std::string s("  2    3  + ");

    // Act
    int res = rpn::calculateRpn(s);

    // Assert
    EXPECT_EQ(res, 5);
}

TEST(Calculate_RPN, Serial_Calculations) {
    // Arrange
    std::string s("1 2 + 4 * 3 +");  // (1 + 2) * 4 + 3

    // Act
    int res = rpn::calculateRpn(s);

    // Assert
    EXPECT_EQ(res, 15);
}

TEST(Calculate_RPN, Serial_Calculations_2) {
    // Arrange
    std::string s("4 6 2 * 1 3 - 2 ^ / +");  // 4 + 6 * 2 / (1 - 3)^2

    // Act
    int res = rpn::calculateRpn(s);

    // Assert
    EXPECT_EQ(res, 7);
}
