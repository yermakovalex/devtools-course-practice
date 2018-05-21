// Copyright 2018 Kozorez Alexandr

#ifndef BOOKS_CLASS_INCLUDE_APPLICATION_H_
#define BOOKS_CLASS_INCLUDE_APP_H_

#include <string>

class BooksApplication
{
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

#endif // !BOOKS_CLASS_INCLUDE_APPLICATION_H_
