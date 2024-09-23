//completes requirement B
#include <iostream>
#include <sstream>
#include "roster.h"
using namespace std;



Roster::Roster(int maxSize) {
    this->maxSize = maxSize;
    this->currentSize = 0;
    classRosterArray = new Student*[maxSize];
}

Roster::~Roster() {
    for (int i = 0; i < currentSize; i++) {
        delete classRosterArray[i];
    }
    delete[] classRosterArray;
}

void Roster::addStudent(Student* student) {
    if (currentSize < maxSize) {
        classRosterArray[currentSize++] = student;
    } else {
        cout << "Roster is full. Cannot add more students." << endl;
    }
}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree degreeProgram) {
    int daysInCourseArray[3] = {daysInCourse1, daysInCourse2, daysInCourse3};
    Student* newStudent = new Student(studentID, firstName, lastName, emailAddress, age, degreeProgram);
    addStudent(newStudent);
}

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

void Roster::printAll() {
    for (int i = 0; i < currentSize; i++) {
        classRosterArray[i]->print();
    }
}

void Roster::printAverageDaysInCourse(string studentID) {
    for (int i = 0; i < currentSize; i++) {
        if (classRosterArray[i]->getStudentID() == studentID) {
            // Add logic to calculate and print average days in courses
        }
    }
}

void Roster::printInvalidEmails() {
    for (int i = 0; i < currentSize; i++) {
        string email = classRosterArray[i]->getEmailAddress();
        if (email.find('@') == string::npos || email.find('.') == string::npos || email.find(' ') != string::npos) {
            cout << "Invalid email: " << email << endl;
        }
    }
}
