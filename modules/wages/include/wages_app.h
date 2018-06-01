// Copyright 2018 Matyasov Mixail

#ifndef MODULES_WAGES_INCLUDE_WAGES_APP_H_
#define MODULES_WAGES_INCLUDE_WAGES_APP_H_

#include<iostream>
#include<string>
#include"include/Wages.h"

class Application {
    static double calculatedValues;
 public:
    explicit Application(double val = 0);
    std::string DoubleToString(double val);
    double StringToDouble(const char* str);
    Month IntToMonth(int val);
    double GetCalculatedValues();
    std::string CalculateWages(double salary, double administrativeLeaveHours,
    double overtime, Month month);
    std::string CalculateHourlyPay(double salary,
    double administrativeLeaveHours,
    double overtime, Month month);
    std::string CalculationWagesWithoutOvertime(double salary,
    double administrativeLeaveHours,
    double overtime, Month month);
    std::string CalculationOvertimePayment(double salary,
    double administrativeLeaveHours,
    double overtime, Month month);

    std::string operator()(int argc, const char** argv);
};

#endif   //  MODULES_WAGES_INCLUDE_WAGES_APP_H_
