// Copyright 2018 Panov Aleksander

#include <gtest/gtest.h>
#include <string>
#include <vector>
#include "include/radix_sort_app.hpp"

using ::testing::internal::RE;

class ApplicationRadixSortTest : public ::testing::Test {
 protected:
    void Act(std::vector<std::string> args_) {
        std::vector<const char*> options;

        options.push_back("appname");
        for (size_t i = 0; i < args_.size(); ++i) {
            options.push_back(args_[i].c_str());
        }

        const char** argv = &options.front();
        int argc = static_cast<int>(args_.size())+1;
        output_ = app_(argc, argv);
    }

    void Assert(std::string expected) {
        EXPECT_TRUE(RE::PartialMatch(output_, RE(expected)));
    }

 private:
    IntegerArray app_;
    std::string output_;
};

TEST_F(ApplicationRadixSortTest, Do_Print_Help_Without_Arguments) {
    std::vector<std::string> args = {};

    Act(args);

    Assert("This is a sort integer array application\\..*");
}

TEST_F(ApplicationRadixSortTest, Find_Incorrect_Input) {
    std::vector<std::string> args = { "11a", "2a2b" };

    Act(args);

    Assert("Wrong number format!");
}

TEST_F(ApplicationRadixSortTest, Sorted_two_elements1) {
    std::vector<std::string> args = { "1", "2" };

    Act(args);

    Assert("1 2");
}

TEST_F(ApplicationRadixSortTest, Sorted_two_elements2) {
    std::vector<std::string> args = { "2", "1" };

    Act(args);

    Assert("1 2");
}

TEST_F(ApplicationRadixSortTest, Sorted_seven_elements1) {
    std::vector<std::string> args = { "1", "2", "3", "4", "5", "6", "7" };

    Act(args);

    Assert("1 2 3 4 5 6 7");
}

TEST_F(ApplicationRadixSortTest, Sorted_seven_elements2) {
    std::vector<std::string> args = { "4", "6", "1", "5", "3", "2", "7" };

    Act(args);

    Assert("1 2 3 4 5 6 7");
}
