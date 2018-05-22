// Copyright 2017 Kulikova Svetlana

#include <stdlib.h>
#include <stdio.h>
#include <string>

#include "include/numerical-integration-app.h"

int main(int argc, const char** argv) {
    IntegralApp app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}
