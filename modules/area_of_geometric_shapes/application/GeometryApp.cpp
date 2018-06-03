// Copyright 2018 Levitsky Ilya

#include <stdlib.h>
#include <stdio.h>
#include <string>

#include "include/GeometryT.h"

int main(int argc, const char** argv) {
    GeometryT app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}
