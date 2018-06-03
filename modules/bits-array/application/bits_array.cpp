// Copyright 2018 Kiselev Denis

#include <stdlib.h>
#include <stdio.h>
#include <string>

#include "include/bits_calculator.h"

int main(int argc, const char** argv) {
    BitsCalculator app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}
