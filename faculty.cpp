#include "faculty.h"

faculty::faculty(){
    
}

faculty::faculty(int facultyId, string name, string level, string department, int advisees[10], int numAdvisees){
    this->facultyId = facultyId;
    this->name = name;
    this->level = level;
    this->department = department;
    for(int i = 0; i < numAdvisees; ++i){
        this->advisees[i] = advisees[i];
    }
    this->numAdvisees = numAdvisees;
}

bool faculty::operator <(const faculty &f){
    if(facultyId < f.facultyId){
        return true;
    }
    else{
        return false;
    }

}
bool faculty::operator ==(const faculty &f){
    if(facultyId == f.facultyId){
        return true;
    }
    else{
        return false;
    }

}
bool faculty::operator >(const faculty &f){
    if(facultyId > f.facultyId){
        return true;
    }
    else{
        return false;
    }
}

ostream &operator << (ostream &os, const faculty &f){
    os << f.facultyId << endl;
    os << f.name << endl;
    os << f.level << endl;
    os << f.department << endl;
    for(int i = 0; i < f.numAdvisees; ++i){
        os << f.advisees[i] << endl;
    }
    return os;
}