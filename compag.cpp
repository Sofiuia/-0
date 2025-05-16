#include <iostream>
using namespace std;

// Клас, що буде використовуватися всередині інших
class Engine {
public:
    Engine() {
        cout << "Engine created\n";
    }

    void start() {
        cout << "Engine started\n";
    }
};

// 1. Композиція (об'єкт створюється всередині класу і знищується разом з ним)
class Car {
private:
    Engine engine; // Композиція: Engine є частиною Car

public:
    Car() {
        cout << "Car created\n";
    }

    void start() {
        engine.start();
        cout << "Car is ready to go\n";
    }
};

// 2. Агрегація (об'єкт передається ззовні і може існувати самостійно)
class Garage {
private:
    Engine* engine; // Агрегація: Engine існує незалежно від Garage

public:
    Garage(Engine* eng) : engine(eng) {
        cout << "Garage created\n";
    }

    void checkEngine() {
        if (engine) {
            cout << "Garage checks engine\n";
            engine->start();
        } else {
            cout << "No engine to check\n";
        }
    }
};

int main() {
    cout << "=== Композиція ===\n";
    Car car;
    car.start();

    cout << "\n=== Агрегація ===\n";
    Engine myEngine; // Об'єкт існує окремо
    Garage garage(&myEngine);
    garage.checkEngine();

    return 0;
}
