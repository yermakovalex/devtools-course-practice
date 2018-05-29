// Copyright 2018 Okunev Boris

#include "include/leftist_heap_app.h"
#include "include/leftist_heap.h"

#include <string>
#include <vector>

using std::string;
using std::vector;

LeftistHeapApp::LeftistHeapApp() : message_("") {}

void LeftistHeapApp::help(const char* appname, const char* message) {
    message_ = string(message) +
        "This is leftist heap application.\n\n" +
        "Please provide arguments in the following format:\n\n" +

        "  $ " + appname + " <operation> <heap_one> <heap_two>\n\n" + 

        "Where heaps is array of keys in the round brackets," +
        "comma is delimited character; \n" +
        "and <operation> is one of 'merge', 'insert', 'isEqual', " +
        "'minKey', 'deleteMin'. \n" +
        "If you use one of the last two operations," + 
        " the last argument is ignored and may be missing. \n";
}

