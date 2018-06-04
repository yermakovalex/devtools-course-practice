// Copyright 2018 Yermakov Alexey

#include <gtest/gtest.h>

#include <string>
#include <sstream>
#include <vector>
#include <cstdio>
#include <unistd.h>

#include "include/bisymmetric-matrix-app.h"

using ::testing::internal::RE;
using std::vector;
using std::string;

const std::string path("../../../../../modules/bisymmetric-matrix/test/");

class BisymmetricMatrixAppTest : public ::testing::Test {
 protected:
    void Act(string args_) {
        vector<const char*> options;

        options.push_back("appname");

        string arg;
        vector<string> argsV;
        std::istringstream ss(args_);
        while (ss >> arg) {
            argsV.push_back(arg);
        }

        for (size_t i = 0; i < argsV.size(); ++i) {
            options.push_back(argsV[i].c_str());
        }

        const char** argv = &options.front();
        int argc = static_cast<int>(options.size());

        output_ = app_(argc, argv);
    }

    void Assert(string expected) {
        EXPECT_TRUE(RE::PartialMatch(output_, RE(expected)));
    }

 private:
    BisymmetricMatrixApp app_;
    string output_;
};

TEST_F(BisymmetricMatrixAppTest, Do_Print_Help_Without_Arguments) {
    string args("");

    char buf[255];
    getcwd(buf, sizeof(buf));
    printf("%s", buf);

    Act(args);

    Assert("    This is a bisymmetric matrix calculator application*");
}

TEST_F(BisymmetricMatrixAppTest, Can_Add) {
    string args(path + "matrix1.txt " + path + "matrix2.txt +");

    Act(args);

    Assert("3 4 8 14 18");
}

TEST_F(BisymmetricMatrixAppTest, Can_Substract) {
    string args(path + "matrix1.txt " + path + "matrix2.txt -");

    Act(args);

    Assert("-1 0 0 0 0");
}

TEST_F(BisymmetricMatrixAppTest, Can_Multiply) {
    string args(path + "matrix1.txt " + path + "matrix2.txt *");

    Act(args);

    Assert("2 4 8 14 18");
}

TEST_F(BisymmetricMatrixAppTest, Equal) {
    string args(path + "matrix1.txt " + path + "matrix1.txt =");

    Act(args);

    Assert("TRUE");
}

TEST_F(BisymmetricMatrixAppTest, Not_Equal) {
    string args(path + "matrix1.txt " + path + "matrix3.txt =");

    Act(args);

    Assert("FALSE");
}

TEST_F(BisymmetricMatrixAppTest, Invalid_File_1) {
    string args("ololo " + path + "matrix2.txt =");

    Act(args);

    Assert("Can not open");
}

TEST_F(BisymmetricMatrixAppTest, Invalid_File_2) {
    string args(path + "matrix1.txt " + "trololo =");

    Act(args);

    Assert("Can not open");
}

TEST_F(BisymmetricMatrixAppTest, Throw_On_Different_Sizes) {
    string args(path + "matrix1.txt " + path + "matrix3.txt +");

    Act(args);

    Assert("It is not possible to sum matrices with different sizes.");
}
