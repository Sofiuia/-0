#include <iostream>
using namespace std;

template <typename T>
class Base {
protected:
    T value;

public:

Base(T v) : value(v) {
        cout << "Base constructor\n";
    }

    virtual ~Base() {
        cout << "Base destructor\n";
    }

    virtual void show() {
        cout << "Value: " << value << endl;
    }

    Base<T> operator+(const Base<T>& other) {
        return Base<T>(this->value + other.value);
    }

    static void staticMethod() {
        cout << "Static method Base\n";
}
};

template <typename T>
class Derived : public Base<T> {
public:

Derived(T v) : Base<T>(v) {
        cout << "Derived constructor\n";
    }

    ~Derived() {
        cout << "Derived destructor\n";
    }

    void show() override {
        cout << "Special value: " << this->value << endl;
    }

    Derived<T> operator*(const Derived<T>& other) {
        return Derived<T>(this->value * other.value);
}
};

int main() {
    Derived<int> obj1(10);
    Derived<int> obj2(5);

    obj1.show();
    obj2.show();

    Derived<int> sum = obj1 + obj2;
    sum.show();

    Derived<int> product = obj1 * obj2;
    product.show();

    Base<int>::staticMethod();

    return 0;
}
