// Copyright 2018 Kulikova Svetlana

#ifndef MODULES_NUMERICAL_INTEGRATION_INCLUDE_NUMERICAL_INTEGRATION_APP_H_
#define MODULES_NUMERICAL_INTEGRATION_INCLUDE_NUMERICAL_INTEGRATION_APP_H_

#include <string>

class IntegralApp {
 public:
    IntegralApp();
    std::string operator()(int argc, const char** argv);

 private:
    void Help(const char* appname, const char* message = "");
    bool ValidateNumberOfArguments(int argc, const char** argv);
    std::string message_;
    typedef struct {
        double low;
        double up;
        int N;
        int Method;
    } Arguments;
};

#endif  // MODULES_NUMERICAL_INTEGRATION_INCLUDE_NUMERICAL_INTEGRATION_APP_H_
