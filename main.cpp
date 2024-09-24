//completes requirement B
#include <iostream>
#include "roster.h"
#include "degreeChosen.h"



int main() {
    // Create a Roster with a maximum size
    Roster classRoster(5);

    // Example student data addition
    classRoster.add("A1", "John", "Smith", "john.smith@example.com", 20, 30, 35, 40, Degree::Security);
    classRoster.add("A2", "Jane", "Doe  ", "jane.doe@example.com", 22, 50, 30, 40, Degree::Software);
    classRoster.add("A3", "Isaac","Marinero", "imarinero@wgu.edu", 29, 24, 24, 24, Degree::Software);

    // Print all student data
    classRoster.printAll();

    // Print invalid emails
    classRoster.printInvalidEmails();

    // Print average days in course for a specific student
    classRoster.printAverageDaysInCourse("A1");

    // Remove a student and attempt to remove a non-existing one
    classRoster.remove("A1");
    classRoster.remove("A2");
    classRoster.remove("A3");

    return 0;
}
