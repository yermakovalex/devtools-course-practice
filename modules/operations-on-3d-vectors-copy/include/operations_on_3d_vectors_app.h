// Copyright 2018 Krasikova Ekaterina

#ifndef MODULES_OPERATIONS_ON_3D_VECTORS_COPY_INCLUDE_OPERATIONS_ON_3D_VECTORS_APP_H_
#define MODULES_OPERATIONS_ON_3D_VECTORS_COPY_INCLUDE_OPERATIONS_ON_3D_VECTORS_APP_H_

#include <string>
#include "include/operations_on_3d_vectors.h"

class OperationsOn3dVectorsApp {
 private:
     std::string message_;
     void help(const char* appname, const char* message = "");
     bool validateNumberOfArguments(int argc, const char** argv);
     std::string appForUnaryOperations(int argc, const char** argv);
     std::string appForBinaryOperations(int argc, const char** argv);
     typedef struct {
         std::string operation;
         Vector3d v1;
         Vector3d v2;
     } Arguments;
 public:
    OperationsOn3dVectorsApp();
    std::string operator()(int argc, const char** argv);
};

#endif  // MODULES_OPERATIONS_ON_3D_VECTORS_COPY_INCLUDE_OPERATIONS_ON_3D_VECTORS_APP_H_
