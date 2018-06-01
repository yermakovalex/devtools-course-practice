// Copyright 2018 Bogatova Margarita

#include <iostream>
#include <string>

#include "include/dijkstra_algorithm_app.h"

int main(int argc, const char** argv) {
    DijkstraAlgorithmApp app;
    std::string output = app(argc, argv);
    std::cout<< output.c_str() <<std::endl;
    return 0;
}
