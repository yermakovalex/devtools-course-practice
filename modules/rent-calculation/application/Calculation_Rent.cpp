// Copyright 2018 Lenkin Slava

#include <cstdlib>
#include <cstdio>
#include <string>

#include "include/Calculation_Rent_App.h"

int main(int argc, const char** argv) {
    Calculation_Rent_App app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}
