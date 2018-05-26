// Copyright 2018 Galochkin Boris

#ifndef MODULES_L_METRICS_FLOAT_INCLUDE_L_METRICS_FLOAT_CALCULATOR_H_
#define MODULES_L_METRICS_FLOAT_INCLUDE_L_METRICS_FLOAT_CALCULATOR_H_

#include <vector>

#include "include/l_metrics_float.h"

class LMetricsFloatCalculator {
 public:
    LMetricsFloatCalculator();
    std::string operator()(int argc, const char** argv);

 private:
    void help(const char* appname, const char* message = "");
    bool validateArguments(int argc, const char** argv);
    std::string message_;
    typedef struct {
        std::vector<float> vec1;
        std::vector<float> vec2;
    } Arguments;
};

#endif  // MODULES_L_METRICS_FLOAT_INCLUDE_L_METRICS_FLOAT_H_
