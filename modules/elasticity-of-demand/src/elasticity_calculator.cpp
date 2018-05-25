// Copyright 2018 Rodionov Fedor

#include "include/elasticity-of-demand.h"
#include "include/elasticity_calculator.h"


#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include <cstring>
#include <string>
#include <sstream>

ElasticityCalculator::ElasticityCalculator() : message_("") {}

void ElasticityCalculator::help(const char* appname, const char* message) {
    message_ =
        std::string(message) +
        "This is an elasticity calculator application.\n\n" +
        "Please provide arguments in the following format:\n\n" +

        "  $ " + appname +
        " <Q1>\n " + " <Q2>\n " + " <T1>\n " + " <T2>\n "
        "<operation> \n\n" +

        "Where all arguments are double-precision numbers, " +
        "and <operation> is one of '1', '2', '3',\n" +
        "where is '1' - PriceElasticity" +
        "'2' - IncomeElasticity, '3' - CrossElasticity.\n";
}

bool ElasticityCalculator::validateNumberOfArguments(int argc,
    const char** argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    }    else if (argc != 6) {
        help(argv[0], "ERROR: Should be 5 arguments.\n\n");
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
    if (strcmp(arg, "1") == 0) {
        op = '1';
    }    else if (strcmp(arg, "2") == 0) {
        op = '2';
    }    else if (strcmp(arg, "3") == 0) {
        op = '3';
    }    else {
        throw std::string("Wrong operation format!");
    }
    return op;
}

std::string ElasticityCalculator::operator()(int argc, const char** argv) {
    Arguments args;

    if (!validateNumberOfArguments(argc, argv)) {
        return message_;
    }
    try {
        args.first_param = parseDouble(argv[1]);
        args.second_param = parseDouble(argv[2]);
        args.third_param = parseDouble(argv[3]);
        args.forth_param = parseDouble(argv[4]);
        args.operation = parseOperation(argv[5]);
    }
    catch (std::string& str) {
        return str;
    }

    Elasticity E;

    std::ostringstream stream;
    switch (args.operation) {
    case '1':
        try {
            E.PriceElasticity(args.first_param, args.second_param,
                args.third_param, args.forth_param);
            E.PriceAnswer();
            stream << "Answer = " << E.GetAns() << " "
                << "Coeff = " << E.GetCoeff();
            break;
        }
        catch (std::string& str) {
            return str;
        }
    case '2':
        try {
            E.IncomeElasticity(args.first_param, args.second_param,
                args.third_param, args.forth_param);
            E.IncomeAnswer();
            stream << "Answer = " << E.GetAns() << " "
                << "Coeff = " << E.GetCoeff();
            break;
        }
        catch (std::string& str) {
            return str;
        }
    case '3':
        try {
            E.CrossElasticity(args.first_param, args.second_param,
                args.third_param, args.forth_param);
            E.CrossAnswer();
            stream << "Answer = " << E.GetAns() << " "
                << "Coeff = " << E.GetCoeff();
            break;
        }
        catch (std::string& str) {
            return str;
        }
    }

    message_ = stream.str();

    return message_;
}
