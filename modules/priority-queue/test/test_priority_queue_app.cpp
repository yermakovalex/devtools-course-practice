// Copyright 2018 Mezina Margarita

#include <gtest/gtest.h>
#include <iostream>
#include <exception>
#include <cstdlib>
#include <string>
#include <sstream>
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

TEST_F(PriorityQueueAppTest, do_error_if_too_few_arguments) {
    // Arrange
    vector<string> args = {"1", "2"};

    // Act
    Act(args);

    // Assert
    Assert("ERROR: Should be 2 +.*");
}

TEST_F(PriorityQueueAppTest, do_error_if_lenght_name_more_20) {
    // Arrange
    vector<string> args = { "1", "abcdefghijklmnopqrstuvwxyz", "1", "1", "1"};

    // Act
    Act(args);

    // Assert
    Assert("ERROR: Lenght names should be less then 20.*");
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
        "In moment 1\n" +
        "\tabc go into queue\n" +
        "\tabc is working\n" +
        "\tabc finished\n" +
        "Finish!\n");
}

TEST_F(PriorityQueueAppTest, complete_work) {
    // Arrange
    vector<string> args = { "4", 
        "Music", "Video", "Imagine", "Game",
        "2",     "9",     "5",       "1",
        "7",     "5",     "2",       "2",
        "2",     "2",     "4",       "3"};

    // Act
    Act(args);

    // Assert
    Assert(std::string("Priority Queue:\n") +
        "In moment 1\n" +
        "\tNot working element\n" +
        "In moment 2\n" +
        "\tImagine go into queue\n" +
        "\tGame go into queue\n" +
        "\tImagine is working\n" +
        "In moment 3\n" +
        "\tImagine is working\n" +
        "In moment 4\n" +
        "\tImagine is working\n" +
        "In moment 5\n" +
        "\tVideo go into queue\n" +
        "\tImagine is working\n" +
        "\tImagine finished\n" +
        "In moment 6\n" +
        "\tVideo is working\n" +
        "In moment 7\n" +
        "\tMusic go into queue\n" +
        "\tVideo is working\n" +
        "\tVideo finished\n" +
        "In moment 8\n" +
        "\tMusic is working\n" +
        "In moment 9\n" +
        "\tMusic is working\n" +
        "\tMusic finished\n" +
        "In moment 10\n" +
        "\tGame is working\n" +
        "In moment 11\n" +
        "\tGame is working\n" +
        "In moment 12\n" +
        "\tGame is working\n" +
        "\tGame finished\n" +
        "Finish!\n");
}