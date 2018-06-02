// Copyright 2018 Romanov Alexander

#include <gtest/gtest.h>

#include <algorithm>
#include <functional>
#include <iterator>
#include <string>
#include <vector>

#include "include/quad_eq_copy.h"
#include "include/quad_eq_copy_calc.h"

using ::testing::internal::RE;
using std::vector;
using std::string;

class QuadEqTest: public ::testing::Test {
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
    void AssertFull(std::string expected) {
        EXPECT_TRUE(RE::FullMatch(output_, RE(expected)));
    }

 private:
    QuadEquatCalc app_;
    string output_;
};

TEST_F(QuadEqTest, Able_Print_Help_No_Arguments) {
    // Arrange
    vector<string> args = {};

    Act(args);

    Assert("This is a quadratic equation calculator");
}

TEST_F(QuadEqTest, Able_Check_Number_Arguments) {
    // Arrange
    vector<string> args = { "1", "2", "3", "4"};

    Act(args);

    Assert("ERROR: Should be 3 arguments*");
}

TEST_F(QuadEqTest, Able_Check_Type) {
    // Arrange
    vector<string> args = { "smth", "2", "4" };

    Act(args);

    Assert("Wrong number format!");
}

TEST_F(QuadEqTest, Able_Get_Correct_Roots1) {
    // Arrange
    vector<string> args = { "1", "-2", "3" };

    Act(args);

    // Assert
    AssertFull("Result: There are no real roots ");
}

TEST_F(QuadEqTest, Able_Get_Correct_Roots2) {
    // Arrange
    vector<string> args = { "1", "2", "1" };

    Act(args);

    // Assert
    AssertFull("Result: There is one real root: -1");
}

TEST_F(QuadEqTest, Able_Get_Correct_Roots3) {
    // Arrange
    vector<string> args = { "1", "-6", "5" };

    Act(args);

    // Assert
    AssertFull("Result: There are two real roots: 1 5");
}
