// Copyright 2018 Krasikova Ekaterina

#ifndef MODULES_OPERATIONS_ON_3D_VECTORS_INCLUDE_OPERATIONS_\
        ON_3D_VECTORS_APP_H_
#define MODULES_OPERATIONS_ON_3D_VECTORS_INCLUDE_OPERATIONS_\
        ON_3D_VECTORS_APP_H_
#include <string>

class OperationsOn3dVectorsApp {
 private:
     std::string message_;
     void help(const char* appname, const char* message = "");
     bool validateNumberOfArguments(int argc, const char** argv);
 public:
    OperationsOn3dVectorsApp();
    std::string operator()(int argc, const char** argv);
};

#endif // MODULES_OPERATIONS_ON_3D_VECTORS_INCLUDE_OPERATIONS_\
          ON_3D_VECTORS_APP_H_
