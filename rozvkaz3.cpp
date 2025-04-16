#include <iostream>
#include <memory>

// weak_ptr використовується для запобігання циклічним посиланням у shared_ptr,
// що може спричинити витоки пам'яті

// weak_ptr є частиною стандартної бібліотеки <memory>.

class MyClass
{
public:
    // Конструктори
    MyClass(int value) : data(value)
    {
        std::cout << "Constructor: " << data << "\n";
    }

    // Деструктор
    ~MyClass()
    {
        std::cout << "Destructor: " << data << "\n";
    }

    void show()
    {
        std::cout << "Data: " << data << "\n";
    }

private:
    int data;
};

int main()
{

    // weak_ptr це шаблонний клас, який не збільшує лічильник посилань, 
    // коли вказує на shared_pt

    // Створення shared_ptr
    std::shared_ptr<MyClass> sharedPtr = std::make_shared<MyClass>(42);

    // Створення weak_ptr на основі shared_ptr
    std::weak_ptr<MyClass> weakPtr = sharedPtr;

    // Оператор присвоєння
    // weak_ptr можна присвоювати іншому weak_ptr або shared_ptr.

    // Перевірка, чи weak_ptr ще валідний
    if (!weakPtr.expired())
    {
        std::cout << "weakPtr is still valid\n";
    }

    // Отримання shared_ptr із weak_ptr (за допомогою lock())
    std::shared_ptr<MyClass> lockedPtr = weakPtr.lock();
    if (lockedPtr)
    {
        lockedPtr->show();
    }

    // Методи weak_ptr: lock(), expired(), use_count()
    std::cout << "Shared count: " << sharedPtr.use_count() << "\n";

    // Проблема циклічних посилань
    // Якщо два об'єкти посилаються один на одного через shared_ptr,
    // вони ніколи не будуть знищені. Використання weak_ptr вирішує цю проблему.

    return 0;
}
