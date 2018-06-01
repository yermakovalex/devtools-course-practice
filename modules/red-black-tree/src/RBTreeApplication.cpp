// Copyright 2018 Churakov Sergey

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <string>
#include <sstream>
#include "include/RBTree.h"
#include "include/RBTreeApplication.h"


RBTree_application::RBTree_application() : message_("") {}

void RBTree_application::help(const char* appname, const char* message) {
    message_ =
        std::string(message) +
          "This is a red black tree application.\n\n" +
          "Please provide arguments in the following format:\n\n"+

          "  $ " + appname +
          "<key> <operation>\n\n" +

          "Where all arguments are integer numbers, " +
          "and <operation> is one of 'f', 'i', 'd'.\n";
}

bool RBTree_application::validateNumberOfArguments(int argc,
                                       const char** argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    } else if (argc != 3) {
        help(argv[0], "ERROR: Should be 2 arguments.\n\n");
        return false;
    }
    return true;
}

int parseInt(const char* arg) {
    int value = std::stoi(std::string(arg));
    return value;
}

char parseOperation(const char* arg) {
    char op;
    if (strcmp(arg, "f") == 0) {
        op = 'f';
    } else if (strcmp(arg, "i") == 0) {
        op = 'i';
    } else if (strcmp(arg, "d") == 0) {
        op = 'd';
    } else {
        throw std::string("Wrong operation format!");
    }
    return op;
}

std::string RBTree_application::operator()(int argc, const char** argv) {
    Arguments args;

    if (!validateNumberOfArguments(argc, argv)) {
        return message_;
    }
    try {
        args.key      = parseInt(argv[1]);
        args.operation    = parseOperation(argv[2]);
    }
    catch(std::string& str) {
        return str;
    }

    RBTree tree;
    tree.insertNode(1);
    tree.insertNode(3);
    tree.insertNode(5);
    tree.insertNode(11);
    tree.insertNode(33);
    tree.insertNode(55);
    tree.insertNode(111);
    tree.insertNode(333);
    tree.insertNode(555);


    std::ostringstream stream;
    switch (args.operation) {
     case 'i':
        tree.insertNode(args.key);
        stream << "New node inserted";
        break;
     case 'd':
        if (tree.findNode(args.key)->count == 0) {
            stream << "Cant delete unexisting node";
        } else {
            tree.deleteNode(args.key);
            stream << "Node deleted";
        }
        break;
     case 'f':
        stream << "Node found " << (tree.findNode(args.key))->count << " times";
    }

    message_ = stream.str();

    return message_;
}
