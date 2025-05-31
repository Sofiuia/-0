#include <iostream>
#include <vector>
#include <functional>

class Parent
{
protected:
    int m_value;

public:
    Parent(int value)
        : m_value(value)
    {
    }

    virtual const char* getName() const { return "Parent"; }
    int getValue() const { return m_value; }
};

class Child: public Parent
{
public:
    Child(int value)
        : Parent(value)
    {
    }

    virtual const char* getName() const { return "Child"; }
};

void printNameByValue(const Parent parent) // Передача по значенню
{
    std::cout << "I am a " << parent.getName() << '\n';
}

void printNameByReference(const Parent& parent) // Передача по посиланню
{
    std::cout << "I am a " << parent.getName() << '\n';
}

int main()
{
    std::cout << "=== Приклади з базовими об'єктами ===\n";
    Child child(7);
    std::cout << "child is a " << child.getName() << " and has value " << child.getValue() << '\n';

    Parent& ref = child;
    std::cout << "ref is a " << ref.getName() << " and has value " << ref.getValue() << '\n';

    Parent* ptr = &child;
    std::cout << "ptr is a " << ptr->getName() << " and has value " << ptr->getValue() << '\n';

    std::cout << "\n=== Приклад обрізки об'єкта при копіюванні ===\n";
    Parent parent = child; // Обрізка
    std::cout << "parent is a " << parent.getName() << " and has value " << parent.getValue() << '\n';

    std::cout << "\n=== Обрізка об'єкта при передачі у функцію ===\n";
    printNameByValue(child); // Обрізається частина Child
    printNameByReference(child); // Поліморфізм працює

    std::cout << "\n=== Приклад обрізки об'єктів у std::vector ===\n";
    std::vector<Parent> v1;
    v1.push_back(Parent(7));
    v1.push_back(Child(8)); // Обрізається частина Child

    for (int i = 0; i < v1.size(); ++i)
        std::cout << "I am a " << v1[i].getName() << " with value " << v1[i].getValue() << "\n";

    std::cout << "\n=== Рішення: std::vector з вказівниками ===\n";
    std::vector<Parent*> v2;
    v2.push_back(new Parent(7));
    v2.push_back(new Child(8));

    for (int i = 0; i < v2.size(); ++i)
        std::cout << "I am a " << v2[i]->getName() << " with value " << v2[i]->getValue() << "\n";

    for (int i = 0; i < v2.size(); ++i)
        delete v2[i];

    std::cout << "\n=== Рішення: std::reference_wrapper ===\n";
    Parent p(7);
    Child ch(8);
    std::vector<std::reference_wrapper<Parent>> v3;
    v3.push_back(p);
    v3.push_back(ch);

    for (int i = 0; i < v3.size(); ++i)
        std::cout << "I am a " << v3[i].get().getName() << " with value " << v3[i].get().getValue() << "\n";

    return 0;
}
