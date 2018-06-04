// Copyright 2018 Panov Alesksander

#include <cstdlib>
#include <string>
#include <vector>
#include "include/radix_sort.hpp"
#include "include/radix_sort_app.hpp"

int parseInt(const char* arg) {
    int value = 0;
    try {
        value = atoi(arg);
    }
    catch (...) {
        throw std::string("Wrong number format!");
    }
    return value;
}

IntegerArray::IntegerArray():message_(""), arr() {}

std::string IntegerArray::operator()(int argc, const char ** argv) {
    if (!validateNumberOfArguments(argc, argv)) {
        return message_;
    }
    try {
        for (int i = 1; i < argc; i++) {
            int tmp = parseInt(argv[i]);
            if (std::to_string(tmp) != argv[i])
                throw std::string("Wrong number format!");
            arr.push_back(parseInt(argv[i]));
        }
    }
    catch (std::string& str) {
        return str;
    }

    RadixSorter sorter(arr.begin(), arr.end());
    auto resArray = sorter.sort();
    std::string resString;
    for (int i = 0; i < static_cast<int>(resArray.size())-1; i++) {
        resString += std::to_string(resArray[i]);
        resString += " ";
    }
    resString += std::to_string(resArray[resArray.size() - 1]);
    return resString;
}

void IntegerArray::help(const char * appname, const char * message) {
    message_ =
        std::string(message) +
        "This is a sort integer array application.\n\n" +
        "Please provide arguments in the following format:\n\n" +

        "  $ " + appname + "<element_1> <element_2> ... " +
        "<element_n>\n\n" +

        "Where all arguments are integer numbers\n";
}

bool IntegerArray::validateNumberOfArguments(int argc, const char ** argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    }
    return true;
}
