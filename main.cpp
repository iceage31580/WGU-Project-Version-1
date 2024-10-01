//completes requirement B
#include <iostream>
#include "roster.h"
#include "degreeChosen.h"



int main() {

    std::cout << "Course Title: Scripting and Programming-Applications-C867" << std::endl;
    std::cout << "Student ID:011269210" << std::endl;
    std::cout << "Name: Isaac Marinero " << std::endl;
    std::cout << "\n";
    std::cout << "\n";
    // Create a Roster with a maximum size
    Roster classRoster(5);

    /*
    const std::string studentData[] =
    {
     "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
     "A2,Suzan,Erickson,Erickson_1990@gmail.com,19,50,30,40,NETWORK",
     "A3,Jack,Napoli,The_lawyer99@yahoo.com,19,20,40,33,SOFTWARE",
     "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
     "A5,[firstname],[lastname],[emailaddress],[age], [numberofdaystocomplete3courses],SOFTWARE"
    };
    */



    classRoster.add("A1", "John", "Smith", "john.smith@example.com", 20, 30, 35, 40, Degree::Security);
    classRoster.add("A2","Suzan","Erickson","Erickson_1990@gmail.com",19,50,30,40,Degree::Network);
    classRoster.add("A3","Jack","Napoli","The_lawyer99@yahoo.com",19,20,40,33,Degree::Software);
    classRoster.add("A4","Erin","Black","Erin.black@comcast.net",22,50,58,40,Degree::Security);
    classRoster.add("A5","Isaac","Marinero","arnoldomarinero@gmail.com",29,7,52,97,Degree::Software);

    // Print all student data
    classRoster.printAll();
    std::cout << "\n";

    // Print invalid emails
    classRoster.printInvalidEmails();


    // Print average days in course for a specific student
    classRoster.printAverageDaysInCourse("A1");
    classRoster.printAverageDaysInCourse("A2");
    classRoster.printAverageDaysInCourse("A3");
    classRoster.printAverageDaysInCourse("A4");
    classRoster.printAverageDaysInCourse("A5");

    // Remove a student and attempt to remove a non-existing one
    std::cout << "\n";
    classRoster.remove("A1");
    classRoster.remove("A2");
    classRoster.remove("A3");
    classRoster.remove("A4");
    classRoster.remove("A5");


    return 0;
}
