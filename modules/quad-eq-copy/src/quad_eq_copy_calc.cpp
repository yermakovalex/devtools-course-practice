// Copyright 2018 Romanov Alexander

#include "include/quad_eq_copy_calc.h"
#include "include/quad_eq_copy.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdexcept>

#include <string>
#include <sstream>

QuadEquatCalc::QuadEquatCalc() : message_("") {}

void QuadEquatCalc::help(const char* appname, const char* message) {
    message_ =
        std::string(message) +
          "This is a quadratic equation calculator.\n\n" +
          "Please provide arguments in the following format:\n\n"+

          "  $ " + appname + " <a> " + " <b> " + " <c> \n\n" +
          "Where all arguments are double-precision numbers, \n";
}

bool QuadEquatCalc::validateNumberOfArguments(int argc, const char** argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    } else if (argc != 4) {
        help(argv[0], "ERROR: Should be 3 arguments.\n\n");
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

std::string QuadEquatCalc::operator()(int argc, const char** argv) {
    Arguments args;

    if (!validateNumberOfArguments(argc, argv)) {
        return message_;
    }
    try {
        args.a = parseDouble(argv[1]);
        args.b = parseDouble(argv[2]);
        args.c = parseDouble(argv[3]);
    }
    catch(std::string& str) {
        return str;
    }

    quadraticEquation QE(args.a, args.b, args.c);
    QE.solve();

    std::ostringstream stream;
    // output handler
    stream << "Result: ";
    if (QE.discriminant < 0.0) {
        stream <<  "There are no real roots ";
    }
    if (QE.discriminant == 0.0) {
        stream << "There is one real root: " << QE.roots[0];
    }
    if (QE.discriminant > 0.0) {
        stream << "There are two real roots: ";
        stream << QE.roots[0] << " " << QE.roots[1];
    }

    message_ = stream.str();
    return message_;
}
