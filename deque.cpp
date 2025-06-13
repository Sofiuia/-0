#include <iostream>
using namespace std;

enum Color { RED, BLACK };

struct Node {
    // Потрібно знати: класи, вказівники, умовні оператори, рекурсію, enum.
    int data;
    Color color;
    Node *left, *right, *parent;

    Node(int data) : data(data), color(RED), left(nullptr), right(nullptr), parent(nullptr) {}
};

class RedBlackTree {
private:
    Node* root;

    // Деструктор
    void deleteTree(Node* node) {
        if (node) {
            deleteTree(node->left);
            deleteTree(node->right);
            delete node;
        }
    }

    // Які є контейнери
    // Ми реалізуємо власний контейнер — структуру для зберігання даних.
    // Це саморобна структура, яка схожа на map або set у STL.

    // Схема роботи контейнера deque
    // deque і RBT обидва підтримують швидкі вставки.
    // Але RBT — це дерево, яке балансується за правилами (кольори, обертання).

    // Повороти дерева (для балансування)
    void rotateLeft(Node* &x) {
        Node* y = x->right;
        x->right = y->left;
        if (y->left) y->left->parent = x;
        y->parent = x->parent;

        if (!x->parent)
            root = y;
        else if (x == x->parent->left)
            x->parent->left = y;
        else
            x->parent->right = y;

        y->left = x;
        x->parent = y;
    }

    void rotateRight(Node* &x) {
        Node* y = x->left;
        x->left = y->right;
        if (y->right) y->right->parent = x;
        y->parent = x->parent;

        if (!x->parent)
            root = y;
        else if (x == x->parent->right)
            x->parent->right = y;
        else
            x->parent->left = y;

        y->right = x;
        x->parent = y;
    }

    // Відновлення властивостей RBT
    void fixInsert(Node* &z) {
        while (z->parent && z->parent->color == RED) {
            Node* gp = z->parent->parent;
            if (z->parent == gp->left) {
                Node* y = gp->right;
                if (y && y->color == RED) {
                    z->parent->color = BLACK;
                    y->color = BLACK;
                    gp->color = RED;
                    z = gp;
                } else {
                    if (z == z->parent->right) {
                        z = z->parent;
                        rotateLeft(z);
                    }
                    z->parent->color = BLACK;
                    gp->color = RED;
                    rotateRight(gp);
                }
            } else {
                Node* y = gp->left;
                if (y && y->color == RED) {
                    z->parent->color = BLACK;
                    y->color = BLACK;
                    gp->color = RED;
                    z = gp;
                } else {
                    if (z == z->parent->left) {
                        z = z->parent;
                        rotateRight(z);
                    }
                    z->parent->color = BLACK;
                    gp->color = RED;
                    rotateLeft(gp);
                }
            }
        }
        root->color = BLACK;
    }

public:
    // Конструктори
    RedBlackTree() : root(nullptr) {}

    // Деструктор
    ~RedBlackTree() {
        deleteTree(root);
    }

    // Методи
    void insert(int value) {
        Node* z = new Node(value);
        Node* y = nullptr;
        Node* x = root;

        while (x) {
            y = x;
            if (value < x->data)
                x = x->left;
            else if (value > x->data)
                x = x->right;
            else
                return; // дублікати не додаємо
        }

        z->parent = y;
        if (!y)
            root = z;
        else if (value < y->data)
            y->left = z;
        else
            y->right = z;

        fixInsert(z);
    }

    bool search(int value) {
        Node* current = root;
        while (current) {
            if (value == current->data)
                return true;
            current = value < current->data ? current->left : current->right;
        }
        return false;
    }

    void inOrder(Node* node) {
        if (node) {
            inOrder(node->left);
            cout << node->data << " ";
            inOrder(node->right);
        }
    }

    void printTree() {
        cout << "In-order: ";
        inOrder(root);
        cout << endl;
    }

    // Глобальні перезавантаження операторів і функції
    // Можна додати: оператори для порівняння, виводу, об'єднання дерев тощо.
    
    // Оцінка операцій по О-нотації
    // Вставка, пошук O(log n)
    // Пам’ять O(n), бо зберігаємо вузли
};

int main() {
    RedBlackTree tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(3);
    tree.printTree();

    cout << (tree.search(5) ? "Знайдено 5" : "5 немає") << endl;
    cout << (tree.search(20) ? "Знайдено 20" : "20 немає") << endl;

 
    return 0;
}
