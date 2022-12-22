#include "student.h"
#include "degree.h"

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

//Student::Student() {}

string Student::getStudentId(){ //accessor
	return studentId;
}

string Student::getFirstName(){ //accessor
	return firstName;
}

string Student::getLastName(){ //accessor
	return lastName;
}

string Student::getEmailAddress(){ //accessor
	return emailAddress;
}

int Student::getAge(){ //accessor
	return age;
}

int* Student::getDaysInCourse(){ //accessor
	return daysInCourse;
}

DegreeProgram Student::getDegreeProgram(){ //accessor
	return degreeProgramEnum;
}

void Student::setStudentId(string newStudentId){ //mutator
	studentId = newStudentId;
}

void Student::setFirstName(string newFirstName){ //mutator
	firstName = newFirstName;
}

void Student::setLastName(string newLastName){ //mutator
	lastName = newLastName;
}

void Student::setEmailAddress(string newEmail){ //mutator
	emailAddress = newEmail;
}

void Student::setAge(int newAge){ //mutator
	age = newAge;
}

void Student::setDaysInCourse(int* daysInCourse){ //mutator
	for (int i = 0; i < 3; i++) {
		this->daysInCourse[i] = daysInCourse[i];
	}
}

void Student::setDegree(DegreeProgram newDegreeProgram){ //mutator
	degreeProgramEnum = newDegreeProgram;
}

void Student::print() {									// printing single student
	cout << this->getStudentId(); 
	cout << "\tFirst Name: " << this->getFirstName();	//tab separated - printing First Name using accessor;
	cout << "\tLast Name: " << this->getLastName();		//tab separated - printing Last Name using accessor;
	cout << "\tAge: " << this->getAge();				//tab separated - printing Age using accessor;
	cout << "\tDaysInCourse: {" << this->getDaysInCourse()[0] << ", " << this->getDaysInCourse()[1] << ", " << this->getDaysInCourse()[2] << "}"; //tab separated - printing days-in-course using accessor;
	
	cout << "\tDegree Program: ";						//tab separated						
	if (this->getDegreeProgram() == DegreeProgram::SECURITY) {		//in order to display the correct Degree Program
		cout << "SECURITY\n";
	}
	else if (this->getDegreeProgram() == DegreeProgram::NETWORK) {	//in order to display the correct Degree Program
		cout << "NETWORK\n";
	}
	else {			//There are only 3 different degree programs in const_array.
		cout << "SOFTWARE\n";										
	}

}

Student::Student(string studentID, string firstName, string lastName, string email, int age, int days[], DegreeProgram deg) {
	setStudentId(studentID);
	setFirstName(firstName);
	setLastName(lastName);
	setEmailAddress(email);
	setAge(age);
	setDaysInCourse(days);
	setDegree(deg);
}

Student::~Student() {} // destructor