#include <iostream>
using namespace std;
// Стек — це структура даних типу LIFO (останній увійшов — перший вийшов).
// Елементи додаються/видаляються лише з одного кінця — вершини стеку.


//Реалізація стеку (Масив із 10 елементів)
class Stack10 {
private:
    int data[10];
    int top;
public:
    Stack10() : top(-1) {}

    bool push(int value) {
        if (top >= 9) return false; // переповнення
        data[++top] = value;
        return true;
    }

    bool pop() {
        if (top < 0) return false; // порожній стек
        --top;
        return true;
    }

    int peek() {
        return top >= 0 ? data[top] : -1;
    }

    bool isEmpty() {
        return top == -1;
    }
};


//Реалізація стеку (Масив із N елементів)
class StackN {
private:
    int* data;
    int top, capacity;

public:
    StackN(int size) : capacity(size), top(-1) {
        data = new int[capacity];
    }

    ~StackN() {
        delete[] data;
    }

    bool push(int value) {
        if (top >= capacity - 1) return false;
        data[++top] = value;
        return true;
    }

    bool pop() {
        if (top < 0) return false;
        --top;
        return true;
    }

    int peek() {
        return top >= 0 ? data[top] : -1;
    }

    bool isEmpty() {
        return top == -1;
    }
};


//Реалізація стеку (Змінний масив на кучі)
// Ми автоматично подвоюємо розмір масиву при потребі.
class StackDynamic {
private:
    int* data;
    int top, capacity;

    void resize() {
        capacity *= 2;
        int* newData = new int[capacity];
        for (int i = 0; i <= top; ++i)
            newData[i] = data[i];
        delete[] data;
        data = newData;
    }

public:
    StackDynamic() : capacity(4), top(-1) {
        data = new int[capacity];
    }

    ~StackDynamic() {
        delete[] data;
    }

    void push(int value) {
        if (top + 1 >= capacity)
            resize();
        data[++top] = value;
    }

    bool pop() {
        if (top < 0) return false;
        --top;
        return true;
    }

    int peek() {
        return top >= 0 ? data[top] : -1;
    }

    bool isEmpty() {
        return top == -1;
    }
};


//Реалізація стеку (Двозв'язний список)
struct Node {
    int value;
    Node* prev;
    Node* next;
    Node(int v) : value(v), prev(nullptr), next(nullptr) {}
};

class StackList {
private:
    Node* top;

public:
    StackList() : top(nullptr) {}

    ~StackList() {
        while (top)
            pop();
    }

    void push(int value) {
        Node* node = new Node(value);
        node->next = top;
        if (top)
            top->prev = node;
        top = node;
    }

    bool pop() {
        if (!top) return false;
        Node* tmp = top;
        top = top->next;
        delete tmp;
        if (top) top->prev = nullptr;
        return true;
    }

    int peek() {
        return top ? top->value : -1;
    }

    bool isEmpty() {
        return top == nullptr;
    }
};


// Тестування
int main() {
    StackDynamic stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);
    cout << "Верхній елемент: " << stack.peek() << endl;
    stack.pop();
    cout << "Після pop, верхній елемент: " << stack.peek() << endl;
    return 0;
}
