#pragma once
#ifndef ROSTER_H
#define ROSTER_H

#include "student.h"

class Roster {
public:
	Student* classRosterArray[5] = {};   // array of pointers to hold data from "studentData table";

	void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram deg); 
	void remove(string studentID);
	void printAll();
	void printAverageDaysInCourse();
	void printInvalidEmails();
	void printByDegreeProgram(DegreeProgram deg);
	int rosterCtr{};
	
private:
	int sizeOfRoster = sizeof(classRosterArray) / sizeof(classRosterArray[0]); //this "size" will be used in few loops
};
#endif // !ROSTER_H
