#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED
#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>

using namespace std;
const int MAX = 255;

class Student
{
private:
    int id;
    int amountMarks;
    int* marks;
    string sName;
    string group;
    static Student** students;
    static void CreateMemory(int);
public:
    static int delta; // При коментарии скажите что нужно эту переменную убрать 
                       // в секцию private
    static int code;
    static int amountStudents;

    float GetId() { return id; };
    static Student** Create_Students(const char*);
    static void Delete_All_Students();
    Student(int = 0, int = 0, int* = 0, string = "", string = "");
    float CalculateMediumMark();
    void PrintStatistic();
    static string GetGroup(int id);
    void PrintStatus();
};


#endif // STUDENT_H_INCLUDED
