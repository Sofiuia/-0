#include <iostream>
#include <map>
#include <string>

// Власний клас
struct Person {
    std::string name;
    int age;

    // Для виведення
    void display() const {
        std::cout << name << ", " << age << " років\n";
    }
};

// Основна програма
int main() {
    // Псевдоніми-члени (просто демонстрація)
    using MapType = std::map<int, Person>;
    using KeyType = MapType::key_type;
    using MappedType = MapType::mapped_type;
    using Iterator = MapType::iterator;

    // Створення map
    MapType people;

    // Використання оператора [] (O(log n))
    people[1] = {"Олег", 28};
    people[3] = {"Катерина", 34};

    // insert – не переписує існуючий ключ (O(log n))
    people.insert({2, {"Ігор", 31}});
    people.insert({1, {"Дубль Олег", 99}}); // не змінить існуючий

    // at – виняток при відсутності ключа (O(log n))
    try {
        Person& p = people.at(2);
        p.age += 1; // Ігор тепер старший на рік
    } catch (const std::out_of_range&) {
        std::cout << "Ключ не знайдено\n";
    }

    // find – пошук за ключем (O(log n))
    Iterator it = people.find(3);
    if (it != people.end()) {
        std::cout << "Знайдено людину з ключем 3: ";
        it->second.display();
    }

    // count – кількість елементів із заданим ключем (0 або 1 для map)
    if (people.count(5) == 0) {
        std::cout << "Ключ 5 відсутній\n";
    }

    // erase – видалення за ключем (O(log n))
    people.erase(1);

    // Обхід елементів (впорядковані за ключем)
    std::cout << "\nУсі учасники:\n";
    for (const auto& [id, person] : people) {
        std::cout << "ID: " << id << " → ";
        person.display();
    }

    // clear – повне очищення (O(n))
    people.clear();
    std::cout << "\nКонтейнер після clear(): " << (people.empty() ? "порожній" : "не порожній") << '\n';

    return 0;
}
