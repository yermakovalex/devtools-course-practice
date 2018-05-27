// Copyright 2018 Talamanov Anatoliy

#ifndef MODULES_POLYNOMS_INCLUDE_POLYNOM_CALCULATOR_HPP_
#define MODULES_POLYNOMS_INCLUDE_POLYNOM_CALCULATOR_HPP_

#include <string>
#include <tuple>
#include "include/polynom.h"

class InputArguments {
 public:
  using Op = char;
  using Arguments = std::tuple<Polynom, Polynom, Op>;

  InputArguments(int argc, const char** argv);

  operator bool()     const { return m_is_valid; }
  Arguments getArgs() const { return m_input_args; }

 private:
  bool validateInputArgs(int argc, const char** argv);
  Arguments m_input_args;
  bool m_is_valid;
};

class PolynomCalculator {
 public:
  PolynomCalculator() = default;
  std::string operator()(int argc, const char** argv);

 private:
  std::string help(const char* appname, const char* message = "");
  std::string calculate(const InputArguments&);
};

#endif  // MODULES_POLYNOMS_INCLUDE_POLYNOM_CALCULATOR_HPP_
