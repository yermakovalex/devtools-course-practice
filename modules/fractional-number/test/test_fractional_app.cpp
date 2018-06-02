// Copyright 2018 Ermachenko

#include <gtest/gtest.h>

#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>

#include "include/Fractional_app.h"

using ::testing::internal::RE;
using std::vector;
using std::string;

class FractionalAppTest : public ::testing::Test {
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
    Fractional_app app_;
    string output_;
};

TEST_F(FractionalAppTest, Can_Print_Help_Without_Arguments) {
    vector<string> args = {};

    Act(args);

    Assert("This is a fractional number calculator application\\..*");
}

TEST_F(FractionalAppTest, Can_Checking_Number_Of_Arguments) {
    vector<string> args = { "5", "2" };

    Act(args);

    Assert("ERROR: Should be 5 arguments\\..*");
}

TEST_F(FractionalAppTest, Cant_Work_If_Wrong_Number_Format) {
    vector<string> args = { "a", "1", "+", "0", "4" };

    Act(args);

    Assert("Wrong Param format!*");
}

TEST_F(FractionalAppTest, Cant_Work_If_Wrong_Operation_Format) {
    vector<string> args = { "5", "6", "=", "4", "2" };

    Act(args);

    Assert("Wrong operation format!");
}

TEST_F(FractionalAppTest, Can_Add) {
    vector<string> args = { "5", "1", "+", "12", "4" };

    Act(args);

    Assert("8/1");
}

TEST_F(FractionalAppTest, Can_Diff) {
    vector<string> args = { "75", "165", "-", "87", "170" };

    Act(args);

    Assert("-107/1870");
}

TEST_F(FractionalAppTest, Can_Mult) {
    vector<string> args = { "0", "-3", "*", "17", "21" };

    Act(args);

    Assert("0/1");
}

TEST_F(FractionalAppTest, Can_Divide) {
    vector<string> args = { "1", "2", "/", "3", "4" };

    Act(args);

    Assert("2/3");
}
