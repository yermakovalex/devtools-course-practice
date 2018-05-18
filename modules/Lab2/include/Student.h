// Copyright 2018 Matyasov Mixail
#ifndef MODULES_LAB2_INCLUDE_STUDENT_H_
#define MODULES_LAB2_INCLUDE_STUDENT_H_
#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>


const int MAX = 255;

class Student {
 private:
    int id;
    int amountMarks;
    int* marks;
    std::string sName;
    std::string group;
    static Student** students;
    static void CreateMemory(int size);
 public:
    static int delta;
    static int code;
    static int amountStudents;

    float GetId() { return id; }
    int GetAmountMarks() { return amountMarks; }
    static Student** Create_Students(const char* path);
    static void Delete_All_Students();
    explicit Student(int = 0, int = 0, int* = 0,
    std::string = "", std::string = "");
    float CalculateMediumMark();
    void PrintStatistic();
    static std::string GetGroup(int id);
    void PrintStatus();
};


#endif  // MODULES_LAB2_INCLUDE_STUDENT_H_
