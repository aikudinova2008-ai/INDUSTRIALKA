//Процедурный

#include <iostream>
#include <cmath>

using namespace std;

// Процедура для задачи 1: гипотенуза по двум катетам
void task1() {
    double leg1, leg2;
    cout << "Задача 1. Введите длины двух катетов: ";
    cin >> leg1 >> leg2;

    double hyp = sqrt(leg1 * leg1 + leg2 * leg2);
    cout << "Длина гипотенузы: " << hyp << endl;
}

// Процедура для задачи 2: отметка байкера на кольце
void task2() {
    double V, T;
    cout << "Задача 2. Введите скорость и время движения: ";
    cin >> V >> T;

    double distance = V * T;
    const double r = 109.0;
    double mark = fmod(distance, r);
    if (mark < 0) mark += r;

    cout << "Положение на кольце: " << mark << endl;
}

int main() {
    task1();
    task2();
    return 0;
}