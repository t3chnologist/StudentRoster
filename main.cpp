#include <iostream>
#include <string>
#include <sstream>

#include "roster.h"
#include "degree.h"
#include "student.h"

using namespace std;

int main()
{
	const string studentData[] = {
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Batnomin,Terbish,batnomin@wgu.edu,31,34,34,55,SOFTWARE" //Included personal info in studentData[];
	};

	cout << "C867-Scripting & Programming: Applications\nLanguage: C++\nStudent ID:0011223344\nName: Batnomin Terbish\n\n";

	Roster classRoster;
	
	for (int i = 0; i < sizeof(studentData) / sizeof(studentData[0]); ++i) {

		istringstream singleStudent(studentData[i]);
		string tempData{}; // initializes/clears the tempData before the nested loop;
		string tempArray[sizeof(studentData)] = {}; // initializes/clears the tempArray before the nested loop;
		int j{}; //counter or index for tempArray to add each student to classRoster;

		while (getline(singleStudent, tempData, ',')) {
			tempArray[j] = tempData;
			j += 1;
		}
		
		DegreeProgram degree{};

		if (tempArray[8] == "NETWORK") {			// checking the degree program name againts the enumerated list  
			degree = DegreeProgram::NETWORK;
		}
		else if (tempArray[8] == "SECURITY") {		// checking the degree program name againts the enumerated list
			degree = DegreeProgram::SECURITY;
		}
		else {								// since the studentData is "const" and there are only 3 different degrees
			degree = DegreeProgram::SOFTWARE;
		}
		
		
		//adding each student to the class Roster using the classRoster object created above: 
		classRoster.add(tempArray[0], tempArray[1], tempArray[2], tempArray[3], (stoi(tempArray[4])), (stoi(tempArray[5])), (stoi(tempArray[6])), (stoi(tempArray[7])), degree); 
	}

	classRoster.printAll();
	classRoster.printInvalidEmails();
	classRoster.printAverageDaysInCourse();
	classRoster.printByDegreeProgram(DegreeProgram::SOFTWARE);
	classRoster.remove("A3"); 
	classRoster.printAll();   
	classRoster.remove("A3"); 
	
	classRoster.~Roster(); // destruction

	return 0;
}
