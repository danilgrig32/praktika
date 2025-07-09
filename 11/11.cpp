#include <iostream>
#include <vector>
#include <string>
#include <windows.h>

using namespace std;

struct Student {
    string firstName;
    string lastName;
    int gradeYear;
    string gradeLetter;
    vector<int> marks;
};

void addStudent(vector<Student>& students, const Student& student) {
    students.push_back(student);
}

void printStudent(const Student& student) {
    cout << "Имя: " << student.firstName
         << ", Фамилия: " << student.lastName
         << ", Класс: " << student.gradeYear << student.gradeLetter
         << ", Оценки: ";
    for (int mark : student.marks) {
        cout << mark << " ";
    }
    cout << endl;
}

void printAllStudents(const vector<Student>& students) {
    for (const Student& student : students) {
        printStudent(student);
    }
}

int countAboveOrEqualFour(const vector<Student>& students) {
    int count = 0;
    for (const Student& student : students) {
        bool allAboveFour = true;
        for (int mark : student.marks) {
            if (mark < 4) {
                allAboveFour = false;
                break;
            }
        }
        if (allAboveFour) {
            count++;
        }
    }
    return count;
}

int countWithThrees(const vector<Student>& students) {
    int count = 0;
    for (const Student& student : students) {
        for (int mark : student.marks) {
            if (mark == 3) {
                count++;
                break;
            }
        }
    }
    return count;
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    vector<Student> students;

    addStudent(students, {"Иван", "Иванов", 10, "А", {5, 4, 4, 5}});
    addStudent(students, {"Мария", "Петрова", 9, "Б", {3, 3, 4, 3}});
    addStudent(students, {"Сергей", "Сидоров", 11, "В", {5, 5, 5, 5}});

    cout << "Все ученики:\n";
    printAllStudents(students);

    cout << "Учеников с оценками не ниже 4: " << countAboveOrEqualFour(students) << endl;
    cout << "Учеников с тройками: " << countWithThrees(students) << endl;

    return 0;
}
