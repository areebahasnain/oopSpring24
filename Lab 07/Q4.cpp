/* K230059 - AREEBA HASNAIN SHAIKH */

#include <iostream>

using namespace std;

#include <iostream>
#include <string>

using namespace std;

class Person {
public:    
    string name;
    int age;

    Person(string name, int age) : name(name), age(age) {}
};

class Student : public Person {
public:
    int studentId, gradeLevel;    

    Student(string name, int age, int id, int grade) : Person(name, age), studentId(id), gradeLevel(grade) {}

    void display() {
        cout << "Name: " << name << "\n";
        cout << "Age: " << age << "\n";
        cout << "Student ID: " << studentId << "\n";
        cout << "Grade: " << gradeLevel << "\n";
    }
};

class Teacher : public Person {
public:
    string subject;
    int roomNumber;

    Teacher(string name, int age, string subject, int room) : Person(name, age), subject(subject), roomNumber(room) {}

    void display() {
        cout << "Name: " << name << "\n";
        cout << "Age: " << age << "\n";
        cout << "Subject: " << subject << "\n";
        cout << "Room Number: " << roomNumber << "\n";
    }
};

class GraduateStudent : public Student {
public:
    string subject;
    int roomNumber;

    GraduateStudent(string name, int age, int id, int grade, string subject, int room) :
        Student(name, age, id, grade), subject(subject), roomNumber(room) {}

    void display() {
        cout << "Name: " << name << "\n";
        cout << "Age: " << age << "\n";
        cout << "Student ID: " << studentId << "\n";
        cout << "Grade: " << gradeLevel << "\n";
        cout << "Subject: " << subject << "\n";
        cout << "Room Number: " << roomNumber << "\n";
    }
};

int main() {
    Teacher teacher("Areeba", 23, "Physics", 22);
    Student student("Emman", 20, 0051, 12);
    GraduateStudent graduate_student("Rumaisa", 21, 0744, 15, "Math", 13);

    teacher.display();
    cout << endl;
    student.display();
    cout << endl;
    graduate_student.display();

    return 0;
}
