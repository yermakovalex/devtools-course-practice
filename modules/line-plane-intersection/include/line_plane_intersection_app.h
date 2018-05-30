// Copyright 2018 Lvova Alina

#ifndef MODULES_LINE_PLANE_INTERSECTION_INCLUDE_LINE_PLANE_INTERSECTION_APP_H_
#define MODULES_LINE_PLANE_INTERSECTION_INCLUDE_LINE_PLANE_INTERSECTION_APP_H_

#include <string>
#include "C:\Users\Лена\Downloads\devtools-course-practice-master\devtools-course-practice-master\modules\line-plane-intersection\include\line_plane_intersection.h"

class LinePlaneIntersectionApp {
private:
    std::string message_;
    void Help(const char* appname, const char* message = "");
    bool ValidateNumberOfArguments(int argc, const char** argv);
    typedef struct {
        std::string operation;
        Dot* plane;
        Dot* line;
    } Arguments;
public:
    LinePlaneIntersectionApp();
    std::string operator()(int argc, const char** argv);
};

#endif  // MODULES_LINE_PLANE_INTERSECTION_INCLUDE_LINE_PLANE_INTERSECTION_APP_H_
