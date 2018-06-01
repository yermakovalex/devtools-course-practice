// Copyright 2018 Volkov Daniel

#include <gtest/gtest.h>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>

#include "include/stack_app.h"

using ::testing::internal::RE;
using std::vector;
using std::string;

class StackAppTest : public ::testing::Test {
 protected:
    void Act(vector<string> args) {
        vector<const char*> options;
        options.push_back("appname");
        for (size_t i = 0; i < args.size(); ++i) {
            options.push_back(args[i].c_str());
        }

        const char** argv = &options.front();
        int argc = static_cast<int>(args.size()) + 1;

        output_ = app_(argc, argv);
    }

    void Assert(std::string expected) {
        EXPECT_TRUE(RE::PartialMatch(output_, RE(expected)));
    }

 private:
    StackApp app_;
    string output_;
};

TEST_F(StackAppTest, Do_Print_Help_Without_Arguments) {
    vector<string> args = {};

    Act(args);

    Assert("This is a stack application\\..*");
}


TEST_F(StackAppTest, Can_Detect_Wrong_Number_Format) {
    vector<string> args = {"re", "7", "tt", "5"};

    Act(args);

    Assert("Wrong format or value is out of range");
}

TEST_F(StackAppTest, Can_Print_Result) {
    vector<string> args = {"3", "1", "5", "2"};

    Act(args);

    Assert("Your stack is full!\n.*");
}
