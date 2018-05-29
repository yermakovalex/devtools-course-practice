// Copyright 2018 Chvanov Leonid

#include <stdlib.h>
#include <stdio.h>
#include <string>

#include "include/length_converter_app.h"

int main(int argc, const char** argv) {
    LengthConverterApp app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}

