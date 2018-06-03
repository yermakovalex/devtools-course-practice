// Copyright 2018 Makarin Kirill

#include "include/graph-diameter.h"
#include "include/graph-diameter-app.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <string>
#include <sstream>

GraphDiameterApp::GraphDiameterApp() : message_("") {}

void GraphDiameterApp::help(const char* appname, const char* message) {
    message_ =
        std::string(message) +
        "This is a graph diameter application.\n\n" +
        "Please provide arguments in the following format:\n\n" +

        "  $ " + appname + " <size of adjacency matrix> " +
        " <adjacency matrix>\n\n" +

        "Where the first argument is non-negative integer, " +
        "adjacency matrix is a sequence of non-negative integers, " +
        "their number is <size matrix> * <size matrix>\n";
}

bool GraphDiameterApp::validateNumberOfArguments(int argc, const char** argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    } else if (argc != (2 + atoi(argv[1]) * atoi(argv[1]))) {
        help(argv[0],
            "ERROR: Should be 1 + <size matrix>*<size matrix> arguments.\n\n");
        return false;
    }
    return true;
}

int parseInt(const char* arg) {
    char* end;
    int value = strtod(arg, &end);

    if (end[0]) {
        throw std::string("Wrong number format!");
    }

    return value;
}

std::string GraphDiameterApp::operator()(int argc, const char** argv) {
    Arguments args;

    if (!validateNumberOfArguments(argc, argv)) {
        return message_;
    }
    try {
        args.size   = parseInt(argv[1]);
        args.matrix = new int*[args.size];
        for (int i = 0; i < args.size; i++) {
            args.matrix[i] = new int[args.size];
        }

        for (int i = 0; i < args.size; i++) {
            for (int j = 0; j < args.size; j++) {
                args.matrix[i][j] = parseInt(argv[i * args.size + j + 2]);
            }
        }
    }
    catch(std::string& str) {
        return str;
    }

    GraphDiameter graph(args.size, args.matrix);
    std::ostringstream stream;

    stream << "The diameter of graph with " << args.size
           << " vertexes is " << graph.GetDiameter() << std::endl;

    message_ = stream.str();

    return message_;
}
