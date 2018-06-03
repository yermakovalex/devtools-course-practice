// Copyright 2018 Kiselev Denis

#ifndef MODULES_BITS_ARRAY_INCLUDE_BITS_CALCULATOR_H_
#define MODULES_BITS_ARRAY_INCLUDE_BITS_CALCULATOR_H_

#include <string>

#include "include/bits_array.h"

class BitsCalculator {
 public:
    BitsCalculator();
    std::string operator()(int argc, const char** argv);

 private:
    void help(const char* appname, const char* message = "");
    bool validateNumberOfArguments(int argc, const char** argv);
    std::string message_;
    typedef struct {
        BitsArray* bits_first;
        BitsArray* bits_second;
        char operation;
    } Arguments;
};

#endif  // MODULES_BITS_ARRAY_INCLUDE_BITS_CALCULATOR_H_
