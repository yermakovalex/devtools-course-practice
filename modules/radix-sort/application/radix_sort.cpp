// Copyright 2018 Panov Aleksander

#include <stdlib.h>
#include <stdio.h>
#include <string>

#include "include/radix_sort_app.hpp"

int main(int argc, const char** argv) {
    IntegerArray app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}
