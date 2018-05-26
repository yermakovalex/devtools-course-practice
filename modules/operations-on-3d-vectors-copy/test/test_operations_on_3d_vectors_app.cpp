// Copyright 2018 Krasikova Ekaterina

#include <gtest/gtest.h>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>
#include "include/operations_on_3d_vectors_app.h"

using ::testing::internal::RE;
using std::vector;
using std::string;

class OperationsOn3dVectorsAppTest : public ::testing::Test {
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
    OperationsOn3dVectorsApp app_;
    string output_;
};

TEST_F(OperationsOn3dVectorsAppTest, Do_Print_Help_Without_Arguments) {
    vector<string> args = {};

    Act(args);

    Assert("This is an operations on 3d vectors application\\..*");
}
TEST_F(OperationsOn3dVectorsAppTest, Is_Checking_Number_Of_Arguments) {
    vector<string> args = { "1", "2" };

    Act(args);

    Assert("ERROR: Not enough arguments\\..*");
}
