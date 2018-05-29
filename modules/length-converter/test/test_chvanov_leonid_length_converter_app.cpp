// Copyright 2018 Chvanov Leonid

#include <gtest/gtest.h>

#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>

#include "include/length_converter_app.h"

using ::testing::internal::RE;
using std::vector;
using std::string;

class LengthConverterAppTest : public ::testing::Test {
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
    LengthConverterApp app_;
    string output_;
};

TEST_F(LengthConverterAppTest, Do_Print_Help_Without_Arguments) {
    vector<string> args = {};

    Act(args);

    Assert("This is a length converter application\\..*");
}

TEST_F(LengthConverterAppTest, Is_Checking_Number_Of_Arguments) {
    vector<string> args = { "Meter", "Centimeter" };

    Act(args);

    Assert("ERROR: Should be 3 arguments\\..*");
}

TEST_F(LengthConverterAppTest, Can_Detect_Wrong_Number_Format) {
    vector<string> args = { "odin", "Meter", "Centimeter" };

    Act(args);

    Assert("Wrong number format!");
}

TEST_F(LengthConverterAppTest, Can_Detect_Negative_Length) {
    vector<string> args = { "-1", "Meter", "Centimeter" };

    Act(args);

    Assert("Error! Invalid argument");
}

TEST_F(LengthConverterAppTest, Can_Detect_Wrong_Length_Unit_Format) {
    vector<string> args = { "2", "Meters", "Centimeter" };

    Act(args);

    Assert("Wrong length unit format!");
}

TEST_F(LengthConverterAppTest, Can_Detect_Unknown_Conversion) {
    vector<string> args = { "2", "Meter", "Meter" };

    Act(args);

    Assert("Error! Unknown conversion");
}


TEST_F(LengthConverterAppTest, Can_Convert_Lengths) {
    vector<string> args = { "25", "Meter", "Centimeter"};

    Act(args);

    Assert("25 meters is 2500 centimeters");
}
