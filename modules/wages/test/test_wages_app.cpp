// Copyright 2018 Matyasov Mixail

#include <gtest/gtest.h>
#include <string>
#include<vector>
#include"include/wages_app.h"

using ::testing::internal::RE;
using std::vector;

class WagesAppTest : public::testing::Test {
 protected:
        void Act(vector<std::string> args_) {
        vector<const char*> options;

        options.push_back("appname");
        for (size_t i = 0; i < args_.size(); ++i) {
            options.push_back(args_[i].c_str());
        }

        const char** argv = &options.front();
        int argc = static_cast<int>(args_.size() + 1);

        output_ = app_(argc, argv);
    }

    void Assert(std::string expected) {
        EXPECT_TRUE(RE::PartialMatch(output_, RE(expected)));
    }

 private:
    Application app_;
    std::string output_;

 private:
    std::string output;
    Application app;
};

TEST_F(WagesAppTest, When_argv_1_is_null) {
    vector<std::string> argc = {};

    Act(argc);

    Assert("Argument 1 is not correct");
}

TEST_F(WagesAppTest, When_argv_2_is_null) {
    vector<std::string> argc = {"1"};

    Act(argc);

    Assert("Argument 2 is not correct");
}

TEST_F(WagesAppTest, When_argv_3_is_null) {
    vector<std::string> argc = {"1", "1"};

    Act(argc);

    Assert("Argument 3 is not correct");
}

TEST_F(WagesAppTest, When_argv_4_is_null) {
    vector<std::string> argc = { "1", "1", "1" };

    Act(argc);

    Assert("Argument 4 is not correct");
}

TEST_F(WagesAppTest, When_argv_5_is_null) {
    vector<std::string> argc = { "1", "1", "1", "1"};

    Act(argc);

    Assert("Argument 5 is not correct");
}

TEST(Application, can_double_to_string) {
    Application app;
    std::string str = app.DoubleToString(12.12);

    EXPECT_EQ(str.length(), 5);
}

TEST(Application, can_string_to_double) {
    Application app;
    double val = app.StringToDouble("12.12");

    EXPECT_EQ(val, 12.12);
}

TEST(Application, can_int_to_Month) {
    Application app;
    app.IntToMonth(1);
    app.IntToMonth(2);
    app.IntToMonth(3);
    app.IntToMonth(4);
    app.IntToMonth(5);
    app.IntToMonth(6);
    app.IntToMonth(7);
    app.IntToMonth(8);
    app.IntToMonth(9);
    app.IntToMonth(10);
    app.IntToMonth(11);


    EXPECT_EQ(app.IntToMonth(12), December);
}

TEST(Application, can_app) {
    Application app;
    unsigned int argc = 6;
    vector<const char*> argv;
    argv.push_back(const_cast<char*>("appname"));
    argv.push_back(const_cast<char*>("CalculateWages"));
    argv.push_back(const_cast<char*>("10000"));
    argv.push_back(const_cast<char*>("1"));
    argv.push_back(const_cast<char*>("1"));
    argv.push_back(const_cast<char*>("1"));
    const char** arg = &argv.front();

    app(argc, arg);

    argv[1] = const_cast<char*>("HourlyPay");
    arg = &argv.front();
    app(argc, arg);

    argv[1] = const_cast<char*>("CalculationOvertimePayment");
    arg = &argv.front();
    app(argc, arg);

    argv[1] = const_cast<char*>("CalculationWagesWithoutOvertime");
    arg = &argv.front();
    app(argc, arg);
    app(-1, arg);

    ASSERT_NO_THROW(app.GetCalculatedValues());
}
