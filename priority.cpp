#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// Створимо компаратор для пріоритетної черги
struct CustomCompare {
    bool operator()(const int &a, const int &b) {
        return a > b; // Менші елементи мають вищий пріоритет
    }
};

int main() {
    // Створення пріоритетної черги (максимальної за замовчуванням)
    priority_queue<int> maxPQ; // Максимальна черга (елементи в порядку спадання)

    // Додавання елементів
    maxPQ.push(10);
    maxPQ.push(30);
    maxPQ.push(20);

    cout << "Максимальна черга (найбільший елемент перший):\n";
    while (!maxPQ.empty()) {
        cout << maxPQ.top() << " "; // Вивід верхнього елемента
        maxPQ.pop(); // Видалення верхнього елемента
    }

    cout << "\n";

    // Створення мінімальної пріоритетної черги (з використанням вектора та компаратора)
    priority_queue<int, vector<int>, CustomCompare> minPQ; // Мінімальна черга (елементи у порядку зростання)

    // Додавання елементів
    minPQ.push(10);
    minPQ.push(30);
    minPQ.push(20);

    cout << "Мінімальна черга (найменший елемент перший):\n";
    while (!minPQ.empty()) {
        cout << minPQ.top() << " "; // Вивід верхнього елемента
        minPQ.pop(); // Видалення верхнього елемента
    }

    cout << "\n";

    return 0;
}
