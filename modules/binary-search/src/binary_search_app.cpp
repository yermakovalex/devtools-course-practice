// Copyright 2018 Gorelova Ksenia

#include "include/binary_search_app.h"
#include "include/binary_search.h"
#include <string>
#include <sstream>

BinarySearchApp::BinarySearchApp() : message_("") {}

void BinarySearchApp::help(const char * appname, const char * message) {
    message_ =
        std::string(message) +
        "This is a binary search application.\n\n" +
        "Please provide arguments in the following format:\n\n" +

        "  $ " + appname + " <num of array>, <search element>, <array> \n\n" +

        "Examples: " +
        " $" + appname + "7, 7, 3 4 5 6 7 8 9 ";
}

bool BinarySearchApp::validateNumberOfArguments(int argc, const char ** argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    } else if (argc < 3) {
        help(argv[0], "Error: Should be more arguments.\n\n");
        return false;
    }
    return true;
}

int parseInt(const char* arg) {
    int value = atoi(arg);
    if (value == 0 && arg[0] != '0')
        throw std::string("Wrong number format!");
    return value;
}

std::string BinarySearchApp::operator()(int argc, const char** argv) {
    Arguments args;
    std::ostringstream out;
    if (!validateNumberOfArguments(argc, argv)) {
        return message_;
    }
    try {
        args.num = parseInt(argv[1]);
        args.elem = parseInt(argv[2]);
        args.mas = new int[args.num];
        for (int i = 3; i < argc; i++)
            args.mas[i-3] = parseInt(argv[i]);
    }
    catch (std::string& str) {
        return str;
    }
    BinarySearch *bSearch = new BinarySearch(args.mas, args.num);
    out << bSearch->Search(args.elem);

    message_ = out.str();
    return message_;
}
