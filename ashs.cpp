#include <iostream>
#include <vector>
using namespace std;

// Функція для перестановки двох елементів
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Розділяє масив та повертає індекс опорного елемента
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high]; // Обираємо опорний елемент (останній)
    int i = low - 1;        // Індекс меншого елемента

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;            // Збільшуємо індекс меншого елемента
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]); // Ставимо опорний на своє місце
    return i + 1;
}

// Рекурсивна функція швидкого сортування
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high); // Знаходимо позицію опорного
        quickSort(arr, low, pivotIndex - 1);        // Сортуємо ліву частину
        quickSort(arr, pivotIndex + 1, high);       // Сортуємо праву частину
    }
}

// Функція для виводу масиву
void printArray(const vector<int>& arr) {
    for (int num : arr)
        cout << num << " ";
    cout << endl;
}

// Основна функція
int main() {
    vector<int> arr = {9, 3, 7, 5, 6, 4, 8, 2};

    cout << "Початковий масив: ";
    printArray(arr);

    quickSort(arr, 0, arr.size() - 1);

    cout << "Відсортований масив: ";
    printArray(arr);

    return 0;
}
