// Copyright 2018 Novikova Alisa

#ifndef MODULES_ACADEMICPEFACCES_INCLUDE_ACADEMICPEFACCES_H_
#define MODULES_ACADEMICPEFACCES_INCLUDE_ACADEMICPEFACCES_H_
#define max 255
#include <string>

class AcademicPefAcces {
public:
	AcademicPefAcces();
	std::string operator()(int argc, const char** argv);

private:
	void help(const char* appname, const char* message = "");
	bool validateNumberOfArguments(int argc, const char** argv);
	std::string message_;
	typedef struct {
		int id;
		int amountMarks;
		int marks[max];
		std::string sName;
		std::string operation;
	} Arguments;
};

#endif  // MODULES_ACADEMICPEFACCES_INCLUDE_ACADEMICPEFACCES_H_