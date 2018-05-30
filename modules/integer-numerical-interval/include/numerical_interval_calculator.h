// Copyright 2018 Gribov Pavel

#ifndef MODULES_INTEGER_NUMERICAL_INTERVAL_INCLUDE_NUMERICAL_INTERVAL_CALCULATOR_H_
#define MODULES_INTEGER_NUMERICAL_INTERVAL_INCLUDE_NUMERICAL_INTERVAL_CALCULATOR_H_

#include <string>
#include <vector>

#include "include/integer_numerical_interval.h"

class NumericalIntervalCalculator {
 public:
    NumericalIntervalCalculator();
    std::string operator()(int argc, const char** argv);

 private:
    enum Operation {
        ep, ap, pc, ro, rc, no_op
    };
    typedef struct {
        IntegerNumericalInterval interval1;
        IntegerNumericalInterval interval2;
        Operation type_of_operation;
        std::vector<int> numbers;
    } Arguments;
    void help(const char* appname, const char* message = "");
    bool validateNumberOfArguments(int argc, const char** argv);
    std::string message_;
    bool parseArguments(int argc, const char** argv, Arguments* parsed_args);
};

#endif  // MODULES_INTEGER_NUMERICAL_INTERVAL_INCLUDE_NUMERICAL_INTERVAL_CALCULATOR_H_
