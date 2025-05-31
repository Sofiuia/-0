#include <iostream>
#include <fstream>
#include <filesystem>

namespace fs = std::filesystem;

int main() {
    // Створення папки
    fs::create_directory("NewFolder");

    // Перейменування папки
    fs::rename("NewFolder", "RenamedFolder");

    // Видалення папки
    fs::remove_all("RenamedFolder");

    // Створення файлу
    std::ofstream file("example.txt");
    file << "Hello, world!" << std::endl;
    file.close();

    // Перейменування файлу
    fs::rename("example.txt", "renamed_example.txt");

    // Видалення файлу
    fs::remove("renamed_example.txt");

    // Робота з потоками вводу-виводу
    std::ifstream inputFile("example.txt");
    std::string content;
    if (inputFile.is_open()) {
        while (std::getline(inputFile, content)) {
            std::cout << content << std::endl;
        }
        inputFile.close();
    }

    return 0;
}
