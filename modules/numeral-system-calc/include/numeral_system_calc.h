// Copyright 2018 Yermakov Alexey

#ifndef MODULES_NUMERAL_SYSTEM_CALC_INCLUDE_NUMERAL_SYSTEM_CALC_H_
#define MODULES_NUMERAL_SYSTEM_CALC_INCLUDE_NUMERAL_SYSTEM_CALC_H_

#include <string>

class Calc {
 private:
    static char _Priority(char a);
    static long _Calculate(long num1, long num2, char operation);
    static long _CalculateRpn(char *s);
    static std::string _ConvertToRpn(const std::string &s);

 public:
    static std::string toString(long number, size_t base);
    static long calculate(const std::string &s);
};

#endif  // MODULES_NUMERAL_SYSTEM_CALC_INCLUDE_NUMERAL_SYSTEM_CALC_H_
