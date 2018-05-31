// Copyright 2018 Generalov Aleksandr

#include <gtest/gtest.h>

#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>

#include "include/set_calculator.h"

using ::testing::internal::RE;
using std::vector;
using std::string;

class SetCalculatorTest : public ::testing::Test {
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
    SetCalculator app_;
    string output_;
};

TEST_F(SetCalculatorTest, Do_Print_Help_Without_Arguments) {
    vector<string> args = {};

    Act(args);

    Assert("Please provide arguments in the following format:*");
}

TEST_F(SetCalculatorTest, Test_Bad_Operation) {
    vector<string> args = { "2", "3", "4", "1", "5", "op" };

    Act(args);

    Assert("ERROR: Wrong operation!*");
}

TEST_F(SetCalculatorTest, Test_Wrong_Counts_Of_Args_Size1) {
    vector<string> args = { "3", "1", "2", "0", "Disj" };

    Act(args);

    Assert("ERROR: Wrong counts of args. Check size1*");
}

TEST_F(SetCalculatorTest, Test_Wrong_Counts_Of_Args_Size2) {
    vector<string> args = { "3", "1", "2", "5", "2", "7", "Disj" };

    Act(args);

    Assert("ERROR: Wrong counts of args. Check size2*");
}

TEST_F(SetCalculatorTest, Test_Wrong_Elements_Vector1) {
    vector<string> args = { "3", "1", "26", "5", "1", "7", "Conj" };

    Act(args);

    Assert("ERROR: Check the elements of the vector1*");
}

TEST_F(SetCalculatorTest, Test_Wrong_Elements_Vector2) {
    vector<string> args = { "3", "1", "2", "5", "2", "7", "91", "Conj" };

    Act(args);

    Assert("ERROR: Check the elements of the vector2*");
}

TEST_F(SetCalculatorTest, Test_Disjunction_Operation) {
    vector<string> args = { "0", "1", "7", "Disj" };

    Act(args);

    Assert("Result: 1 7*");
}

TEST_F(SetCalculatorTest, Test_Conjunction_Operation) {
    vector<string> args = { "2", "3", "5", "1", "5", "Conj" };

    Act(args);

    Assert("Result: 5*");
}
