// Copyright 2018 Lipatov Igor

#ifndef MODULES_DHEAP_INCLUDE_DHEAP_APP_H_
#define MODULES_DHEAP_INCLUDE_DHEAP_APP_H_

#endif  // MODULES_DHEAP_INCLUDE_DHEAP_APP_H_

#include <string>

class MinSearcher{
 public:
    MinSearcher();
    ~MinSearcher();
    std::string operator()(int argc, const char** argv);
 private:
    void help(const char* appname, const char* message = "");
    bool validateNumberOfArguments(int argc, const char** argv);
    std::string message_;
};
