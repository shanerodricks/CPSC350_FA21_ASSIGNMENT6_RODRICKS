#ifndef STUDENT_H
#define STUDENT_H
#include <string>
#include <iostream>
using namespace std;

class student{
    public:
        int studentId;
        string name;
        string grade;
        string major;
        double gpa;
        int advisor;
        student();
        student(int studentId, string name, string grade, string major, double gpa, int advisor);
        bool operator <(const student &s);
        bool operator ==(const student &s);
        bool operator >(const student &s);
        friend ostream &operator << (ostream &os, const student &s);

};

#endif