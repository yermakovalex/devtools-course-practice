// Copyright 2018 Kozorez Alexandr

#include <stdio.h>
#include <string>

#include "include/Books-app.h"

int main(int argc, const char**argv) {
    BooksApplication app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}
