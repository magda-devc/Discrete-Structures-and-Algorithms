#include <iostream>
#include <string>
using namespace std;

class Course {
public:
    string course_code;
    string course_name;

    // Default constructor
    Course() {}

    // Parameterized constructor
    Course(const string& code, const string& name) : course_code(code), course_name(name) {}
};

class Grade {
public:
    int mark;
    char the_grade;

    // Default constructor
    Grade() {}

    // Parameterized constructor
    Grade(int m) : mark(m) {
        calculateGrade();
    }

    // Function to calculate grade based on the mark
    void calculateGrade() {
        if (mark > 69) {
 the_grade = 'A';
        } else if (mark > 59) {
            the_grade = 'B';
        } else if (mark > 49) {
            the_grade = 'C';
        } else if (mark > 39) {
            the_grade = 'D';
        } else {
            the_grade = 'E';
        }
    }
};

class Student {
public:
    string reg_number;
    string name;
    int age;
    Course course;
    Grade grades;

    // Default constructor
    Student() {}

    // Parameterized constructor
    Student(const string& reg, const string& nm, int ag, const Course& crs, int mark)
        : reg_number(reg), name(nm), age(ag), course(crs), grades(mark) {}
};

class StudentDatabase {
public:
    static const int MAX_STUDENTS = 40;
 Student students[MAX_STUDENTS];
    int count = 0;

    // Function to add a student to the database
    void addStudent(const Student& student) {
        if (count < MAX_STUDENTS) {
            students[count] = student;
            ++count;
            cout << "Student added successfully!" << endl;
        } else {
            cout << "Maximum number of students reached!" << endl;
        }
    }

    // Function to display details of a specific student
    void displayStudentDetails(int index) {
        if (index >= 0 && index < count) {
            cout << "Student Details:" << endl;
            cout << "Registration Number: " << students[index].reg_number << endl;
            cout << "Name: " << students[index].name << endl;
            cout << "Age: " << students[index].age << endl;
            cout << "Course Code: " << students[index].course.course_code << endl;
            cout << "Course Name: " << students[index].course.course_name << endl;
            cout << "Mark: " << students[index].grades.mark << endl;
            cout << "Grade: " << students[index].grades.the_grade << endl;
            cout << "------------------------" << endl;
        } else {
            cout << "Invalid index." << endl;
        }
    }

    // Function to display details of all students in the database
    void displayAllStudents() {
        cout << "All Students:" << endl;
        for (int i = 0; i < count; ++i) {
            displayStudentDetails(i);
        }
    }
};

int main() {
    Course computerScience("CS101", "Computer Science");
    Grade studentGrade(85);
    Student student1("2023001", "John Doe", 20, computerScience, studentGrade.mark);

    StudentDatabase database;
    database.addStudent(student1);

    database.displayAllStudents();

    return 0;
}
