// Copyright 2018 Sharov Ivan

#include "include/debt_service.h"
#include "include/debt_service_app.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <string>
#include <sstream>

DebtServiceCalculator::DebtServiceCalculator() : message_("") {}

void DebtServiceCalculator::help(const char* appname, const char* message) {
    message_ =
        std::string(message) +
        "This is a debtservice calculator application.\n\n" +
        "Please provide arguments in the following format:\n\n" +

        "  $ " + appname + " <loan amount> <loan term> " +
        "<loan rate> <DebtService Type> <operation> <Summa of payment>\n\n"+

          "Where <DebtService Type> can take on valuescan take on values:" +
          " 0 - 'ONE_PAYMENT_AT_THE_END' \n" +
          " 1 - 'PRINCIPAL_DEBT_ONE_PAYMENT_AT_THE_END' \n" +
          " 2 - 'EQUAL_ANNUAL_PAYMENTS'\n\n" +

        "Where <operation> can take on valuescan take on values:" +
        " 1 - calculate the amount of payments for the entire loan period \n" +
        " 2 - find out the balance on a debt\n" +
        " 3 - enter an amount and find out the balance on a debt'\n" +
        " 4 - create two identical debts with the same service'\n\n" +

        " if you need to make an amount, then\n" +
        " <Summa of payment> - input amount\n\n";
}

bool DebtServiceCalculator::
     validateNumberOfArguments(int argc, const char** argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    } else {
        if ((argc != 6) && (argc != 7)) {
            help(argv[0], "ERROR: Should be 5 or 6 arguments.\n\n");
            return false;
        } else {
            return true;
        }
    }
}

float parseFloat(const char* arg) {
    char* end;
    float value = strtof(arg, &end);

    if (end[0]) {
        throw std::string("Wrong number format!");
    }

    return value;
}

int parseInt(const char* arg) {
    char* end;
    int value = strtol(arg, &end, 10);

    if (end[0]) {
        throw std::string("Wrong number format!");
    }

    return value;
}

DebtServiceType parseType(const char* arg) {
    char* end;
    DebtServiceType Type;
    int value = strtol(arg, &end, 10);

    switch (value) {
    case 0: {
        Type = ONE_PAYMENT_AT_THE_END;
        break;
    }
    case 1: {
        Type = PRINCIPAL_DEBT_ONE_PAYMENT_AT_THE_END;
        break;
    }
    case 2: {
        Type = EQUAL_ANNUAL_PAYMENTS;
        break;
    }
    default:
        throw std::string("Type of service not defined!");
    }
    return Type;
}

int parseOperation(const char* arg) {
    char* end;
    int value = strtol(arg, &end, 10);

    if ((value != 1) && (value != 2) && (value != 3) && (value != 4)) {
        throw std::string("Operation not defined!");
    }

    return value;
}

std::string DebtServiceCalculator::operator()(int argc, const char** argv) {
    Arguments args;

    if (!validateNumberOfArguments(argc, argv)) {
        return message_;
    }
    try {
        args.loan_amount = parseFloat(argv[1]);
        args.loan_term = parseInt(argv[2]);
        args.loan_rate = parseFloat(argv[3]);
        args.service_type = parseType(argv[4]);
        args.operation = parseOperation(argv[5]);
        if (argc == 7) args.summa = parseFloat(argv[6]);
    }
    catch(std::string& str) {
        return str;
    }

    DebtService Ivanov(args.loan_amount, args.loan_term,
        args.loan_rate, args.service_type);

    std::ostringstream stream;
    switch (args.operation) {
     case 1:
        stream << "The amount of payments for the entire loan period = "
               << Ivanov.GetTotalPayout();
        break;
     case 2:
        stream << "Find out the balance on a debt = "
               << Ivanov.GetBalance();
        break;
     case 3: {
         float oldBalance = Ivanov.GetBalance();
         Ivanov.MakingPayment(args.summa);
         stream << "It was = " << oldBalance
             << "; amount of payment = " << args.summa
             << "; current balance = " << Ivanov.GetBalance();
         break;
     }
     case 4: {
         DebtService Borodin = Ivanov;
         stream << "The amount of Ivanov = " << Ivanov.GetBalance()
             << "; the amount of Borodin = " << Borodin.GetBalance();
     }
    }

    message_ = stream.str();

    return message_;
}
