#include <iostream>
using namespace std;


// черга - структура типу FIFO — перший увійшов, перший вийшов.


// Буде лише одна реалізація черги
// Ми реалізуємо просту чергу на основі масиву з фіксованим розміром.

class Queue {
private:
    int* data;
    int front, rear, size, capacity;

public:
    Queue(int cap) : capacity(cap), front(0), rear(-1), size(0) {
        data = new int[capacity];
    }

    ~Queue() {
        delete[] data;
    }


    // Додаємо (enqueue) в кінець, забираємо (dequeue) з початку.
    bool enqueue(int value) {
        if (size >= capacity) {
            cout << "Черга переповнена\n";
            return false;
        }
        rear = (rear + 1) % capacity;
        data[rear] = value;
        size++;
        return true;
    }

    bool dequeue() {
        if (isEmpty()) {
            cout << "Черга порожня\n";
            return false;
        }
        front = (front + 1) % capacity;
        size--;
        return true;
    }

    int peek() const {
        if (isEmpty()) return -1;
        return data[front];
    }

    bool isEmpty() const {
        return size == 0;
    }

    void printQueue() const {
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


// Реалізація черги
int main() {
    Queue q(5); // черга на 5 елементів
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.printQueue();

    q.dequeue();
    q.printQueue();

    cout << "На початку: " << q.peek() << endl;
    return 0;
}



// - Динамічні черги (з масивом, який збільшується)
// - Черги на списках (зв'язні структури без обмеження розміру)
// - Двосторонні черги (deque)
// - Пріоритетні черги (з пріоритетом, не просто FIFO)

