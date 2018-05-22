// Copyright 2018 Kulikova Svetlana

#include "include/numerical_integration.h"
#include "include/numerical-integration-app.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <string>
#include <sstream>

IntegralApp::IntegralApp() : message_("") {}

void IntegralApp::Help(const char* appname, const char* message) {
    message_ =
        std::string(message) +
          "This is a numerical integration application.\n\n" +
          "Please provide arguments in the following format:\n\n"+

          "  $ " + appname + " <low> <up> <N> <Method>\n\n" +

          "Where <low> and <up> arguments are double-precision numbers, " +
          "and <N> should be in non-negative integer numbers, " +
          "and <Methods> is one of 'RiemannSumLeft', 'TrapezoidalRule', 'SimpsonRule', " +
          "'Simpson3_8Rule', 'BooleRule', 'NewtonCotes5', 'GaussianQuadrature'.\n";
}

bool IntegralApp::ValidateNumberOfArguments(int argc, const char** argv) {
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

char parseOperation(const char* arg) {
    char op;
    if (strcmp(arg, "+") == 0) {
        op = '+';
    } else if (strcmp(arg, "-") == 0) {
        op = '-';
    } else if (strcmp(arg, "*") == 0) {
        op = '*';
    } else if (strcmp(arg, "/") == 0) {
        op = '/';
    } else {
        throw std::string("Wrong operation format!");
    }
    return op;
}

std::string IntegralApp::operator()(int argc, const char** argv) {
    Arguments args;

    if (!ValidateNumberOfArguments(argc, argv))
        return message_;

    try {
        args.low    = parseDouble(argv[1]);
        args.up     = parseDouble(argv[2]);
        args.N      = parseInt(argv[3]);
        args.Method = parseMethod(argv[4]);
    }
    catch(std::string& str) {
        return str;
    }
    
    Integral I;
    
    I.setLower(args.low);
    I.setUpper(args.up);
    I.setDevisions(args.N);

    ComplexNumber I1;
    std::ostringstream stream;
    switch (args.Method) {
     case 'RiemannSumLeft':
        z = z1 + z2;
        stream << "Real = " << z.getRe() << " "
               << "Imaginary = " << z.getIm();
        break;
     case '-':
        z = z1 - z2;
        stream << "Real = " << z.getRe() << " "
               << "Imaginary = " << z.getIm();
        break;
     case '*':
        z = z1 * z2;
        stream << "Real = " << z.getRe() << " "
               << "Imaginary = " << z.getIm();
        break;
     case '/':
        try {
            z = z1 / z2;
            stream << "Real = " << z.getRe() << " "
                   << "Imaginary = " << z.getIm();
            break;
        }
        catch(std::string& str) {
            return str;
        }
    }

    message_ = stream.str();

    return message_;
}
