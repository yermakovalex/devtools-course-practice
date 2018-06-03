// Copyright 2018 Gribov Pavel

#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

#include "include/integer_numerical_interval.h"
#include "include/numerical_interval_calculator.h"

NumericalIntervalCalculator::NumericalIntervalCalculator() : message_("") {}

void NumericalIntervalCalculator::help(const char* appname,
    const char* message) {
    message_ =
        std::string(message) +
        "This is a integer numerical interval calculator application.\n\n" +
        "Please provide arguments in the following format:\n\n" +

        "  $ " + appname + "\n\n  <interval> <operation> " +
        "[<numbers ..>]\n  or\n" +
        "  <interval1> <interval2> <operation>\n\n" +

        "Where <interval> is string interval with following format:\n" +
        "<left_bracket> <number1> <,> <number2> <right_bracket> " +
        "without spaces\n " +
        "where <left_bracket> is one of '[', '('\n" +
        "<right_bracket> is one of ']', ')' .\n" +
        "And where <operation> in first case is:\n" +
        "ep - get end points\n" +
        "ap - get all points\n" +
        "pc - checks the entry points from <numbers ..>\n" +
        "And in second case is:\n" +
        "ro - checks ranges for overlapse\n" +
        "rc - checks intervals for entry\n";
}

bool NumericalIntervalCalculator::validateNumberOfArguments
(int argc, const char** argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    }
    return true;
}

bool NumericalIntervalCalculator::parseArguments(int argc, const char** argv,
    Arguments* parsed_args) {
    try {
        parsed_args->interval1
            = IntegerNumericalInterval(std::string(argv[1]));

        if (argc > 2) {
            std::string arg(argv[2]);
            if (arg == "ep") {
                parsed_args->type_of_operation = Operation::ep;
            } else if (arg == "ap") {
                parsed_args->type_of_operation = Operation::ap;
            } else if (arg == "pc") {
                parsed_args->type_of_operation = Operation::pc;
            } else {
                parsed_args->type_of_operation = Operation::no_op;
            }

            if (argc == 3) {
                if (parsed_args->type_of_operation == Operation::no_op) {
                    help(argv[0], "ERROR: Wrong arguments format!\n\n");
                    return false;
                }
                if (parsed_args->type_of_operation == Operation::pc) {
                    help(argv[0], "ERROR: You dont enter numbers!\n\n");
                    return false;
                }
                return true;
            }

            if (parsed_args->type_of_operation == Operation::pc) {
                for (int i = 3; i < argc; ++i)
                    parsed_args->numbers.push_back(std::stoi(argv[i]));
                return true;
            }

            parsed_args->interval2
                = IntegerNumericalInterval(std::string(argv[2]));

            if (argc > 4) {
                help(argv[0], "ERROR: Too much arguments!\n\n");
                return false;
            }

            arg = std::string(argv[3]);
            if (arg == "ro") {
                parsed_args->type_of_operation = Operation::ro;
            } else if (arg == "rc") {
                parsed_args->type_of_operation = Operation::rc;
            } else {
                parsed_args->type_of_operation = Operation::no_op;
            }
        }
        return true;
    }
    catch (const std::string& str) {
        help(argv[0], str.c_str());
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

    switch (args.type_of_operation) {
        case Operation::ep:
        {
            pair<int, int> endPoints = args.interval1.getEndPoints();
            message_ = std::to_string(endPoints.first) + " " +
                std::to_string(endPoints.second);
            break;
        }
        case Operation::ap:
        {
            vector<int> allPoints = args.interval1.getAllPoints();
            message_ = "";
            for (auto point : allPoints)
                message_ += std::to_string(point) + " ";
            break;
        }
        case Operation::pc:
        {
            bool isContained
                = args.interval1.isContainPoints(args.numbers);
            if (isContained)
                message_ = "Contained points\n";
            else
                message_ = "Not contained points\n";
            break;
        }
        case Operation::ro:
        {
            bool isOverlapse
                = args.interval1.isHaveOverlapsRange(args.interval2);
            if (isOverlapse)
                message_ = "Ranges overlapsed\n";
            else
                message_ = "Ranges not overlapsed\n";
            break;
        }
        case Operation::rc:
        {
            bool isContained
                = args.interval1.isContainsRange(args.interval2);
            if (isContained)
                message_ = "Contained range\n";
            else
                message_ = "Not contained range\n";
            break;
        }
        case Operation::no_op:
        {
            message_ = "ERROR: Wrong arguments format!\n\n";
            break;
        }
    }

    return message_;
}
