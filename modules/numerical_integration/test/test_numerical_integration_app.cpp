// Copyright 2018 Kulikova Svetlana
#include <gtest/gtest.h>

#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>

#include "include/numerical_integration_app.h"

using ::testing::internal::RE;
using std::vector;
using std::string;

class NumericalIntegrationTest : public ::testing::Test {
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
    IntegralApp app_;
    string output_;
};

TEST_F(NumericalIntegrationTest, Do_Print_Help_Without_Arguments) {
    vector<string> args = {};

    Act(args);

    Assert("This is a numerical integration application\\..*");
}

TEST_F(NumericalIntegrationTest, Is_Checking_Number_Of_Arguments) {
    vector<string> args = {"1.0", "2.0"};

    Act(args);

    Assert("ERROR: Should be 4 arguments\\..*");
}

TEST_F(NumericalIntegrationTest, Can_Detect_Wrong_Number_Format_Double) {
    vector<string> args = {"pi", "1.0", "2", "RiemannSumLeft"};

    Act(args);

    Assert("Wrong number format!");
}


TEST_F(NumericalIntegrationTest, Can_Detect_Wrong_Number_Format_Int) {
    vector<string> args = {"0.0", "1.0", "pi", "RiemannSumLeft"};

    Act(args);

    Assert("Wrong number format!");
}

TEST_F(NumericalIntegrationTest, Can_Detect_Wrong_Method_Format) {
    vector<string> args = {"1.0", "1.0", "1", "Hello"};

    Act(args);

    Assert("Wrong method format!");
}

TEST_F(NumericalIntegrationTest, Can_RiemannSumLeft) {
    vector<string> args = {"1.0", "10.0", "1000", "RiemannSumLeft"};

    Act(args);

    Assert("result = 402.783");
}


TEST_F(NumericalIntegrationTest, Can_TrapezoidalRule) {
    vector<string> args = {"1.0", "10.0", "1000", "TrapezoidalRule"};

    Act(args);

    Assert("result = 403.333");
}


TEST_F(NumericalIntegrationTest, Can_SimpsonRule) {
    vector<string> args = {"1.0", "10.0", "1000", "SimpsonRule"};

    Act(args);

    Assert("result = 403.333");
}

TEST_F(NumericalIntegrationTest, Can_Simpson3_8Rule) {
    vector<string> args = {"1.0", "10.0", "1000", "Simpson3_8Rule"};

    Act(args);

    Assert("result = 403.333");
}

TEST_F(NumericalIntegrationTest, Can_BooleRule) {
    vector<string> args = {"1.0", "10.0", "1000", "BooleRule"};

    Act(args);

    Assert("result = 403.333");
}

TEST_F(NumericalIntegrationTest, Can_NewtonCotes5) {
    vector<string> args = {"1.0", "10.0", "1000", "NewtonCotes5"};

    Act(args);

    Assert("result = 403.333");
}

TEST_F(NumericalIntegrationTest, Can_GaussianQuadrature) {
    vector<string> args = {"1.0", "10.0", "1000", "GaussianQuadrature"};

    Act(args);

    Assert("result = 403.333");
}
