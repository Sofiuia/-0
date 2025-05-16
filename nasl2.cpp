#include <iostream>
using namespace std;

// Базовий клас
class Animal {
protected:
    string name; // protected - доступний у похідних класах

public:
    Animal(string n) : name(n) {
        cout << "Конструктор базового класу Animal\n";
    }

    virtual void speak() {
        cout << name << " видає звук\n";
    }
};

// Похідний клас Dog, що наслідує Animal
class Dog : public Animal {
public:
    Dog(string n) : Animal(n) {
        cout << "Конструктор похідного класу Dog\n";
    }

    void speak() override {
        cout << name << " каже: Гав!\n";
    }
};

int main() {
    cout << "Створюємо об'єкти...\n";
    Animal animal("Тварина");
    Dog dog("Бобік");

    cout << "\nВикликаємо методи speak():\n";
    animal.speak();
    dog.speak();

    return 0;
}
