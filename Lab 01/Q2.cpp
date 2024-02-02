#include <iostream>
using namespace std;

void calculateGrade(float average) {
    if (average >= 90)
        cout << "Grade: A\n";
    else if (average >= 80)
       cout << "Grade: B\n";
    else if (average >= 70)
        cout << "Grade: C\n";
    else if (average >= 60)
        cout << "Grade: D\n";
    else
        cout << "Grade: F\n";
}
 
int main() {
    int students, subjects=3;
    cout << "Enter the number of students: ";
    cin >> students;
    
    int math, english, science;
    for(int i = 1; i<= students; i++){
        cout << "Enter marks of student " << i << ":\n";
        cout << "enter marks of mathematics: ";
        cin >> math;
        cout << "enter marks of science: ";
        cin >> science;
        cout << "enter marks of english: ";
        cin >> english;
        
        cout << "Math: " << math << "\n";
        cout << "English: " << english << "\n";
        cout << "Science: " << science << "\n";

        int totalMarks = math + english + science;
        float avg = totalMarks/3;
        cout << "Total Average: " << avg << "\n";
        calculateGrade(avg);
        }
}