// Copyright 2018 Krasikova Ekaterina

#include "include/operations_on_3d_vectors_app.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <string>
#include <sstream>

OperationsOn3dVectorsApp::OperationsOn3dVectorsApp(): message_("") {}
void OperationsOn3dVectorsApp::help(const char* appname, const char* message) {
    message_ =
        std::string(message) +
        "This is an operations on 3d vectors application.\n\n" +
        "Please provide arguments in one of the following formats:\n\n" +

        "  $ " + appname + " <unary operation> " +
        "<x1> <x2> <x3>\n\n" +

        "Where x1, x2, x3 are the components of the vector," +
        "double-precision numbers, and <unary operation> is one of the " +
        "following operations: norm, normalize.\n\n" +

        "  $ " + appname + " <binary operation> " +
        "<x1> <x2> <x3> <y1> <y2> <y3>\n\n" +

        "Where x1, x2, x3 are the components of the first vector, " +
        "double-precision numbers, y1, y2, y3 are the components of the " +
        "second vector, double-precision numbers, and <binary operation> " +
        "is one of the following operations: dotproduct, crossproduct.\n";
}

bool OperationsOn3dVectorsApp::validateNumberOfArguments(int argc,
    const char** argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    } else if ((argc != 5) && (argc != 8)) {
        help(argv[0], "ERROR: Wrong number of arguments.\n\n");
        return false;
    }
    return true;
}
double parseDouble(const char* arg) {
    char* end;
    double value = strtod(arg, &end);

    if (end[0]) {
        throw std::string("Wrong number format!");
    }
    return value;
}
std::string parseOperation(const char* arg) {
    std::string op;
    if (strcmp(arg, "norm") == 0) {
        op = "norm";
    } else if (strcmp(arg, "normalize") == 0) {
        op = "normalize";
    } else if (strcmp(arg, "dotproduct") == 0) {
        op = "dotproduct";
    } else if (strcmp(arg, "crossproduct") == 0) {
        op = "crossproduct";
    } else {
        throw std::string("Wrong operation format!");
    }
    return op;
}
std::string OperationsOn3dVectorsApp::appForUnaryOperations(int argc,
    const char** argv) {
    Arguments args;
    std::ostringstream stream;
    try {
        args.operation = parseOperation(argv[1]);
        args.v1.x = parseDouble(argv[2]);
        args.v1.y = parseDouble(argv[3]);
        args.v1.z = parseDouble(argv[4]);
    }
    catch (std::string& str) {
        return str;
    }
    if (args.operation == "norm") {
        double norm = OperationsOn3dVectors::GetNorm(args.v1);
        stream << "Norm of the vector = " << norm;
    }
    if (args.operation == "normalize") {
        Vector3d normalized =
            OperationsOn3dVectors::GetNormalizedVector(args.v1);
        stream << "Normalized vector = " << normalized.x << ',';
        stream << normalized.y << ',' << normalized.z;
    }
    message_ = stream.str();
    return message_;
}
std::string OperationsOn3dVectorsApp::appForBinaryOperations(int argc,
    const char** argv) {
    Arguments args;
    std::ostringstream stream;
    try {
        args.operation = parseOperation(argv[1]);
        args.v1.x = parseDouble(argv[2]);
        args.v1.y = parseDouble(argv[3]);
        args.v1.z = parseDouble(argv[4]);
        args.v2.x = parseDouble(argv[5]);
        args.v2.y = parseDouble(argv[6]);
        args.v2.z = parseDouble(argv[7]);
    }
    catch (std::string& str) {
        return str;
    }
    if (args.operation == "dotproduct") {
        double dotproduct =
            OperationsOn3dVectors::DotProduct(args.v1, args.v2);
        stream << "Dot product of the vectors = " << dotproduct;
    }
    if (args.operation == "crossproduct") {
        Vector3d crossproduct =
            OperationsOn3dVectors::CrossProduct(args.v1, args.v2);
        stream << "Cross product of the vectors = " << crossproduct.x;
        stream << ',' << crossproduct.y << ',' << crossproduct.z;
    }
    message_ = stream.str();
    return message_;
}
std::string OperationsOn3dVectorsApp::operator()(int argc, const char** argv) {
    if (validateNumberOfArguments(argc, argv)) {
        if (argc == 5) {
            return appForUnaryOperations(argc, argv);
        }
        if (argc == 8) {
            return appForBinaryOperations(argc, argv);
        }
    }
    return message_;
}
