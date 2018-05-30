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
		"  $ " + appname + " <int>size \n\n" +
		" + x[i] + y[i] \n\n" +
		"Where all arguments are double numbers and 0 < i < size .\n";
}

bool AreaCalculationApp::validateNumberOfArguments(int argc,
    const char** argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    }
    else if (argc != atoi(argv[1]) * 2 + 2) {
        help(argv[0], "ERROR: Should be 1 + 2 * size arguments.\n\n");
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

std::string AreaCalculationApp::operator()(int argc, const char** argv) {
    Arguments args;
    if (!validateNumberOfArguments(argc, argv)) {
        return message_;
    }
    try {
        args.size = atoi(argv[1]);
        args.d1 = new double[args.size];
        args.d2 = new double[args.size];
        for (int i = 0; i < args.size; i++)
        {
            args.d1[i] = parseDouble(argv[2*i]);
            args.d2[i] = parseDouble(argv[2 * i + 1]);
        }
    }
    catch (std::string& str) {
        return str;
    }
    AreaCalculation ac(args.size, args.d1, args.d2);
    std::ostringstream stream;
    stream << "area = " << ac.GetArea();
    message_ = stream.str();
    return message_;
}
