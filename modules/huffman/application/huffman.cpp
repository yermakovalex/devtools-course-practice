// Copyright 2018 Gracheva Elena

#include <stdlib.h>
#include <stdio.h>
#include <string>

#include "include/huffman_calculator.h"

int main(int argc, const char** argv) {
    HuffmanCalculator app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}
