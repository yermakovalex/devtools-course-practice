// Copyright 2018 Lvova Alina

#include <stdlib.h>
#include <stdio.h>
#include <string>

#include "include/line_plane_intersection_app.h"

int main(int argc, const char** argv) {
    LinePlaneIntersectionApp app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}
