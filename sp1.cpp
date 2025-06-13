#include <iostream>
using namespace std;


// Це набір вузлів (Node), кожен з яких має дані та вказівник на наступний вузол.

// Реалізація списку в процедурному стилі
// У цьому прикладі ми реалізуємо все як клас, але без STL для навчальних цілей.

class List {
private:

    // Закрита частина класу (Node, head, Copy)
    struct Node {
        int value;
        Node* next;
        Node(int v) : value(v), next(nullptr) {}
    };

    Node* head;

    void Copy(const List& other) {
        Node* current = other.head;
        while (current)
        {
            PushBack(current->value);
            current = current->next;
        }
    }

public:
    // Конструктор за замовчуванням
    List() : head(nullptr) {}

    // Деструктор і метод очищення Clear
    ~List() {
        Clear();
    }

    void Clear() {
        while (head)
            PopFront();
    }

    // Метод вставки елементу в кінець PushBack
    void PushBack(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
    }

    // Метод вставки елементу на початок PushFront
    void PushFront(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    // Метод видалення елементу з кінця PopBack
    void PopBack() {
        if (!head) return;
        if (!head->next) {
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head;
        while (temp->next->next)
            temp = temp->next;
        delete temp->next;
        temp->next = nullptr;
    }

    // Метод видалення елементу з початку PopFront
    void PopFront() {
        if (!head) return;
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    // Метод видалення елементу по значенню Remove
    void Remove(int value) {
        if (!head) return;
        if (head->value == value) {
            PopFront();
            return;
        }
        Node* current = head;
        while (current->next && current->next->value != value)
            current = current->next;
        if (current->next) {
            Node* tmp = current->next;
            current->next = tmp->next;
            delete tmp;
        }
    }

    // Метод пошуку по значенню Find
    Node* Find(int value) {
        Node* current = head;
        while (current) {
            if (current->value == value)
                return current;
            current = current->next;
        }
        return nullptr;
    }

    // Метод перевірки чи список пустий IsEmpty
    bool IsEmpty() const {
        return head == nullptr;
    }

    // Метод розрахунку розміру списку Size
    int Size() const {
        int count = 0;
        Node* current = head;
        while (current) {
            count++;
            current = current->next;
        }
        return count;
    }

    // Метод виводу елементів на екран (Show)
    void Show() const {
        Node* current = head;
        while (current) {
            cout << current->value << " ";
            current = current->next;
        }
        cout << endl;
    }

    // Перезавантажені оператори присвоєння
    List& operator=(const List& other) {
        if (this != &other) {
            Clear();
            Copy(other);
        }
        return *this;
    }

    // Перезавантажені оператори індексації
    int& operator[](int index) {
        Node* current = head;
        for (int i = 0; i < index; ++i)
            current = current->next;
        return current->value;
    }

    // Конструктор копії і метод копіювання Copy
    List(const List& other) : head(nullptr) {
        Copy(other);
    }

    // Конструктор переносу
    List(List&& other) noexcept {
        head = other.head;
        other.head = nullptr;
    }

    // Знайомство з О-нотацією
    // Вставка: O(1) для PushFront, O(n) для PushBack
    // Пошук: O(n), бо треба пройти список

    // Оптимізація №1 (добавлення tail) — дозволить швидко додавати в кінець
    // Оптимізація №2 (додавання size) — дозволить швидко знати розмір
    // Оптимізація №3 (реалізація ітератора) — потрібна для for-each стилю та STL-сумісності
};



// Перетворення List в шаблон класу
// Можна перетворити List на template <typename T>, щоб зберігати не лише int

// Користувацький клас як елемент списку
// Просто заміни тип int на будь-який свій клас, наприклад Book або Student

int main() {
    List l;
    l.PushBack(1);
    l.PushBack(2);
    l.PushFront(0);
    l.Show(); // Виведе: 0 1 2
    l.PopBack();
    l.Show(); // Виведе: 0 1

    return 0;
}
