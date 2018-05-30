// Copyright 2018 Talamanov Anatoliy

#ifndef MODULES_POLYNOMS_INCLUDE_POLYNOM_CALCULATOR_HPP_
#define MODULES_POLYNOMS_INCLUDE_POLYNOM_CALCULATOR_HPP_

#include <vector>
#include <string>
#include <tuple>
#include <unordered_map>
#include <functional>
#include "include/monom.h"
#include "include/polynom.h"

using Op            = char;
using CalculateArgs = std::vector<double>;
using Arguments     = std::tuple<Polynom, Polynom, Op, CalculateArgs>;
using p_ref         = Polynom&;
using Callback      = std::function<Polynom(p_ref, p_ref)>;

class PolynomCalculator {
 public:
  PolynomCalculator();
  std::string operator()(int argc, const char** argv);
  static std::unordered_map<Op, Callback> m_ops;

 private:
  void help(const char* appname, const char* message = "");
  bool validateInputArguments(int argc, const char** argv);
  std::string calculate(const Arguments& args);

  std::string m_message;
};

#endif  // MODULES_POLYNOMS_INCLUDE_POLYNOM_CALCULATOR_HPP_
