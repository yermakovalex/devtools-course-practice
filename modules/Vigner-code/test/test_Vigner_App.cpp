// Copyright 2018 Dvorjanchikov Evginiy

#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "include/Vigner_App.h"

using ::testing::internal::RE;
using std::vector;
using std::string;

class VignerAppTest : public ::testing::Test {
 protected:
    void Act(vector<string> _args) {
       vector<const char*> args;

        args.push_back("appname");
        for (size_t i = 0; i < _args.size(); ++i) {
             args.push_back(_args[i].c_str());
        }
        const char** argv = &args.front();

        int argc = static_cast<int>(_args.size()) + 1;

        msg_out = app(argc, argv);
    }

    void Assert(std::string expected) {
        EXPECT_TRUE(RE::PartialMatch(msg_out, RE(expected)));
    }

 private:
    VignerApp app;
    string msg_out;
};

TEST_F(VignerAppTest, No_Arguments_Test) {
    vector<string> args = {};

    Act(args);

    Assert("This is a Vigner code  application\\..*");
}

TEST_F(VignerAppTest, Is_Checking_Number_Of_Arguments_1) {
    vector<string> args = { "1", "2" };

    Act(args);

    Assert("ERROR: Should be 3 arguments\\..*");
}

TEST_F(VignerAppTest, Is_Checking_Number_Of_Arguments_2) {
    vector<string> args = { "-b", "hello", "key"};

    Act(args);

    Assert("Wrong param format");
}

TEST_F(VignerAppTest, Checking_1) {
    vector<string> args = { "-d", "hello", "sky" };

    Act(args);

    Assert("Decode message = OTMSd");
}

TEST_F(VignerAppTest, Checking_2) {
    vector<string> args = { "-e", "OTMSd", "sky" };

    Act(args);

    Assert("Encode message = hello");
}
