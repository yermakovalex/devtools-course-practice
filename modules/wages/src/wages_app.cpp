// Copyright 2018 Matyasov Mixail

#include "include/wages_app.h"
#include <string>

double Application::calculatedValues = -1;

Application::Application(double val) {
    calculatedValues = val;
}

std::string Application::DoubleToString(double val) {
    int sizeMantis = 2;
    int degree = 1;
    std::string output;

    for (int i = 0; i < sizeMantis; i++)
        degree *= 10;
    int integerPart = static_cast<int>(val);
    int mantis = static_cast<int>((val - integerPart) * degree);

    while (integerPart != 0) {
        output += integerPart % 10 + '0';
        integerPart /= 10;
    }
    output += '.';
    while (mantis != 0) {
        output += mantis % 10 + '0';
        mantis /= 10;
    }

    return output;
}

double Application::StringToDouble(const char* str) {
    int sizeMantis = 0;
    std::string output = str;
    bool isMantis = true;
    int intPart = 0;
    int mantis = 0;

    for (unsigned int i = output.length() - 1, j = 1, k = 1; ;) {
        if (isMantis) {
            if (output[i] == '.') {
                isMantis = false;
                i--;
                continue;
            }
            mantis += j * (output[i] - '0');
            j *= 10;
            sizeMantis++;
        } else {
            intPart += k * (output[i] - '0');
            k *= 10;
        }
        int check = i;
        i--;
        check--;
        if (check == -1)
            break;
    }
    if (isMantis == true) {
        intPart = mantis;
        mantis = 0;
    }

    double degree = 1;
    for (int i = 0; i < sizeMantis; i++)
        degree *= 10;
    degree = static_cast<int>(degree);
    double result = intPart + mantis / degree;

    return result;
}

Month Application::IntToMonth(int val) {
    switch (val) {
    case 1:
        return January;
        break;
    case 2:
        return February;
        break;
    case 3:
        return March;
        break;
    case 4:
        return April;
        break;
    case 5:
        return May;
        break;
    case 6:
        return June;
        break;
    case 7:
        return July;
        break;
    case 8:
        return August;
        break;
    case 9:
        return September;
        break;
    case 10:
        return October;
        break;
    case 11:
        return November;
        break;
    default:
        return December;
        break;
    }
}

double Application::GetCalculatedValues() {
    return calculatedValues;
}

std::string Application::CalculateWages(double salary,
double administrativeLeaveHours, double overtime, Month month) {
    Wages w(salary, administrativeLeaveHours, overtime, month);
    calculatedValues = w.calculationFullWages();
    return "\nWages = " + DoubleToString(calculatedValues) + "\n";
}

std::string Application::CalculateHourlyPay(double salary,
double administrativeLeaveHours, double overtime, Month month) {
    Wages w(salary, administrativeLeaveHours, overtime, month);
    calculatedValues = w.calculationHourPayment();
    return "\nHourly pay = " + DoubleToString(calculatedValues) + "\n";
}

std::string Application::CalculationWagesWithoutOvertime(double salary,
double administrativeLeaveHours, double overtime, Month month) {
    Wages w(salary, administrativeLeaveHours, overtime, month);
    calculatedValues = w.calculationWagesWithoutOvertime();
    return "\nWages without overtime = " + DoubleToString(calculatedValues)
    + "\n";
}

std::string Application::CalculationOvertimePayment(double salary,
double administrativeLeaveHours, double overtime, Month month) {
    Wages w(salary, administrativeLeaveHours, overtime, month);
    calculatedValues = w.calculationPaymentOvertime();
    return "\nOvertime payment = " + DoubleToString(calculatedValues) + "\n";
}

std::string Application::operator()(int argc, const char ** argv) {
    if (argc == 1)
        return "Argument 1 is not correct";
    if (argc == 2)
        return "Argument 2 is not correct";
    if (argc == 3)
        return "Argument 3 is not correct";
    if (argc == 4)
        return "Argument 4 is not correct";
    if (argc == 5)
        return "Argument 5 is not correct";

    if (argc > 1) {
        std::string values = argv[1];

        if (values == "CalculateWages")
            return CalculateWages(StringToDouble(argv[2]),
            StringToDouble(argv[3]), StringToDouble(argv[4]),
            IntToMonth(argv[5][0] - '0'));
        else if (values == "HourlyPay")
            return CalculateHourlyPay(StringToDouble(argv[2]),
            StringToDouble(argv[3]), StringToDouble(argv[4]),
            IntToMonth(argv[5][0] - '0'));
        else if (values == "CalculationOvertimePayment")
            return CalculationOvertimePayment(StringToDouble(argv[2]),
            StringToDouble(argv[3]), StringToDouble(argv[4]),
            IntToMonth(argv[5][0] - '0'));
        else
            return CalculationWagesWithoutOvertime(StringToDouble(argv[2]),
            StringToDouble(argv[3]), StringToDouble(argv[4]),
            IntToMonth(argv[5][0] - '0'));
    }
    return "";
}
