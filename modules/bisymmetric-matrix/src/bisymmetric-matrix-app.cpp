// Copyright 2018 Yermakov Alexey

#include "include/bisymmetric_matrix.h"
#include "include/bisymmetric-matrix-app.h"

#include <string>
#include <fstream>

BisymmetricMatrixApp::BisymmetricMatrixApp(void)
: message_("") {
}

void BisymmetricMatrixApp::help(const char *appname, const char *message) {
    message_ =
        std::string(message) +
        "    This is a bisymmetric matrix calculator application. " +
        "Please provide\narguments in the following format:\n\n    " +

        appname + " <file_matrix1> <file_matrix2> <operator>\n\n" +

        "    Operators are allowed: +, -, *, =.\n\n" +
        
        "    Operator `*` takes the first element of the second matrix " +
        "and multiplies it\nwith the first matrix.\n";
}

bool BisymmetricMatrixApp::validateNumberOfArguments(int argc,
                                                 const char *argv[]) {
    if (argc != 4) {
        help(argv[0]);
        return false;
    } else {
        return true;
    }
}

std::string BisymmetricMatrixApp::operator ()(int argc, const char *argv[]) {
    if (!validateNumberOfArguments(argc, argv))
        return message_;

    std::ifstream is1(argv[1]);
    std::ifstream is2(argv[2]);

    if (!is1.is_open()) {
        message_ += std::string("Can not open `") + argv[1] + "`!\n";
        return message_;
    }

    if (!is2.is_open()) {
        message_ += std::string("Can not open `") + argv[2] + "`!\n";
        return message_;
    }

    Matrix a, b;
    is1 >> a;
    is1.close();
    is2 >> b;
    is2.close();

    try {
        switch (*argv[3]) {
        case '+': message_ += (a + b).ToString(); break;
        case '-': message_ += (a - b).ToString(); break;
        case '*': message_ += (a * b.GetElem(1, 1)).ToString(); break;
        case '=':
            if (a == b)
                message_ += "TRUE\n";
            else
                message_ += "FALSE\n";
        }
    } catch (const char *error) {
        message_ += error;
    }

    return message_;
}
