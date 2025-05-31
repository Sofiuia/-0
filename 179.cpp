#include <iostream>
#include <string>

class Parent
{
protected:
    int m_value;

public:
    Parent(int value)
        : m_value(value)
    {
    }

    virtual ~Parent() {} // обов’язково має бути віртуальний деструктор, щоб dynamic_cast працював
};

class Child : public Parent
{
protected:
    std::string m_name;

public:
    Child(int value, std::string name)
        : Parent(value), m_name(name)
    {
    }

    const std::string& getName() { return m_name; }
};

// функція, що повертає Parent*, який може вказувати або на Parent, або на Child
Parent* getObject(bool bReturnChild)
{
    if (bReturnChild)
        return new Child(1, "Banana");
    else
        return new Parent(2);
}

int main()
{
    // тестуємо: true - поверне Child, false - поверне Parent
    Parent *p = getObject(true);

    // намагаємося понизити тип з Parent* до Child* через dynamic_cast
    Child *ch = dynamic_cast<Child*>(p);

    // обов’язково перевіряємо результат динамічного приведення
    if (ch)
        std::cout << "The name of the Child is: " << ch->getName() << '\n';
    else
        std::cout << "Conversion failed. p does not point to a Child object.\n";

    delete p;

    return 0;
}
