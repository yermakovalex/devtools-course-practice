// Copyright 2018 Bederdinov Daniil

#include "include/hypothec_calculator.h"
#include "include/hypothec_calculator_app.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <string>
#include <sstream>

HypothecCalculatorApp::HypothecCalculatorApp() : message_("") {}

void HypothecCalculatorApp::help(const char* appname, const char* message) {
    message_ =
        std::string(message) +
          "This is a hypothec calculator application.\n\n" +
          "Please provide arguments in the following format:\n\n"+

          "  $ " + appname + " <apartments_cost> <an_initial_fee> " +
          "<credit_term_in_month> <interest_rate_in_month>" +
          "<output_file_name>\n\n" +

          "Where the first, second and forth arguments are non-negative " +
          "floating point numbers, " + " and the third one is " +
          "non-negative integer" +
          "and and <output_file_name> is the filename where you " +
          "want to save your result.\n";
}

bool HypothecCalculatorApp::validateNumberOfArguments
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

float parseFloat(const char* arg) {
    float value = std::stof(std::string(arg));
    return value;
}

int parseInt(const char* arg) {
    int value = std::stoi(std::string(arg));
    return value;
}

std::string HypothecCalculatorApp::operator()(int argc, const char** argv) {
    Arguments args;

    if (!validateNumberOfArguments(argc, argv)) {
        return message_;
    }
    try {
        args.apartments_cost        = parseFloat(argv[1]);
        args.an_initial_fee         = parseFloat(argv[2]);
        args.credit_term_in_month   = parseInt(argv[3]);
        args.interest_rate_in_month = parseFloat(argv[4]);
        args.output_file_name       = argv[3];
    }
    catch (std::exception& exc) {
        return std::string("Wrong format or value is out of range");
    }

    try {
        HypothecCalculator hc(args.apartments_cost, args.an_initial_fee,
            args.credit_term_in_month, args.interest_rate_in_month);

        std::ostringstream stream;
        std::ofstream output_file_stream(args.output_file_name);

        if (output_file_stream.is_open()) {
            output_file_stream << hc.return_final_amount_of_payment();
            output_file_stream.close();
                stream << "Successfully written to " << args.output_file_name;
        }
        else {
            stream << "Cannot open " << args.output_file_name;
        }

        message_ = stream.str();
        return message_;
        }
        catch (const char* exc) {
            return std::string(exc);
        }
    }
