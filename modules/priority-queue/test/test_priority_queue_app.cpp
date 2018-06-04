// Copyright 2018 Mezina Margarita

#include <gtest/gtest.h>
#include <iostream>
#include <exception>
#include <cstdlib>
#include <string>
#include <sstream>
#include <vector>
#include "include/priority_queue.h"
#include "include/priority_queue_app.h"

using ::testing::internal::RE;
using std::vector;
using std::string;

class PriorityQueueAppTest : public ::testing::Test {
 protected:
    void Act(vector<string> args_) {
        vector<const char*> options;
        options.push_back("appname");
        for (size_t i = 0; i < args_.size(); ++i)
            options.push_back(args_[i].c_str());
        const char** argv = &options.front();
        int argc = static_cast<int>(args_.size()) + 1;
        output_ = app_(argc, argv);
    }
    void Assert(std::string expected) {
        EXPECT_TRUE(RE::PartialMatch(output_, RE(expected)));
    }
 private:
    PriorityQueueApp app_;
    string output_;
};

TEST_F(PriorityQueueAppTest, do_print_help_without_arguments) {
    // Arrange
    vector<string> args = {};

    // Act
    Act(args);

    // Assert
    Assert("This is a priority queue application\\..*");
}

TEST_F(PriorityQueueAppTest, do_error_if_lenght_name_more_20) {
    // Arrange
    vector<string> args = { "1", "abcdefghijklmnopqrstuvwxyz", "1", "1", "1"};

    // Act
    Act(args);

    // Assert
    Assert("ERROR: Lenght names should be less then 20.*");
}


TEST_F(PriorityQueueAppTest, do_error_if_too_few_arguments) {
    // Arrange
    vector<string> args = { "1", "2" };

    // Act
    Act(args);

    // Assert
    Assert("ERROR: Should be 2 +.*");
}

TEST_F(PriorityQueueAppTest, do_error_out_of_range) {
    // Arrange
    vector<string> args = { "1", "abc", "1", "gg", "1" };

    // Act
    Act(args);

    // Assert
    Assert("Wrong format integer number or out of range\n");
}

TEST_F(PriorityQueueAppTest, do_error_if_negative_priority) {
    // Arrange
    vector<string> args = { "1", "abc", "-1", "1", "1" };

    // Act
    Act(args);

    // Assert
    Assert("Priority is negstive");
}

TEST_F(PriorityQueueAppTest, do_work) {
    // Arrange
    vector<string> args = { "1", "abc", "1", "1", "1" };

    // Act
    Act(args);

    // Assert
    Assert("Priority Queue:.*");
}

TEST_F(PriorityQueueAppTest, do_correct_work) {
    // Arrange
    vector<string> args = { "1", "abc", "1", "1", "1" };

    // Act
    Act(args);

    // Assert
    Assert(std::string("Priority Queue:\n") +
        "1\tGo: abc\n" +
        "\tWork: abc - finished\n" +
        "Finish!\n");
}

TEST_F(PriorityQueueAppTest, do_complete_work) {
    // Arrange
    vector<string> args = { "3",
            "A", "B", "C",
            "1", "2", "3",
            "2", "2", "3",
            "1", "1", "1"};

    // Act
    Act(args);

    // Assert
    Assert(std::string("Priority Queue:\n") +
        "1\tNot work\n" +
        "2\tGo: A B\n" +
        "\tWork: B - finished\n" +
        "3\tGo: C\n" +
        "\tWork: C - finished\n" +
        "4\tWork: A - finished\n" +
        "Finish!\n");
}

TEST_F(PriorityQueueAppTest, do_long_work) {
    // Arrange
    vector<string> args = { "3",
        "A", "B", "C",
        "1", "2", "3",
        "2", "2", "3",
        "2", "1", "1" };

    // Act
    Act(args);

    // Assert
    Assert(std::string("Priority Queue:\n") +
        "1\tNot work\n" +
        "2\tGo: A B\n" +
        "\tWork: B - finished\n" +
        "3\tGo: C\n" +
        "\tWork: C - finished\n" +
        "4\tWork: A\n" +
        "5\tWork: A - finished\n" +
        "Finish!\n");
}
