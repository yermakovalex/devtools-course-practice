// Copyright 2018 Yermakov Alexey

#include <iostream>
#include <string>

#include "include/bisymmetric-matrix-app.h"

int main(int argc, const char *argv[]) {
    BisymmetricMatrixApp app;
    std::string output = app(argc, argv);
    std::cout << output;
    return 0;
}
