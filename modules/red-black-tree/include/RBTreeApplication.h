// Copyright 2018 Churakov Sergey

#ifndef MODULES_RBTREE_INCLUDE_RBTREE_APPLICATION_H_
#define MODULES_RBTREE_INCLUDE_RBTREE_APPLICATION_H_

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

#endif  // MODULES_RBTREE_INCLUDE_RBTREE_APPLICATION_H_
