// Copyright 2018 Shurygin Dmitriy

#include <stdlib.h>
#include <stdio.h>
#include <string>

#include "include/fractional_calculator.h"
#include "include/Fractional_app.h"

int main(int argc, const char** argv) {
    // FractionalCalculator app;
    Fractional_app app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}
