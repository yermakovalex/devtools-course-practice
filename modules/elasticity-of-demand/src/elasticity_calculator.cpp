// Copyright 2018 Rodionov Fedor

#include "include/elasticity-of-demand.h"
#include "include/elasticity_calculator.h"


#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include <cstring>
#include <sstream>

ElasticityCalculator::ElasticityCalculator() : message_("") {}

void ElasticityCalculator::help(const char* appname, const char* message) {
    message_ =
        std::string(message) +
        "This is a number in words converter application.\n\n" +
        "Please provide argument in the following format:\n\n" +

        "  $ " + appname + " <number> " +
        "\n\n" +

        "Where argument is integer number" +
        ".\n";
}
