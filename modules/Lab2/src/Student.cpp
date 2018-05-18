// Copyright 2018 Matyasov Mixail
#include"Student.h"

ifstream *file;

int Student::amountStudents = 0;
int Student::code = 0;
int Student::delta = 1;
Student** Student::students;

void Student::CreateMemory(int amountStudents) {
    int lenght = 10;

    if (amountStudents == (delta - 1) * lenght) {

        if (amountStudents == 0) {
            students = new Student*[lenght];
            for (int i = 0; i < lenght; i++)
                 students[i] = new Student();
        }
        else {
            Student** buf = new Student*[amountStudents];
            for (int i = 0; i < amountStudents; i++)
                buf[i] = students[i];

            students = new Student*[lenght * delta];

            for (int i = 0; i < amountStudents; i++)
                students[i] = buf[i];

            delete[] buf;
        }
        delta++;
    }
}

Student** Student::Create_Students(const char* path) {// в файле в конце каждой строки нужно ставить 1 пробел
    code = 0;
    file = new ifstream(path);
    if (file->is_open()) {
        string buf;
        string line;
        int count = 0;
        int countStudents = 0;

        while (getline(*file,buf)) {

            CreateMemory(countStudents);
            for (unsigned int i = 0; i < buf.length(); i++) {

                if (buf[i] != ' ') {

                    line += buf[i];
                }
                else {

                    switch (count) {

                    case 0:
                        students[countStudents]->id = atoi(line.c_str());
                        break;
                    case 1:
                        students[countStudents]->sName = line;
                        break;
                    case 2:
                        students[countStudents]->marks = new int[line.length()];
                        for (unsigned int i = 0; i < line.length(); i++) {

                            students[countStudents]->marks[i] = line[i] - '0';
                            students[countStudents]->amountMarks++;
                        }
                        break;
                    default:
                        students[countStudents]->group = line;
                        break;
                    }
                    line = "";
                    count++;
                }
            }
            countStudents++;
            count = 0;
            line = "";
        }
        amountStudents = countStudents;
    }
    else {

        code = 1;
        return NULL;
    }
    return students;
}

void Student::Delete_All_Students() {
    for (int i = 0; i < amountStudents; i++)
        delete[] students[i]->marks;

    amountStudents = 0;
}

Student::Student(int id, int amountmarks, int * marks, string sName, string group) {
    this->id = id;
    this->amountMarks = amountmarks;
    this->marks = new int[amountmarks];
    for (int i = 0; i < amountmarks; i++)
        this->marks[i] = marks[i];
    this->sName = sName;
    this->group = group;

    if (amountStudents == 0)
        students = new Student*[MAX];
    students[amountStudents] = this;
    amountStudents++;
}

float Student::CalculateMediumMark() {
    float sum = 0;
    for (int i = 0; i < amountMarks; i++)
         sum += marks[i];
    return sum / amountMarks;
}

void Student::PrintStatistic() {
    std::cout << endl << "---------------------------------------------";
    std::cout << endl;
    std::cout << "Id: " << id << endl;
    std::cout << "Marks: ";
    for (int i = 0; i < amountMarks; i++) {

        cout << marks[i];
    }
    std::cout << endl;
    std::cout << "sName: ";
    for (unsigned int i = 0; i < sName.length(); i++) {

         std::cout << sName[i];
    }
    std::cout << endl;

    float mediumMark = CalculateMediumMark();
    std::cout << "MediumMark: " << mediumMark << endl;
    std::cout << "Group: ";
    for (unsigned int i = 0; i < group.length(); i++)
        std::cout << group[i];
    std::cout << endl;
    PrintStatus();
    std::cout << "---------------------------------------------" << endl;
}

string Student::GetGroup(int id) {
    int i;
    for (i = 0; i < amountStudents; i++)
        if (students[i]->id == id)
           break;

    return students[i]->group;
}

void Student::PrintStatus() {
    std::cout << "Status: ";
    float mark = CalculateMediumMark();
    if (mark >= 4.5 && mark <= 5)
        std::cout << "Excellent";
    else if (mark >= 3.5 && mark < 4.5)
        std::cout << "Good";
    else if (mark >= 2.5 && mark < 3.5)
        std::cout << "Bad";
    else
        std::cout << "Very bad";
    std::cout << endl;
}
