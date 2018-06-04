// Copyright 2018 Yermakov Alexey

#ifndef MODULES_BISYMMETRIC_MATRIX_INCLUDE_BISYMMETRIC_MATRIX_APP_H_
#define MODULES_BISYMMETRIC_MATRIX_INCLUDE_BISYMMETRIC_MATRIX_APP_H_

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

#endif  // MODULES_BISYMMETRIC_MATRIX_INCLUDE_BISYMMETRIC_MATRIX_APP_H_
