// Copyright 2018 Ermachenko Boris

#ifndef MODULES_FRACTIONAL_NUMBER_INCLUDE_FRACTIONAL_APP_H_
#define MODULES_FRACTIONAL_NUMBER_INCLUDE_FRACTIONAL_APP_H_

#include <string>

class Fractional_app {
 public:
    Fractional_app();
    std::string operator()(int argc, const char** argv);
 private:
    void help_message(const char* message = "");
    double GetParam(const char* arg = "");
    char GetOperation(const char* arg);
    bool forArguments(int argc, const char** argv);
    std::string message_;
    typedef struct {
        double numerator1;
        double denominator1;
        char operation;
        double numerator2;
        double denominator2;
    } Arguments;
};

#endif  // MODULES_FRACTIONAL_NUMBER_INCLUDE_FRACTIONAL_APP_H_
