// Copyright 2018 Lvova Alina

#include "include/line_plane_intersection_app.h"
#include "include/line_plane_intersection.h"

#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <string>
#include <sstream>

void LinePlaneIntersectionApp::Help
(const char * appname, const char * message) {
    message_ =
        std::string(message) +
        "This is an application to check the intersection.\n\n" +
        "Please provide arguments in the following format:\n\n" +

        "  $ " + appname + " <operation> " +
        "<plane> <line>\n\n" +

        "* <operation> should take one of the following arguments:\n " +
        "-`Intersect`, " +
        "-`Isnt_it_intersected`\n\n" +

        "* <plane> should be write like this " +
        "<x1> <y1> <z1> <x2> <y2> <z2> <x3> <y3> <z3>,\n" +
        "where (x1, y1, z1), (x2, y2, z2)," +
        " (x3, y3, z3) are dots of the plane\n\n" +

        "* <line> should be write like this " +
        "<x1> <y1> <z1> <x2> <y2> <z2>,\n" +
        "where (x1, y1, z1), (x2, y2, z2) are dots of the line\n\n";
}

bool LinePlaneIntersectionApp::ValidateNumberOfArguments
(int argc, const char ** argv) {
    if (argc == 1) {
        Help(argv[0]);
        return false;
    } else if (argc != 17) {
        Help(argv[0], "ERROR: Should be 16 arguments.\n\n");
        return false;
    }
    return true;
}

LinePlaneIntersectionApp::LinePlaneIntersectionApp() : message_("") {}

double parseDouble(const char* arg) {
    char* end;
    double value = strtod(arg, &end);

    if (end[0]) {
        throw std::string("Invalid numeric format");
    }

    return value;
}

std::string parseOperation(const char* arg) {
    std::string op;
    if (strcmp(arg, "Intersect") == 0) {
        op = "PlaneIntersectLine";
    } else if (strcmp(arg, "Isnt_it_intersected") == 0) {
        op = "GetNotIntersectPlaneLine";
    } else {
        throw std::string("Invalid operation");
    }
    return op;
}

std::string LinePlaneIntersectionApp::operator()(int argc, const char ** argv) {
    Arguments args;
    args.plane = new Dot[3];
    args.line = new Dot[2];
    LinePlaneIntersection line_plane_intesect;
    Dot dot_of_intesection;
    bool isnt_intersect;
    std::ostringstream stream;

    if (!ValidateNumberOfArguments(argc, argv))
        return message_;

    try {
        int count = 2;
        for (int i = 0; i < 3; i++) {
            args.plane[i] = {
                parseDouble(argv[count++]),
                parseDouble(argv[count++]),
                parseDouble(argv[count++]) };
        }
        for (int i = 0; i < 2; i++) {
            args.line[i] = {
                parseDouble(argv[count++]),
                parseDouble(argv[count++]),
                parseDouble(argv[count++]) };
        }
        args.operation = parseOperation(argv[1]);
    }
    catch (std::string& str) {
        return str;
    }

    dot_of_intesection = line_plane_intesect.PlaneIntersectLine(
        args.plane[0], args.plane[1], args.plane[2],
        args.line[0], args.line[1]);
    isnt_intersect = line_plane_intesect.GetNotIntersectPlaneLine();

    if (isnt_intersect == true) {
        stream << "The plane is not intersecting the line";
    } else {
        if (args.operation == "PlaneIntersectLine")
            stream << "dot of intersection is = " << dot_of_intesection.x
            << ", " << dot_of_intesection.y << ", " << dot_of_intesection.z;
        else
            stream << "The plane is intersecting the line";
    }

    message_ = stream.str();

    return message_;
}
