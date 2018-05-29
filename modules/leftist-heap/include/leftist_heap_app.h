// Copyright 2018 Okunev Boris

#ifndef MODULES_LEFTIST_HEAP_INCLUDE_LEFTIST_HEAP_APP_H_
#define MODULES_LEFTIST_HEAP_INCLUDE_LEFTIST_HEAP_APP_H_

#include <string>
#include <vector>

#include "leftist_heap.h"

using std::string;

class LeftistHeapApp {
public:
    LeftistHeapApp();
    string operator()(int argc, const char** argv);

private:
    void help(const char* appname, const char* message = "");
    bool validateArguments(int argc, const char** argv);
    void parseArguments(int argc, const char** argv);
    void parseOperation(char* op);
    void parseHeap(char* heap);
    string message_;
    typedef struct {
        leftist_heap heapOne;
        leftist_heap heapTwo;
        string operation;
    } Arguments;
};

#endif  // MODULES_LEFTIST_HEAP_INCLUDE_LEFTIST_HEAP_APP_H_
