// Copyright 2018 Chernenko Valery
#ifndef MODULES_INVEST_INCLUDE_INVESTOR_H_
#define MODULES_INVEST_INCLUDE_INVESTOR_H_

#include <string>
#include <vector>
#include "include/Invest.h"

class Investor {
 public:
    Investor();
    std::string operator()(int argc, const  char** argv);

 private:
    void help(const char* appname, const char* massage = "");
    bool validateNumberOfArguments(int argc, const  char** argv);
    std::string message_;
    typedef struct {
        std::vector<money> Incomes;
        std::vector<money> Expenses;
        double RatePercent;
        int YearCount;
        std::string Function;
        double RateParameter;
    } Arguments;
};

#endif  // MODULES_INVEST_INCLUDE_INVESTOR_H_
