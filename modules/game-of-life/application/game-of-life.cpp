// Copyright 2018 Senina Anastasia

#include <stdlib.h>
#include <stdio.h>
#include <string>

#include "include/game-of-life-app.h"

int main(int argc, const char** argv) {
    GameOfLife app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}
