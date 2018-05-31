// Copyright 2018 Generalov Aleksandr

#ifndef MODULES_SET_INCLUDE_SET_CALCULATOR_H_
#define MODULES_SET_INCLUDE_SET_CALCULATOR_H_

#include <vector>
#include <string>

class SetCalculator {
 public:
    SetCalculator();
    std::string operator()(int argc, const char** argv);

 private:
    void help(const char* appname, const char* message = "");
    bool parseArguments(int argc, const char** argv, Arguments* out_args);
    std::string message_;

    enum Op {
        Conj, Disj
    };
    typedef struct {
        int numbOfEl1;
        int numbOfEl2;
        std::vector<int> vec1;
        std::vector<int> vec2;
        Op op;
    } Arguments;
};

#endif //MODULES_SET_INCLUDE_SET_CALCULATOR_H_