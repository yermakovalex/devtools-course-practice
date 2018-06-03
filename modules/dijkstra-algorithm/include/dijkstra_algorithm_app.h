// Copyright 2018 Bogatova Margarita

#ifndef MODULES_DIJKSTRA_ALGORITHM_INCLUDE_DIJKSTRA_ALGORITHM_APP_H_
#define MODULES_DIJKSTRA_ALGORITHM_INCLUDE_DIJKSTRA_ALGORITHM_APP_H_

#include <string>

class DijkstraAlgorithmApp {
 public:
    DijkstraAlgorithmApp();
    std::string operator()(int argc, const char** argv);

 private:
    void help(const char* appname, const char* message = "");
    bool validateNumberOfArguments(int argc, const char** argv);
    std::string message_;
    typedef struct {
        int n;
        double **graph_matrix;
        int start;
        int finish;
    } Arguments;
};

#endif  // MODULES_DIJKSTRA_ALGORITHM_INCLUDE_DIJKSTRA_ALGORITHM_APP_H_
