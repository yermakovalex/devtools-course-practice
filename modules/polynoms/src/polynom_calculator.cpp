// Copyright 2018 TolyaTalamanov

#include <algorithm>
#include <string>
#include <vector>
#include "include/monom.h"
#include "include/polynom_calculator.hpp"

using std::make_tuple;

InputArguments::InputArguments(int argc, const char** argv) {
    m_is_valid = validateInputArgs(argc, argv);
    if (m_is_valid) m_input_args = make_tuple(Polynom(std::string(argv[1])),
                                              Polynom(std::string(argv[2])),
                                              argv[3][0]);
}

bool InputArguments::validateInputArgs(int argc, const char** argv) {
    std::vector<char> ops = {'+', '-', '*'};
    return (argc < 4 ||
            std::find(ops.begin(), ops.end(), argv[3][0]) != ops.end());
}

std::string PolynomCalculator::operator()(int argc, const char** argv) {
    if (argc == 1) return help(argv[0]);
    InputArguments ins(argc, argv);
    return ins ? calculate(ins) : help(argv[0], "arguments aren't valid\n");
}

std::string PolynomCalculator::calculate(const InputArguments& ins) {
    char op;
    Polynom f_p, s_p;
    std::tie(f_p, s_p, op) = ins.getArgs();

    switch (op) {
        case '+' : return (f_p + s_p).ToString();
        case '-' : return (f_p - s_p).ToString();
    }
    return "invalid operations";
}

std::string PolynomCalculator::help(const char* appname, const char* message) {
    return
        std::string(message) +
          "This is a polynom calculator application.\n\n" +
          "Please provide arguments in the following format:\n\n"+

          "  $ " + appname + " <first polynom>, <second polynom>, <" + "+,->" +
          "Examples: " +
          " $" + appname + " 3x 4y +";
}
