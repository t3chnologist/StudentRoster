#include <iostream>
#include <string>

#include "roster.h"
#include "degree.h"
#include "student.h"
using namespace std;

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram deg) { 

	int days[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };
	classRosterArray[rosterCtr] = new Student(studentID, firstName, lastName, emailAddress, age, days, deg);
	rosterCtr += 1; 
}

void Roster::printAll() {							//printing all students;
	cout << "Displaying all students:\n";			
	for (int i = 0; i < sizeOfRoster; ++i) {
		if (classRosterArray[i] != nullptr) {		//checking nullptr since 1 or more of the students could be removed
			classRosterArray[i]->print();
		}
	}
}

void Roster::printAverageDaysInCourse() {			//printing average days in course;
	for (int i = 0; i < sizeOfRoster; ++i) {
		int* courseDays = classRosterArray[i]->getDaysInCourse();
		cout << "\nStudent ID: " << classRosterArray[i]->getStudentId() << ", averages " << (courseDays[0] + courseDays[1] + courseDays[2]) / 3 << " days in a course.";
		}
}

void Roster::printByDegreeProgram(DegreeProgram deg) {		//print students info by given Degree Program

	cout << "\n\nShowing students in degree program: ";		
	if (deg == DegreeProgram::NETWORK)						//in order to display the correct Degree Program
		cout << "NETWORK\n";							
	else if (deg == DegreeProgram::SECURITY)				//in order to display the correct Degree Program
		cout << "SECURITY\n";
	else cout << "SOFTWARE\n";			//since the studentData is "const" and there are only 3 different degrees
		
	
	for (int i = 0; i < sizeOfRoster; ++i) {
		DegreeProgram check = classRosterArray[i]->getDegreeProgram();
		if (check == deg) {									//
			classRosterArray[i]->print();
		}
	}
}

void Roster::remove(string studentID) {			// removing student;
	
	bool studentExist = { false };

	for (int i = 0; i < sizeOfRoster; ++i) {
		
		string tempID{};

		if (classRosterArray[i] != nullptr) {					//checking nulptr since 1 or more students could be removed
			tempID = classRosterArray[i]->getStudentId();		
		}
		if (tempID == studentID) {
			cout << "\nRemoving " << tempID << " ...";
			
			classRosterArray[i] = nullptr;						//re-assigning a null pointer to remove student;
				
			classRosterArray[i] = classRosterArray[i + 1];		//re-structuring the array ...
			classRosterArray[i + 1] = classRosterArray[i + 2];	//re-structuring the array ...
			classRosterArray[sizeOfRoster - 1] = nullptr;		//re-structuring the array ...
			
			cout << " Successful!\n\n";
			studentExist = { true };							//updating bool to "true" if students exist, so that it won't print out the incorrect message;
			break;
		}
	} 
	if (!studentExist) {
		cout << "\nThe student with the ID: " << studentID << " was not found\n\n";
	}
}

void Roster::printInvalidEmails() {								//printing invalid emails;

	cout << "\nDisplaying invalid emails:\n\n";

	for (int i = 0; i < sizeOfRoster; ++i) {
		
		string tempEmail = classRosterArray[i]->getEmailAddress(); //using accessor -> storing current email to temp container
		bool isValid = false;
		
		size_t checkSpace = tempEmail.find(' '); // checking ' ' space;
		if (checkSpace != string::npos) {
			cout << tempEmail << " - no spaces allowed.\n";
		}
		
		size_t checkAtSign = tempEmail.find('@'); // checking '@' symbol;
		if (checkAtSign == string::npos) {
			cout << tempEmail << " - missing an @ symbol.\n";
		}
		
		size_t checkPeriod = tempEmail.find('.'); // checking '.' period;
		if (checkPeriod == string::npos) {
			cout << tempEmail << " - missing a period.\n";
		}
		
	}
}