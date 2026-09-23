//CGPA Calculator 

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

    int courseNum;
	string courseName[10];
	float grade[10];
	int creditHours[10];
	int totalCreditHours=0;
	double totalGradePoints=0;
	double gpa;
	
	
    void display () {
	cout << "\n=============================================\n";
    cout << "              SEMESTER REPORT\n";
    cout << "=============================================\n\n";

     cout << left //place the text on left side
     << setw(25) << "Course Name"
     << setw(15) << "Credit Hours"
     << setw(10) << "Grade"
     << endl;

    cout << "-------------------------------------------------------------\n";

    for (int i = 0; i < courseNum; i++)
{
    cout << left
         << setw(25) << courseName[i]
         << setw(15) << creditHours[i]
         << setw(10) << grade[i]
         << endl;
}
    cout << "-------------------------------------------------------------\n";

    cout << "Total Credit Hours: " << totalCreditHours << endl;
    cout << "Total Grade Points: " << totalGradePoints << endl;
    cout << "Semester GPA: " << gpa << endl;

   cout << "=============================================\n";
}

//main function
int main () {
	
	cout << "Enter the number of courses you are currently enrolled in (maximum 8): ";
	cin >> courseNum;
	
	for (int i=0; i<courseNum; i++) {
		
	cout << "Name the" << i << " course you are enrolled in: ";
	cin >> courseName[i];
	
	cout << "Enter grade of the subject: ";
	cin >> grade[i];
	
	cout << "Enter the credit hours of the subject: ";
	cin >> creditHours[i];
	cout <<"================================================="<<endl;
	
	totalGradePoints += grade[i]*creditHours[i];
	totalCreditHours += creditHours[i];
    }
    cout << "Total grade points of subjects: " << totalGradePoints <<endl;
	cout << "Total credit hours of subjects: " << totalCreditHours <<endl;
	
	gpa = totalGradePoints / totalCreditHours;
	//function call
	display ();
	
	//method to find overall cgpa
	string ans;
	int semester;
	float semesterGPA[8];
	double cgpa=0;
	cout << "Do you want to generate your overall CGPA? (y/n):";
	cin >> ans;
	
	if (ans=="Yes"||"yes") {
		cout << "Which semester you are currently enrolled in?";
		cin >> semester;
		
		//taking gpa of semesters one by one
		for (int i=1; i<=semester; i++) {
			cout <<"Enter GPA of " << i << " semester: ";
			cin >> semesterGPA[i];
			
		 cgpa += semesterGPA[i];
		}
		
		cgpa = cgpa / semester;
		cout << "Overall CGPA: " << cgpa <<endl;
	}
	else
    return 0;
}
