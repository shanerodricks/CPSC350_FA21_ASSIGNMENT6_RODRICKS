#include "student.h"

student::student(){
    
}

student::student(int studentId, string name, string grade, string major, double gpa, int advisor){
    this->studentId = studentId;
    this->name = name;
    this->grade = grade;
    this->major = major;
    this->gpa = gpa;
    this->advisor = advisor;
}

bool student::operator <(const student &s){
    if(studentId < s.studentId){
        return true;
    }
    else{
        return false;
    }
}

bool student::operator ==(const student &s){
    if(studentId == s.studentId){
        return true;
    }
    else{
        return false;
    }

}

bool student::operator >(const student &s){
    if(studentId > s.studentId){
        return true;
    }
    else{
        return false;
    }
}

ostream &operator << (ostream &os, const student &s){
    os << s.studentId << endl;
    os << s.name << endl;
    os << s.grade << endl;
    os << s.major << endl;
    os << s.gpa << endl;
    os << s.advisor << endl;
    return os;
}