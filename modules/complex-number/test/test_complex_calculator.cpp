// Copyright 2017 Korniakov Kirill

#include <gtest/gtest.h>

#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>

#include "include/complex_calculator.h"

using ::testing::internal::RE;
using std::vector;
using std::string;

class ComplexCalculatorTest : public ::testing::Test {
 protected:
    // virtual void SetUp() {}

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
    ComplexCalculator app_;
    string output_;
};

TEST_F(ComplexCalculatorTest, Do_Print_Help_Without_Arguments) {
    vector<string> args = {};

    Act(args);

    Assert("This is a complex number calculator application\\..*");
}

TEST_F(ComplexCalculatorTest, Is_Checking_Number_Of_Arguments) {
    vector<string> args = {"1", "2"};

    Act(args);

    Assert("ERROR: Should be 5 arguments\\..*");
}

TEST_F(ComplexCalculatorTest, Can_Detect_Wrong_Number_Format) {
    vector<string> args = {"1", "pi", "2", "4", "+"};

    Act(args);

    Assert("Wrong number format!.*");
}

TEST_F(ComplexCalculatorTest, Can_Detect_Wrong_Operation_Format) {
    vector<string> args = {"1", "1", "1", "1", "garbage"};

    Act(args);

    Assert("Wrong operation format!");
}

TEST_F(ComplexCalculatorTest, Can_Add_Complexs) {
    vector<string> args = {"2.0", "3.5", "1.5", "4.0", "+"};

    Act(args);

    Assert("Real = 3.5 Imaginary = 7.5");
}

TEST_F(ComplexCalculatorTest, Can_Diff_Complexs) {
    vector<string> args = {"13", "7.6", "26", "-14", "-"};

    Act(args);

    Assert("Real = -13 Imaginary = 21.6");
}

TEST_F(ComplexCalculatorTest, Can_Mult_Complexs) {
    vector<string> args = {"0", "-3.6", "17.4", "21", "*"};

    Act(args);

    Assert("Real = 75.6 Imaginary = -62.64");
}

TEST_F(ComplexCalculatorTest, Can_Divide_Complexs) {
    vector<string> args = {"27", "30", "15", "20", "/"};

    Act(args);

    Assert("Real = 1.608 Imaginary = -0.144");
}

TEST_F(ComplexCalculatorTest, Can_Detect_Divide_By_Zero) {
    vector<string> args = {"27", "30", "0", "0", "/"};

    Act(args);

    Assert("Can't divide by zero");
}
