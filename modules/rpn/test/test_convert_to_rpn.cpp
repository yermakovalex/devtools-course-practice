// Copyright 2018 Shkenev Petr

#include <gtest/gtest.h>

#include <string>

#include "include/rpn.h"

TEST(Convert_to_RPN, Can_Parse_Number) {
    // Arrange
    std::string s("12");
    std::string answer("12");

    // Act
    std::string res = rpn::convertToRpn(s);

    // Assert
    EXPECT_EQ(res, answer);
}

TEST(Convert_to_RPN, One_Operator) {
    // Arrange
    std::string s("1 + 2");
    std::string answer("1 2 +");

    // Act
    std::string res = rpn::convertToRpn(s);

    // Assert
    EXPECT_EQ(res, "1 2 +");
}

TEST(Convert_to_RPN, String_Without_Spaces) {
    // Arrange
    std::string s("1+2");
    std::string answer("1 2 +");

    // Act
    std::string res = rpn::convertToRpn(s);

    // Assert
    EXPECT_EQ(res, answer);
}

TEST(Convert_to_RPN, Serial_Calculations) {
    // Arrange
    std::string s("1 + 2 + 3");
    std::string answer("1 2 + 3 +");

    // Act
    std::string res = rpn::convertToRpn(s);

    // Assert
    EXPECT_EQ(res, answer);
}

TEST(Convert_to_RPN, Different_Priorities) {
    // Arrange
    std::string s("4 + 5 * 3 ^ 2");
    std::string answer("4 5 3 2 ^ * +");

    // Act
    std::string res = rpn::convertToRpn(s);

    // Assert
    EXPECT_EQ(res, answer);
}

TEST(Convert_to_RPN, Different_Priorities_2) {
    // Arrange
    std::string s("4 - 5 ^ 3 / 10");
    std::string answer("4 5 3 ^ 10 / -");

    // Act
    std::string res = rpn::convertToRpn(s);

    // Assert
    EXPECT_EQ(res, answer);
}

TEST(Convert_to_RPN, Parentheses) {
    // Arrange
    std::string s("4 * (1 + 2)");
    std::string answer("4 1 2 + *");

    // Act
    std::string res = rpn::convertToRpn(s);

    // Assert
    EXPECT_EQ(res, answer);
}

TEST(Convert_to_RPN, Parentheses_2) {
    // Arrange
    std::string s("2 / (1 - 3)^2");
    std::string answer("2 1 3 - 2 ^ /");

    // Act
    std::string res = rpn::convertToRpn(s);

    // Assert
    EXPECT_EQ(res, answer);
}

TEST(Convert_to_RPN, Parentheses_3) {
    // Arrange
    std::string s("2 ^ (1 - 3)*2");
    std::string answer("2 1 3 - ^ 2 *");

    // Act
    std::string res = rpn::convertToRpn(s);

    // Assert
    EXPECT_EQ(res, answer);
}

TEST(Convert_to_RPN, Parentheses_Nested) {
    // Arrange
    std::string s("4 * (2 + (5 - 3))");
    std::string answer("4 2 5 3 - + *");

    // Act
    std::string res = rpn::convertToRpn(s);

    // Assert
    EXPECT_EQ(res, answer);
}

TEST(Convert_to_RPN, Parentheses_Error) {
    // Arrange
    std::string s("2 * (3 + 4))");

    // Act & Assert
    EXPECT_THROW(rpn::convertToRpn(s), int);  // throws POP_EMPTY_STACK
}

TEST(Convert_to_RPN, Throw_On_Invalid_Symbols) {
    // Arrange
    std::string s("2 + ?3");

    // Act & Assert
    EXPECT_THROW(rpn::convertToRpn(s), int);  // throws POP_EMPTY_STACK
}
