// Copyright 2018 Gusev Alexandr

#include "include/area_calculation.h"
#include "include/area_calculation_app.h"

#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include <cstring>
#include <string>
#include <sstream>

AreaCalculationApp::AreaCalculationApp() : message_("") {}

void AreaCalculationApp::help(const char* appname, const char* message) {
    message_ =
        std::string(message) +
        "This is a area calculation application.\n\n" +
        "Please provide arguments in the following format:\n\n" +
        "  $ " + appname + " size \n\n" +
        " + x[i] + y[i] \n\n" +
        "Where size is int number and \n\n" +
        "all x[i] and y[i] are double numbers and 0 < i < size .\n";
}
bool AreaCalculationApp::validateNumberOfArguments(int argc,
    const char** argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    } else if (argc != atoi(argv[1])*2+2) {
        help(argv[0],
        "ERROR: Should be size multiplication 2 plus 1 arguments.\n\n");
        return false;
    }
    return true;
}

int parseInt(const char* arg) {
    char* end;
    int value = strtol(arg, &end, 10);

    if (end[0]) {
        throw std::string("Wrong int format!");
    }
    return value;
}
double parseDouble(const char* arg) {
    char* end;
    double value = strtod(arg, &end);
    if (end[0]) {
        throw std::string("Wrong double format!");
    }
    return value;
}

std::string AreaCalculationApp::operator()(int argc, const char** argv) {
    Arguments args;
    if (!validateNumberOfArguments(argc, argv)) {
        return message_;
    }
    try {
        args.size = parseInt(argv[1]);
        args.d1 = new double[args.size];
        args.d2 = new double[args.size];
        for (int i = 0; i < args.size; i++) {
            args.d1[i] = parseDouble(argv[i+2]);
            args.d2[i] = parseDouble(argv[args.size + 2 + i]);
        }
    }
    catch (std::string& str) {
        return str;
    }
    AreaCalculation ac(args.size, args.d1, args.d2);
    std::ostringstream stream;
    stream << "area = " << ac.GetArea();
    message_ = stream.str();
    delete args.d1;
    delete args.d2;
    return message_;
}
