// Copyright 2018 TolyaTalamanov

#include <gtest/gtest.h>
#include <stdexcept>
#include <string>
#include <vector>
#include "include/monom.h"
#include "include/polynom_calculator.hpp"

using ::testing::internal::RE;
using std::vector;
using std::string;

class PolynomCalculatorTest : public ::testing::Test {
 protected:
    void Act(vector<string> args_) {
        vector<const char*> options;

        options.push_back("appname");
        for (size_t i = 0; i < args_.size(); ++i) {
            options.push_back(args_[i].c_str());
        }

        const char** argv = &options.front();
        int argc = static_cast<int>(args_.size()) + 1;

        output_ = app_(argc, argv);
    }

    void Assert(std::string expected) {
        EXPECT_TRUE(RE::PartialMatch(output_, RE(expected)));
    }

 private:
    PolynomCalculator app_;
    string output_;
};

TEST_F(PolynomCalculatorTest, Do_Print_Help_Without_Arguments) {
    vector<string> args = {};

    Act(args);

    Assert("This is a polynom calculator application\\..*");
}

TEST_F(PolynomCalculatorTest, Check_Invalid_Size_Arguments) {
    vector<string> args = {"3x", "2y"};

    Act(args);

    Assert("ERROR: Invalid size arguments\\..*");
}

TEST_F(PolynomCalculatorTest, Check_Invalid_Operation) {
    vector<string> args = {"3x", "2y", "i", "4", "2"};

    Act(args);

    Assert("ERROR: Invalid operation\\..*");
}

TEST_F(PolynomCalculatorTest, Check_Invalid_Computation_Variables) {
    vector<string> args = {"2x", "3y", "+", "2"};

    Act(args);

    Assert("ERROR: Invalid size variables for computations\\..*");
}

TEST_F(PolynomCalculatorTest, Can_Add_Polynoms) {
    vector<string> args = {"2x", "3y", "+", "1", "2"};

    Act(args);

    Assert("8.00000");
}

TEST_F(PolynomCalculatorTest, Can_Diff_Polynoms) {
    vector<string> args = {"2x", "3y", "-", "1", "2"};

    Act(args);

    Assert("-4.00000");
}

TEST_F(PolynomCalculatorTest, Can_Mult_Polynoms) {
    vector<string> args = {"2x", "3y", "*", "1", "2"};

    Act(args);

    Assert("12.00000");
}

TEST_F(PolynomCalculatorTest, Add_When_One_Polynom_Without_Args) {
    vector<string> args = {"2", "3y", "+", "2"};

    Act(args);

    Assert("8.00000");
}

TEST_F(PolynomCalculatorTest, Polynoms_Without_Args) {
    vector<string> args = {"2", "3", "+"};

    Act(args);

    Assert("5.00000");
}
