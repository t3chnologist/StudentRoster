#pragma once
#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>

#include "degree.h"

using namespace std;

class Student { //RUBRIC D1: Create class Student with correct variables; 

private:
	string studentId{}, firstName{}, lastName{}, emailAddress{};
	int age{}, daysInCourse[3];
	DegreeProgram degreeProgramEnum;

public:
	Student();
	Student(string, string, string, string, int, int days[], DegreeProgram); 
	
	
	void setStudentId(string);        //mutator
	void setFirstName(string);        //mutator
	void setLastName(string);         //mutator
	void setEmailAddress(string);     //mutator
	void setAge(int);                 //mutator
	void setDaysInCourse(int days[]); //mutator
	void setDegree(DegreeProgram);    //mutator
	void print();
	
	DegreeProgram getDegreeProgram(); //accessor
	DegreeProgram degreeType;

	string getStudentId();            //accessor
	string getFirstName();            //accessor
	string getLastName();             //accessor
	string getEmailAddress();         //accessor
	
	int getAge();                     //accessor
	int* getDaysInCourse();           //accessor
	
	~Student();
};
#endif


