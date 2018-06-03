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

TEST_F(NumericalIntervalCalculatorTest,
       Can_Detect_Wrong_Arguments_Format_Case1) {
    vector<string> args = { "[1,2]", "1" };

    Act(args);

    Assert("ERROR: Wrong arguments format!.*");
}

TEST_F(NumericalIntervalCalculatorTest,
       Can_Detect_Wrong_Arguments_Format_Case2) {
    vector<string> args = { "[1,2]", "[3,4]", "trash" };

    Act(args);

    Assert("ERROR: Wrong arguments format!.*");
}

TEST_F(NumericalIntervalCalculatorTest,
       Can_Detect_Contain_Points_Without_Points) {
    vector<string> args = { "[-1,5)", "pc" };

    Act(args);

    Assert("ERROR: You dont enter numbers!.*");
}

TEST_F(NumericalIntervalCalculatorTest,
    Can_Detect_Too_Much_Arguments) {
    vector<string> args = { "[-1,5]", "[2,3]", "or", "trash" };

    Act(args);

    Assert("ERROR: Too much arguments!.*");
}

TEST_F(NumericalIntervalCalculatorTest, Can_Detect_Wrong_Interval_From_Trash) {
    vector<string> args = { "trash" };

    Act(args);

    Assert("Wrong interval!");
}

TEST_F(NumericalIntervalCalculatorTest, Can_Detect_Wrong_Interval_Case1) {
    vector<string> args = { "[1,-1158]" };

    Act(args);

    Assert("Wrong interval!");
}

TEST_F(NumericalIntervalCalculatorTest, Can_Detect_Wrong_Interval_Case2) {
    vector<string> args = { "[1,1)" };

    Act(args);

    Assert("Wrong interval!");
}

TEST_F(NumericalIntervalCalculatorTest, Can_Detect_Wrong_Interval_Case3) {
    vector<string> args = { "(1,2)" };

    Act(args);

    Assert("Wrong interval!");
}

TEST_F(NumericalIntervalCalculatorTest, Can_Get_End_Points) {
    vector<string> args = { "[-3,5)", "ep" };

    Act(args);

    Assert("-3 4.*");
}

TEST_F(NumericalIntervalCalculatorTest, Can_Get_All_Points) {
    vector<string> args = { "[-1,3)", "ap" };

    Act(args);

    Assert("-1 0 1 2.*");
}

TEST_F(NumericalIntervalCalculatorTest, Can_Checks_Entry_Points) {
    vector<string> args = { "[-1,8]", "pc", "-1", "0", "3", "8" };

    Act(args);

    Assert("Contained points.*");
}

TEST_F(NumericalIntervalCalculatorTest, Can_Checks_No_Entry_Points) {
    vector<string> args = { "[-3,4)", "pc", "-3", "0", "4" };

    Act(args);

    Assert("Not contained points.*");
}

TEST_F(NumericalIntervalCalculatorTest, Can_Checks_Ranges_For_Overlapse) {
    vector<string> args = { "[-1,8]", "(7,9]", "ro" };

    Act(args);

    Assert("Ranges overlapsed.*");
}

TEST_F(NumericalIntervalCalculatorTest, Can_Checks_Ranges_For_No_Overlapse) {
    vector<string> args = { "[-1,8)", "(7,9]", "ro" };

    Act(args);

    Assert("Ranges not overlapsed.*");
}

TEST_F(NumericalIntervalCalculatorTest, Can_Checks_Ranges_For_Entry) {
    vector<string> args = { "[-1,8]", "(7,8]", "rc" };

    Act(args);

    Assert("Contained range.*");
}

TEST_F(NumericalIntervalCalculatorTest, Can_Checks_Ranges_For_No_Entry) {
    vector<string> args = { "[-1,8]", "(7,9]", "rc" };

    Act(args);

    Assert("Not contained range.*");
}

TEST_F(NumericalIntervalCalculatorTest, Can_Detect_No_Operation_With_4_Args) {
    vector<string> args = { "[-1,8]", "[3,11]", "trash" };

    Act(args);

    Assert("ERROR: Wrong arguments format!.*");
}
