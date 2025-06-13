#include <iostream>
using namespace std;

// Черга (queue) — це структура, де елементи йдуть по порядку:
// хто перший зайшов — той перший і вийде. Типова "черга в магазин".
// Працює за принципом FIFO (First In - First Out).

class Queue {
private:
    int* data;      // масив, де будемо зберігати наші елементи
    int front;      // звідси ми витягуємо значення (передній елемент)
    int rear;       // сюди додаємо нові елементи (останній елемент)
    int size;       // поточна кількість елементів у черзі
    int capacity;   // максимально допустима кількість елементів

public:
    // Конструктор: створює порожню чергу заданого розміру
    Queue(int cap) {
        capacity = cap;
        data = new int[capacity];
        front = 0;
        rear = -1;
        size = 0;
    }

    // Деструктор: очищає памʼять, коли черга більше не потрібна
    ~Queue() {
        delete[] data;
    }

    // Додаємо елемент у кінець черги
    bool enqueue(int value) {
        if (size == capacity) {
            cout << "Черга переповнена\n";
            return false;
        }
        rear = (rear + 1) % capacity;
        data[rear] = value;
        size++;
        return true;
    }

    // Видаляємо елемент з початку черги
    bool dequeue() {
        if (isEmpty()) {
            cout << "Черга порожня\n";
            return false;
        }
        front = (front + 1) % capacity;
        size--;
        return true;
    }

    // Дивимося, який елемент стоїть першим
    int peek() const {
        if (isEmpty()) return -1;
        return data[front];
    }

    // Перевіряємо, чи черга порожня
    bool isEmpty() const {
        return size == 0;
    }

    // Повертаємо розмір черги (кількість елементів)
    int getSize() const {
        return size;
    }

    // Просто показуємо все, що є в черзі
    void print() const {
        if (isEmpty()) {
            cout << "Черга порожня\n";
            return;
        }
        cout << "Черга: ";
        for (int i = 0; i < size; ++i)
            cout << data[(front + i) % capacity] << " ";
        cout << endl;
    }
};


// Як це виглядає на практиці
int main() {
    Queue q(5); // черга на 5 елементів

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.print();          // Черга: 10 20 30

    q.dequeue();        // Видаляємо 10
    q.print();          // Черга: 20 30

    cout << "Перший: " << q.peek() << endl; // 20

    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);      // Це додасть 60 і займе місце звільненого 10
    q.print();          // Черга: 20 30 40 50 60

    q.enqueue(70);      // Переповнення
}
