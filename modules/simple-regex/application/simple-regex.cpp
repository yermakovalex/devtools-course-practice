// Copyright 2018 Vyunov Roman

#include <stdlib.h>
#include <stdio.h>
#include <string>

#include "include/simple_regex-app.h"

int main(int argc, const char** argv) {
    Application app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}
