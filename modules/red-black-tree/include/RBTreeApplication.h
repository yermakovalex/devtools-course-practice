// Copyright 2018 Churakov Sergey

#ifndef MODULES_RED_BLACK_TREE_INCLUDE_RBTREEAPPLICATION_H_
#define MODULES_RED_BLACK_TREE_INCLUDE_RBTREEAPPLICATION_H_

#include <string>

class RBTree_application {
 public:
    RBTree_application();
    std::string operator()(int argc, const char** argv);

 private:
    void help(const char* appname, const char* message = "");
    bool validateNumberOfArguments(int argc, const char** argv);
    std::string message_;
    typedef struct {
        int key;
        char operation;
    } Arguments;
};

#endif  // MODULES_RED_BLACK_TREE_INCLUDE_RBTREEAPPLICATION_H_
