// Copyright 2018 Mezina Margarita

#ifndef MODULES_PRIORITY_QUEUE_INCLUDE_PRIORITY_QUEUE_APP_H_
#define MODULES_PRIORITY_QUEUE_INCLUDE_PRIORITY_QUEUE_APP_H_

#include <string>

class PriorityQueueApp {
 public:
    PriorityQueueApp();
    std::string operator()(int argc, const char** argv);
 private:
    void help(const char* appname, const char* message = "");
    bool validateNumberOfArguments(int argc, const char** argv);
    std::string message_;
    typedef struct {
        int n;
        std::string* element_names;
        int* element_priority;
        int* element_time_start;
        int* element_time_work;
    } Arguments;
};

#endif  // MODULES_PRIORITY_QUEUE_INCLUDE_PRIORITY_QUEUE_APP_H_
