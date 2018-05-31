// Copyright 2018 Lvova Alina
#include <gtest/gtest.h>

#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>

#include "include/line_plane_intersection_app.h"

using ::testing::internal::RE;
using std::vector;
using std::string;

class LinePlaneIntersectionAppTest : public ::testing::Test {
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
    LinePlaneIntersectionApp app_;
    string output_;
};

TEST_F(LinePlaneIntersectionAppTest, Do_Print_Help_Without_Arguments) {
    vector<string> args = {};

    Act(args);

    Assert(" This is an application to check the intersection\\..*");
}

TEST_F(LinePlaneIntersectionAppTest,
    Is_Checking_Number_Of_Arguments) {
    vector<string> args = { "Intersect", "-1", "10" };

    Act(args);

    Assert("ERROR: Should be 16 arguments\\..*");
}

TEST_F(LinePlaneIntersectionAppTest,
    Can_Detect_Invalid_Numeric_Format_Double) {
    vector<string> args = { "Intersect", "it_isn't_number", "0", "3", "0",
"1", "1", "-3", "0", "0", "0", "9", "-11", "1", "12", "-14"};

    Act(args);

    Assert("Invalid numeric format");
}

TEST_F(LinePlaneIntersectionAppTest,
    Can_Detect_Invalid_Operation_Format) {
    vector<string> args = { "it_isn't_operation", "0", "0", "3", "0",
"1", "1", "-3", "0", "0", "0", "9", "-11", "1", "12", "-14"};

    Act(args);

    Assert("Invalid operation");
}

TEST_F(LinePlaneIntersectionAppTest, Can_Plane_Intersection_Line) {
    vector<string> args = { "Intersect", "0", "0", "3", "0", "1",
"1", "-3", "0", "0", " 0", "9", "-11", "1", "12", "-14"};

    Act(args);

    Assert("dot of intersection is = -2, 3, -5");
}

TEST_F(LinePlaneIntersectionAppTest, Can_Not_Plane_Intersection_Line) {
    vector<string> args = { "Intersect", "0", "1", "0",
"-0.5", "0", "0", "1", "0", "1", "0", "-2", "1", "1", "0", "1" };

    Act(args);

    Assert("The plane is not intersecting the line");
}

TEST_F(LinePlaneIntersectionAppTest, Can_To_Get_Not_Intersect_PlaneLine) {
    vector<string> args = { "Isnt_it_intersected", "0", "1", "0",
"-0.5", "0", "0", "1", "0", "1", "0", "-2", "1", "1", "0", "1" };

    Act(args);

    Assert("The plane is not intersecting the line");
}

TEST_F(LinePlaneIntersectionAppTest, Can_Not_To_Get_Not_Intersect_PlaneLine) {
    vector<string> args = { "Isnt_it_intersected", "0",
"0", "3", "0", "1", "1", "-3", "0", "0", " 0", "9", "-11", "1", "12", "-14" };

    Act(args);

    Assert("The plane is intersecting the line");
}
