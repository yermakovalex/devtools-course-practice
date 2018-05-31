// Copyright 2017 Mayachkin Arseny

#include <stdlib.h>
#include <stdio.h>
#include <string>

#include "include/heap.h"

int main(int argc, const char** argv) {
    ComplexCalculator app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}
