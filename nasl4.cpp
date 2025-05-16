#include <iostream>
using namespace std;

// Базовий клас з модифікаторами доступу та віртуальним деструктором
class Base {
protected:
    int value;

public:
    Base(int v) : value(v) {
        cout << "Base constructor\n";
    }

    virtual ~Base() {
        cout << "Base destructor\n";
    }

    virtual void show() {
        cout << "Value: " << value << endl;
    }

    Base operator+(const Base& other) {
        return Base(this->value + other.value);
    }

    static void staticMethod() {
        cout << "Static method in Base\n";
    }
};

// Похідний клас з перевизначенням методів та операторів
class Derived : public Base {
public:
    Derived(int v) : Base(v) {
        cout << "Derived constructor\n";
    }

    ~Derived() {
        cout << "Derived destructor\n";
    }

    void show() override {
        cout << "Special value: " << value << endl;
    }

    Derived operator*(const Derived& other) {
        return Derived(this->value * other.value);
    }
};

// Віртуальне наслідування для вирішення "діамантової проблеми"
class A {
public:
    virtual void show() {
        cout << "Class A\n";
    }
};

class B : virtual public A {};
class C : virtual public A {};
class D : public B, public C {};

// Структура vs Клас
struct StructExample {
    int x; // За замовчуванням public
};

class ClassExample {
    int x; // За замовчуванням private
};

int main() {
    Derived obj1(10), obj2(5);

    obj1.show();
    obj2.show();

    Derived sum = obj1 + obj2;
    sum.show();

    Derived product = obj1 * obj2;
    product.show();

    Base::staticMethod();

    D objD;
    objD.show();

    return 0;
}
