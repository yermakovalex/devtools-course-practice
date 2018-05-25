// Copyright 2018 Bogatova Margarita

#include "include\dijkstra_algorithm_app.h"

#include <iostream>
#include <string>

int main(int argc, const char** argv) {
    DijkstraAlgorithmApp app;
    std::string output = app(argc, argv);
    std::cout<< output.c_str() <<std::endl;
    return 0;
}
