// Copyright 2018 Sharov Ivan

#include <gtest/gtest.h>

#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>

#include "include/debt_service_app.h"

using ::testing::internal::RE;
using std::vector;
using std::string;

class DebtServiceCalculatorTest : public ::testing::Test {
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
    DebtServiceCalculator app_;
    string output_;
};

TEST_F(DebtServiceCalculatorTest, Do_Print_Help_Without_Arguments) {
    vector<string> args = {};

    Act(args);

    Assert("This is a debtservice calculator application\\..*");
}

TEST_F(DebtServiceCalculatorTest, Is_Checking_Number_Of_Arguments) {
    vector<string> args = { "1", "2" };

    Act(args);

    Assert("ERROR: Should be 5 or 6 arguments\\..*");
}

TEST_F(DebtServiceCalculatorTest, Can_Detect_Wrong_Number_Format_Float) {
    vector<string> args = { "abc", "1", "1", "2", "1" };

    Act(args);

    Assert("Wrong number format!");
}

TEST_F(DebtServiceCalculatorTest, Can_Detect_Wrong_Number_Format_Int) {
    vector<string> args = { "10", "pi", "1", "1", "1" };

    Act(args);

    Assert("Wrong number format!");
}

TEST_F(DebtServiceCalculatorTest, Can_Detect_Wrong_Number_Format_Type) {
    vector<string> args = { "1", "1", "1", "33", "2" };

    Act(args);

    Assert("Type of service not defined!");
}

TEST_F(DebtServiceCalculatorTest, Can_Detect_Wrong_Operation_Format) {
    vector<string> args = { "1", "1", "1", "2", "33" };

    Act(args);

    Assert("Operation not defined!");
}

TEST_F(DebtServiceCalculatorTest,
    Can_calculate_The_Amount_Of_Payments_For_The_Entire_Loan_Period) {
    vector<string> args = { "1", "1", "1", "1", "1" };

    Act(args);

    Assert("The amount of payments for the entire loan period = 2");
}

TEST_F(DebtServiceCalculatorTest,
    Can_Find_Out_The_Balance_On_A_Debt) {
    vector<string> args = { "1", "1", "1", "0", "2" };

    Act(args);

    Assert("Find out the balance on a debt = 2");
}

TEST_F(DebtServiceCalculatorTest,
    Can_Enter_An_Amount_And_Find_Out_The_Balance_On_A_Debt) {
    vector<string> args = { "1", "1", "1", "2", "3", "2" };

    Act(args);

    Assert("It was = 2; amount of payment = 2; current balance = 0");
}

TEST_F(DebtServiceCalculatorTest,
    Can_Create_Two_Identical_Debts_With_The_Same_Service) {
    vector<string> args = { "1", "1", "1", "2", "4" };

    Act(args);

    Assert("The amount of Ivanov = 2; the amount of Borodin = 2");
}
