// Copyright 2018 Dvorjanchikov Evginiy

#include <stdlib.h>
#include <stdio.h>
#include <string>

#include "include/Vigner_App.h"

int main(int argc, const char** argv) {
    VignerApp app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}
