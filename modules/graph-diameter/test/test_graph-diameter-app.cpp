// Copyright 2018 Makarin Kirill

#include <gtest/gtest.h>

#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>

#include "include/graph-diameter-app.h"

using ::testing::internal::RE;
using std::vector;
using std::string;

class GraphDiameterAppTest : public ::testing::Test {
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
    GraphDiameterApp app_;
    string output_;
};

TEST_F(GraphDiameterAppTest, Do_Print_Help_Without_Arguments) {
    vector<string> args = {};

    Act(args);

    Assert("This is a graph diameter application\\..*");
}

TEST_F(GraphDiameterAppTest, Is_Checking_Number_Of_Arguments) {
    vector<string> args = {"2"};

    Act(args);

    Assert("ERROR: Should be 1 +.*");
}

TEST_F(GraphDiameterAppTest, Can_Detect_Wrong_Number_Format) {
    vector<string> args = {"3", "-3", "2", "4", "pi", "2", "4", "-3", "2", "4"};

    Act(args);

    Assert("Wrong number format!.*");
}

TEST_F(GraphDiameterAppTest, Can_Get_Diameter) {
    vector<string> args = {"3",
                           "0", "1", "0",
                           "1", "0", "1",
                           "0", "1", "0"};

    Act(args);

    Assert("The diameter of graph with 3 vertexes is 2");
}
