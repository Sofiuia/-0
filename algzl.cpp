#include <iostream>
#include <vector>
using namespace std;

// Злиття двох відсортованих частин
void merge(vector<int>& arr, int left, int mid, int right) {
    vector<int> leftPart(arr.begin() + left, arr.begin() + mid + 1);
    vector<int> rightPart(arr.begin() + mid + 1, arr.begin() + right + 1);

    int i = 0, j = 0, k = left;

    while (i < leftPart.size() && j < rightPart.size()) {
        if (leftPart[i] <= rightPart[j]) {
            arr[k++] = leftPart[i++];
        } else {
            arr[k++] = rightPart[j++];
        }
    }

    // Додаємо залишки
    while (i < leftPart.size()) arr[k++] = leftPart[i++];
    while (j < rightPart.size()) arr[k++] = rightPart[j++];
}

// Рекурсивна функція сортування злиттям
void mergeSort(vector<int>& arr, int left, int right) {
    if (left >= right) return; // База рекурсії

    int mid = left + (right - left) / 2;

    mergeSort(arr, left, mid);        // Сортуємо ліву частину
    mergeSort(arr, mid + 1, right);   // Сортуємо праву частину
    merge(arr, left, mid, right);     // Зливаємо
}

int main() {
    vector<int> arr = {38, 27, 43, 3, 9, 82, 10};

    cout << "До сортування: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    mergeSort(arr, 0, arr.size() - 1);

    cout << "Після сортування: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    return 0;
}
