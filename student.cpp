//completes requirement B
#include <iostream>
#include "student.h"
using namespace std;

//class student requirement D.1
Student::Student(const string& studentID, const string& firstName, const string& lastName,
                 const string& emailAddress, int age, Degree degree)
    : studentID(studentID), firstName(firstName), lastName(lastName),
      emailAddress(emailAddress), age(age), degree(degree) {
    cout << "Student Object Created" << endl;
}

//D.2 Accessors
string Student::getStudentID() const { return studentID; }
string Student::getFirstName() const { return firstName; }
string Student::getLastName() const { return lastName; }
string Student::getEmailAddress() const { return emailAddress; }
int Student::getAge() const { return age; }
Degree Student::getDegree() const { return degree; }

//D.2 Mutator
void Student::setStudentID(const string& studentID) { this->studentID = studentID; }
void Student::setFirstName(const string& firstName) { this->firstName = firstName; }
void Student::setLastName(const string& lastName) { this->lastName = lastName; }
void Student::setEmailAddress(const string& emailAddress) { this->emailAddress = emailAddress; }
void Student::setAge(int age) { this->age = age; }
void Student::setDegree(Degree degree) { this->degree = degree; }

//D.2 Print() requirements
void Student::print() const {
    cout << "Student ID: " << studentID << "\t"
         << "First Name: " << firstName << "\t"
         << "Last Name: " << lastName << "\t"
         << "Age: " << age << "\t"
         << "Degree Program: " << static_cast<int>(degree) << endl; // Cast enum to int for simplicity
}
