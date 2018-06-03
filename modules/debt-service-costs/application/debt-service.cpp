// Copyright 2018 Sharov Ivan

#include <stdlib.h>
#include <stdio.h>
#include <string>

#include "include/debt_service_app.h"

int main(int argc, const char** argv) {
    DebtServiceCalculator app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}
