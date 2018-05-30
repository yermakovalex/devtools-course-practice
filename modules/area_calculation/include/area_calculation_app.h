// Copyright 2018 Gusev Alexandr

#ifndef MODULES_AREA_CALCULATION_INCLUDE_AREA_CALCULATION_APP_H_
#define MODULES_AREA_CALCULATION_INCLUDE_AREA_CALCULATION_APP_H_

#include <string>

class AreaCalculationApp {
 public:
    AreaCalculationApp();
    std::string operator()(int argc, const char** argv);
 private:
    void help(const char* appname, const char* message = "");
    bool validateNumberOfArguments(int argc, const char** argv);
    std::string message_;
    typedef struct {
        int size;
        double* d1;
        double* d2;
    } Arguments;
};

#endif  // MODULES_AREA_CALCULATION_INCLUDE_AREA_CALCULATION_APP_H_
