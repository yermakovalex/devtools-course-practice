// Copyright 2018 Pozdeeva Varvara

#ifndef MODULES_QUICK_SORT_INCLUDE_Q_SORT_APP_H_
#define MODULES_QUICK_SORT_INCLUDE_Q_SORT_APP_H_

#include <string>
#include <vector>

class QuickSortApp {
 public:
    QuickSortApp();
    std::string operator()(int argc, const char** argv);

 private:
    void help(const char* appname, const char* message = "");
    bool validateNumberOfArguments(int argc, const char** argv);
    std::string message_;
    typedef struct {
        int num;
        int first;
        int last;
        std::vector<int> mas;
    } Arguments;
};

#endif  // MODULES_QUICK_SORT_INCLUDE_Q_SORT_APP_H_
