// Copyright 2018 Mezina Margarita

#include <iostream>
#include <exception>
#include <cstdlib>
#include <string>
#include <cstring>
#include <sstream>

#include "include/priority_queue_app.h"
#include "include/priority_queue.h"

PriorityQueueApp::PriorityQueueApp() : message_("") {}
void PriorityQueueApp::help(const char* appname, const char* message) {
    message_ =
        std::string(message) +
        "This is a priority queue application.\n\n" +
        "Please provide arguments in the following format:\n\n" +

        "  $ " + appname + " <amount of elements> " +
        " <array of element names> " + " <array of element priorities> " +
        " <array of queue times> " + " <array of time working>\n\n" +

        "Where the first argument is non-negative integer.\n" +
        "Then array of element names is a sequence of strings, " +
        "their lengths are less than 20, " +
        "their number is <amount of elements>.\n" +
        "Array of element priorities is non-negative integers, " +
        "their number is <amount of elements>.\n" +
        "Array of queue times is non-negative integers, " +
        "their number is <amount of elements>.\n" +
        "Array of time working is non-negative integers, " +
        "their number is <amount of elements>.\n";
}

bool PriorityQueueApp::validateNumberOfArguments(int argc, const char** argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    }
    if (argc != (2 + atoi(argv[1]) * 4)) {
        help(argv[0],
            "ERROR: Should be 2 + 4*<amount of elements> arguments\n\n");
        return false;
    }
    for (int i = 0; i < atoi(argv[1]); ++i) {
        if (strlen(argv[2 + i]) > 20) {
            help(argv[0],
                "ERROR: Lenght names should be less then 20\n\n");
            return false;
        }
    }
    return true;
}

int parseInt(const char* arg) {
    int value = std::stoi(std::string(arg));
    return value;
}

std::string PriorityQueueApp::operator()(int argc, const char** argv) {
    Arguments args;
    if (!validateNumberOfArguments(argc, argv)) {
        return message_;
    }
    try {
        args.n = parseInt(argv[1]);
        args.element_names = new std::string[args.n];
        args.element_priority = new int[args.n];
        args.element_time_start = new int[args.n];
        args.element_time_work = new int[args.n];
        for (int i = 0; i < args.n; ++i)
            args.element_names[i] = std::string(argv[2 + i]);
        for (int i = 0; i < args.n; ++i)
            args.element_priority[i] = parseInt(argv[2 + args.n + i]);
        for (int i = 0; i < args.n; ++i)
            args.element_time_start[i] = parseInt(argv[2 + 2*args.n + i]);
        for (int i = 0; i < args.n; ++i)
            args.element_time_work[i] = parseInt(argv[2 + 3*args.n + i]);
    }
    catch (std::exception& exc) {
        return
            std::string("Wrong format integer number or out of range\n");
    }
    try {
        PriorityQueue<int> pq;
        std::ostringstream stream;
        stream << "Priority Queue:\n";
        int finished_count = 0;
        int work_element = -1;
        int time_work = 0;
        int time = 0;
        while (finished_count != args.n) {
            time++;
            stream << time;
            bool ch = true;
            for (int i = 0; i < args.n; ++i)
                if (args.element_time_start[i] == time) {
                    if (ch) {
                        stream << "\tGo: ";
                        ch = false;
                        stream << args.element_names[i];
                    } else {
                        stream << " " << args.element_names[i];
                    }
                    pq.Push(i, args.element_priority[i]);
                }
            if (!ch)
                stream << "\n";
            if (work_element == -1) {
                if (pq.Empty()) {
                    stream << "\tNot work";
                } else {
                    work_element = pq.ExtractMax();
                    pq.DeleteMax();
                }
            }
            if (work_element != -1) {
                time_work++;
                stream << "\tWork: " << args.element_names[work_element];
                if (args.element_time_work[work_element] == time_work) {
                    stream << " - finished";
                    work_element = -1;
                    time_work = 0;
                    finished_count++;
                }
            }
            stream << "\n";
        }
        stream << "Finish!\n";
        message_ = stream.str();
        return message_;
    }
    catch (std::exception& exc) {
        return std::string(exc.what());
    }
}
