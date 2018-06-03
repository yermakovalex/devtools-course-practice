// Copyright 2018 Kiselev Denis

#include <gtest/gtest.h>

#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>

#include "include/bits_calculator.h"

using ::testing::internal::RE;
using std::vector;
using std::string;

class BitsCalculatorTest : public ::testing::Test {
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
    BitsCalculator app_;
    string output_;
};

TEST_F(BitsCalculatorTest, Do_Print_Help_Without_Arguments) {
    vector<string> args = {};

    Act(args);

    Assert("This is a bits calculator application\\..*");
}

TEST_F(BitsCalculatorTest, Is_Checking_Number_Of_Arguments) {
    vector<string> args = {"1", "2"};

    Act(args);

    Assert("ERROR: Should be 3 arguments\\..*");
}

TEST_F(BitsCalculatorTest, Can_Detect_Wrong_Bits_Format) {
    vector<string> args = {"0100", "0112", "&"};

    Act(args);

    Assert("Wrong bits format!");
}

TEST_F(BitsCalculatorTest, Can_Detect_Wrong_Operation_Format) {
    vector<string> args = {"0100", "0110", "+"};

    Act(args);

    Assert("Wrong operation format!");
}

TEST_F(BitsCalculatorTest, Can_Detect_Wrong_Operation_Format2) {
    vector<string> args = {"0100", "0110", "or"};

    Act(args);

    Assert("Wrong operation format!");
}

TEST_F(BitsCalculatorTest, And_Operation_Is_Correct) {
    vector<string> args = {"01001", "0110", "&"};

    Act(args);

    Assert("Result: 01000");
}

TEST_F(BitsCalculatorTest, Or_Operation_Is_Correct) {
    vector<string> args = {"01001", "0110", "|"};

    Act(args);

    Assert("Result: 01101");
}

TEST_F(BitsCalculatorTest, Xor_Operation_Is_Correct) {
    vector<string> args = {"0101", "0011", "^"};

    Act(args);

    Assert("Result: 0110");
}
