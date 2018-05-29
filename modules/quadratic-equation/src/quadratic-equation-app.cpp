// Copyright 2018 Tipanov Daniil

#include <string>
#include <exception>
#include <sstream>
#include <fstream>
#include <vector>

#include "include/quadratic_equation.h"
#include "include/quadratic-equation-app.h"

QuadraticEquationApp::QuadraticEquationApp() : message_("") {}

void QuadraticEquationApp::Help(const char* appname, const char* message) {
    message_ = std::string(message) +
    "This is a quadratic equation application.\n\n" +
    "Please provide arguments in the following format:\n\n" +
    "  $ " + appname + " <aK> <bK> <cK> " +
    "<output_file_name>\n\n" +
    "Where the first three arguments are double " +
    "numbers and <output_file_name> is the filename where you " +
    "want to save found roots.\n";
}

bool QuadraticEquationApp::ValidateNumerOfArguments
                        (int argc, const char** argv) {
    if (argc == 1) {
        Help(argv[0]);
        return false;
    } else if (argc != 5) {
        Help(argv[0], "ERROR: Should be 4 arguments.\n\n");
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

std::string QuadraticEquationApp::operator()(int argc, const char** argv) {
    Arguments args;
    if (!ValidateNumerOfArguments(argc, argv)) {
        return message_;
    }
    try {
        args.aK = parseDouble(argv[1]);
        args.bK = parseDouble(argv[2]);
        args.cK = parseDouble(argv[3]);
        args.output_file_name = argv[4];
    }
    catch (std::exception& exc) {
        return std::string("Wrong format or value is out of range");
    }
    try {
        QuadraticEquation qe(args.aK, args.bK, args.cK);
        std::vector<double> eqRoots = qe.getRoots();
        std::ostringstream stream;
        std::ofstream output_file_stream(args.output_file_name);
        if (output_file_stream.is_open()) {
            for (auto& i : eqRoots)
                output_file_stream << i << " ";
            output_file_stream.close();
            stream << "Successfully written to " <<
                args.output_file_name;
        } else {
            stream << "Cannot open " << args.output_file_name;
        }
        message_ = stream.str();
        return message_;
    }
    catch (const char* exc) {
        return std::string(exc);
    }
}
