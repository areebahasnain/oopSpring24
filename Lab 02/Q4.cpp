/* K230059 - AREEBA HASNAIN SHAIKH */
/* Task Desciption: establish a Student Registration System using structures. Define "Register" with course details and "Student," 
inheriting from "Register," with additional student information. The program should create an array for five students, take user 
input for their details, and then display the collected information for all students. */

#include <iostream>

using namespace std;

struct Register {
    int courseId;
    string coursename;
};

struct Student {
    Register reg;
    int studentId;
    string firstName;
    string lastName;
    string cellNo;
    string email;
};

int main() {
    Student student[5];
    for(int i=0; i<5; i++){
        cout << "Enter student " << i+1 << " information: " << endl;
        cout << "Course ID: ";
        cin >> student[i].reg.courseId;
        cin.ignore();
        cout << "Course Name: " ;
        getline (cin, student[i].reg.coursename);
        cout << "First Name: ";
        cin >> student[i].firstName;
        cout << "Last Name: ";
        cin >> student[i].lastName;
        cout << "Cell Number: ";
        cin >> student[i].cellNo;
        cout << "Email: ";
        cin >> student[i].email;
        cout << endl;

    }
   
    cout << "Student Information: ";
    for (int i=0; i<5; i++){
        cout << "Student " << i+1 << " :";
        cout << "Course ID: " << student[i].reg.courseId;
        cout << "Course Name: " << student[i].reg.courseId;
        cout << "First Name: " << student[i].firstName;
        cout << "Last Name: " << student[i].lastName;
        cout << "Cell Number: " << student[i].cellNo;
        cout << "Email: " << student[i].email;
       
    }
   
    return 0;
}