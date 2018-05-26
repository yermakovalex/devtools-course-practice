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

    Assert("ERROR: Wrong number of arguments\\..*");
}
TEST_F(OperationsOn3dVectorsAppTest, Can_Detect_Wrong_Number_Format) {
    vector<string> args = { "norm", "pi", "2", "4" };

    Act(args);

    Assert("Wrong number format!.*");
}

TEST_F(OperationsOn3dVectorsAppTest,
    Can_Detect_Wrong_Unary_Operation_Format) {
    vector<string> args = { "hello,world", "1", "1", "1" };

    Act(args);

    Assert("Wrong operation format!");
}
TEST_F(OperationsOn3dVectorsAppTest,
    Can_Detect_Wrong_Binary_Operation_Format) {
    vector<string> args = { "hello,world", "1", "1", "1", "1", "1", "1" };

    Act(args);

    Assert("Wrong operation format!");
}
TEST_F(OperationsOn3dVectorsAppTest, Can_Get_Correct_Norm) {
    vector<string> args = { "norm", "0", "3", "-4" };

    Act(args);

    Assert("Norm of the vector = 5");
}
TEST_F(OperationsOn3dVectorsAppTest, Can_Get_Correct_Normalized_Vector) {
    vector<string> args = { "normalize", "0", "3", "-4" };

    Act(args);

    Assert("Normalized vector = 0,0.6,-0.8");
}
TEST_F(OperationsOn3dVectorsAppTest, Can_Get_Correct_Dot_Product) {
    vector<string> args = { "dotproduct", "1", "2", "3", "2", "3", "-4" };

    Act(args);

    Assert("Dot product of the vectors = -4");
}
TEST_F(OperationsOn3dVectorsAppTest, Can_Get_Correct_Cross_Product) {
    vector<string> args = { "crossproduct", "0", "1", "0", "1", "0", "0" };

    Act(args);

    Assert("Cross product of the vectors = 0,0,-1");
}
