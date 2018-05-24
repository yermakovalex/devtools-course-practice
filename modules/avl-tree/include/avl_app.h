// Copyright 2018 Tarakanov Kirill

#include <string>

enum operation {
    Add, Remove, FindMin, RemoveMin, Search
};

class AVL_App {
public:
    AVL_App();
    std::string operator()(int argc, const char** argv);
private:
    void help(const char* appname, const char* message = "");
    bool validateNumberOfArguments(int argc, const char** argv);
    std::string message_;
};
