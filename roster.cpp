//completes requirement B
#include <iostream>
#include <sstream>
//string stream allows for string operations to occur
#include "roster.h"
using namespace std;


/*Constructor to initialize maxSize, sets to 0,
and allocates memory for an array of student pointers*/
Roster::Roster(int maxSize) {
    this->maxSize = maxSize;
    this->currentSize = 0;
    classRosterArray = new Student*[maxSize];
}

/*Destructor deletes student object in classRosterArray,
 frees allocated memory of array*/
Roster::~Roster() {
    for (int i = 0; i < currentSize; i++) {
        delete classRosterArray[i];
    }
    delete[] classRosterArray;
}

/* Adds a student object to classRosterArray
if there is no space, it'll create an error message*/
void Roster::addStudent(Student* student) {
    if (currentSize < maxSize) {
        classRosterArray[currentSize++] = student;
    } else {
        cout << "Roster is full. Cannot add more students." << endl;
    }
}

/* creates new student object
   adds to classRosterArray by calling addStudent*/
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree degreeProgram) {
    int daysInCourseArray[3] = {daysInCourse1, daysInCourse2, daysInCourse3};
    Student* newStudent = new Student(studentID, firstName, lastName, emailAddress, age, degreeProgram);
    addStudent(newStudent);
}

/* Removes the student with the given ID from classRosterArray
shifts remaining elements left
prints not found or error message
*/
void Roster::remove(string studentID) {
    bool found = false;
    for (int i = 0; i < currentSize; i++) {
        if (classRosterArray[i]->getStudentID() == studentID) {
            delete classRosterArray[i];
            for (int j = i; j < currentSize - 1; j++) {
                classRosterArray[j] = classRosterArray[j + 1];
            }
            currentSize--;
            found = true;
            cout << "Student " << studentID << " removed from roster." << endl;
            break;
        }
    }
    if (!found) {
        cout << "Error: Student ID " << studentID << " not found." << endl;
    }
}

//prints student details in classRosterArray
void Roster::printAll() {
    for (int i = 0; i < currentSize; i++) {
        classRosterArray[i]->print();
    }
}

//finds student by ID
//calculate average number of days spent in courses
void Roster::printAverageDaysInCourse(string studentID) {
    for (int i = 0; i < currentSize; i++) {
        if (classRosterArray[i]->getStudentID() == studentID) {
            int* days = classRosterArray[i]->getDaysInCourse();  // Assuming getDaysInCourse() returns an array
            int average = (days[0] + days[1] + days[2]) / 3;
            cout << "Average days in course for student " << studentID << ": " << average << endl;
            return;
        }
    }
}

//Check each student's email for invalid formats
//prints invalid emails
void Roster::printInvalidEmails() {
    for (int i = 0; i < currentSize; i++) {
        string email = classRosterArray[i]->getEmailAddress();
        if (email.find('@') == string::npos || email.find('.') == string::npos || email.find(' ') != string::npos) {
            cout << "Invalid email: " << email << endl;
        }
    }
}
