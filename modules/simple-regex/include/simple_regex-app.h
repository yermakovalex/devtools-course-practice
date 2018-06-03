// Copyright 2018 Vyunov Roman

#ifndef MODULES_SIMPLE_REGEX_INCLUDE_SIMPLE_REGEX_APP_H_
#define MODULES_SIMPLE_REGEX_INCLUDE_SIMPLE_REGEX_APP_H_

#include <string>

class Application {
 public:
    Application();
    std::string operator()(int argc, const char** argv);

 private:
    void help(const char* appname, const char* message = "");
    bool validateNumberOfArguments(int argc, const char** argv);
    std::string message_;
    typedef struct {
        char mode;
        std::string target;
        std::string regex;
    } Arguments;
};

#endif  // MODULES_SIMPLE_REGEX_INCLUDE_SIMPLE_REGEX_APP_H_
