// Copyright 2018 Shkenev Petr

#include <gtest/gtest.h>

#include <string>
#include <sstream>
#include <vector>

#include "include/numeral-system-app.h"

using ::testing::internal::RE;
using std::vector;
using std::string;

class NumeralSystemAppTest : public ::testing::Test {
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
    NumeralSystemApp app_;
    string output_;
};

TEST_F(NumeralSystemAppTest, Do_Print_Help_Without_Arguments) {
    string args("");

    Act(args);

    Assert("    This calculator works with different numeral systems*");
}

TEST_F(NumeralSystemAppTest, Parse_Number) {
    string args("030");

    Act(args);

    Assert("Binary: 11000*");  // 24
}

TEST_F(NumeralSystemAppTest, Calculate_Binary) {
    string args("1110011101001 + 101000001111");

    Act(args);

    Assert("Binary: 10011011111000*");  // 9976
}

TEST_F(NumeralSystemAppTest, Calculate_Octal) {
    string args("016351 + 05017");

    Act(args);

    Assert("Binary: 10011011111000*");  // 9976
}

TEST_F(NumeralSystemAppTest, Calculate_Hexadecimal) {
    string args("0x1CE9 + 0xA0F");

    Act(args);

    Assert("Binary: 10011011111000*");  // 9976
}

TEST_F(NumeralSystemAppTest, Calculate_Different_Radices) {
    string args("101 + 017 + 0xF");

    Act(args);

    Assert("Binary: 100011");  // 35
}

TEST_F(NumeralSystemAppTest, Parse_Zero) {
    string args("0 + 1 + 01 + 0 + 0xF + 0");

    Act(args);

    Assert("Binary: 10001");  // 17
}

TEST_F(NumeralSystemAppTest, Different_Operators) {
    string args("101 + 017 - 0xF * 10 / 05");

    Act(args);

    Assert("Binary: 1110");  // 14
}

TEST_F(NumeralSystemAppTest, Parentheses) {
    string args("040 - (101 + 017 - 0xF) * 10 / 05");

    Act(args);

    Assert("Binary: 11110");  // 30
}

TEST_F(NumeralSystemAppTest, Parentheses_Nested) {
    string args("040 - (101 + (017 - 0xF) * 10) / 05");

    Act(args);

    Assert("Binary: 11111");  // 31
}

TEST_F(NumeralSystemAppTest, Invalid_Operator) {
    string args("016351 + 05017 % 0x1");

    Act(args);

    Assert("    This calculator works with different numeral systems*");
}

TEST_F(NumeralSystemAppTest, Division_By_Zero) {
    string args("016351 + 05017 / 0x0");

    Act(args);

    Assert("    This calculator works with different numeral systems*");
}
