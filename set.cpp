#include <iostream>
#include <set>
#include <string>

struct Person {
    std::string name;
    int age;

    // Оператор < для порівняння — необхідний для std::set
    bool operator<(const Person& other) const {
        return name < other.name; // Порівнюємо лише за ім'ям для простоти
    }
};

int main() {
    std::set<Person> people;

    people.insert({"Андрій", 28});
    people.insert({"Олена", 31});
    people.insert({"Андрій", 35}); // Не додасться, бо ім’я "Андрій" вже є

    for (const auto& person : people) {
        std::cout << person.name << " — " << person.age << " років\n";
    }

    return 0;
}
