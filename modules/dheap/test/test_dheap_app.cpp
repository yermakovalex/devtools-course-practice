// Copyright 2018 Lipatov Igor

#include <gtest/gtest.h>
#include <string>
#include <vector>
#include "include/dheap-app.h"


using ::testing::internal::RE;

class DheapAppTest : public ::testing::Test {
 protected:
    void Act(std::vector <std::string> args_) {
        std::vector<const char *> options;
        options.push_back("appname");
        for (auto &arg : args_) {
            options.push_back(arg.c_str());
        }
        const char **argv = &options.front();
        int argc = static_cast<int>(args_.size());
        output_ = app_(argc, argv);
    }

    void Assert(const std::string &expected) {
        EXPECT_TRUE(RE::PartialMatch(output_, RE(expected)));
    }

 private:
    MinSearcher app_;
    std::string output_;
};

TEST_F(DheapAppTest, No_Arguments_Test) {
    // Arrange
    std::vector<std::string> args = {};
    // Act
    Act(args);
    // Assert
    Assert("ERROR: You should provide at least 3 arguments!");
}

TEST_F(DheapAppTest, Uncorrect_Number_Of_Arguments) {
    // Arrange
    std::vector <std::string> args = {"3", "1", "2", "3", "1", "2", "1"};
    // Act
    Act(args);
    // Assert
    Assert("ERROR: Incorrect element count!");
}

TEST_F(DheapAppTest, Not_Enough_Arguments) {
    // Arrange
    std::vector <std::string> args = {"1" , "0"};
    // Act
    Act(args);
    // Assert
    Assert("ERROR: You should provide at least 3 arguments!");
}

TEST_F(DheapAppTest, Can_Find_Min) {
    // Arrange
    std::vector <std::string> args = {"3" , "3", "2", "3", "1"};
    // Act
    Act(args);
    // Assert
    Assert("min=2");
}

TEST_F(DheapAppTest, Can_Find_Min2) {
    // Arrange
    std::vector <std::string> args = {"3" , "5", "1", "2", "6", "5", "1"};
    // Act
    Act(args);
    // Assert
    Assert("min=1");
}
