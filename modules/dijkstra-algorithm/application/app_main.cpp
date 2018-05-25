// Copyright 2018 Bogatova Margarita

#include "include\dijkstra_algorithm_app.h"

#include <stdio.h>
#include <string>

int main(int argc, const char** argv) {
    DijkstraAlgorithmApp app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}
