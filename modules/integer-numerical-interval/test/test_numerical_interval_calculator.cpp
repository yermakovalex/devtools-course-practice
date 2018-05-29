// Copyright 2018 Gribov Pavel

#include <gtest/gtest.h>

#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>

#include "include/numerical_interval_calculator.h"

using ::testing::internal::RE;
using std::vector;
using std::string;

class NumericalIntervalCalculatorTest : public ::testing::Test {
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
    NumericalIntervalCalculator app_;
    string output_;
};

TEST_F(NumericalIntervalCalculatorTest, Do_Print_Help_Without_Arguments) {
    vector<string> args = {};

    Act(args);

    Assert("This is a integer numerical interval calculator application\\..*");
}

TEST_F(NumericalIntervalCalculatorTest, Is_Checking_Number_Of_Arguments) {
    vector<string> args = { "1", "2" };

    Act(args);

    Assert("ERROR: Should be 5 arguments\\..*");
}

TEST_F(NumericalIntervalCalculatorTest, Can_Detect_Wrong_Arguments_Format) {
    vector<string> args = { "1", "pi", "2", "4", "+" };

    Act(args);

    Assert("ERROR: Wrong arguments format!.*");
}

TEST_F(NumericalIntervalCalculatorTest, Can_Detect_Wrong_Interval) {
    vector<string> args = { "[", "3", ",", "3", ")" };

    Act(args);

    Assert("Wrong interval!");
}