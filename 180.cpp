#include <iostream>

class Parent
{
public:
    Parent() {}

    // Дружня функція operator<< для класу Parent
    friend std::ostream& operator<<(std::ostream &out, const Parent &p)
    {
        // Делегуємо вивід віртуальному методу print()
        return p.print(out);
    }

    // Віртуальний метод print(), який робить власне вивід
    virtual std::ostream& print(std::ostream& out) const
    {
        out << "Parent";
        return out;
    }
};

class Child : public Parent
{
public:
    Child() {}

    // Перевизначення методу print() для виводу інформації про Child
    virtual std::ostream& print(std::ostream& out) const override
    {
        out << "Child";
        return out;
    }
};

int main()
{
    Parent p;
    std::cout << p << '\n';  // Виведе "Parent"

    Child ch;
    std::cout << ch << '\n'; // Виведе "Child"

    Parent &pref = ch;
    std::cout << pref << '\n'; // Виведе "Child", бо print() віртуальний

    return 0;
}
