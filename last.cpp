#include <iostream>
#include <list>
using namespace std;

// Створюємо простий клас Person з ім’ям і віком
class Person {
public:
    string name;
    int age;

    // Конструктор за замовчуванням
    Person() : name(""), age(0) {}

    // Конструктор з параметрами
    Person(string n, int a) : name(n), age(a) {}

    // Метод для виводу об’єкта Person
    void print() const {
        cout << name << " (" << age << " років)" << endl;
    }

    // Оператор порівняння за віком
    bool operator<(const Person& other) const {
        return age < other.age;
    }
};

// Функція для виводу списку осіб
void printList(const list<Person>& people) {
    for (const Person& p : people)
        p.print();
}

int main() {
    // створюємо список типу list, який зберігає об'єкти Person
    list<Person> people;

    // додаємо елементи в кінець списку
    people.push_back(Person("Іван", 30));
    people.push_back(Person("Оля", 25));
    people.push_back(Person("Марко", 35));

    // виводимо список
    cout << "Список осіб:" << endl;
    printList(people);

    // вставляємо елемент на початок
    people.push_front(Person("Софія", 28));

    // видаляємо перший елемент
    people.pop_front();

    // сортуємо за віком
    people.sort();

    // ще раз виводимо, тепер відсортований список
    cout << "\nВідсортований список:" << endl;
    printList(people);

    return 0;
}
