// Copyright 2018 Bogatova Margarita

#include "include/Graph.h"
#include "include/dijkstra_algorithm_app.h"

#include <iostream>
#include <exception>
#include <cstdlib>
#include <string>
#include <sstream>

DijkstraAlgorithmApp::DijkstraAlgorithmApp() : message_("") {}

void DijkstraAlgorithmApp::help(const char* appname, const char* message) {
    message_ =
        std::string(message) +
        "This is a dijkstra algorithm application.\n\n" +
        "Please provide arguments in the following format:\n\n" +

        "  $ " + appname + " <size of adjacency matrix> " +
        " <adjacency matrix> " + " <initial vertex> " + " <final vertex>\n\n" +

        "Where the first argument is non-negative integer, " +
        "adjacency matrix is a sequence of non-negative double, " +
        "their number is <size matrix>*<size matrix>, " +
        "last two arguments are non-negative integer and " +
        "their values range from 1 to <size matrix>\n";
}

bool DijkstraAlgorithmApp::
validateNumberOfArguments(int argc, const char** argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    } else if (argc != (4 + atoi(argv[1])*atoi(argv[1]))) {
        help(argv[0],
            "ERROR: Should be 3 + <size matrix>*<size matrix> arguments\n\n");
        return false;
    }
    return true;
}

int parseInt(const char* arg) {
    std::size_t pos;
    int value = std::stoi(std::string(arg), &pos);

    if (pos == 0)
        throw std::string("Wrong number format!");

    return value;
}

double parseDouble(const char* arg) {
    char* end;
    double value = strtod(arg, &end);

    if (end[0])
        throw std::string("Wrong number format!");

    return value;
}

std::string DijkstraAlgorithmApp::operator()(int argc, const char** argv) {
    Arguments args;

    if (!validateNumberOfArguments(argc, argv)) {
        return message_;
    }
    try {
        args.n = parseInt(argv[1]);
        for (int i = 0; i < args.n; ++i)
            for (int j = 0; j < args.n; ++j)
                args.graph_matrix[i][j] = parseDouble(argv[i*args.n + j + 2]);
        args.start = parseInt(argv[args.n*args.n + 2]);
        args.finish = parseInt(argv[args.n*args.n + 3]);
    }
    catch (std::string& str) {
        return str;
    }

    try {
        Graph graph(args.n, args.graph_matrix);

        std::ostringstream stream;
        stream << "Graph: " << std::endl;
        for (int i = 0; i < args.n; ++i) {
            for (int j = 0; j < args.n; ++j)
                stream << args.graph_matrix[i][j] << " ";
            stream << std::endl;
        }

        stream << "The shortest path from vertex " << args.start;
        stream << " to vertex " << args.finish << " is ";
        stream << graph.FindDistance(args.start, args.finish) << std::endl;

        return message_;
    }
    catch (std::exception& exc) {
        return std::string(exc.what());
    }
}
