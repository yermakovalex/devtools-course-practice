// Copyright 2018 Aglikov Ilya

#ifndef MODULES_QUEUE_INCLUDE_QUEUE_H_
#define MODULES_QUEUE_INCLUDE_QUEUE_H_

#include <string>

class QueueApp {
 public:
    QueueApp();
    std::string operator()(int argc, const char** argv);

 private:
    void help(const char* appname, const char* message = "");
    bool validateNumberOfArguments(int argc, const char** argv);
    std::string message_;
    typedef struct {
        unsigned int clocks;
        unsigned int capacity;  // queue capacity
        double jobIntens;  // intensity of arrivals of tasks
        double procRate;  // processor performance
    } Arguments;
};

#endif  // MODULES_QUEUE_INCLUDE_QUEUE_H_
