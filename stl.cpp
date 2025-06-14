#include <iostream>
#include <vector>
using namespace std;

struct Student {
    string name;
    int age;
    double grade;

    void print() const {
        cout << "Ім'я: " << name << ", Вік: " << age << ", Бал: " << grade << endl;
    }
};

int main() {
    vector<Student> students = {
        {"Анна", 19, 91.5},
        {"Богдан", 21, 78.0},
        {"Катерина", 20, 87.3},
        {"Дмитро", 22, 60.0},
        {"Єва", 18, 95.1}
    };

    cout << "Студенти з балом > 85:\n";
    for (const auto& s : students) {
        if (s.grade > 85) s.print();
    }

    cout << "\nЗаміна студентів з балом < 70:\n";
    for (auto& s : students) {
        if (s.grade < 70) s = {"Незараховано", 0, 0.0};
        s.print();
    }

    cout << "\nСтуденти з віком > 20:\n";
    for (const auto& s : students) {
        if (s.age > 20) s.print();
    }

    cout << "\nПошук студента з балом 95.1:\n";
    for (const auto& s : students) {
        if (s.grade == 95.1) {
            s.print();
            break;
        }
    }

    cout << "\nЗбільшення віку на 1 рік:\n";
    for (auto& s : students) {
        s.age++;
        s.print();
    }

    return 0;
}
