// Copyright 2018 TolyaTalamanov

#include <gtest/gtest.h>
#include <stdexcept>
#include <string>
#include <vector>
#include "include/monom.h"
#include "include/polynom_calculator.hpp"

TEST(PolynomCalculator, Create_Calculator) {
    // AAA
    ASSERT_NO_THROW(PolynomCalculator pc);
}

TEST(PolynomCalculator, Calculate_With_Correct_Arguments) {
    // Arrange
    PolynomCalculator pc;
    std::vector<const char*> args = {"app_name", "3x", "5y", "+"};
    const char** argv = args.data();
    int argc = args.size() + 1;
    std::string res = Polynom("3x + 5y").ToString();

    // Act
    std::string out = pc(argc, argv);

    // Assert
    EXPECT_EQ(res, out);
}

TEST(PolynomCalculator, Substration_Polinom) {
    // Arrange
    PolynomCalculator pc;
    std::vector<const char*> args = {"app_name", "37xy", "5y", "-"};
    const char** argv = args.data();
    int argc = args.size() + 1;
    std::string res = Polynom("37xy - 5y").ToString();

    // Act
    std::string out = pc(argc, argv);

    // Assert
    EXPECT_EQ(res, out);
}

TEST(PolynomCalculator, InvaliArgumentsSize) {
    // Arrange
    PolynomCalculator pc;
    std::vector<const char*> args = {"app_name", "37xy", "5y", "6x", "*"};
    const char** argv = args.data();
    int argc = args.size() + 1;

    // Act & Assert
    EXPECT_THROW(pc(argc, argv), std::logic_error);
}

TEST(PolynomCalculator, InvalidOperation) {
    // Arrange
    PolynomCalculator pc;
    std::vector<const char*> args = {"app_name", "37xy", "5y", "!"};
    const char** argv = args.data();
    int argc = args.size() + 1;

    // Act & Assert
    EXPECT_THROW(pc(argc, argv), std::logic_error);
}
