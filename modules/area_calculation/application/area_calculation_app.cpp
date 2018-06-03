// Copyright 2018 Gusev Alexandr

#include <stdlib.h>
#include <stdio.h>
#include <string>

#include "include/area_calculation_app.h"

int main(int argc, const char** argv) {
    AreaCalculationApp app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}
