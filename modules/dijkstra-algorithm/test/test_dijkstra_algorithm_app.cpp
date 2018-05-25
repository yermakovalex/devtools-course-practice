// Copyright 2018 Bogatova Margarita

#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "include/dijkstra_algorithm_app.h"

using ::testing::internal::RE;
using std::vector;
using std::string;

class DijkstraAlgorithmAppTest : public ::testing::Test {
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
    DijkstraAlgorithmApp app_;
    string output_;
};

TEST_F(DijkstraAlgorithmAppTest, do_print_help_without_arguments) {
    vector<string> args = {};

    Act(args);

    Assert("This is a dijkstra algorithm application\\..*");
}

TEST_F(DijkstraAlgorithmAppTest, is_checking_number_of_arguments) {
    vector<string> args = { "1", "2" };

    Act(args);

    Assert("ERROR: Should be 3 +.*");
}

TEST_F(DijkstraAlgorithmAppTest, can_detect_wrong_matrix_format) {
    vector<string> args = { "4",
        "pi", "8", "4", "0",
        "8", "0", "9", "6",
        "4", "9", "0", "1",
        "0", "6", "1", "0",
        "1", "4" };

    Act(args);

    Assert("Wrong number format!.*");
}

TEST_F(DijkstraAlgorithmAppTest, can_detect_wrong_start_vertex_format) {
    vector<string> args = { "4",
        "0", "8", "4", "0",
        "8", "0", "9", "6",
        "4", "9", "0", "1",
        "0", "6", "1", "0",
        "gg", "4" };

    Act(args);

    Assert("Wrong format integer number or out of range");
}

TEST_F(DijkstraAlgorithmAppTest, can_detect_longer_start_vertex_format) {
    vector<string> args = { "4",
        "0", "8", "4", "0",
        "8", "0", "9", "6",
        "4", "9", "0", "1",
        "0", "6", "1", "0",
        "4949449494494", "4" };

    Act(args);

    Assert("Wrong format integer number or out of range");
}

TEST_F(DijkstraAlgorithmAppTest, can_find_distantion) {
    vector<string> args = { "4",
        "0", "8", "4", "0",
        "8", "0", "9", "6",
        "4", "9", "0", "1",
        "0", "6", "1", "0",
        "1", "4" };

    Act(args);

    Assert("The shortest path from vertex 1 to vertex 4 is 5.*");
}

TEST_F(DijkstraAlgorithmAppTest, can_detect_zero_start_vertex) {
    vector<string> args = { "4",
        "0", "8", "4", "0",
        "8", "0", "9", "6",
        "4", "9", "0", "1",
        "0", "6", "1", "0",
        "0", "4" };

    Act(args);

    Assert("Non_exist_vertex.*");
}

TEST_F(DijkstraAlgorithmAppTest, can_detect_longer_finish_vertex) {
    vector<string> args = { "4",
        "0", "8", "4", "0",
        "8", "0", "9", "6",
        "4", "9", "0", "1",
        "0", "6", "1", "0",
        "1", "9" };

    Act(args);

    Assert("Non_exist_vertex.*");
}

TEST_F(DijkstraAlgorithmAppTest, can_detect_negative_wieght_of_vertex) {
    vector<string> args = { "4",
        "0", "-8", "4", "0",
        "8", "0", "9", "6",
        "4", "9", "0", "1",
        "0", "6", "1", "0",
        "1", "9" };

    Act(args);

    Assert("Negative_weight.*");
}
