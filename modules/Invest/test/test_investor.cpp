// Copyright 2018 Chernenko_Valery

#include <gtest/gtest.h>

#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>

#include "include/Investor.h"

using ::testing::internal::RE;
using std::vector;
using std::string;

class InvestorTest : public ::testing::Test {
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
    Investor app_;
    string output_;
};

TEST_F(InvestorTest, Do_Print_Help_Without_Arguments) {
    vector<string> args = {};

    Act(args);

    Assert("This is a Investor application\\..*");
}

TEST_F(InvestorTest, Is_Checking_Number_Of_Arguments) {
    vector<string> args = {"1", "2"};

    Act(args);

    Assert("Wrong Parameters!*");
}

TEST_F(InvestorTest, can_Detect_Wrong_Number_Format) {
    vector<string> args = {"1", "p", "2.0", "2", "NPV"};

    Act(args);

    Assert("Wrong number format!.*");
}

TEST_F(InvestorTest, can_Detect_Wrong_Function_Format) {
    vector<string> args = {"1", "2", "2", "2", "pi"};

    Act(args);

    Assert("Wrong Operation!.*");
}

TEST_F(InvestorTest, can_Find_Npv) {
    vector<string> args = {"2", "5", "4", "3", "2.0" , "1" , "NPV"};

    Act(args);

    Assert("NPV = 3.9802");
}

TEST_F(InvestorTest, can_Find_Npv_with_parameter) {
    vector<string> args = {"2", "5", "4", "3", "2.0", "1", "NPV", "2"};

    Act(args);

    Assert("NPV = 3.96078");
}

TEST_F(InvestorTest, can_Find_Irr) {
    vector<string> args = {"2", "5", "4", "3", "2.0" , "1" , "IRR"};

    Act(args);

    Assert("IRR = -2");
}

TEST_F(InvestorTest, can_Find_Recoupment_Time) {
    vector<string> args =
            {"2", "5", "4", "3", "2.0" , "1" , "RecoupmentTime"};

    Act(args);

    Assert("RecoupmentTime = 0");
}

TEST_F(InvestorTest, can_Find_Pbindex) {
    vector<string> args = {"2", "5", "4", "3", "0" , "1" , "PBIndex"};

    Act(args);

    Assert("PBIndex = 2.00667");
}

