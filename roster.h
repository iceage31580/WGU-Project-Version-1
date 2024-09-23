//Completes requirement B
#ifndef ROSTER_H
#define ROSTER_H

#include "student.h"
#include <string>

class Roster {
public:
    Roster(int maxSize); // Constructor
    ~Roster();           // Destructor

    void addStudent(Student* student); // Adds a student
    void add(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree degreeProgram);
    void remove(std::string studentID);     // Removes a student by ID
    void printAll();                   // Prints all students
    void printAverageDaysInCourse(std::string studentID); // Prints average days in courses
    void printInvalidEmails();         // Prints invalid emails

private:
    Student** classRosterArray;  // Pointer array to Student objects
    int maxSize;
    int currentSize;
};

#endif // ROSTER_H
