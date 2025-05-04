#include <iostream>

template <typename T>
class Repository8;

template <>
class Repository8<bool> {

private:

    uint8_t data;

public:

    Repository8() : data(0) {}

void set(size_t index, bool value) {

        if (index < 8) {
            if (value)
                data |= (1 << index);
            else
                data &= ~(1 << index);

        }
    }
bool get(size_t index) const {
        if (index < 8)
            return (data >> index) & 1;
        return false;
    }

void print() const {
        for (int i = 7; i >= 0; --i) { // Виводимо побітово
            std::cout << ((data >> i) & 1);
        }
        std::cout << std::endl;
    }
};

int main() {
    Repository8<bool> repo;
    repo.set(0, true);
    repo.set(3, true);
    repo.set(7, true);
    repo.print(); 
    return 0;
}

// Очікуваний результат: 10001001
