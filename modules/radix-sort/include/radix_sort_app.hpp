// Copyright 2018 Panov Aleksander

#ifndef MODULES_RADIX_SORT_INCLUDE_INTEGER_ARRAY_HPP_
#define MODULES_RADIX_SORT_INCLUDE_INTEGER_ARRAY_HPP_

#include <vector>
#include <string>

class IntegerArray {
 public:
    IntegerArray();
    std::string operator()(int argc, const char** argv);
 private:
    void help(const char* appname, const char* message = "");
    bool validateNumberOfArguments(int argc, const char** argv);
    std::string message_;
    std::vector<int> arr;
};

#endif  // MODULES_RADIX_SORT_INCLUDE_INTEGER_ARRAY_HPP_


