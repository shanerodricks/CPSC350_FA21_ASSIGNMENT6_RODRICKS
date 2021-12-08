#include "student.h"
#include "faculty.h"
#include "bst.h"

int printMenu();
void initStudent(BST<int, student> &masterStudent);
void addStudent(BST<int, student> &masterStudent);
void printStudents(BST<int, student> &masterStudent);
void deleteStudent(BST<int, student> &masterStudent);
void displayStudent(BST<int, student> &masterStudent);
void changeStuAdvisor(BST<int, student> &masterStudent);
void printFacultyInfo(BST<int, student> &masterStudent, BST<int, faculty> &masterFaculty);
void printStudentInfo(BST<int, student> &masterStudent, BST<int, faculty> &masterFaculty);

void initFaculty(BST<int, faculty> &masterFaculty);
void addFaculty(BST<int, faculty> &masterFaculty);
void printFaculty(BST<int, faculty> &masterFaculty);
void deleteFaculty(BST<int, faculty> &masterFaculty);
void displayFaculty(BST<int, faculty> &masterFaculty);
void removeAdvisee(BST<int, faculty> &masterFaculty);
void writeDataBase(BST<int, faculty> &masterFaculty, BST<int, student> &masterStudent);

int main(int argc, char **argv){
    BST<int, student> masterStudent;
    BST<int, faculty> masterFaculty;

    initStudent(masterStudent);
    initFaculty(masterFaculty);

    int input = printMenu();
    while(input != 14){
        switch (input)
        {
        case 1:
            printStudents(masterStudent);
            break;
        case 2:
            printFaculty(masterFaculty);
            break;
        case 3:
            displayStudent(masterStudent);
            break;
        case 4:
            displayFaculty(masterFaculty);
            break;
        case 5:
            printFacultyInfo(masterStudent, masterFaculty);
            break;
        case 6:
            printStudentInfo(masterStudent, masterFaculty);
            break;
        case 7:
            addStudent(masterStudent);
            break;
        case 8:
            deleteStudent(masterStudent);
            break;
        case 9:
            addFaculty(masterFaculty);
            break;
        case 10:
            deleteFaculty(masterFaculty);
            break;
        case 11:
            changeStuAdvisor(masterStudent);
            break;
        case 12:
            removeAdvisee(masterFaculty);
            break;
        case 13:
            break;
        default:
            break;  
        }
        input = printMenu();
    }
    writeDataBase(masterFaculty, masterStudent);
}

void initStudent(BST<int, student> &masterStudent){
    /*
    //creation of file object(input)
    ifstream inputFile("studentTable");
    //if statement checks if the file can open
    //if file cannot be opened, an error message is printed to the screen(input)
    if(!inputFile.is_open()){
        cout << "Could not open the file." << inputFile << endl;
        exit(1);
    }
    string temp;
    int studentId;
    string name;
    string grade;
    string major;
    double gpa;
    int advisor;

    while(inputFile >> studentId){
        inputFile >> studentId;
        getline(inputFile, temp);
        getline(inputFile, name);
        getline(inputFile, grade);
        getline(inputFile, major);
        inputFile >> gpa;
        getline(inputFile, temp);
        inputFile >> advisor;
        getline(inputFile, temp);
        getline(inputFile, temp);
        student newStudent(studentId, name, grade, major, gpa, advisor);
        masterStudent.insert(studentId, newStudent);
    }
    inputFile.close();
    */
}

void initFaculty(BST<int, faculty> &masterFaculty){
    /*
    //creation of file object(input)
    ifstream inputFile("FacultyTable");
    //if statement checks if the file can open
    //if file cannot be opened, an error message is printed to the screen(input)
    if(!inputFile.is_open()){
        cout << "Could not open the file." << inputFile << endl;
        exit(1);
    }
    string temp;
    int facultyId;
    string name;
    string level;
    string department;
    int advisee;
    int numAdvisee;

    while(inputFile >> facultyId){
        inputFile >> studentId;
        getline(inputFile, temp);
        getline(inputFile, name);
        getline(inputFile, level);
        getline(inputFile, department);
        inputFile >> department;
        getline(inputFile, temp);
        inputFile >> advisee;
        getline(inputFile, temp);
        getline(inputFile, temp);
        faculty newFaculty(facultyId, name, level, department, advisee, numAdvisee);
        masterFaculty.insert(facultyId, newFaculty);
    }
    inputFile.close();
    */
}

int printMenu(){
    int userInput;
    cout << "Choose a selection from the list: " << endl;
    cout << "1. Print all students and their information (sorted by ascending id #)" << endl;
    cout << "2. Print all faculty and their information (sorted by ascending id #)" << endl;
    cout << "3. Find and display student information given the students id " << endl;
    cout << "4. Find and display faculty information given the faculty id " << endl;
    cout << "5. Given a student’s id, print the name and info of their faculty advisor " << endl;
    cout << "6. Given a faculty id, print ALL the names and info of his/her advisees." << endl;
    cout << "7. Add a new student " << endl;
    cout << "8. Delete a student given the id " << endl;
    cout << "9. Add a new faculty member " << endl;
    cout << "10. Delete a faculty member given the id. " << endl;
    cout << "11. Change a student’s advisor given the student id and the new faculty id. " << endl;
    cout << "12. Remove an advisee from a faculty member given the ids " << endl;
    cout << "13. Rollback " << endl;
    cout << "14. Exit" << endl;
    cout << ">>";
    cin >> userInput;
    return userInput;
}

void addStudent(BST<int, student> &masterStudent){
    string temp;
    int studentId;
    string name;
    string grade;
    string major;
    double gpa;
    int advisor;
    cout << "Enter student id: ";
    cin >> studentId;
    getline(cin, temp);
    cout << "Enter name of student: ";
    getline(cin, name);
    cout << "Enter student grade: ";
    getline(cin, grade);
    cout << "Enter student major: ";
    getline(cin, major);
    cout << "Enter student gpa: ";
    cin >> gpa;
    getline(cin, temp);
    cout << "Enter student advisor: ";
    cin >> advisor;
    getline(cin, temp);

    student newStudent(studentId, name, grade, major, gpa, advisor);
    masterStudent.insert(studentId, newStudent);
}

void printStudents(BST<int, student> &masterStudent){
    masterStudent.printNodes();
}

void printFaculty(BST<int, faculty> &masterFaculty){
    masterFaculty.printNodes();
}

void addFaculty(BST<int, faculty> &masterFaculty){
    string temp;
    int facultyId;
    string name;
    string level;
    string department;
    int advisees[10];
    int numAdvisees;
    cout << "Enter faculty id: ";
    cin >> facultyId;
    getline(cin, temp);
    cout << "Enter name of faculty member: ";
    getline(cin, name);
    cout << "Enter faculty level: ";
    getline(cin, level);
    cout << "Enter the faculty member's deparment: ";
    getline(cin, department);
    cout << "Enter the number of advisees: ";
    cin >> numAdvisees;
    getline(cin, temp);
    cout << "Enter the faculty advisees: ";
    for(int i = 0; i < numAdvisees; ++i){
        cin >> advisees[i];
    }
    getline(cin, temp);
    faculty newFaculty(facultyId, name, level, department, advisees, numAdvisees);
    masterFaculty.insert(facultyId, newFaculty);
}

void deleteFaculty(BST<int, faculty> &masterFaculty){
    int facultyId;
    string temp;
    cout << "Enter the faculty id which you wish to delete: ";
    cin >> facultyId;
    getline(cin, temp);
    masterFaculty.deleteNode(facultyId);
}

void deleteStudent(BST<int, student> &masterStudent){
    int studentId;
    string temp;
    cout << "Enter the student id which you wish to delete: ";
    cin >> studentId;
    getline(cin, temp);
    masterStudent.deleteNode(studentId);
}

void displayFaculty(BST<int, faculty> &masterFaculty){
    faculty fac;
    int facultyId;
    string temp;
    cout << "Enter the faculty id which you wish to display their information: ";
    cin >> facultyId;
    getline(cin, temp);
    bool isFound = masterFaculty.find(facultyId, fac);
    if(isFound == false){
        cout << "Faculty member could not be found with given faculty ID." << endl;
    }
    else{
        cout << fac << endl;
    }
}

void displayStudent(BST<int, student> &masterStudent){
    student stu;
    int studentId;
    string temp;
    cout << "Enter the student id which you wish to display their information: ";
    cin >> studentId;
    getline(cin, temp);
    bool isFound = masterStudent.find(studentId, stu);
    if(isFound == false){
        cout << "Student could not be found with given student ID." << endl;
    }
    else{
        cout << stu << endl;
    }
}

void printFacultyInfo(BST<int, student> &masterStudent, BST<int, faculty> &masterFaculty){
    student stu;
    faculty fac;
    int studentId;
    string temp;
    cout << "Enter the student id: ";
    cin >> studentId;
    getline(cin, temp);
    bool isFound = masterStudent.find(studentId, stu);
    if(isFound == false){
        cout << "Student could not be found with given student ID." << endl;
    }
    else{
        bool isFound = masterFaculty.find(stu.advisor, fac);
        if(isFound == false){
            cout << "Advisor could not be found with given faculty ID." << endl;
        }
        else{
            cout << fac << endl;
        }
    }
}

void printStudentInfo(BST<int, student> &masterStudent, BST<int, faculty> &masterFaculty){
    student stu;
    faculty fac;
    int stuId;
    int facId;
    string temp;
    cout << "Enter the faculty ID: ";
    cin >> facId;
    getline(cin, temp);
    bool isFound = masterFaculty.find(facId, fac);
    if(isFound == false){
        cout << "Faculty member could not be found with given faculty ID. " << endl;
    }
    else{
        for(int i = 0; i < fac.numAdvisees; ++i){
            stuId = fac.advisees[i]; //
            bool isFound = masterStudent.find(stuId, stu);
            if(isFound == false){
                cout << "Student could not be found with given student ID. " << endl;
            }
            else{
                cout << stu << endl;
            }
        }
    }
}

void changeStuAdvisor(BST<int, student> &masterStudent){
    int stuId;
    int facId;
    string temp;
    student stu;
    cout << "Enter student ID: ";
    cin >> stuId;
    getline(cin, temp);
    cout << "Enter the new faculty ID of the new advisor: ";
    cin >> facId;
    getline(cin, temp);
    bool isFound = masterStudent.find(stuId, stu);
    if(isFound == false){
        cout << "The student ID entered is not valid." << endl;
    }
    else{
        stu.advisor = facId;
        isFound = masterStudent.update(stuId, stu);
        if(isFound == false){
            cout << "The student ID entered is not valid." << endl;
        }
    }
}

void removeAdvisee(BST<int, faculty> &masterFaculty){
    int facId;
    int stuId;
    string temp;
    faculty fac;
    cout << "Enter faculty members ID for which you wish to remove an advisee: ";
    cin >> facId;
    getline(cin, temp);
    cout << "Which advisee would you like to remove? Type the student ID: ";
    cin >> stuId;
    getline(cin, temp);
    bool isFound = masterFaculty.find(facId, fac);
    if(isFound == false){
        cout << "The faculty ID entered is not valid." << endl;
    }
    else{
        for(int i = 0; i < fac.numAdvisees; ++i){
            if(stuId == fac.advisees[i]){
                fac.advisees[i] = fac.advisees[fac.numAdvisees - 1];
                fac.numAdvisees--;
                break;
            }
        }
        masterFaculty.update(facId, fac);
    }
}

void writeDataBase(BST<int, faculty> &masterFaculty, BST<int, student> &masterStudent){
    masterFaculty.writeToFile("facultyTable");
    masterStudent.writeToFile("studentTable");
}