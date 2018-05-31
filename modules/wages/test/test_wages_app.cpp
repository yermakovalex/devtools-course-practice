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
