// Copyright 2018 Dvorjanchikov Evginiy

#ifndef MODULES_VIGNER_CODE_INCLUDE_VIGNER_APP_H_
#define MODULES_VIGNER_CODE_INCLUDE_VIGNER_APP_H_

#include <string>

class VignerApp {
 public:
    VignerApp();
    std::string operator()(int argc, const char** argv);

 private:
    void help(const char* appname, const char* message = "");
    bool validateNumberOfArguments(int argc, const char** argv);
    std::string message_;
    typedef struct {
        std::string message;
        std::string keyword;
        char param;
    } Arguments;
};

#endif  // MODULES_VIGNER_CODE_INCLUDE_VIGNER_APP_H_
