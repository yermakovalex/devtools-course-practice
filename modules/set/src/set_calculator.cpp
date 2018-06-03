// Copyright 2018 Generalov Aleksandr

#include "include/set_calculator.h"
#include "include/set.h"

#include <string>
#include <vector>
#include <sstream>
#include <stdexcept>

SetCalculator::SetCalculator() : message_("") {}

void SetCalculator::help(const char* appname, const char* message) {
    message_ = std::string(message) +
        "Please provide arguments in the following format:\n\n"

        "$ " + appname +
        "<first vector length = n> <v1[0]> <v1[1]> ... <v1[n]>\n" +
        "<second vector length = n> <v2[0]> <v2[1]> ... <v2[n]>\n" +
        "<operation>\n\n" +

        "Where sizes and lengths are int and more then 0" +
        "vectors values are int numbers\n" +
        "<length> - number of set elements in the range [0, 9]\n" +
        "<operation> - one of 'Conj', 'Disj'\n";
}

std::string SetCalculator::operator()(int argc, const char ** argv) {
    Arguments args;
    if (!parseArguments(argc, argv, &args))
        return message_;

    std::stringstream ss;
    set A, B, C;
    A.Insert(args.vec1);
    B.Insert(args.vec2);

    switch (args.op) {
    case Op::Disj:
        C = A + B;
        break;
    case Op::Conj:
        C = A * B;
        break;
    }

    std::vector<int> res = C.GetElements();
    for (auto i = res.begin(); i != res.end() - 1; i++)
        ss << *i << ' ';
    ss << *(res.end() - 1);

    message_ = "Result: " + ss.str();

    return message_;
}

bool SetCalculator::parseArguments(int argc, const char** argv,
                                   Arguments* out_args) {
    if (argc < 4) {
        help(argv[0]);
        return false;
    }

    auto op = std::string(argv[argc - 1]);
    if (op == "Conj") {
        out_args->op = Op::Conj;
    } else if (op == "Disj") {
        out_args->op = Op::Disj;
    } else {
        help(argv[0], "ERROR: Wrong operation!\n\n");
        return false;
    }

    int size1 = std::atoi(argv[1]);
    if (argc < size1 + 4) {
        help(argv[0], "ERROR: Wrong counts of args. Check size1\n\n");
        return false;
    }
    int size2 = std::atoi(argv[2 + size1]);
    if (argc < size1 + 4 + size2) {
        help(argv[0], "ERROR: Wrong counts of args. Check size2\n\n");
        return false;
    }

    for (int i = 2; i < size1 + 3; i++) {
        if (std::atoi(argv[i]) >= 0 && std::atoi(argv[i]) < 10) {
            out_args->vec1.emplace_back(std::atoi(argv[i]));
        } else {
            help(argv[0], "ERROR: Check the elements of the vector1\n\n");
            return false;
        }
    }
    for (int i = 3 + size1; i < size2 + 4 + size1; i++) {
        if (std::atoi(argv[i]) >= 0 && std::atoi(argv[i]) < 10) {
            out_args->vec2.emplace_back(std::atoi(argv[i]));
        } else {
            help(argv[0], "ERROR: Check the elements of the vector2\n\n");
            return false;
        }
    }

    return true;
}
