// Copyright 2018 Gribov Pavel

#ifndef MODULES_INTEGER_NUMERICAL_INTERVAL_INCLUDE_NUMERICAL_INTERVAL_CALCULATOR_H_
#define MODULES_INTEGER_NUMERICAL_INTERVAL_INCLUDE_NUMERICAL_INTERVAL_CALCULATOR_H_

#include <string>

class NumericalIntervalCalculator {
 public:
    NumericalIntervalCalculator();
    std::string operator()(int argc, const char** argv);

 private:
    typedef struct {
        char left_border;
        char right_border;
        int first_num;
        int second_num;
        char comma;
    } Arguments;
    void help(const char* appname, const char* message = "");
    bool validateNumberOfArguments(int argc, const char** argv);
    std::string message_;
    bool parseArguments(int argc, const char** argv, Arguments& parsed_args);
};

#endif  // MODULES_INTEGER_NUMERICAL_INTERVAL_INCLUDE_NUMERICAL_INTERVAL_CALCULATOR_H_