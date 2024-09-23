//Completes Requirement B
#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED
#include "degreeChosen.h"
#include <string>

class Student {
public:
    Student(const std::string& studentID, const std::string& firstName, const std::string& lastName,
            const std::string& emailAddress, int age, Degree degree);

    std::string getStudentID() const;
    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getEmailAddress() const;
    int getAge() const;
    Degree getDegree() const;

    void setStudentID(const std::string& studentID);
    void setFirstName(const std::string& firstName);
    void setLastName(const std::string& lastName);
    void setEmailAddress(const std::string& emailAddress);
    void setAge(int age);
    void setDegree(Degree degree);

    void print() const;  // Add this function to print student details

private:
    std::string studentID;
    std::string firstName;
    std::string lastName;
    std::string emailAddress;
    int age;
    Degree degree;
    int daysInCourse[3]; // Add this array to track days in courses
};

#endif // STUDENT_H_INCLUDED
