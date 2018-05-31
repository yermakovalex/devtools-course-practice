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

TEST_F(LengthConverterAppTest, Can_Detect_Unknown_Conversion2) {
    vector<string> args = { "2", "Centimeter", "Centimeter" };

    Act(args);

    Assert("Error! Unknown conversion");
}

TEST_F(LengthConverterAppTest, Can_Detect_Unknown_Conversion3) {
    vector<string> args = { "2", "Kilometer", "Kilometer" };

    Act(args);

    Assert("Error! Unknown conversion");
}

TEST_F(LengthConverterAppTest, Can_Detect_Unknown_Conversion4) {
    vector<string> args = { "2", "Mile", "Mile" };

    Act(args);

    Assert("Error! Unknown conversion");
}

TEST_F(LengthConverterAppTest, Can_Detect_Unknown_Conversion5) {
    vector<string> args = { "2", "Foot", "Foot" };

    Act(args);

    Assert("Error! Unknown conversion");
}

TEST_F(LengthConverterAppTest, Can_Detect_Unknown_Conversion6) {
    vector<string> args = { "2", "Yard", "Yard" };

    Act(args);

    Assert("Error! Unknown conversion");
}

TEST_F(LengthConverterAppTest, Can_Detect_Unknown_Conversion7) {
    vector<string> args = { "2", "Inch", "Inch" };

    Act(args);

    Assert("Error! Unknown conversion");
}

TEST_F(LengthConverterAppTest, Can_Detect_Unknown_Conversion8) {
    vector<string> args = { "2", "NauticalMile", "NauticalMile" };

    Act(args);

    Assert("Error! Unknown conversion");
}

TEST_F(LengthConverterAppTest, Can_Detect_Unknown_Conversion9) {
    vector<string> args = { "2", "AstronomicalUnit", "AstronomicalUnit" };

    Act(args);

    Assert("Error! Unknown conversion");
}

TEST_F(LengthConverterAppTest, Can_Detect_Unknown_Conversion10) {
    vector<string> args = { "2", "Span", "Span" };

    Act(args);

    Assert("Error! Unknown conversion");
}

TEST_F(LengthConverterAppTest, Can_Detect_Unknown_Conversion11) {
    vector<string> args = { "2", "Verst", "Verst" };

    Act(args);

    Assert("Error! Unknown conversion");
}

TEST_F(LengthConverterAppTest, Can_Convert_Meters_To_Centimeters) {
    vector<string> args = { "1", "Meter", "Centimeter" };

    Act(args);

    Assert("1 meters is 100 centimeters");
}

TEST_F(LengthConverterAppTest, Can_Convert_Centimeters_To_Meters) {
    vector<string> args = { "100", "Centimeter", "Meter" };

    Act(args);

    Assert("100 centimeters is 1 meters");
}

TEST_F(LengthConverterAppTest, Can_Convert_Meters_To_Kilometers) {
    vector<string> args = { "1000", "Meter", "Kilometer" };

    Act(args);

    Assert("1000 meters is 1 kilometers");
}

TEST_F(LengthConverterAppTest, Can_Convert_Kilometers_To_Meters) {
    vector<string> args = { "1", "Kilometer", "Meter" };

    Act(args);

    Assert("1 kilometers is 1000 meters");
}

TEST_F(LengthConverterAppTest, Can_Convert_Kilometers_To_Miles) {
    vector<string> args = { "1.609344", "Kilometer", "Mile" };

    Act(args);

    Assert("1.60934 kilometers is 1 miles");
}

TEST_F(LengthConverterAppTest, Can_Convert_Miles_To_Kilometers) {
    vector<string> args = { "1", "Mile", "Kilometer" };

    Act(args);

    Assert("1 miles is 1.60934 kilometers");
}

TEST_F(LengthConverterAppTest, Can_Convert_Feet_To_Yards) {
    vector<string> args = { "3", "Foot", "Yard" };

    Act(args);

    Assert("3 feet is 1 yards");
}

TEST_F(LengthConverterAppTest, Can_Convert_Yards_To_Feet) {
    vector<string> args = { "1", "Yard", "Foot" };

    Act(args);

    Assert("1 yards is 3 feet");
}

TEST_F(LengthConverterAppTest, Can_Convert_Feet_To_Meters) {
    vector<string> args = { "0.3048", "Foot", "Meter" };

    Act(args);

    Assert("0.3048 feet is 1 meters");
}

TEST_F(LengthConverterAppTest, Can_Convert_Meters_To_Feet) {
    vector<string> args = { "1", "Meter", "Foot" };

    Act(args);

    Assert("1 meters is 0.3048 feet");
}

TEST_F(LengthConverterAppTest, Can_Convert_Centimeters_To_Inches) {
    vector<string> args = { "2.54", "Centimeter", "Inch" };

    Act(args);

    Assert("2.54 centimeters is 1 inches");
}

TEST_F(LengthConverterAppTest, Can_Convert_Inch_To_Centimeters) {
    vector<string> args = { "1", "Inch", "Centimeter" };

    Act(args);

    Assert("1 inches is 2.54 centimeters");
}

TEST_F(LengthConverterAppTest, Can_Convert_Meters_To_NauticalMiles) {
    vector<string> args = { "1852", "Meter", "NauticalMile" };

    Act(args);

    Assert("1852 meters is 1 nautical miles");
}

TEST_F(LengthConverterAppTest, Can_Convert_NauticalMiles_To_Meters) {
    vector<string> args = { "1", "NauticalMile", "Meter" };

    Act(args);

    Assert("1 nautical miles is 1852 meters");
}

TEST_F(LengthConverterAppTest, Can_Convert_Kilometers_To_AstronimicalUnits) {
    vector<string> args = { "149599", "Kilometer", "AstronomicalUnit" };

    Act(args);

    Assert("149599 kilometers is 0.00100001 astronomical units");
}

TEST_F(LengthConverterAppTest, Can_Convert_AstronimicalUnits_To_Kilometers) {
    vector<string> args = { "0.02", "AstronomicalUnit", "Kilometer" };

    Act(args);

    Assert("0.020000 astronomical units is 2991957.414000 kilometres");
}

TEST_F(LengthConverterAppTest, Can_Convert_Centimeters_To_Spans) {
    vector<string> args = { "17.78", "Centimeter", "Span" };

    Act(args);

    Assert("17.78 centimeters is 1 spans");
}

TEST_F(LengthConverterAppTest, Can_Convert_Spans_To_Centimeters) {
    vector<string> args = { "1", "Span", "Centimeter" };

    Act(args);

    Assert("1 spans is 17.78 centimeters");
}

TEST_F(LengthConverterAppTest, Can_Convert_Spans_To_Versts) {
    vector<string> args = { "6000", "Span", "Verst" };

    Act(args);

    Assert("6000 spans is 1 versts");
}

TEST_F(LengthConverterAppTest, Can_Convert_Versts_To_Spans) {
    vector<string> args = { "1", "Verst", "Span" };

    Act(args);

    Assert("1 versts is 6000 spans");
}

TEST_F(LengthConverterAppTest, Can_Convert_Miles_To_Meters) {
    vector<string> args = { "1", "Mile", "Meter" };

    Act(args);

    Assert("1 miles is 1609.34 meters");
}

TEST_F(LengthConverterAppTest, Can_Convert_Meters_To_Miles) {
    vector<string> args = { "1609.344", "Meter", "Mile" };

    Act(args);

    Assert("1609.34 meters is 1 miles");
}

TEST_F(LengthConverterAppTest, Can_Convert_Yards_To_Meters) {
    vector<string> args = { "1", "Yard", "Meter" };

    Act(args);

    Assert("1 yards is 9.84252 meters");
}

TEST_F(LengthConverterAppTest, Can_Convert_Meters_To_Yards) {
    vector<string> args = { "9.842519685", "Meter", "Yard" };

    Act(args);

    Assert("9.84252 meters is 1 yards");
}

TEST_F(LengthConverterAppTest, Can_Convert_Inches_To_Meters) {
    vector<string> args = { "1", "Inch", "Meter" };

    Act(args);

    Assert("1 inches is 0.0254 meters");
}

TEST_F(LengthConverterAppTest, Can_Convert_AstronomicalUnits_To_Meters) {
    vector<string> args = { "1", "AstronomicalUnit", "Meter" };

    Act(args);

    Assert("1.000000 astronomical units is 149597870700.000000 meters");
}

TEST_F(LengthConverterAppTest, Can_Convert_Meters_To_AstronomicalUnits) {
    vector<string> args = { "149597870700", "Meter", "AstronomicalUnit" };

    Act(args);

    Assert("149597870700.000000 meters is 1.000000 astronomical units");
}

TEST_F(LengthConverterAppTest, Can_Convert_Spans_To_Meters) {
    vector<string> args = { "1", "Span", "Meter" };

    Act(args);

    Assert("1 spans is 0.1778 meters");
}

TEST_F(LengthConverterAppTest, Can_Convert_Meters_To_Spans) {
    vector<string> args = { "0.1778", "Meter", "Span" };

    Act(args);

    Assert("0.1778 meters is 1 spans");
}

TEST_F(LengthConverterAppTest, Can_Convert_Meters_To_Versts) {
    vector<string> args = { "1066.8", "Meter", "Verst" };

    Act(args);

    Assert("1066.8 meters is 1 versts");
}

TEST_F(LengthConverterAppTest, Can_Convert_Meters_To_Inches) {
    vector<string> args = { "0.0254", "Meter", "Inch" };

    Act(args);

    Assert("0.0254 meters is 1 inches");
}

TEST_F(LengthConverterAppTest, Can_Convert_Versts_To_Meters) {
    vector<string> args = { "1", "Verst", "Meter" };

    Act(args);

    Assert("1 versts is 1066.8 meters");
}
