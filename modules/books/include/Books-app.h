// Copyright 2018 Kozorez Alexandr

#ifndef MODULES_BOOKS_INCLUDE_BOOKS_APP_H_
#define MODULES_BOOKS_INCLUDE_BOOKS_APP_H_

#include <string>

class BooksApplication {
 public:
    BooksApplication();
    std::string operator()(int argc, const char** argv);
 private:
    std::string message_;
    void Help(const char* appname, const char* message = "");
    bool ValidateNumberOfArguments(int argc, const char** argv);
    typedef struct {
        int* books;
        const char* output_file_name;
    } Arguments;
};

#endif  // MODULES_BOOKS_INCLUDE_BOOKS_APP_H_
