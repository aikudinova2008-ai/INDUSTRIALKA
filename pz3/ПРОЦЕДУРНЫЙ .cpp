#include <iostream>
#include <cmath>
using namespace std;

int main() {
    // Задача 1: гипотенуза
    double a, b;
    cout << "Введите катеты a и b: ";
    cin >> a >> b;
    double c = sqrt(a * a + b * b);
    cout << "Гипотенуза: " << c << endl;

    // Задача 2: МКАД
    double v, t;
    cout << "Введите скорость v (км/ч) и время t (ч): ";
    cin >> v >> t;
    double S = 109.0;
    double pos = fmod(v * t, S);
    if (pos < 0) pos += S;
    cout << "Отметка на МКАД: " << pos << " км" << endl;

    return 0;
}