// Copyright 2018 Kiselev Denis

#include <sstream>
#include <string>

#include "include/bits_calculator.h"

BitsCalculator::BitsCalculator() : message_("") {}

void BitsCalculator::help(const char* appname, const char* message) {
    message_ =
        std::string(message) +
          "This is a bits calculator application.\n\n" +
          "Please provide arguments in the following format:\n\n"+

          "  $ " + appname + " <bits1> <bits2> <operation>\n\n" +

          "Where all arguments are bit sequences, " +
          "and <operation> is one of '&', '|', '^'.\n";
}

bool BitsCalculator::validateNumberOfArguments(int argc, const char** argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    } else if (argc != 4) {
        help(argv[0], "ERROR: Should be 3 arguments.\n\n");
        return false;
    }
    return true;
}

BitsArray* parseBits(const char* arg) {
    int size = 0;

    while (arg[size++] != '\0') {}

    BitsArray* array = new BitsArray(--size);
    for (--size; size >= 0; --size) {
        switch (arg[size]) {
            case '0' :
                break;

            case '1' :
                array->SetBit(size);
                break;

            default :
                throw std::string("Wrong bits format!");
        }
    }

    return array;
}

char parseOperation(const char* arg) {
    char op;

    if (arg[1] != '\0') {
        throw std::string("Wrong operation format!");
    } else {
        switch (arg[0]) {
            case '&' :
                op = '&';
                break;

            case '|' :
                op = '|';
                break;

            case '^' :
                op = '^';
                break;

            default :
                throw std::string("Wrong operation format!");
        }
    }

    return op;
}

std::string BitsCalculator::operator()(int argc, const char** argv) {
    Arguments args;

    if (!validateNumberOfArguments(argc, argv)) {
        return message_;
    }
    try {
        args.bits_first     = parseBits(argv[1]);
        args.bits_second    = parseBits(argv[2]);
        args.operation      = parseOperation(argv[3]);
    }
    catch(std::string& str) {
        return str;
    }

    BitsArray result(1);
    std::ostringstream stream;
    switch (args.operation) {
        case '&':
            result = BitsArray(*args.bits_first & *args.bits_second);
            break;

        case '|' :
            result = BitsArray(*args.bits_first | *args.bits_second);
            break;

        case '^' :
            result = BitsArray((~*args.bits_first & *args.bits_second) |
                               (*args.bits_first & ~*args.bits_second));
            break;
    }

    stream << "Result: ";
    int size = result.GetLength();
    for (int i = 0; i < size; ++i) {
        stream << result.GetBit(i);
    }
    stream << std::endl;

    message_ = stream.str();

    return message_;
}
