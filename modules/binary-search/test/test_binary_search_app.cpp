// Copyright 2018 Gorelova Ksenia

#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "include/binary_search_app.h"

using ::testing::internal::RE;
using std::vector;
using std::string;

class BinarySearchAppTest : public ::testing::Test {
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
    BinarySearchApp app_;
    string output_;
};

TEST_F(BinarySearchAppTest, Do_Print_Help_Without_Arguments) {
    vector<string> args = {};

    Act(args);

    Assert("This is a binary search application\\..*");
}

TEST_F(BinarySearchAppTest, Is_Checking_Number_Of_Arguments) {
    vector<string> args = { "1" };

    Act(args);

    Assert("Error: Should be more arguments\\..*");
}

TEST_F(BinarySearchAppTest, Can_Detect_Wrong_Number_Format) {
    vector<string> args = { "1", "pi", "2", "4" };

    Act(args);

    Assert("Wrong number format!.*");
}

TEST_F(BinarySearchAppTest, Can_Detect_Wrong_Format_Of_Arguments) {
    vector<string> args = { "1", ",", ",", "1", "1"};

    Act(args);

    Assert("Wrong number format!.*");
}

TEST_F(BinarySearchAppTest, Can_Search) {
    vector<string> args =
    { "7, ", "7, ", "4", "1" , "5" , "3" , "4", "7", "9" };

    Act(args);

    Assert("5");
}
