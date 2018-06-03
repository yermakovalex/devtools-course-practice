// Copyright 2018 Vyunov Roman

#include <gtest/gtest.h>

#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>

#include "include/simple_regex-app.h"

using ::testing::internal::RE;
using std::vector;
using std::string;

class SimpleRegexTest : public ::testing::Test {
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
    Application app_;
    string output_;
};

TEST_F(SimpleRegexTest, Do_Print_Help_Without_Arguments) {
    vector<string> args = {};

    Act(args);

    Assert("This is a regex finder application\\..*");
}

TEST_F(SimpleRegexTest, Is_Checking_Number_Of_Arguments) {
    vector<string> args = { "1", "2" };

    Act(args);

    Assert("ERROR: Should be 3 arguments\\..*");
}

TEST_F(SimpleRegexTest, Invalid_Operator) {
    vector<string> args = { "abc", "world", "Hello world!" };

    Act(args);

    Assert("Wrong operation format!");
}

TEST_F(SimpleRegexTest, Valid_Operator_i_Can_Find_regex) {
    vector<string> args = { "-i", "world", "Hello world!" };

    Act(args);

    Assert("Regex is match");
}

TEST_F(SimpleRegexTest, Valid_Operator_i_Cant_Find_regex) {
    vector<string> args = { "-i", "worl\\d", "Hello world!" };

    Act(args);

    Assert("Regex is not match");
}

TEST_F(SimpleRegexTest, Valid_Operator_g_Can_Find_regex) {
    vector<string> args = { "-g", "world", "Hello world!" };

    Act(args);

    Assert("Find : world\nBegin position : 6");
}

TEST_F(SimpleRegexTest, Valid_Operator_g_Cant_Find_regex) {
    vector<string> args = { "-g", "worl\\d", "Hello world!" };

    Act(args);

    Assert("Nothing found");
}
