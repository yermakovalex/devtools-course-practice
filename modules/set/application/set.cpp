// Copyright 2018 Generalov Aleksandr

#include <stdlib.h>
#include <stdio.h>
#include <string>

#include "include/set_calculator.h"

int main(int argc, const char** argv) {
    SetCalculator app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}
