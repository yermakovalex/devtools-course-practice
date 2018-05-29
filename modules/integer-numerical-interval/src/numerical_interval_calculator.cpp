// Copyright 2018 Gribov Pavel

#include <stdexcept>
#include <string>

#include "include/integer_numerical_interval.h"
#include "include/numerical_interval_calculator.h"

NumericalIntervalCalculator::NumericalIntervalCalculator() : message_("") {}

void NumericalIntervalCalculator::help(const char* appname,
                                       const char* message) {
    message_ =
        std::string(message) +
          "This is a integer numerical interval calculator application.\n\n" +
          "Please provide arguments in the following format:\n\n"+

          "  $ " + appname + "\n<left_border> <first_num> " +
          "<comma> <second_num> <right_border>\n\n" +

          "Where <first_num>, <second_num> are integer numbers,\n" +
          "<left_border> is one of '[', '('\n" +
          "<right_border> is one of ']', ')'\n" +
          "<comma> is ',' .";
}

bool NumericalIntervalCalculator::validateNumberOfArguments
    (int argc, const char** argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    } else if (argc != 6) {
        help(argv[0], "ERROR: Should be 5 arguments.\n\n");
        return false;
    }
    return true;
}

bool NumericalIntervalCalculator::parseArguments(int argc, const char** argv,
                                                 Arguments* parsed_args) {
    try {
        if (!((argv[1][0] == '[' || argv[1][0] == '(')
            && (argv[5][0] == ']' || argv[5][0] == ')')
            && argv[3][0] == ',')) {
            help(argv[0], "ERROR: Wrong arguments format!\n\n");
            return false;
        }

        parsed_args->left_border = argv[1][0];
        parsed_args->right_border = argv[5][0];
        parsed_args->comma = argv[3][0];

        parsed_args->first_num = std::stoi(argv[2]);
        parsed_args->second_num = std::stoi(argv[4]);

        return true;
    }
    catch (const std::invalid_argument& ia) {
        help(argv[0], "ERROR: Wrong arguments format!\n\n");
        return false;
    }
}

std::string NumericalIntervalCalculator::operator()(int argc,
                                                    const char** argv) {
    Arguments args;

    if (!validateNumberOfArguments(argc, argv))
        return message_;

    if (!parseArguments(argc, argv, &args))
        return message_;

    try {
        IntegerNumericalInterval interval(args.first_num, args.second_num,
            args.left_border == '[' ? true : false,
            args.right_border == ']' ? true : false);

        std::string string_interval(interval);

        message_ = string_interval;

        return message_;
    }
    catch (const std::string& str) {
        return str;
    }
}
