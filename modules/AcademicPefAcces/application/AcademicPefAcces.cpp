 // Copyright 2018 Novikova Alisa

#include <stdlib.h>
#include <stdio.h>
#include <string>

#include "AcademicPefAcces.h"

int main(int argc, const char** argv) {
    AcademicPefAcces app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}