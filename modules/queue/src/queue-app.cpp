// Copyright 2018 Aglikov Ilya

#include "include/queue.h"
#include "include/queue-app.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <string>
#include <sstream>

#include <ctime>

QueueApp::QueueApp() : message_("") {}

void QueueApp::help(const char* appname, const char* message) {
    message_ =
        std::string(message) +
          "This is a queue application.\n\n" +
          "Please provide arguments in the following format:\n\n"+

          "  $ " + appname + " <queue_type> <queue_size>" +
          "<operation> <output_file_name>\n\n" +

          "Where the first argument is queue type (char, int, double), " +
          "second is queue capasity - non-negative integer number, " +
          "third - <operation> is one of 'pop', 'push', " +
          "and <output_file_name> is the filename where you " +
          "want to save your queue.\n";;
}

bool QueueApp::validateNumberOfArguments(int argc, const char** argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    } else if (argc != 5) {
        help(argv[0], "ERROR: Should be 4 arguments.\n\n");
        return false;
    }
    return true;
}

double parseDouble(const char* arg) {
    char* end;
    double value = strtod(arg, &end);

    if (end[0]) {
        throw std::string("Wrong number format!");
    }

    return value;
}

int parseUnsInt(const char* arg) {
    unsigned int value = std::stoi(std::string(arg));
    return value;
}

std::string QueueApp::operator()(int argc, const char** argv) {
    Arguments args;

    if (!validateNumberOfArguments(argc, argv)) {
        return message_;
    }
    try {
        args.clocks = parseUnsInt(argv[1]);
        args.capacity = parseUnsInt(argv[2]);
        args.jobIntens = parseDouble(argv[3]);
        args.procRate      = parseDouble(argv[4]);
    }
    catch(std::string& str) {
        return str;
    }

    Queue<unsigned int> queue(args.capacity);

    unsigned int clocks = args.clocks;
    double jobIntens = args.jobIntens;
    double procRate = args.procRate;
    unsigned int jobNumber = 0;
    double denial = 0;
    double downtime = 0;
    srand(time(0));

    for (int i = 0; i < clocks; i++) {
        if ((rand() % 100) < (jobIntens * 100))
        {
            jobNumber++;
            if (!queue.full())
                queue.enqueue(jobNumber);
            else denial++;
        }
        if ((rand() % 100) < (procRate * 100))
            if (!queue.empty())
                queue.dequeue();
            else downtime++;
    }

    std::ostringstream stream;
    stream << "Result of imitation:" 
        << "\nThe number of submitted jobs: " << jobNumber
        << "\nDenial of service (the queue is full): ~" <<  (int)(denial / jobNumber * 100) << '%'
        << "\nThe average number of quanta of the job: " << ((double)clocks - downtime) / jobNumber
        << "\nDowntime of CPU (the queue is empty): " << downtime / clocks * 100 << '%';

    message_ = stream.str();

    return message_;
}
