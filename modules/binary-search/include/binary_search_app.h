// Copyright 2018 Gorelova Ksenia

#ifndef MODULES_BINARY_SEARCH_INCLUDE_BINARY_SEARCH_APP_H_
#define MODULES_BINARY_SEARCH_INCLUDE_BINARY_SEARCH_APP_H_

#include <string>

class BinarySearchApp {
 public:
    BinarySearchApp();
    std::string operator()(int argc, const char** argv);

 private:
    void help(const char* appname, const char* message = "");
    bool validateNumberOfArguments(int argc, const char** argv);
    std::string message_;
    typedef struct {
        int num;
        int elem;
        int* mas;
    } Arguments;
};

#endif  // MODULES_BINARY_SEARCH_INCLUDE_BINARY_SEARCH_APP_H_
