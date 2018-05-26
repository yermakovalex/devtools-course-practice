// Copyright 2018 Krasikova Ekaterina

#include "include/operations_on_3d_vectors_app.h"

OperationsOn3dVectorsApp::OperationsOn3dVectorsApp(): message_("") {}
void OperationsOn3dVectorsApp::help(const char* appname, const char* message) {
    message_ =
        std::string(message) +
        "This is an operations on 3d vectors application.\n\n" +
        "Please provide arguments in one of the following formats:\n\n" +

        "  $ " + appname + " <unary operation> " +
        "<x1> <x2> <x3>\n\n" +

        "Where x1, x2, x3 are the components of the vector, double-precision numbers, " +
        "and <unary operation> is one of the following operations: norm, normalize.\n\n" +

        "  $ " + appname + " <binary operation> " +
        "<x1> <x2> <x3> <y1> <y2> <y3>\n\n" +

        "Where x1, x2, x3 are the components of the first vector, double-precision numbers, " +
        "y1, y2, y3 are the components of the second vector, double - precision numbers, " +
        "and <binary operation> is one of the following operations: dotproduct, crossproduct.\n";
}

bool OperationsOn3dVectorsApp::validateNumberOfArguments(int argc, const char** argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    }
    else if (argc < 5) {
        help(argv[0], "ERROR: Not enough arguments.\n\n");
        return false;
    }
    return true;
}
std::string OperationsOn3dVectorsApp::operator()(int argc, const char** argv) {
    if (!validateNumberOfArguments(argc, argv)) {
        return message_;
    }
    return message_;
}
