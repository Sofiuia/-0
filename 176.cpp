#include <iostream>
#include <string>

class Animal
{
protected:
    std::string m_name;

public:
    Animal(std::string name)
        : m_name(name)
    {
    }

    std::string getName() const
    {
        return m_name;
    }

    // Метод speak() з базовою реалізацією
    virtual std::string speak() const
    {
        return "???";
    }
};

class Dragonfly : public Animal
{
public:
    Dragonfly(std::string name)
        : Animal(name)
    {
    }

    // Dragonfly не перевизначає speak(), тому викликається реалізація з Animal
};

int main()
{
    Dragonfly df("Buzz");
    std::cout << df.getName() << " says " << df.speak() << '\n';
    return 0;
}
