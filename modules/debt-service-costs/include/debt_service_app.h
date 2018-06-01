// Copyright 2018 Sharov Ivan

#ifndef MODULES_DEBT_SERVICE_COSTS_INCLUDE_DEBT_SERVICE_APP_H_
#define MODULES_DEBT_SERVICE_COSTS_INCLUDE_DEBT_SERVICE_APP_H_

#include "include/debt_service.h"
#include <string>

class DebtServiceCalculator {
 public:
     DebtServiceCalculator();
    std::string operator()(int argc, const char** argv);

 private:
    void help(const char* appname, const char* message = "");
    bool validateNumberOfArguments(int argc, const char** argv);
    std::string message_;
    typedef struct {
        float loan_amount;
        int loan_term;
        float loan_rate;
        int operation;
        float summa;
        DebtServiceType service_type;
    } Arguments;
};

#endif  // MODULES_DEBT_SERVICE_COSTS_INCLUDE_DEBT_SERVICE_APP_H_
