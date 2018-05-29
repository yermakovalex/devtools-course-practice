// Copyright 2018 Chernenko Valery

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <string>
#include <sstream>

#include "include/Invest.h"
#include "include/Investor.h"

Investor::Investor() : message_("") {}

void Investor::help(const char* appname, const char* message) {
    message_ = std::string(message) +
        "This is a Investor application.\n\n" +
        "Please provide arguments in the following format:\n\n" +
        "  $ " + appname + " <int YearCount> <money* Incomes>" +
        " <money* Expenses> <double RatePercent>" +
        " <char* Function> [double RateParameter]\n\n";
}

bool Investor::validateNumberOfArguments(int argc, const char** argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    } else {
        int year = atoi(argv[1]);
        if (argc == 4 + year * 2 ||
           (argc == 5 + year * 2 &&
            !strcmp(argv[2 + year * 2 + 1], "FindNPV"))) {
            return true;
        } else {
            help(argv[0], "Wrong Parameters!\n");
            return false;
        }
    }
}

double parseDouble(const char* arg) {
    char* end;
    double value = strtod(arg, &end);

    if (end[0]) {
        throw std::string("Wrong number format!\n");
    }

    return value;
}

std::string Investor::operator()(int argc, const char** argv) {
    Arguments args;

    if (!validateNumberOfArguments(argc, argv)) {
        return message_;
    }
    try {
        args.YearCount = atoi(argv[1]);
        args.Incomes.reserve(args.YearCount);
        for (int i = 0; i < args.YearCount; i++)
            args.Incomes.push_back(parseDouble(argv[2+i]));
        args.Expenses.reserve(args.YearCount);
        for (int i = 0; i < args.YearCount; i++)
            args.Expenses.push_back(parseDouble(argv[2 +args.YearCount + i]));
        args.RatePercent = parseDouble(argv[2 + args.YearCount*2]);
        args.Function = new char[30];
        snprintf(args.Function, strlen(argv[2 + args.YearCount * 2 + 1]), 
                 argv[2 + args.YearCount * 2 + 1]);
        if (strcmp(args.Function, "FindNPV") != 0 &&
            strcmp(args.Function, "FindIRR") != 0 &&
            strcmp(args.Function, "FindRecoupmentTime") != 0 &&
            strcmp(args.Function, "FindPBIndex") != 0)
            throw std::string("Wrong Operation!\n");
        if (strcmp(args.Function, "FindNPV") ==  0 &&
            argc == 5 + args.YearCount * 2)
            args.RateParameter = parseDouble(argv[argc-1]);
        else
            args.RateParameter = -1;
    }
    catch (std::string& str) {
        return str;
    }

    Investition invest(args.YearCount, args.Incomes,
                       args.Expenses, args.RatePercent);
    std::ostringstream stream;
    if (!strcmp(args.Function, "FindNPV") &&
                argc == 5 + args.YearCount * 2) {
        stream << "NPV = " << invest.FindNPV(args.RateParameter);
    } else if (!strcmp(args.Function, "FindNPV")) {
        stream << "NPV = " << invest.FindNPV();
    } else if (!strcmp(args.Function, "FindIRR")) {
        stream << "IRR = " << invest.FindIRR();
    } else if (!strcmp(args.Function, "FindRecoupmentTime")) {
        stream << "RecoupmentTime = " << invest.FindRecoupmentTime();
    } else {
        stream << "PBIndex = " << invest.FindPBIndex();
    }

    message_ = stream.str();
    return message_;
}


