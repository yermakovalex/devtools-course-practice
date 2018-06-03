// Copyright 2018 TolyaTalamanov

#include <cstddef>
#include <string>
#include "include/monom.h"
#include "include/polynom.h"
#include "include/polynom_calculator.hpp"

std::unordered_map<Op, Callback> PolynomCalculator::m_ops =
                               { {'+', [](p_ref l, p_ref r){return l + r;}},
                                 {'-', [](p_ref l, p_ref r){return l - r;}},
                                 {'*', [](p_ref l, p_ref r){return l * r;}} };

PolynomCalculator::PolynomCalculator() : m_message("") {}

void PolynomCalculator::help(const char* appname, const char* message) {
    m_message =
          std::string(message) +
            "This is a polynom calculator application.\n\n" +
            "Please provide arguments in the following format:\n\n" +

            "  $ " + appname + " <first_polinom> <second_polinom>" +
            "<operation> <computation_variables>\n\n" +

            "Where <computation_variables> are double-pricision numbers\n" +
            "<polinoms> are string\n" +
            "operation is one of '+', '-', '*'.\n";
}

bool PolynomCalculator::validateInputArguments(int argc, const char** argv) {
    if (argc < 4) {
        if (argc == 1) {
            help(argv[0]);
        } else {
            help(argv[0], "ERROR: Invalid size arguments.\n\n");
        }
        return false;
    }
    if (m_ops.find(argv[3][0]) == m_ops.end()) {
        help(argv[0], "ERROR: Invalid operation.\n\n");
        return false;
    }
    return true;
}

std::string PolynomCalculator::operator()(int argc, const char** argv) {
    if (!validateInputArguments(argc, argv)) return m_message;

    Polynom l_p(argv[1]);
    Polynom r_p(argv[2]);
    Op op = argv[3][0];

    Polynom res_p = m_ops[op](l_p, r_p);
    auto vars = res_p.GetVarsList();

    if (vars.size() != static_cast<std::size_t>(argc - 4)) {
        help(argv[0], "ERROR: Invalid size variables for computations.\n\n");
        return m_message;
    }

    int var_index = 4;  // appname, polinom, polinom, operation, vars...
    for (auto& var : vars) {
        var.second = std::stod(argv[var_index++]);
    }

    double calculate_res = res_p.CalculateResult(vars);
    m_message = std::to_string(calculate_res);

    return m_message;
}
