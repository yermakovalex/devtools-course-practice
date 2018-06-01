// Copyright 2018 Matyasov Mixail

#include <gtest/gtest.h>
#include <string>
#include"include/wages_app.h"

using ::testing::internal::RE;

class WagesAppTest : public::testing::Test {
 protected:
    void Act(int argc, char** argv) {
        output = app(argc, argv);
    }

    void Assert(std::string expected) {
        EXPECT_TRUE(RE::PartialMatch(output, RE(expected)));
    }

 private:
    std::string output;
    Application app;
};

TEST_F(WagesAppTest, error_when_argc_negative) {
    int argc = -1;
    char** argv;
    argv = new char*[1];

    Act(argc, argv);

    Assert("Wrong variable");
}

TEST_F(WagesAppTest, error_when_argv_1_is_null) {
    const int size = 6;
    int argc = 0;
    char** argv;
    argv = new char*[size];

    Act(argc, argv);

    Assert("Argument 1 is not correct");
}

TEST_F(WagesAppTest, error_when_argv_2_is_null) {
    const int size = 6;
    int argc = 1;
    char** argv;
    argv = new char*[size];

    Act(argc, argv);

    Assert("Argument 2 is not correct");
}

TEST_F(WagesAppTest, error_when_argv_3_is_null) {
    const int size = 6;
    int argc = 2;
    char** argv;
    argv = new char*[size];

    Act(argc, argv);

    Assert("Argument 3 is not correct");
}

TEST_F(WagesAppTest, error_when_argv_4_is_null) {
    const int size = 6;
    int argc = 3;
    char** argv;
    argv = new char*[size];

    Act(argc, argv);

    Assert("Argument 4 is not correct");
}

TEST_F(WagesAppTest, error_when_argv_5_is_null) {
    const int size = 6;
    int argc = 4;
    char** argv;
    argv = new char*[size];

    Act(argc, argv);

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
    char** argv = new char*[argc];
    argv[1] = const_cast<char*>("CalculateWages");
    argv[2] = const_cast<char*>("10000");
    argv[3] = const_cast<char*>("1");
    argv[4] = const_cast<char*>("1");
    argv[5] = const_cast<char*>("1");

    app(argc, argv);

    argv[1] = const_cast<char*>("HourlyPay");
    app(argc, argv);

    argv[1] = const_cast<char*>("CalculationOvertimePayment");
    app(argc, argv);

    argv[1] = const_cast<char*>("CalculationWagesWithoutOvertime");
    app(argc, argv);

    ASSERT_NO_THROW(app.GetCalculatedValues());
}
