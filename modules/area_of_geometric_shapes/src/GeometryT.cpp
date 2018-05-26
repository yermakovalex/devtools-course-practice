// Copyright 2017 Levitsky Ilya

#include <stdlib.h>
#include <stdio.h>
#include <string>

#include "include/GeometryT.h"
#include "include/Cone.h"
#include "include/Cube.h"
#include "include/Cylinder.h"
#include "include/Sphere.h"

GeometryT::GeometryT() : message_("") {}

void GeometryT::help(const char* appname, const char* message) {
    message_ =
        std::string(message) +
        "This is a area of geometric figure.\n\n" +
        "Please provide arguments in the following format : \n\n"

        " $" + appname + " <radius> <height> for Cylinder and Cone \n" +
        "Or <radius/height> for Sphere and Cube. \n\n" +

        "Where arguments are real positive numbers. \n\n";
}

bool GeometryT::validateNumberOfArguments(int argc, const char** argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
	} else if(argc > 4) {
        help(argv[0], "ERROR: Should be not more than 3");
		return false;
    }
    return true;
}

double parseDouble(const char* arg) {
    char* end;
    double value = strtod(arg, &end);

    if (end[0]) {
        throw std::string("Wrong number format!");
    }

    return value;
}

std::string GeometryT::operator()(int argc, const char** argv) {
    Arguments args;
    double res = 0;

    if (!validateNumberOfArguments(argc, argv)) {
        return message_;
    }

    if (argc == 3) {
        try {
            args.radius = parseDouble(argv[2]);
        }
        catch (std::string& str) {
            return str;
        }
    }

    if (argc == 4) {
        try {
            args.radius = parseDouble(argv[2]);
            args.height = parseDouble(argv[3]);
        }
        catch (std::string& str) {
            return str;
        }
    }

    if (argc == 3 && argv[1] == "Cone") {
        Cone cone(radius, height);
    }
    if (argc == 3 && argv[1] == "Cylinder") {
        Cylinder cyliner(radius, height);
    }
    if (argc == 2 && argv[1] == "Sphere") {
        Sphere sphere(radius);
    }
    if (argc == 2 && argv[1] == "Cube") {
        Cube cube(radius);
    }

    std::ostringstream stream;

    switch (argv[1]) {
    case 'Cone':
        res = cone.areaCone();
        stream << "Area of cone: " << res;
        break;
    case 'Cylinder':
        res = cylinder.areaCyl();
        stream << "Area of cylinder: " << res;
        break;
    case 'Sphere':
        res = sphere.areaSph();
        stream << "Area of sphere: " << res;
        break;
    case 'Cube':
        try {
            res = cube.areaCube();
            stream << "Area of cube: " << res;
            break;
        }
        catch (std::string& str) {
            return str;
        }
    }

    message_ = stream.str();

    return message_;
}
