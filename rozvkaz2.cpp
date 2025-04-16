#include <iostream>
#include <memory>

// unique_ptr і shared_ptr
// shared_ptr дозвляє кільком вказівникам володіти 1 об'єктом
// unique_ptr забезпечує унікальне володіння

// shared_ptr веде підрахунок кількості вказівників, які ним володіють.
// Коли останній shared_ptr звільняється, об'єкт видаляється

class MyClass
{
public:
// Конструктори
    MyClass(int value) : data(value)
    {
        std::cout << "Constructor: " << data << "\n";
    }

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
 // shared_ptr знаходиться в стандартній бібліотеці <memory>, як і unique_ptr.

// Створення shared_ptr
    std::shared_ptr<MyClass> ptr1 = std::make_shared<MyClass>(42);
    ptr1->show();

    // Конструктори
    // shared_ptr підтримує копіювання та переміщення, на відміну від unique_ptr.
    std::shared_ptr<MyClass> ptr2 = ptr1; // Тепер об'єкт має два володаря.

    // Для масивів використовується std::shared_ptr<MyClass[]>.
    std::shared_ptr<MyClass[]> arrayPtr = std::shared_ptr<MyClass[]>(new MyClass[3]);

    // У shared_ptr є псевдонім element_type для отримання типу об'єкта.
    using ElementType = std::shared_ptr<MyClass>;

    // Перезавантажені оператори
    // shared_ptr перевантажує *, ->, bool для зручності
    if (ptr1)
    {
        std::cout << "ptr1 still exists\n";
    }

    // Методи shared_ptr: use_count() get) reset()
    std::cout << "Reference count: " << ptr1.use_count() << "\n";

    ptr2.reset(); // Один власник видалено, але об'єкт все ще існує

    std::cout << "Reference count after reset: " << ptr1.use_count() << "\n";

    // owner_before() дозволяє порівнювати володіння shared_ptr
    std::shared_ptr<MyClass> ptr3 = std::make_shared<MyClass>(99);
    std::cout << "ptr1 owner_before ptr3: " << ptr1.owner_before(ptr3) << "\n";

    // make_shared краще використовує пам'ять, ніж ручне виділення new
    std::shared_ptr<MyClass> ptr4 = std::make_shared<MyClass>(77);

    return 0;
}
