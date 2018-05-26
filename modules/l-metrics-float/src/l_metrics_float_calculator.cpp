// Copyright 2018 Galochkin Boris

#include <vector>
#include <string>

#include "include/l_metrics_float_calculator.h"

LMetricsFloatCalculator::LMetricsFloatCalculator()
{
}

std::string LMetricsFloatCalculator::operator()(int argc, const char ** argv)
{
    return std::string();
}

void LMetricsFloatCalculator::help(const char * appname, const char * message)
{
    message_ = std::string(message) +
        "Please provide arguments in the following format:\n\n"

        "  $ " + appname + " <distance type>"
        "<first vector length = n> <v1[0]> <v1[1]> ... <v1[n]>"
        "<second vector length = n> <v2[0]> <v2[1]> ... <v2[n]>\n\n"

        "Where <length> are integer, vectors values are float numbers, " +
        "and <distance type> is one of 'Linf', 'L1', 'L2', 'L3', 'L4'\n";
}

bool LMetricsFloatCalculator::validateArguments(int argc, const char ** argv)
{
    return false;
}
