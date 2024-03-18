/* K230059 - AREEBA HASNAIN SHAIKH */

#include<iostream>

using namespace std;

class Course {
public:
    string courseName, courseCode;
    int creditHours;

    Course(string name = "", string code = "", int ch = 0) : courseName(name), courseCode(code), creditHours(ch) {}
};

class Student {
private:
    string name, id;
    Course* courses;
    int num_courses;

public:
    // initialize the num_courses variable to zero. As the student enrolls in courses, this variable will be incremented to reflect the actual number of enrolled courses.
    // initialize the courses pointer to a null pointer. Later, when the student enrolls in courses, this pointer will be dynamically allocated memory to store the enrolled courses
    Student(string name, string id) : name(name), id(id), courses(nullptr), num_courses(0) {}

    void enroll(const Course& course) {
        // increase the size of the new array by one to accommodate the newly enrolled course
        Course* new_courses = new Course[num_courses + 1];
        // copy the existing courses from the old array to the new array
        for (int i = 0; i < num_courses; i++) {
            new_courses[i] = courses[i];
        }
        // add the newly enrolled course to the end of the new array
        new_courses[num_courses] = course;
        // delete the old array of courses since all the existing courses have now been copied to the new array
        delete[] courses;
        // update the courses pointer to point to the new array
        courses = new_courses;
        // increment num_courses
        num_courses++;
    }

    void drop(const Course& course) {
        // decrease the size of the new array by one to remove the dropped course
        Course* new_courses = new Course[num_courses - 1];
        int new_num_courses = 0; // Counter for the new array
        for (int i = 0; i < num_courses; i++) {
            // Check if the current course is the one to be dropped.
            if (courses[i].courseCode == course.courseCode) {
                continue; // Skip copying this course
            }
            // If the current course is not the one to be dropped, copy it to the new array.
            new_courses[new_num_courses++] = courses[i];
        }
        // delete the old array of courses 
        delete[] courses;
        // update the courses pointer
        courses = new_courses;
        // update the number of enrolled courses
        num_courses = new_num_courses;
    }

    int getTotalCreditHours() {
        int ch = 0;
        for (int i = 0; i < num_courses; i++)
            ch += courses[i].creditHours;
        return ch;
    }

    void printEnrolledCourses() {
        for (int i = 0; i < num_courses; i++) {
            cout << "Course[" << i + 1 << "]" << endl;
            cout << "Code: " << courses[i].courseCode << endl;
            cout << "Name: " << courses[i].courseName << endl;
            cout << "Credit Hours: " << courses[i].creditHours << endl << endl;
        }
    }
};

int main() {
    Course dld("Digital Logic Design", "123ABC" , 3);
    Course oop("Object Oriented Programming", "321CBA", 3);
    Course ew("Expository Writing", "456DEF", 2);

    Student student("Areeba", "23K0059");

    student.enroll(dld);
    student.enroll(oop);
    student.enroll(ew);

    student.printEnrolledCourses();
    cout << "Total Credit Hours: " << student.getTotalCreditHours() << endl;

    cout << endl;
    student.drop(oop);
    cout << "--UPDATED COURSE INFO--"<< endl << endl;
    student.printEnrolledCourses();
    cout << "Total Credit Hours: " << student.getTotalCreditHours() << endl;

    return 0;
}