// Copyright 2018 Chernenko Valery

#include <stdlib.h>
#include <stdio.h>
#include <string>

#include "include/Investor.h"

int main(int argc, const char** argv) {
    Investor app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}
