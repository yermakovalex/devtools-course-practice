// Copyright 2018 Okunev Boris

#ifndef MODULES_LEFTIST_HEAP_INCLUDE_LEFTIST_HEAP_APP_H_
#define MODULES_LEFTIST_HEAP_INCLUDE_LEFTIST_HEAP_APP_H_

#include <string>
#include <vector>

using std::string;
using std::vector;

class LeftistHeapApp {
public:
    LeftistHeapApp();
    string operator()(int argc, const char** argv);

private:
    void help(const char* appname, const char* message = "");
    bool validateArguments(int argc, const char** argv);
    void parseArguments(int argc, const char** argv);
    string message_;
    typedef struct {
        vector<int> heapOne;
        vector<int> heapTwo;
        string operation;
    } Arguments;
};

#endif  // MODULES_LEFTIST_HEAP_INCLUDE_LEFTIST_HEAP_APP_H_
