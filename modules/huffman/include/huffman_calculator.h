// Copyright 2018 Gracheva Elena

#ifndef MODULES_HUFFMAN_INCLUDE_HUFFMAN_CALCULATOR_H_
#define MODULES_HUFFMAN_INCLUDE_HUFFMAN_CALCULATOR_H_

#include <string>

class HuffmanCalculator {
 public:
    HuffmanCalculator();
    std::string operator()(int argc, const char** argv);
 private:
    void help(const char* appname, const char* message = "");
    bool validateNumberOfArguments(int argc, const char** argv);
    std::string message_;
    typedef struct {
        const char* text;
    } Arguments;
};

#endif  // MODULES_HUFFMAN_INCLUDE_HUFFMAN_CALCULATOR_H_
