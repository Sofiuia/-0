#include <iostream>
#include <memory>

// розумний вказівник
// Розумні вказівники (smart pointers) автоматично керують динамічно виділеною пам’яттю.
// Вони зменшують ризик витоків пам’яті та полегшують керування ресурсами.

// unique_ptr - це унікальний розумний вказівник, який має право володіння об’єктом,
// тобто тільки один unique_ptr може володіти певним об’єктом у будь-який момент часу.

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

// Передача unique_ptr у функцію
// Оскільки unique_ptr забезпечує унікальне володіння,
// ми повинні використовувати std::move(), щоб передати вказівник без копіювання.
void processData(std::unique_ptr<MyClass> ptr)
{
    std::cout << "Processing data...\n";
    ptr->show();
}

// Функція, яка повертає unique_ptr
std::unique_ptr<MyClass> createObject(int value)
{
    return std::make_unique<MyClass>(value);
}

int main()
{
    // unique_ptr
    // Він знищує об'єкт автоматично, коли виходить за межі області видимості.
    std::unique_ptr<MyClass> ptr1 = std::make_unique<MyClass>(42);
    ptr1->show();

    // Передача unique_ptr у функцію (після цього ptr1 стане nullptr)
    processData(std::move(ptr1));

    if (!ptr1)
    {
        std::cout << "ptr1 is now nullptr after move.\n";
    }

    // Отримання unique_ptr із функції
    std::unique_ptr<MyClass> ptr2 = createObject(99);
    ptr2->show();

    /*Структура default_delete
    За замовчуванням unique_ptr використовує std::default_delete для видалення об'єкта.

    Перезавантажені оператори
     unique_ptr перевантажує оператори *, -> та bool для зручного доступу.*/
    if (ptr2)
    {
        std::cout << "ptr2 exists\n";
    }

    // Методи unique_ptr: get(), release(), reset()
    ptr2.reset(); // Видаляє старий об'єкт і може отримати новий.

    // Коли використовувати unique_ptr?
    // Використовуйте його для об'єктів, які належать лише одній сутності та не потребують спільного володіння.

    // unique_ptr і масиви
    std::unique_ptr<MyClass[]> arrayPtr = std::make_unique<MyClass[]>(3);
    
    // Робота з масивом
    for (int i = 0; i < 3; ++i)
    {
        arrayPtr[i].show();
    }

    // Метод swap
    // Дозволяє обмінюватися об'єктами між unique_ptr.
    std::unique_ptr<MyClass> anotherPtr = std::make_unique<MyClass>(77);
    ptr2.swap(anotherPtr);

    // Відправлення і повернення із функцій
    // unique_ptr можна повертати з функцій без ризику витоків пам’яті.

    return 0;
}
