#include <iostream>
#include <vector>
#include <list>

using namespace std;

// Простий хеш-клас, що підтримує метод ланцюжків
class HashTable {
private:
    vector<list<int>> table;
    int size;

    // Проста хеш-функція
    int hashFunction(int key) {
        return key % size;
    }

public:
    // Конструктор, що створює хеш-таблицю заданого розміру
    HashTable(int s) : size(s) {
        table.resize(size);
    }

    // Додавання елемента
    void insert(int key) {
        int index = hashFunction(key);
        table[index].push_back(key);
    }

    // Пошук елемента
    bool search(int key) {
        int index = hashFunction(key);
        for (int val : table[index]) {
            if (val == key) return true;
        }
        return false;
    }

    // Видалення елемента
    void remove(int key) {
        int index = hashFunction(key);
        table[index].remove(key);
    }

    // Вивід хеш-таблиці
    void display() {
        for (int i = 0; i < size; ++i) {
            cout << "Index " << i << ": ";
            for (int val : table[i]) {
                cout << val << " -> ";
            }
            cout << "null" << endl;
        }
    }
};

int main() {
    HashTable hashTable(10);

    // Додаємо елементи
    hashTable.insert(5);
    hashTable.insert(15);
    hashTable.insert(25);
    hashTable.insert(35);

    // Вивід
    cout << "Хеш-таблиця:\n";
    hashTable.display();

    // Пошук елемента
    cout << "\nПошук 15: " << (hashTable.search(15) ? "Знайдено" : "Не знайдено") << endl;
    cout << "Пошук 100: " << (hashTable.search(100) ? "Знайдено" : "Не знайдено") << endl;

    // Видалення елемента
    cout << "\nВидалення 15...\n";
    hashTable.remove(15);
    hashTable.display();

    return 0;
}
