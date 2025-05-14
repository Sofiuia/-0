#include <iostream>
#include <forward_list>

int main() {
    // Створення контейнера forward_list
    std::forward_list<int> flist = {1, 2, 3, 4, 5};

    // Виведення елементів списку
    std::cout << "Елементи forward_list: ";
    for (int num : flist) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Додавання елемента на початок списку
    flist.push_front(0);
    std::cout << "Після push_front(0): ";
    for (int num : flist) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Видалення першого елемента списку
    flist.pop_front();
    std::cout << "Після pop_front(): ";
    for (int num : flist) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Вставка елемента після першого
    auto it = flist.begin();
    flist.insert_after(it, 99);
    std::cout << "Після insert_after(it, 99): ";
    for (int num : flist) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Видалення всіх елементів
    flist.clear();
    std::cout << "Розмір після clear(): " << std::distance(flist.begin(), flist.end()) << std::endl;

    return 0;
}
