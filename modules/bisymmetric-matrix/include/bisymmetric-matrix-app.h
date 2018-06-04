// Copyright 2018 Yermakov Alexey

#ifndef MODULES_bisymmetric_matrix_CALC_INCLUDE_bisymmetric_matrix_APP_H_
#define MODULES_bisymmetric_matrix_CALC_INCLUDE_bisymmetric_matrix_APP_H_

#include <string>

class BisymmetricMatrixApp {
 public:
    BisymmetricMatrixApp();
    std::string operator()(int argc, const char *argv[]);

 private:
    void help(const char *appname, const char *message = "");
    bool validateNumberOfArguments(int argc, const char *argv[]);

    std::string message_;
    std::string arguments;
};

#endif  // MODULES_bisymmetric_matrix_CALC_INCLUDE_bisymmetric_matrix_APP_H_
