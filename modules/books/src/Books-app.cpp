// Copyright 2018 Kozorez Alexandr

#include <string>
#include <exception>
#include <sstream>
#include <fstream>

#include "include/Books.h"
#include "include/Books-app.h"

BooksApplication::BooksApplication() : message_("") {}


void BooksApplication::Help(const char * appname, const char * message) {
    message_ =
        std::string(message) +
        "This is a books application.\n\n" +
        "Please provide arguments in the following format:\n\n" +
        "  $ " + appname + "<book1> <book2> <book3> <book4> <book5> " +
        "<output_file_name\n\n" +
        "Books counts should be in non-negative integer numbers " +
        "<output_file_name> is the filename where you want to save result.\n";
}

bool BooksApplication::ValidateNumberOfArguments(int argc, const char ** argv) {
    if (argc == 1) {
        Help(argv[0]);
        return false;
    } else if (argc != 7) {
        Help(argv[0], "ERROR: Should be 6 arguments.\n\n");
        return false;
    }
    return true;
}

int parseInt(const char* arg) {
    int value = std::stoi(std::string(arg));
    return value;
}

std::string BooksApplication::operator()(int argc, const char ** argv) {
    Arguments args;

    if (!ValidateNumberOfArguments(argc, argv)) return message_;

    try {
        args.books = new int[5];
        for (int i = 0; i < 5; i++)
            args.books[i] = parseInt(argv[i+1]);
        args.output_file_name = argv[6];

        Books books_area(5, args.books);
        std::ostringstream stream;
        std::ofstream output_file_stream(args.output_file_name);

        if (output_file_stream.is_open()) {
            output_file_stream << books_area.CalculateAllPayment(args.books);
            output_file_stream.close();

            stream << "Successfully written to " << args.output_file_name;
        } else {
            stream << "Cannot open " << args.output_file_name;
        }

        message_ = stream.str();
        return message_;
    }
    catch (std::exception& exc) {
        return std::string("Wrong format or value is out of range");
    }
}
