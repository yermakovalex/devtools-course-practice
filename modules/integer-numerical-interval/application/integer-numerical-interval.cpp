// Copyright 2018 Gribov Pavel

#include <stdio.h>
#include <string>

#include "include/numerical_interval_calculator.h"

int main(int argc, const char** argv) {
    NumericalIntervalCalculator app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}
