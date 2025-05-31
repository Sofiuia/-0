#include <iostream>

// Клас точки на площині
class Point {
public:
    int x, y;
    Point(int x = 0, int y = 0) : x(x), y(y) {}
    friend std::ostream& operator<<(std::ostream& os, const Point& p) {
        os << "(" << p.x << ", " << p.y << ")";
        return os;
    }
};

// Абстрактний клас Shape
class Shape {
public:
    virtual void print(std::ostream& os) const = 0;
    friend std::ostream& operator<<(std::ostream& os, const Shape& shape) {
        shape.print(os);
        return os;
    }
    virtual ~Shape() {}
    virtual double Area() const = 0;
};

// Клас Triangle
class Triangle : public Shape {
private:
    Point p1, p2, p3;
public:
    Triangle(Point p1, Point p2, Point p3) : p1(p1), p2(p2), p3(p3) {}
    void print(std::ostream& os) const override {
        os << "Triangle: " << p1 << ", " << p2 << ", " << p3;
    }
    double Area() const override {
        return 0.5 * abs(p1.x * (p2.y - p3.y) + p2.x * (p3.y - p1.y) + p3.x * (p1.y - p2.y));
    }
};

// Клас Circle
class Circle : public Shape {
private:
    Point center;
    int radius;
public:
    Circle(Point center, int radius) : center(center), radius(radius) {}
    void print(std::ostream& os) const override {
        os << "Circle: Center = " << center << ", Radius = " << radius;
    }
    double Area() const override {
        return 3.14159 * radius * radius;
    }
};

// Бінарне дерево пошуку
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Вставка елемента у дерево
Node* insert(Node* root, int value) {
    if (!root) return new Node(value);
    if (value < root->data) root->left = insert(root->left, value);
    else root->right = insert(root->right, value);
    return root;
}

// Симетричний обхід дерева
void inorderTraversal(Node* root) {
    if (!root) return;
    inorderTraversal(root->left);
    std::cout << root->data << " ";
    inorderTraversal(root->right);
}

int main() {
    // Тестування класів фігур
    Triangle t(Point(0, 0), Point(5, 0), Point(0, 5));
    Circle c(Point(2, 2), 3);

    std::cout << t << "\n";
    std::cout << "Triangle Area: " << t.Area() << "\n";

    std::cout << c << "\n";
    std::cout << "Circle Area: " << c.Area() << "\n";

    // Тестування бінарного дерева
    Node* root = nullptr;
    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 15);
    root = insert(root, 2);
    root = insert(root, 7);

    std::cout << "Inorder traversal: ";
    inorderTraversal(root);
    std::cout << std::endl;

    return 0;
}

