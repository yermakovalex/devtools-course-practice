// Copyright 2018 Shkenev Petr

#ifndef MODULES_RPN_INCLUDE_RPN_H_
#define MODULES_RPN_INCLUDE_RPN_H_

#include <string>

#include "include/messages.h"

class rpn {
 private:
    static int _Pow(int a, int b);
    static bool _Contains(const std::string &s, char c);
    static char _Priority(char a);
    static int _Calculate(int num1, int num2, char operation);

 public:
    static int calculateRpn(const std::string &s);
    static std::string convertToRpn(const std::string &s);
};

#endif  // MODULES_RPN_INCLUDE_RPN_H_
