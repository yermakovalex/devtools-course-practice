// Copyright 2017 Churakov Sergey

#include <stdlib.h>
#include <stdio.h>
#include <string>

#include "include/RBTreeApplication.h"

int main(int argc, const char** argv) {
    RBTree_application app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}
