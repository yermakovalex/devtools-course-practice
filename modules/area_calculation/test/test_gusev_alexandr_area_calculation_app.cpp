// Copyright 2018 Gusev Alexandr

#include <gtest/gtest.h>

#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>

#include "include/area_calculation_app.h"
using ::testing::internal::RE;
using std::vector;
using std::string;

class AreaCalculationAppTest : public ::testing::Test {
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
    AreaCalculationApp app_;
    string output_;
};

TEST_F(AreaCalculationAppTest, No_Arguments_Test) {
    // Arrange
    vector<string> args = {};
    // Act
    Act(args);
    // Assert
    Assert("This is a area calculation application\\..*");
}
TEST_F(AreaCalculationAppTest, UnCorrectly_Arguments_Test) {
    // Arrange
    vector<string> args = { "3", "1.0.1", "2.0", "3.0", "1.0", "2.0", "1.0"};
    // Act
    Act(args);
    // Assert
    Assert("Wrong double format!");
}
TEST_F(AreaCalculationAppTest, UnCorrectly_Int_Arguments_Test) {
    // Arrange
    vector<string> args = { "3.0", "1.0", "2.0", "3.0", "1.0", "2.0", "1.0" };
    // Act
    Act(args);
    // Assert
    Assert("Wrong int format!");
}
TEST_F(AreaCalculationAppTest, Correctly_Area_Calculation_Test) {
    // Arrange
    vector<string> args = { "3", "1.0", "2.0", "3.0", "1.0", "2.0", "1.0"};
    // Act
    Act(args);
    // Assert
    Assert("area = 1");
}
TEST_F(AreaCalculationAppTest, Uncorrectly_Number_Arguments_Test) {
    // Arrange
    vector<string> args = { "3", "2.0"};
    // Act
    Act(args);
    // Assert
    Assert("ERROR: Should be size multiplication 2 plus 1 arguments\\..*");
}
TEST_F(AreaCalculationAppTest, Square_Area_Calculation_Test) {
    // Arrange
    vector<string> args = { "4", "1.0", "1.0", "2.0", "2.0",
               "1.0", "3.0", "3.0", "1.0" };
    // Act
    Act(args);
    // Assert
    Assert("area = 2");
}
TEST_F(AreaCalculationAppTest, Trapezium_Area_Calculation_Test) {
    // Arrange
    vector<string> args = { "4", "1.0", "1.0", "2.0", "3.0",
               "1.0", "3.0", "3.0", "1.0" };
    // Act
    Act(args);
    // Assert
    Assert("area = 3");
}
TEST_F(AreaCalculationAppTest, Octagon_Area_Calculation_Test) {
    // Arrange
    vector<string> args = { "8", "1.0", "1.0", "2.0", "2.0",
        "3.0", "3.0", "4.0", "4.0", "-3.0", "-2.0", "-2.0",
        "-1.0", "-1.0", "-2.0", "-2.0", "-3.0" };
    // Act
    Act(args);
    // Assert
    Assert("area = 4");
}
TEST_F(AreaCalculationAppTest, Zero_Area_Calculation_Test) {
    // Arrange
    vector<string> args = { "3", "1.0", "1.0", "1.0", "2.0", "2.0", "2.0"};
    // Act
    Act(args);
    // Assert
    Assert("area = 0");
}
