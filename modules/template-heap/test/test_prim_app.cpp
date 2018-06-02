// Copyright 2018 Kamelina Julia

#include <gtest/gtest.h>

#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>

#include "include/prim-app.hpp"

using ::testing::internal::RE;
using std::vector;
using std::string;

class PrimAppTest : public ::testing::Test {
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
    PrimApp app_;
    string output_;
};

TEST_F(PrimAppTest, Do_Print_Help_Without_Arguments) {
  vector<string> args = {};

  Act(args);

  Assert("This application implements Prim's algorithm*");
}

TEST_F(PrimAppTest, Do_Print_Help_With_Help_Key) {
  vector<string> args = { "-h" };

  Act(args);

  Assert("This application implements Prim's algorithm*");
}

TEST_F(PrimAppTest, Do_Print_Help_With_Invalid_Key) {
  vector<string> args = { "-p", "../PrimGraph.txt", "-a", "j" };

  Act(args);

  Assert("This application implements Prim's algorithm*");
}

TEST_F(PrimAppTest, Is_Checking_Number_Of_Arguments) {
  vector<string> args = { "1"};

  Act(args);

  Assert("ERROR: Wrong argument format*");
}

TEST_F(PrimAppTest, Can_Detect_Wrong_Number_Format) {
  vector<string> args = { "-p", "../PrimGraph.txt", "-d", "j" };

  Act(args);

  Assert("Wrong number format!");
}

TEST_F(PrimAppTest, Can_Detect_Wrong_Demention) {
  vector<string> args = { "-p", "../PrimGraph.txt", "-d", "0" };

  Act(args);

  Assert("invalid dimension");
}

TEST_F(PrimAppTest, Can_Detect_Wrong_File_Name) {
  vector<string> args = { "-p", "../PrimGraph1.txt" };

  Act(args);

  Assert("FILE NOT FOUND!*");
}

TEST_F(PrimAppTest, Can_Compute_Core) {
  vector<string> args = { "-p", "../PrimGraph.txt", "-d", "2" };

  Act(args);

  Assert("Distance 2 First 0 Second 1\nDistance 4 First 0 Second 3\n*");
}

TEST_F(PrimAppTest, Can_Compute_Core_Without_Demention) {
  vector<string> args = { "-p", "../PrimGraph.txt" };

  Act(args);

  Assert("Distance 2 First 0 Second 1\nDistance 4 First 0 Second 3\n*");
}

TEST_F(PrimAppTest, Can_Compute_Core_With_Different_Demention) {
  vector<string> args = { "-p", "../PrimGraph.txt", "-d", "3" };

  Act(args);

  Assert("Distance 2 First 0 Second 1\nDistance 4 First 0 Second 3\n*");
}
