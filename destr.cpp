#include <iostream>
using namespace std;

class Base {
public:
    virtual ~Base() { cout << "Base destructor\n"; } // Віртуальний деструктор
    virtual void show() { cout << "Base show\n"; }
};

class Derived : public Base {
public:
    ~Derived() { cout << "Derived destructor\n"; } // Деструктор дочірнього класу
    void show() override { cout << "Derived show\n"; }
};

int main() {
    Base* p = new Derived(); // Динамічне виділення пам’яті
    p->show(); // Виклик перевизначеного методу
    delete p; // Виклик деструкторів
    return 0;
}
