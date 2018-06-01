// Copyright 2018 Volkov Daniel

#include "../include/stack.h"
#include "../include/stack_app.h"

#include <string>
#include <exception>
#include <sstream>
#include <fstream>

StackApp::StackApp() : message_("") {}

void StackApp::help(const char* appname, const char* message) {
    message_ =
        std::string(message) +
        "This is a stack application.\n\n" +
        "Please provide arguments in the following format:\n\n" +
        "  $ " + appname + " <number of elements> <elemet 1> " +
        "...<element 2>\n\n" +
        "Where the first argument is non-negative " +
        "other any integers\n";
}

bool StackApp::validateNumberOfArguments
(int argc, const char** argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    }
    return true;
}

int parseInt(const char* arg) {
    int value = std::stoi(std::string(arg));
    return value;
}

std::string StackApp::operator()(int argc, const char** argv) {
    if (!validateNumberOfArguments(argc, argv)) {
        return message_;
    }
    try {
        int * data, size;
        size = parseInt(argv[1]);
        data = new int[size];
        for (int i = 0; i < size; i++)
            data[i] = parseInt(argv[i + 2]);
        TStack<int> dc(size, data);
        std::ostringstream stream;
        stream << "Your stack is full!\n{ ";
        for (int i = 0; i < size-1; i++) {
            stream << data[i] << ", ";
        }
        stream << data[size - 1] << " }\n";
        message_ = stream.str();
        delete[] data;
        return message_;
    }
    catch (std::exception& exc) {
        return std::string("Wrong format or value is out of range");
    }
}
