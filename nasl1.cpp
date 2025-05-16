#include <iostream>
using namespace std;

// Базовий клас
class Animal {
public:
    string name;

    Animal(string n) : name(n) {}

    virtual string speak() {
        return "Звук";
    }
};

// Похідний клас (наслідує Animal)
class Dog : public Animal {
public:
    Dog(string n) : Animal(n) {}

    string speak() override {
        return "Гав!";
    }
};

int main() {
    Animal animal("Загальна тварина");
    Dog dog("Бобік");

    cout << animal.name << " - " << animal.speak() << endl; 
    cout << dog.name << " - " << dog.speak() << endl; 

    return 0;
}
