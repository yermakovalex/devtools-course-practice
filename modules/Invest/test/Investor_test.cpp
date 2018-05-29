// Copyright 2018 Chernenko_Valery
include <gtest/gtest.h>

#include <string>
#include <vector>

#include "include/Investor.h"

using ::testing::internal::RE;
using std::vector;
using std::string;

class InvestorAppTest : public ::testing::Test {
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
    Investor app_;
    string output_;
};

TEST_F(QuickSortAppTest, can_Print_Help_Without_Arguments) {
    vector<string> args = {};

    Act(args);

    Assert("This is a Investor application\\..*");
}

TEST_F(QuickSortAppTest, can_Check_Number_Of_Arguments) {
    vector<string> args = {"1", "2"};

    Act(args);

    Assert("Wrong Parametrs!\\..*");
}

TEST_F(QuickSortAppTest, can_Detect_Wrong_Number_Format) {
    vector<string> args = {"1", "p", "2.0", "2", "FindNPV"};

    Act(args);

    Assert("Wrong number format!.*");
}

TEST_F(QuickSortAppTest, can_Detect_Wrong_Function_Format) {
    vector<string> args = {"1", "2", "2", "2", "pi"};

    Act(args);

    Assert(""Wrong Operation!.*");
}

TEST_F(QuickSortAppTest, can_FindNPV) {
    vector<string> args = {"2", "5", "4", "3", "2.0" , "1" , "FindNPV"};

    Act(args);

    Assert("NPV = 3.9802");
}

TEST_F(QuickSortAppTest, can_FindNPV_with_parameter) {
    vector<string> args = {"2", "5", "4", "3", "2.0" , "1" , "FindNPV", "2"};

    Act(args);

    Assert("NPV = 3.96078");
}

TEST_F(QuickSortAppTest, can_FindIRR) {
    vector<string> args = {"2", "5", "4", "3", "2.0" , "1" , "FindIRR"};

    Act(args);

    Assert("IRR = -2");
}

TEST_F(QuickSortAppTest, can_FindRecoupmentTime) {
    vector<string> args = {"2", "5", "4", "3", "2.0" , "1" , "FindRecoupmentTime"};

    Act(args);

    Assert("RecoupmentTime = 0");
}

TEST_F(QuickSortAppTest, can_FindPBIndex) {
    vector<string> args = {"2", "5", "4", "3", "2.0" , "1" , "FindPBIndex"};

    Act(args);

    Assert("PBIndex = 2.00667");
}

