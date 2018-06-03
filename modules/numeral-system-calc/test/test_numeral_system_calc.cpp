// Copyright 2018 Yermakov Alexey

#include <gtest/gtest.h>

#include <string>

#include "include/numeral_system_calc.h"

TEST(Numeral_System_Calculate, Parse_Number) {
    // Arrange
    std::string s("030");  // 24
    int answer = 24;

    // Act
    int res = Calc::calculate(s);

    // Assert
    EXPECT_EQ(answer, res);
}

TEST(Numeral_System_Calculate, Calculate_Binary) {
    // Arrange
    std::string s("1110011101001 + 101000001111");  // 7401 + 2575
    int answer = 9976;

    // Act
    int res = Calc::calculate(s);

    // Assert
    EXPECT_EQ(answer, res);
}

TEST(Numeral_System_Calculate, Calculate_Octal) {
    // Arrange
    std::string s("016351 + 05017");  // 7401 + 2575
    int answer = 9976;

    // Act
    int res = Calc::calculate(s);

    // Assert
    EXPECT_EQ(answer, res);
}

TEST(Numeral_System_Calculate, Calculate_Hexadecimal) {
    // Arrange
    std::string s("0x1CE9 + 0xA0F");  // 7401 + 2575
    int answer = 9976;

    // Act
    int res = Calc::calculate(s);

    // Assert
    EXPECT_EQ(answer, res);
}

TEST(Numeral_System_Calculate, Calculate_Different_Radices) {
    // Arrange
    std::string s("101 + 017 + 0xF");  // 5 + 15 + 15
    int answer = 35;

    // Act
    int res = Calc::calculate(s);

    // Assert
    EXPECT_EQ(answer, res);
}


TEST(Numeral_System_Calculate, Parse_Zero) {
    // Arrange
    std::string s("0 + 1 + 01 + 0 + 0xF + 0");  // 0 + 1 + 1 + 0 + 15 + 0
    int answer = 17;

    // Act
    int res = Calc::calculate(s);

    // Assert
    EXPECT_EQ(answer, res);
}

TEST(Numeral_System_Calculate, Different_Operators) {
    // Arrange
    std::string s("101 + 017 - 0xF * 10 / 05");  // 5 + 15 - 15*2 / 5
    int answer = 14;

    // Act
    int res = Calc::calculate(s);

    // Assert
    EXPECT_EQ(answer, res);
}

TEST(Numeral_System_Calculate, Parentheses) {
    // Arrange
    // 32 - (5 + 15 - 15) * 2 / 5
    std::string s("040 - (101 + 017 - 0xF) * 10 / 05");
    int answer = 30;

    // Act
    int res = Calc::calculate(s);

    // Assert
    EXPECT_EQ(answer, res);
}

TEST(Numeral_System_Calculate, Parentheses_Nested) {
    // Arrange
    // 32 - (5 + (15 - 15) * 2) / 5
    std::string s("040 - (101 + (017 - 0xF) * 10) / 05");
    int answer = 31;

    // Act
    int res = Calc::calculate(s);

    // Assert
    EXPECT_EQ(answer, res);
}

TEST(Numeral_System_Calculate, Invalid_Operator) {
    // Arrange
    std::string s("016351 + 05017 % 0x1");

    // Act & Assert
    EXPECT_THROW(Calc::calculate(s), int);
}

TEST(Numeral_System_Calculate, Division_By_Zero) {
    // Arrange
    std::string s("016351 + 05017 / 0x0");

    // Act & Assert
    EXPECT_THROW(Calc::calculate(s), int);
}
