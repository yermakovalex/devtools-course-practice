// Copyright 2018 Makarin Kirill

#ifndef MODULES_GRAPH_DIAMETER_INCLUDE_GRAPH_DIAMETER_APP_H_
#define MODULES_GRAPH_DIAMETER_INCLUDE_GRAPH_DIAMETER_APP_H_

#include <string>

class GraphDiameterApp {
 public:
    GraphDiameterApp();
    std::string operator()(int argc, const char** argv);

 private:
    void help(const char* appname, const char* message = "");
    bool validateNumberOfArguments(int argc, const char** argv);
    std::string message_;
    typedef struct {
        int size;
        int **matrix;
    } Arguments;
};

#endif  // MODULES_GRAPH_DIAMETER_INCLUDE_GRAPH_DIAMETER_APP_H_
