// Copyright 2018 Pozdeeva Varvara

#include "include/q_sort_app.h"
#include "include/q_sort.h"

#include <string>
#include <vector>
#include <sstream>

QuickSortApp::QuickSortApp() : message_("") {}

void QuickSortApp::help(const char* appname, const char* message) {
    message_ =
        std::string(message) +
          "This is a quick sort application.\n\n" +
          "Please provide arguments in the following format:\n\n"+

          "  $ " + appname + " <num of array>, <left index>,  " +
          "<right index> , <array> \n\n" +

          "Examples: " +
          " $" + appname + "9, 0, 8, 0 3 1 5 7 4 2 6 9 ";
}

bool QuickSortApp::validateNumberOfArguments(int argc, const char** argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    } else if (argc <= 3) {
        help(argv[0], "ERROR: Should be more arguments.\n\n");
        return false;
    }
    return true;
}

double parseInt(const char* arg) {
    int value = atoi(arg);
    if (value ==0 && arg[0] != '0') {
        throw std::string("Wrong number format!");
    }

    return value;
}
void CheckParam(int first, int last, std::vector<int> *array) {
    if ((first < 0) || (last < 0))
        throw std::string("Array index can't be < 0");
    if (static_cast<int>(array->size()) < last)
        throw std::string("Right bound of array > array size");
}


std::string QuickSortApp::operator()(int argc, const char** argv) {
    Arguments args;
    std::ostringstream stream;

    if (!validateNumberOfArguments(argc, argv)) {
        return message_;
    }
    try {
        args.num = parseInt(argv[1]);
        args.left = parseInt(argv[2]);
        args.right = parseInt(argv[3]);
        for (int i = 4; i < argc; i++)
            args.mas.push_back(parseInt(argv[i]));
        CheckParam(args.left, args.right, &args.mas);
    }
    catch(std::string& str) {
        return str;
    }
    try {
            sort::quickSort(&args.mas, args.left, args.right);
            for (int i = 0; i <  args.mas.size(); i++)
                stream << args.mas[i] << " ";
        }
        catch(std::string& str) {
            return str;
        }
    message_ = stream.str();

    return message_;
}
