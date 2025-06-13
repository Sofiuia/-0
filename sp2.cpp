#include <iostream>
using namespace std;

// Кожен елемент списку буде зберігати число,
// а також знати, хто йде перед ним і хто після нього.
struct Node {
    int value;
    Node* next;
    Node* prev;

    Node(int v) : value(v), next(nullptr), prev(nullptr) {}
};

class List {
private:
    Node* head; // це початок списку
    Node* tail; // це кінець списку

    // ця функція копіює всі елементи з іншого списку
    void Copy(const List& other) {
        Node* current = other.head;
        while (current) {
            PushBack(current->value);
            current = current->next;
        }
    }

    // ця функція просто забирає дані з іншого списку (без копіювання)
    void Move(List& other) {
        head = other.head;
        tail = other.tail;
        other.head = nullptr;
        other.tail = nullptr;
    }

public:
    // створюємо порожній список
    List() : head(nullptr), tail(nullptr) {}

    // при знищенні списку — видаляємо всі його елементи
    ~List() {
        Clear();
    }

    // видаляємо всі елементи списку
    void Clear() {
        while (head)
            PopFront();
    }

    // додаємо число в кінець списку
    void PushBack(int val) {
        Node* node = new Node(val);
        if (!tail) {
            head = tail = node;
        } else {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
    }

    // виводимо всі числа списку на екран
    void Show() const {
        Node* current = head;
        cout << "Список: ";
        while (current) {
            cout << current->value << " ";
            current = current->next;
        }
        cout << endl;
    }

    // повертаємо кількість елементів у списку
    int Size() const {
        int count = 0;
        Node* cur = head;
        while (cur) {
            count++;
            cur = cur->next;
        }
        return count;
    }

    // перевіряємо, чи список порожній
    bool IsEmpty() const {
        return head == nullptr;
    }

    // шукаємо елемент за значенням
    Node* Find(int val) {
        Node* cur = head;
        while (cur) {
            if (cur->value == val)
                return cur;
            cur = cur->next;
        }
        return nullptr;
    }

    // повертаємо перше число (якщо список не порожній)
    int Front() const {
        return head ? head->value : -1;
    }

    // повертаємо останнє число (якщо список не порожній)
    int Back() const {
        return tail ? tail->value : -1;
    }

    // створюємо копію з іншого списку
    List(const List& other) : head(nullptr), tail(nullptr) {
        Copy(other);
    }

    // переносимо дані з іншого списку (без копіювання)
    List(List&& other) noexcept {
        Move(other);
    }

    // оператор копіювання (дорівнювання)
    List& operator=(const List& other) {
        if (this != &other) {
            Clear();
            Copy(other);
        }
        return *this;
    }

    // оператор переносу (коли список передається як тимчасовий)
    List& operator=(List&& other) noexcept {
        if (this != &other) {
            Clear();
            Move(other);
        }
        return *this;
    }

    // додаємо число на початок списку
    void PushFront(int val) {
        Node* node = new Node(val);
        if (!head) {
            head = tail = node;
        } else {
            node->next = head;
            head->prev = node;
            head = node;
        }
    }

    // видаляємо останній елемент
    void PopBack() {
        if (!tail) return;
        Node* tmp = tail;
        tail = tail->prev;
        if (tail)
            tail->next = nullptr;
        else
            head = nullptr;
        delete tmp;
    }

    // видаляємо перший елемент
    void PopFront() {
        if (!head) return;
        Node* tmp = head;
        head = head->next;
        if (head)
            head->prev = nullptr;
        else
            tail = nullptr;
        delete tmp;
    }

    // шукаємо елемент з заданим значенням і видаляємо його
    void Remove(int val) {
        Node* cur = head;
        while (cur) {
            if (cur->value == val) {
                if (cur == head)
                    PopFront();
                else if (cur == tail)
                    PopBack();
                else {
                    cur->prev->next = cur->next;
                    cur->next->prev = cur->prev;
                    delete cur;
                }
                return;
            }
            cur = cur->next;
        }
    }

    // перевертаємо список: перший стає останнім, останній — першим
    void Reverse() {
        Node* current = head;
        while (current) {
            swap(current->next, current->prev);
            current = current->prev;
        }
        swap(head, tail);
    }
};

// приклад використання
int main() {
    List list;
    list.PushBack(10);
    list.PushBack(20);
    list.PushFront(5);
    list.Show();         // виведе: 5 10 20

    list.Remove(10);     
    list.Show();         // виведе: 5 20

    list.Reverse();      
    list.Show();         // виведе: 20 5

    cout << "Розмір: " << list.Size() << endl;
    cout << "Перший: " << list.Front() << ", Останній: " << list.Back() << endl;

    return 0;
}
