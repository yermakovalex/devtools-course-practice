// Copyright 2018 Lipatov Igor

#include <include/dheap-app.h>
#include <include/dheap.h>
#include <sstream>
#include <string>

int parseInt(const char *arg) {
    char *end;
    int value = strtol(arg, &end, 10);
    return value;
}

void MinSearcher::help(const char *appname, const char *message) {
    message_ =
            std::string(message) +
            "This is a d-heap minimum searcher application.\n\n" +
            "Please provide arguments in the following format:\n\n" +
            "  $ " + appname + " d-parameter\n\n" +
            " + elements count + elements... \n\n" +
            "Where all parameters are int number and \n\n";
}

bool MinSearcher::validateNumberOfArguments(int argc, const char **argv) {
    std::ostringstream stream;
    if (argc < 3) {
        stream << "ERROR: You should provide at least 3 arguments!\n\n";
        help(argv[0], stream.str().c_str());
        return false;
    }
    if (argc != parseInt(argv[2]) + 2) {
        int t = parseInt(argv[2]) + 2;
        stream << "ERROR: Incorrect element count!\n\n"
               << "argc " << argc << "argv+2 " << t;
        help(argv[0], stream.str().c_str());
        return false;
    }
    return true;
}

std::string MinSearcher::operator()(int argc, const char **argv) {
    if (validateNumberOfArguments(argc, argv)) {
        std::ostringstream stream;
        Vertex tmp;
        Dheap dh(parseInt(argv[1]), parseInt(argv[2]));
        for (int i = 3; i < argc + 1; i++) {
            tmp.first = parseInt(argv[i]);
            tmp.second = i;
            dh.push(tmp);
        }
        stream << "min=" << dh.pop().first;
        message_ = stream.str();
    }
    return message_;
}

MinSearcher::MinSearcher() : message_("") {}

MinSearcher::~MinSearcher() {}
