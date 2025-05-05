#include <iostream>
#include <fstream>
#include <memory>
#include <mutex>
#include <thread>

std::mutex mtx; // М’ютекс для синхронізації доступу до ресурсів у багатопотоковому середовищі

// Клас, який демонструє основний принцип RAII
class Resource {
public:
    Resource() { std::cout << "Ресурс отримано\n"; }
    ~Resource() { std::cout << "Ресурс звільнено\n"; }
    void use() { std::cout << "Використання ресурсу\n"; }
};

// Клас для автоматичного управління файлом
class FileHandler {
private:
    std::ofstream file;
public:
    FileHandler(const std::string& filename) : file(filename) {
        if (!file) {
            std::cerr << "Не вдалося відкрити файл!\n";
        }
    }

    ~FileHandler() {
        // Автоматичне закриття файлу при виході об'єкта з області видимості
        if (file.is_open()) {
            file.close();
            std::cout << "Файл закрито\n";
        }
    }

    void write(const std::string& text) {
        if (file.is_open()) {
            file << text;
        }
    }
};

// Функція, яка використовує м’ютекс у багатопотоковому середовищі
void safeFunction() {
    std::lock_guard<std::mutex> lock(mtx); // Гарантує автоматичне розблокування `mutex` при виході з області видимості
    std::cout << "Безпечний доступ до ресурсу в багатопотоковому середовищі\n";
}

int main() {
    std::cout << "=== Динамічна пам’ять ===\n";
    {
        // Використання розумного вказівника `std::unique_ptr`
        std::unique_ptr<Resource> res = std::make_unique<Resource>();
        res->use(); // Використання ресурсу
    } // `res` автоматично звільняється після виходу з області видимості

    std::cout << "\n=== Робота з файлами ===\n";
    {
        FileHandler fileHandler("example.txt");
        fileHandler.write("Це приклад використання RAII для файлів.\n");
    } // Об’єкт `fileHandler` виходить з області видимості, і файл автоматично закривається

    std::cout << "\n=== Багатопотокове програмування ===\n";
    std::thread t1(safeFunction);
    std::thread t2(safeFunction);
    
    t1.join();
    t2.join();

    std::cout << "\n=== Завершення роботи ===\n";

    return 0;
}
