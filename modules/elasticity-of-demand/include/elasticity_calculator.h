// Copyright 2018 Rodionov Fedor

#ifndef MODULES_ELASTICITY_CALCULATOR_INCLUDE_ELASTICITY_CALCULATO_H_
#define MODULES_ELASTICITY_CALCULATOR_INCLUDE_ELASTICITY_CALCULATO_H_

#include <string>

class ElasticityCalculator {
public:
    ElasticityCalculator();
    std::string operator()(int argc, const char** argv);

private:
    void help(const char* appname, const char* message = "");
    bool validateNumberOfArguments(int argc, const char** argv);
    std::string message_;
    typedef struct {
        int first_param;
        int second_param;
        int third_param;
        int forth_param;
    } Arguments;
};

#endif  // MODULES_ELASTICITY_CALCULATOR_INCLUDE_ELASTICITY_CALCULATO_H_
