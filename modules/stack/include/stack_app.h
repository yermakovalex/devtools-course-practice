// Copyright 2018 Volkov Daniel

#ifndef MODULES_HYPOTHEC_CALCULATOR_INCLUDE_HYPOTHEC_CALCULATOR_APP_H_
#define MODULES_STACK_INCLUDE_HYPOTHEC_CALCULATOR_APP_H_
#include <string>

class StackApp {
 public:
    StackApp();
    std::string operator()(int argc, const char** argv);

 private:
    void help(const char* appname, const char* message = "");
    bool validateNumberOfArguments(int argc, const char** argv);
    std::string message_;
};

#endif  // MODULES_STACK_INCLUDE_HYPOTHEC_CALCULATOR_APP_H_
