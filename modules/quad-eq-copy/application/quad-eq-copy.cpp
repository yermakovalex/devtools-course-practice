// Copyright 2018 Romanov Alexander

#include <stdlib.h>
#include <stdio.h>
#include <string>

#include "include/quad_eq_copy_calc.h"

int main(int argc, const char** argv) {
    QuadEquatCalc app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}
