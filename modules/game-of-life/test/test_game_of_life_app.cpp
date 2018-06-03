// Copyright 2018 Senina Anastasia

#include <gtest/gtest.h>

#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>

#include "include/game-of-life-app.h"

using ::testing::internal::RE;
using std::vector;
using std::string;

class GameofLifeTest : public ::testing::Test {
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
    GameOfLife app_;

 public:
    string output_;
};

TEST_F(GameofLifeTest, Do_Print_Help_Without_Arguments) {
    vector<string> args = {};

    Act(args);

    Assert("\nThis is a Game of Life application\\..*");
}

TEST_F(GameofLifeTest, Is_Checking_Number_Of_Arguments) {
    vector<string> args = {"1"};

    Act(args);

    Assert("ERROR: Should be more than 1 arguments\\..*");
}

TEST_F(GameofLifeTest, Can_Detect_Wrong_Number_Format) {
    vector<string> args = {"pi", "**."};

    Act(args);

    Assert("Wrong number format!.*");
}

TEST_F(GameofLifeTest, Can_Detect_Wrong_Grid_Format) {
    vector<string> args = {"1", ".m."};

    Act(args);

    Assert("ERROR: Wrong grid format!");
}

TEST_F(GameofLifeTest, Can_Detect_Wrong_Lengths) {
  vector<string> args = { "1", ".*", "**." };

  Act(args);

  Assert("ERROR: Wrong lengths of strings!");
}

TEST_F(GameofLifeTest, Can_Detect_Wrong_Lengths2) {
  vector<string> args = { "1", ".**", "**" };

  Act(args);

  Assert("ERROR: Wrong lengths of strings!");
}

TEST_F(GameofLifeTest, Can_Do_1_Step) {
    vector<string> args = {"1", "....", ".**.", ".**.", "...."};

    Act(args);


    EXPECT_EQ(output_, "Input:\n"
      "....\n"
      ".**.\n"
      ".**.\n"
      "....\n\n"
      "Result:\n"
      "....\n"
      ".**.\n"
      ".**.\n"
      "....\n");
}

TEST_F(GameofLifeTest, Can_Do_10_Steps) {
  vector<string> args = { "10", "....", ".**.", ".**.", "...." };

  Act(args);

  EXPECT_EQ(output_, "Input:\n"
    "....\n"
    ".**.\n"
    ".**.\n"
    "....\n\n"
    "Result:\n"
    "....\n"
    ".**.\n"
    ".**.\n"
    "....\n");
}
