#include <iostream>
#include <string>

// Перелік можливих станів світлофора
enum class State
{
    RED,
    YELLOW,
    GREEN
};

// Клас TrafficLight
class TrafficLight
{
public:
    TrafficLight();

    // Змінює стан на вказаний
    void changeSignal(State newState);

    // Виводить поточний стан
    void currentState() const;

    // Перетворює стан у текст
    static std::string stateToString(State s);

private:
    State _currentState;
};

// Реалізація конструктора
TrafficLight::TrafficLight() : _currentState(State::RED)
{
    std::cout << "Traffic light started. Current state: RED\n";
}

// Зміна сигналу
void TrafficLight::changeSignal(State newState)
{
    if (_currentState == newState)
    {
        std::cout << "State unchanged: " << stateToString(_currentState) << "\n";
        return;
    }

    _currentState = newState;
    std::cout << "New state: " << stateToString(_currentState) << "\n";
}

// Поточний стан
void TrafficLight::currentState() const
{
    std::cout << "Current state is: " << stateToString(_currentState) << "\n";
}

// Перетворення стану в текст
std::string TrafficLight::stateToString(State s)
{
    switch (s)
    {
    case State::RED:
        return "RED";
    case State::YELLOW:
        return "YELLOW";
    case State::GREEN:
        return "GREEN";
    default:
        return "UNKNOWN";
    }
}

// === main ===
int main()
{
    TrafficLight light;

    std::cout << "\n--- Manual signal changes ---\n";

    light.changeSignal(State::YELLOW);
    light.currentState();

    light.changeSignal(State::GREEN);
    light.currentState();

    light.changeSignal(State::RED);
    light.currentState();

    light.changeSignal(State::RED); // Повторний виклик без змін

    return 0;
}
