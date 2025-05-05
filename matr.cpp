#include <iostream>
#include <vector>

template <typename T>
class Matrix {
private:
std::vector<std::vector<T>> data;
size_t rows, cols;

public:
 // Конструктор
Matrix(size_t rows, size_t cols, T initValue = T()) 
    : rows(rows), cols(cols), data(rows, std::vector<T>(cols, initValue)) {}

   
   
    // Оператор доступу до елементів
    T& operator()(size_t row, size_t col) {
        return data[row][col];
    }

    // Метод для виведення матриці
    void print() const {
        for (const auto& row : data) {
            for (const auto& elem : row) {
                std::cout << elem << " ";
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    Matrix<int> intMatrix(3, 3, 1);   // Матриця int заповнена 1
    Matrix<double> doubleMatrix(3, 3, 3.14);  // Матриця double заповнена 3.14

    std::cout << "Ціла матриця:\n";
    intMatrix.print();

    std::cout << "\nДробова матриця:\n";
    doubleMatrix.print();

    return 0;
}
