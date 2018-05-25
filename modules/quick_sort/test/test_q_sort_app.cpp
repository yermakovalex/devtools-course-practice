// Copyright 2018 Pozdeeva Varavara

#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "include/q_sort_app.h"

using ::testing::internal::RE;
using std::vector;
using std::string;

class QuickSortAppTest : public ::testing::Test {
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
     QuickSortApp app_;
    string output_;
};

TEST_F(QuickSortAppTest, Do_Print_Help_Without_Arguments) {
    vector<string> args = {};

    Act(args);

    Assert("This is a quick sort application\\..*");
}

TEST_F(QuickSortAppTest, Is_Checking_Number_Of_Arguments) {
    vector<string> args = {"1", "2"};

    Act(args);

    Assert("ERROR: Should be more arguments\\..*");
}

TEST_F(QuickSortAppTest, Can_Detect_Wrong_Number_Format) {
    vector<string> args = {"1", "pi", "2", "4"};

    Act(args);

    Assert("Wrong number format!.*");
}

TEST_F(QuickSortAppTest, Can_Detect_Wrong_Format_Of_Arguments) {
    vector<string> args = {"1", ",", ",", "1", "1", "1" , "1" , "1" , "1" };

    Act(args);

    Assert("Wrong number format!.*");
}

TEST_F(QuickSortAppTest, Can_Sort) {
    vector<string> args = {"5,", "0,", "4", "2", "1" , "5" , "3" , "4" };

    Act(args);

    Assert("1 2 3 4 5 ");
}

TEST_F(QuickSortAppTest, Can_not_Sort_with_Uncorrect_Args_Out_Of_Range) {
    vector<string> args = { "5,", "0,", "6", "2", "1" , "5" , "3" , "4" };

    Act(args);

    Assert("Right bound of array > array size.*");
}

TEST_F(QuickSortAppTest, Can_not_Sort_with_Uncorrect_Args_Negative_Index) {
    vector<string> args = { "5,", "-1,", "3", "2", "1" , "5" , "3" , "4" };

    Act(args);

    Assert("Array index can't be < 0.*");
}

