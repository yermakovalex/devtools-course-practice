// Copyright 2018 Churakov Sergey

#include <gtest/gtest.h>

#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>

#include "include/RBTreeApplication.h"

using ::testing::internal::RE;
using std::vector;
using std::string;

class RBTreeApplicationTest : public ::testing::Test {
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
    RBTree_application app_;
    string output_;
};

TEST_F(RBTreeApplicationTest, Do_Print_Help_Without_Arguments) {
    vector<string> args = {};

    Act(args);

    Assert("This is a red black tree application\\..*");
}

TEST_F(RBTreeApplicationTest, Is_Checking_Number_Of_Arguments) {
    vector<string> args = {"1", "2", "3", "4", "5"};

    Act(args);

    Assert("ERROR: Should be 2 arguments\\..*");
}

TEST_F(RBTreeApplicationTest, Can_Detect_Wrong_Operation_Format) {
    vector<string> args = {"2", "qwerty"};

    Act(args);

    Assert("Wrong operation format!");
}

TEST_F(RBTreeApplicationTest, Can_Insert_Node) {
    vector<string> args = {"2", "i"};

    Act(args);

    Assert("New node inserted");
}

TEST_F(RBTreeApplicationTest, Can_Find_Node) {
    vector<string> args = {"1", "f"};

    Act(args);

    Assert("Node found 1 times");
}

TEST_F(RBTreeApplicationTest, Cant_Find_Unexisting_Node) {
    vector<string> args = {"4", "f"};

    Act(args);

    Assert("Node found 0 times");
}

TEST_F(RBTreeApplicationTest, Can_Delete_Node) {
    vector<string> args = {"1", "d"};

    Act(args);

    Assert("Node deleted");
}

TEST_F(RBTreeApplicationTest, Cant_Delete_Unexisting_Node) {
    vector<string> args = {"4", "d"};

    Act(args);

    Assert("Cant delete unexisting node");
}
