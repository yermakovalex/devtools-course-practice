// Copyright 2018 Shkenev Petr

#ifndef MODULES_NUMERAL_SYSTEM_CALC_INCLUDE_NUMERAL_SYSTEM_APP_H_
#define MODULES_NUMERAL_SYSTEM_CALC_INCLUDE_NUMERAL_SYSTEM_APP_H_

#include <string>

class NumeralSystemApp {
 public:
    NumeralSystemApp();
    std::string operator()(int argc, const char *argv[]);

 private:
    void help(const char *appname, const char *message = "");
    bool validateNumberOfArguments(int argc, const char *argv[]);

    std::string message_;
    std::string arguments;
};

#endif  // MODULES_NUMERAL_SYSTEM_CALC_INCLUDE_NUMERAL_SYSTEM_APP_H_
