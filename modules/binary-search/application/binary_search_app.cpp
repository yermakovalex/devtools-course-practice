// Copyright 2018 Gorelova Ksenia

#include <string>

#include "include/binary_search_app.h"

int main(int argc, const char** argv) {
    BinarySearchApp app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}
