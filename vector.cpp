#include <iostream>
#include <vector>
#include <string>

// ==== Власний клас ====
class Person {
public:
    std::string name;
    int age;

    Person(const std::string& n, int a) : name(n), age(a) {
        std::cout << "Конструктор: " << name << "\n";
    }

    ~Person() {
        std::cout << "Деструктор: " << name << "\n";
    }

    void greet() const {
        std::cout << "Привіт, мене звати " << name << ", мені " << age << " років.\n";
    }
};

// ==== Глобальна функція для демонстрації перевантаження ====
bool operator==(const Person& a, const Person& b) {
    return a.name == b.name && a.age == b.age;
}

// ==== Основна програма ====
int main() {
    // === Конструктори ===
    std::vector<int> v1;                       // Порожній
    std::vector<int> v2(5, 42);                // 5 елементів зі значенням 42
    std::vector<int> v3{1, 2, 3, 4, 5};        // Список ініціалізації

    // === Методи ===
    v3.push_back(6);                           // O(1) амортизовано
    v3.insert(v3.begin(), 0);                  // O(n)
    v3.pop_back();                             // O(1)
    v3.erase(v3.begin() + 2);                  // O(n)

    // === Цикл for по діапазону ===
    std::cout << "Вміст v3: ";
    for (int x : v3) {
        std::cout << x << " ";
    }
    std::cout << "\n";

    // === Псевдоніми ===
    using Vec = std::vector<Person>;
    using Iterator = Vec::iterator;

    // === Вектор об’єктів ===
    Vec people;
    people.emplace_back("Оксана", 25);
    people.emplace_back("Юрій", 30);

    // === Вивід через цикл ===
    for (const auto& p : people) {
        p.greet();
    }

    // === Вектор вказівників ===
    std::vector<Person*> ptrVec;
    ptrVec.push_back(new Person("Ірина", 22));
    ptrVec.push_back(new Person("Богдан", 28));

    for (const auto* ptr : ptrVec) {
        ptr->greet();
    }

    // === Очищення пам’яті ===
    for (auto* ptr : ptrVec) {
        delete ptr;
    }

    // === Спеціалізація vector<bool> ===
    std::vector<bool> flags = {true, false, true};
    for (size_t i = 0; i < flags.size(); ++i) {
        std::cout << "flags[" << i << "] = " << flags[i] << "\n";
    }

    // === Оцінка складності ===
    std::cout << "Розмір v3: " << v3.size() << ", ємність: " << v3.capacity() << "\n";

    return 0;
}
