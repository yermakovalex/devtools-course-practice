// Copyright 2018 Ermachenko Boris

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <string>
#include <sstream>
#include "include/fractional_number.h"
#include "include/Fractional_app.h"

Fractional_app::Fractional_app() : message_("") {}

void Fractional_app::help_message(const char* message) {
    message_ =
        std::string(message) +
        "HELLO, Dear friend!\n\n"+
        "This is a fractional number calculator application.\n\n" +
        "Values - double-precision numbers, " +
        "<operation> choose from '+', '-', '*', '/'.\n\n"
        "Please provide arguments in the following format:\n\n" +
        "<this_app_names>" +" <value_Numerator_#1> <value_Denomenator_#1> " +
        "<operation>"+"<value_Numerator_#2> <value_Denomenator_#2> \n\n" +
        "Good luck";
}

bool Fractional_app::
forArguments(int argc, const char** argv) {
    if (argc == 1) {
        help_message();
        return false;
    } else if (argc != 6) {
        message_ = "ERROR: Should be 5 arguments.\n\n";
        return false;
    }
    return true;
}

double Fractional_app::GetParam(const char* arg) {
    char* endptr;
    double value = strtod(arg, &endptr);
    if (endptr[0]) {
        help_message("ERROR: Wrong Param format!\n\n");
        throw std::string("Wrong Param format!");
        return false;
    }
    return value;
}

bool isEqual(const char*p, char*q)
{
    while (*p && *q) {
        if (*p++ != *q++)
            return false;
    }
    return true;
}

char Fractional_app::GetOperation(const char* arg) {
    char operation;
    if (isEqual(arg, "+")) {
        operation = '+';
    }
    else if (isEqual(arg, "-")) {
        operation = '-';
    }
    else if (isEqual(arg, "/")) {
        operation = '/';
    }
    else if (isEqual(arg, "*")) {
        operation = '*';
    }
    else {
        help_message("Wrong operation format!");
        throw std::string("Wrong operation format!");
    }
    return operation;
}

std::string Fractional_app:: operator()(int argc, const char** argv) {
    Arguments args;
    if (!forArguments(argc, argv)) {
        return message_;
    }
    try {
        args.a1 = GetParam(argv[1]);
        args.b1 = GetParam(argv[2]);
        args.operation = GetOperation(argv[3]);
        args.a2 = GetParam(argv[4]);
        args.b2 = GetParam(argv[5]);
    }
    catch (std::string& str) {
            return message_;
        }
    FractionalNumber Argument1;
    FractionalNumber Argument2;
    Argument1.setNumerator(args.a1);
    Argument1.setDenominator(args.b1);
    Argument2.setNumerator(args.a2);
    Argument2.setDenominator(args.b2);
    FractionalNumber Rezult_value;
    std::ostringstream stream;
    switch (args.operation) {
    case '+':
        Rezult_value = Argument1 + Argument2;
        stream  << Rezult_value.getNumerator()  << "/"
        <<Rezult_value.getDenominator();
        break;
    case '-':
        Rezult_value = Argument1 - Argument2;
        stream << Rezult_value.getNumerator() << "/"
            << Rezult_value.getDenominator();
        break;
    case '*':
        Rezult_value = Argument1 * Argument2;
        stream << Rezult_value.getNumerator() << "/"
            << Rezult_value.getDenominator();
        break;
    case '/':
        Rezult_value = Argument1 / Argument2;
        stream << Rezult_value.getNumerator() << "/"
            << Rezult_value.getDenominator();
        break;
        }
    message_ = stream.str();
    return message_;
}
