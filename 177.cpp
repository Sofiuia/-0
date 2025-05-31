
#include <iostream>

// Базовий клас
class PoweredDevice
{
public:
    PoweredDevice(int power)
    {
        std::cout << "PoweredDevice: " << power << '\n';
    }
};

// Клас Scanner, який віртуально наслідує PoweredDevice
class Scanner: virtual public PoweredDevice
{
public:
    Scanner(int scanner, int power)
        : PoweredDevice(power) // Ігнорується, коли створюється Copier
    {
        std::cout << "Scanner: " << scanner << '\n';
    }
};

// Клас Printer, який також віртуально наслідує PoweredDevice
class Printer: virtual public PoweredDevice
{
public:
    Printer(int printer, int power)
        : PoweredDevice(power) // Ігнорується, коли створюється Copier
    {
        std::cout << "Printer: " << printer << '\n';
    }
};

// Клас Copier наслідує як Scanner, так і Printer
// Тому саме Copier відповідає за ініціалізацію PoweredDevice
class Copier: public Scanner, public Printer
{
public:
    Copier(int scanner, int printer, int power)
        : Scanner(scanner, power), Printer(printer, power), PoweredDevice(power)
    {
        std::cout << "Copier створено\n";
    }
};

int main()
{
    Copier copier(1, 2, 3);
    return 0;
}
