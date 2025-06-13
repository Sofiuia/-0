#include <iostream>
using namespace std;

enum Color { RED, BLACK };

struct Node {
int data;
Color color;
Node *left, *right, *parent;

Node(int data) : data(data), color(RED), left(nullptr), right(nullptr), parent(nullptr) {}
};

class RedBlackTree {
private:
Node* root;

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
    RedBlackTree() : root(nullptr) {}

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
                return; // Дублікати ігноруємо
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
};
