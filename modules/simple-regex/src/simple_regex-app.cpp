// Copyright 2018 Vyunov Roman

#include "include/simple_regex.h"
#include "include/simple_regex-app.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <string>
#include <sstream>

Application::Application() : message_("") {}

void Application::help(const char* appname, const char* message) {
    message_ =
        std::string(message) +
        "This is a regex finder application.\n\n" +
        "Please provide arguments in the following format:\n\n" +
        "  $ " + appname + " <flag> \"<target string>\" \"<regex>\" \n" +
        "As <flag> you may use :\n" +
        "-i  --  for give answer Regex is (not) match \n" +
        "-g  --  for give finded result \n\n";
}

char parseOperation(const char* arg) {
    char op;
    if (strcmp(arg, "-i") == 0) {
        op = 'i';
    } else if (strcmp(arg, "-g") == 0) {
        op = 'g';
    } else {
        throw std::string("Wrong operation format!");
    }
    return op;
}

bool Application::validateNumberOfArguments(int argc, const char** argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    } else if (argc != 4) {
        help(argv[0], "ERROR: Should be 3 arguments.\n\n");
        return false;
    }
    return true;
}

std::string Application::operator()(int argc, const char** argv) {
    Arguments args;

    if (!validateNumberOfArguments(argc, argv)) {
        return message_;
    }
    try {
        args.mode = parseOperation(argv[1]);
        args.target = argv[3];
        args.regex = argv[2];
    }
    catch (std::string& str) {
        return str;
    }
    SimpleRegex regex(args.regex.c_str());
    std::ostringstream stream;
    switch (args.mode) {
    case 'i':
        if (regex.isMatch(args.target.c_str()))
            stream << "Regex is match" << std::endl;
        else
            stream << "Regex is not match" << std::endl;
        break;
    case 'g':
        regex.isMatch(args.target.c_str());
        char * tmp = new char[args.target.size() + 1];
        snprintf(tmp, args.target.size() +1, "%s", args.target.c_str());
        regex.getMatch(tmp, args.target.size());
        if (regex.getMatchIndex() != -1) {
            stream << "Find : " << std::string(tmp) << std::endl <<
                "Begin position : " << regex.getMatchIndex() << std::endl;
        } else {
            stream << "Nothing found" << std::endl;
        }
        break;
    }
    message_ = stream.str();
    return message_;
}
