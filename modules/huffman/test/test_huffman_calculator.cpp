// Copyright 2018 Gracheva Elena

#include <gtest/gtest.h>

#include <string>
#include <map>
#include <utility>
#include <vector>

using ::testing::internal::RE;
using std::make_pair;
using std::pair;
using std::vector;
using std::string;

#include "include/huffman_calculator.h"

class HuffmanCalculatorTest : public ::testing::Test {
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

    void Assert(string expected) {
        EXPECT_TRUE(RE::PartialMatch(output_, RE(expected)));
    }

 private:
    HuffmanCalculator app_;
    string output_;
};

TEST_F(HuffmanCalculatorTest, Do_Print_Help_Without_Arguments) {
    //  Arrange
    vector<string> args = {};

    //  Act
    Act(args);

    //  Assert
    Assert("This is a huffman calculator application\\..*");
}

TEST_F(HuffmanCalculatorTest, Is_Checking_Number_Of_Arguments) {
    //  Arrange
    vector<string> args = { "text1", "text2" };

    //  Act
    Act(args);

    //  Assert
    Assert("ERROR: Should be 1 argument\\..*");
}

TEST_F(HuffmanCalculatorTest, Can_Encode_First_Symbol) {
    //  Arrange
    vector<string> args = { "AAAAAAABBBBBBBCCDDDCCDDDCCFFFFFAA" };

    //  Act
    Act(args);

    //  Assert
    Assert("\"A\" is encoded as \"10\"");
}

TEST_F(HuffmanCalculatorTest, Can_Encode_Not_First_Symbol) {
    //  Arrange
    vector<string> args = { "AAAAAAABBBBBBBCCDDDCCDDDCCFFFFFAA" };

    //  Act
    Act(args);

    //  Assert
    Assert("\"D\" is encoded as \"00\"");
}

TEST_F(HuffmanCalculatorTest, Can_Encode_Symbol) {
    //  Arrange
    vector<string> args = { "AAAABBB!CCC!@" };

    //  Act
    Act(args);

    //  Assert
    Assert("\"@\" is encoded as \"000\"");
}

TEST_F(HuffmanCalculatorTest, Can_Encode_If_Text_Has_Special_Symbols) {
    //  Arrange
    vector<string> args = { "\\\n\"\b" };

    //  Act
    Act(args);

    //  Assert
    Assert("\"\\\" is encoded as");
}
