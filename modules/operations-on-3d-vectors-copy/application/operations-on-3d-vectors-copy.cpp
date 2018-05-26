// Copyright 2018 Krasikova Ekaterina

#include <stdlib.h>
#include <stdio.h>
#include <string>

#include "include/operations_on_3d_vectors_app.h"

int main(int argc, const char** argv) {
    OperationsOn3dVectorsApp app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}
