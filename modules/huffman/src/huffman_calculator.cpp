// Copyright 2018 Gracheva Elena

#include "include/huffman.h"
#include "include/huffman_calculator.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <map>
#include <string>
#include <sstream>

HuffmanCalculator::HuffmanCalculator() : message_("") {}

void HuffmanCalculator::help(const char* appname, const char* message) {
    message_ =
        std::string(message) +
        "This is a huffman calculator application.\n\n" +
        "Please provide arguments in the following format:\n\n" +

        "  $ " + appname + " <text> \n\n" +

        "Where \"text\" argument is a text " +
        "for which the Huffman algorithm will be applied.\n";
}

bool HuffmanCalculator::validateNumberOfArguments(int argc, const char** argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    } else if (argc != 2) {
        help(argv[0], "ERROR: Should be 1 argument.\n\n");
        return false;
    }
    return true;
}

std::string HuffmanCalculator::operator()(int argc, const char** argv) {
    Arguments args;

    if (!validateNumberOfArguments(argc, argv)) {
        return message_;
    }
    args.text = argv[1];

    Huffman huff(args.text);
    map<char, char*> ans = huff.Encode();

    std::ostringstream stream;
    for (auto it = ans.begin(); it != ans.end(); it++)
        stream << "\"" << it->first << "\" is encoded as \""
            << it->second << "\"\n";

    message_ = stream.str();

    return message_;
}
