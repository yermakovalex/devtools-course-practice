// Copyright 2018 Dvorjanchikov Evginiy

#include "include/Vigner_code.h"
#include "include/Vigner_App.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <string>
#include <sstream>

VignerApp::VignerApp() : message_("") {}

void VignerApp::help(const char* appname, const char* message) {
    message_ =
        std::string(message) +
          "This is a Vigner code  application.\n\n" +
          "Please provide arguments in the following format:\n\n"+

          "  $ " + appname + " <-param> <message> " +
          "<keyword> \n\n" +

          "Where <message> is text without space , " +
          "<keyword> is word , " +
          "and <param> is one of 'e', 'd'.\n"+
          "Use '-e' for encoding , '-d' for decoding. \n";
}

bool VignerApp::validateNumberOfArguments(int argc, const char** argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    } else if (argc != 4) {
        help(argv[0], "ERROR: Should be 3 arguments.\n\n");
        return false;
    }
    return true;
}

char parseParam(const char* arg) {
    char param;
    if (strcmp(arg, "-e") == 0) {
        param = 'e';
    } else if (strcmp(arg, "-d") == 0) {
        param = 'd';
    } else {
        throw std::string("Wrong param format!");
    }
    return param;
}

std::string VignerApp::operator()(int argc, const char** argv) {
    Arguments args;

    if (!validateNumberOfArguments(argc, argv)) {
        return message_;
    }
    try {
        args.message = argv[2];
        args.keyword = argv[3];
        args.param    = parseParam(argv[1]);
    }
    catch(std::string& str) {
        return str;
    }

    Vigner_code A;

    std::ostringstream stream;
    switch (args.param) {
     case 'e':
         A.Encode(args.message, args.keyword);
         stream << "Encode message = " << A.Encode(args.message, args.keyword);
        break;
     case 'd':
        stream << "Decode message = " << A.Decode(args.message, args.keyword);
        break;
    }

    message_ = stream.str();

    return message_;
}

