// Copyright 2018 Chvanov Leonid

#ifndef MODULES_LENGTH_CONVERTER_INCLUDE_LENGTH_CONVERTER_APP_H_
#define MODULES_LENGTH_CONVERTER_INCLUDE_LENGTH_CONVERTER_APP_H_

#include <string>

enum LengthUnit { Centimeter, Meter, Kilometer, Mile, Foot,
                Yard, Inch, NauticalMile, AstronomicalUnit, Span, Verst};

class LengthConverterApp {
 public:
    LengthConverterApp();
    std::string operator()(int argc, const char** argv);

 private:
    void help(const char* appname, const char* message = "");
    bool validateNumberOfArguments(int argc, const char** argv);
    std::string message_;
    typedef struct {
        double originalValue;
        LengthUnit originalLengthUnit;
        LengthUnit targetLengthUnit;
    } Arguments;
};

#endif  // MODULES_LENGTH_CONVERTER_INCLUDE_LENGTH_CONVERTER_APP_H_
