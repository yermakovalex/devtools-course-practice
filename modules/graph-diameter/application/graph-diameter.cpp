// Copyright 2018 Makarin Kirill

#include <stdlib.h>
#include <stdio.h>
#include <string>

#include "include/graph-diameter-app.h"

int main(int argc, const char** argv) {
    GraphDiameterApp app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}
