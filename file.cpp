#include <iostream>
#include <fstream>

int main() {
    // Відкриття файлу у режимі запису
    std::ofstream outFile("example.txt", std::ios::out);
    if (outFile.is_open()) {
        outFile << "Це тестовий запис у файл.\n";
        outFile.close();
    }

    // Відкриття файлу у режимі читання
    std::ifstream inFile("example.txt", std::ios::in);
    std::string line;
    if (inFile.is_open()) {
        while (std::getline(inFile, line)) {
            std::cout << "Прочитано з файлу: " << line << std::endl;
        }
        inFile.close();
    }

    // Робота з позицією у файлі
    std::fstream file("example.txt", std::ios::in | std::ios::out);
    if (file.is_open()) {
        file.seekp(0, std::ios::end); // Переміщення вказівника у кінець файлу
        file << "Додатковий запис у файл.\n";
        file.seekg(0, std::ios::beg); // Переміщення вказівника у початок файлу

        while (std::getline(file, line)) {
            std::cout << "Оновлений вміст файлу: " << line << std::endl;
        }
        file.close();
    }

    return 0;
}
