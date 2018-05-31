// Copyright 2018 Chvanov Leonid

#include "include/length-converter.h"
#include "include/length_converter_app.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <string>
#include <sstream>
#include <iomanip>

LengthConverterApp::LengthConverterApp() : message_("") {}

void LengthConverterApp::help(const char* appname, const char* message) {
    message_ =
        std::string(message) +
        "This is a length converter application.\n\n" +
        "Please provide arguments in the following format:\n\n" +

        "  $ " + appname + " <originalValue> <originalLengthUnit> " +
        "<targetLengthUnit>\n\n" +

        "Where the first argument is positive double-precision number, " +
        "and length units are one of Centimeter, Meter, Kilometer, Mile, " +
        "Foot, Yard, Inch, NauticalMile, AstronomicalUnit, Span, Verst.\n";
}

bool LengthConverterApp::validateNumberOfArguments(int argc,
    const char** argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    } else if (argc != 4) {
        help(argv[0], "ERROR: Should be 3 arguments.\n\n");
        return false;
    }
    return true;
}

double ParseDouble(const char* arg) {
    char* end;
    double value = strtod(arg, &end);

    if (end[0]) {
        throw std::string("Wrong number format!");
    }

    return value;
}

LengthUnit ParseLengthUnit(const char* arg) {
    LengthUnit lenUnit;
    if (strcmp(arg, "Centimeter") == 0) {
        lenUnit = Centimeter;
    } else if (strcmp(arg, "Meter") == 0) {
        lenUnit = Meter;
    } else if (strcmp(arg, "Kilometer") == 0) {
        lenUnit = Kilometer;
    } else if (strcmp(arg, "Mile") == 0) {
        lenUnit = Mile;
    } else if (strcmp(arg, "Foot") == 0) {
        lenUnit = Foot;
    } else if (strcmp(arg, "Yard") == 0) {
        lenUnit = Yard;
    } else if (strcmp(arg, "Inch") == 0) {
        lenUnit = Inch;
    } else if (strcmp(arg, "NauticalMile") == 0) {
        lenUnit = NauticalMile;
    } else if (strcmp(arg, "AstronomicalUnit") == 0) {
        lenUnit = AstronomicalUnit;
    } else if (strcmp(arg, "Span") == 0) {
        lenUnit = Span;
    } else if (strcmp(arg, "Verst") == 0) {
        lenUnit = Verst;
    } else {
        throw std::string("Wrong length unit format!");
    }
    return lenUnit;
}

std::string LengthConverterApp::operator()(int argc, const char** argv) {
    Arguments args;

    if (!validateNumberOfArguments(argc, argv)) {
        return message_;
    }
    try {
        args.originalValue = ParseDouble(argv[1]);
        args.originalLengthUnit = ParseLengthUnit(argv[2]);
        args.targetLengthUnit = ParseLengthUnit(argv[3]);
    }
    catch (std::string& str) {
        return str;
    }

    LengthConverter lenConv;
    std::ostringstream stream;
    try {
        double res;
        switch (args.originalLengthUnit) {
        case Centimeter:
            switch (args.targetLengthUnit) {
            case Meter:
                res = lenConv.centimetersToMeters(args.originalValue);
                stream << args.originalValue << " centimeters is "
                    << res << " meters";
                break;
            case Inch:
                res = lenConv.centimetersToInches(args.originalValue);
                stream << args.originalValue << " centimeters is "
                    << res << " inches";
                break;
            case Span:
                res = lenConv.centimetersToSpans(args.originalValue);
                stream << args.originalValue << " centimeters is "
                    << res << " spans";
                break;
            default:
                throw std::string("Error! Unknown conversion");
                break;
            }
            break;
        case Meter:
            switch (args.targetLengthUnit) {
            case Centimeter:
                res = lenConv.metersToCentimeters(args.originalValue);
                stream << args.originalValue << " meters is "
                    << res << " centimeters";
                break;
            case Kilometer:
                res = lenConv.metersToKilometers(args.originalValue);
                stream << args.originalValue << " meters is "
                    << res << " kilometers";
                break;
            case Foot:
                res = lenConv.metersToFoot(args.originalValue);
                stream << args.originalValue << " meters is "
                    << res << " feet";
                break;
            case NauticalMile:
                res = lenConv.metersToNauticalMiles(args.originalValue);
                stream << args.originalValue << " meters is "
                    << res << " nautical miles";
            case Mile:
                res = lenConv.metersToMiles(args.originalValue);
                stream << args.originalValue << " meters is "
                    << res << " miles";
                break;
            case Yard:
                res = lenConv.metersToYards(args.originalValue);
                stream << args.originalValue << " meters is "
                    << res << " yards";
                break;
            case Inch:
                res = lenConv.metersToInches(args.originalValue);
                stream << args.originalValue << " meters is "
                    << res << " inches";
                break;
            case AstronomicalUnit:
                res = lenConv.metersToAstronomicalUnits(args.originalValue);
                stream << std::fixed;
                stream << args.originalValue << " meters is "
                    << res << " astronomical units";
                break;
            case Span:
                res = lenConv.metersToSpans(args.originalValue);
                stream << args.originalValue << " meters is "
                    << res << " spans";
                break;
            case Verst:
                res = lenConv.metersToVersts(args.originalValue);
                stream << args.originalValue << " meters is "
                    << res << " versts";
                break;
            default:
                throw std::string("Error! Unknown conversion");
                break;
            }
            break;
        case Kilometer:
            switch (args.targetLengthUnit) {
            case Meter:
                res = lenConv.kilometersToMeters(args.originalValue);
                stream << args.originalValue << " kilometers is "
                    << res << " meters";
                break;
            case Mile:
                res = lenConv.kilometersToMiles(args.originalValue);
                stream << args.originalValue << " kilometers is "
                    << res << " miles";
                break;
            case AstronomicalUnit:
                res = lenConv.kilometersToAstronomicalUnits(args.originalValue);
                stream << args.originalValue << " kilometers is "
                    << res << " astronomical units";
                break;
            default:
                throw std::string("Error! Unknown conversion");
                break;
            }
            break;
        case Mile:
            switch (args.targetLengthUnit) {
            case Kilometer:
                res = lenConv.milesToKilometers(args.originalValue);
                stream << args.originalValue << " miles is "
                    << res << " kilometers";
                break;
            case Meter:
                res = lenConv.milesToMeters(args.originalValue);
                stream << args.originalValue << " miles is "
                    << res << " meters";
                break;
            default:
                throw std::string("Error! Unknown conversion");
                break;
            }
            break;
        case Foot:
            switch (args.targetLengthUnit) {
            case Meter:
                res = lenConv.footToMeters(args.originalValue);
                stream << args.originalValue << " feet is "
                    << res << " meters";
                break;
            case Yard:
                res = lenConv.footToYards(args.originalValue);
                stream << args.originalValue << " feet is "
                    << res << " yards";
                break;
            default:
                throw std::string("Error! Unknown conversion");
                break;
            }
            break;
        case Yard:
            switch (args.targetLengthUnit) {
            case Foot:
                res = lenConv.yardsToFoot(args.originalValue);
                stream << args.originalValue << " yards is "
                    << res << " feet";
                break;
            case Meter:
                res = lenConv.yardsToMeters(args.originalValue);
                stream << args.originalValue << " yards is "
                    << res << " meters";
                break;
            default:
                throw std::string("Error! Unknown conversion");
                break;
            }
            break;
        case Inch:
            switch (args.targetLengthUnit) {
            case Centimeter:
                res = lenConv.inchesToCentimeters(args.originalValue);
                stream << args.originalValue << " inches is "
                    << res << " centimeters";
                break;
            case Meter:
                res = lenConv.inchesToMeters(args.originalValue);
                stream << args.originalValue << " inches is "
                    << res << " meters";
                break;
            default:
                throw std::string("Error! Unknown conversion");
                break;
            }
            break;
        case NauticalMile:
            switch (args.targetLengthUnit) {
            case Meter:
                res = lenConv.nauiticalMilesToMeters(args.originalValue);
                stream << args.originalValue << " nautical miles is "
                    << res << " meters";
                break;
            default:
                throw std::string("Error! Unknown conversion");
                break;
            }
            break;
        case AstronomicalUnit:
            switch (args.targetLengthUnit) {
            case Kilometer:
                res = lenConv.astronomicalUnitsToKilometers(args.originalValue);
                stream << std::fixed;
                stream << args.originalValue << " astronomical units is "
                    << res << " kilometres";
                break;
            case Meter:
                res = lenConv.astronomicalUnitsToMeters(args.originalValue);
                stream << std::fixed;
                stream << args.originalValue << " astronomical units is "
                    << res << " meters";
                break;
            default:
                throw std::string("Error! Unknown conversion");
                break;
            }
            break;
        case Span:
            switch (args.targetLengthUnit) {
            case Centimeter:
                res = lenConv.spansToCentimeters(args.originalValue);
                stream << args.originalValue << " spans is "
                    << res << " centimeters";
                break;
            case Meter:
                res = lenConv.spansToMeters(args.originalValue);
                stream << args.originalValue << " spans is "
                    << res << " meters";
                break;
            case Verst:
                res = lenConv.spansToVersts(args.originalValue);
                stream << args.originalValue << " spans is "
                    << res << " versts";
                break;
            default:
                throw std::string("Error! Unknown conversion");
                break;
            }
            break;
        case Verst:
            switch (args.targetLengthUnit) {
            case Meter:
                res = lenConv.verstsToMeters(args.originalValue);
                stream << args.originalValue << " versts is "
                    << res << " meters";
                break;
            case Span:
                res = lenConv.verstsToSpans(args.originalValue);
                stream << args.originalValue << " versts is "
                    << res << " spans";
                break;
            default:
                throw std::string("Error! Unknown conversion");
                break;
            }
        }
    }
    catch (std::string& str) {
        return str;
    }
    catch (const char* str) {
        return std::string(str);
    }
    message_ = stream.str();
    return message_;
}
