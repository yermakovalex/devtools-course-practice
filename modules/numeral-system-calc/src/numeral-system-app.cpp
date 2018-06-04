// Copyright 2018 Shkenev Petr

#include "include/numeral_system_calc.h"
#include "include/numeral-system-app.h"

#include <string>

NumeralSystemApp::NumeralSystemApp(void)
: message_("") {
}

void NumeralSystemApp::help(const char *appname, const char *message) {
    message_ =
        std::string(message) +
        "    This calculator works with different numeral systems " +
        "(BIN, OCT, HEX).\n\n    " +

        appname + " <expression_to_calculate>\n\n" +

        "    Octal and hexadecimal numbers are written " +
        "in the following format:\n" +
        "        010  for octal numbers,\n" +
        "        0x10  for hexadecimal numbers.\n\n" +

        "    Allowed operators: +, -, *, /.\n";
}

bool NumeralSystemApp::validateNumberOfArguments(int argc,
                                                 const char *argv[]) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    } else {
        return true;
    }
}

std::string NumeralSystemApp::operator ()(int argc, const char *argv[]) {
    if (!validateNumberOfArguments(argc, argv)) {
        return message_;
    }

    std::string expression("");
    for (int i = 1; i < argc; i++)
        expression += argv[i];

    int answer;
    try {
        answer = Calc::calculate(expression);
    } catch (...) {
        help(argv[0]);
        return message_;
    }

    message_ += "Binary: " + Calc::toString(answer, 2) + "\nOctal: " +
        Calc::toString(answer, 8) + "\nHexadecimal: " +
        Calc::toString(answer, 16) + "\n";

    return message_;
}
