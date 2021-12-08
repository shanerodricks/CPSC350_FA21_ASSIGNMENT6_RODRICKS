#ifndef FACULTY_H
#define FACULTY_H
#include <string>
#include <iostream>
using namespace std;

class faculty{
    public:
        int facultyId;
        string name;
        string level;
        string department;
        int advisees[10];
        int numAdvisees;
        faculty();
        faculty(int facultyId, string name, string level, string department, int advisees[10], int numAdvisees);
        bool operator <(const faculty &f);
        bool operator ==(const faculty &f);
        bool operator >(const faculty &f);
        friend ostream &operator << (ostream &os, const faculty &f);
        

};

#endif