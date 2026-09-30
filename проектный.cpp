//Проектный


#include <iostream>
#include <cmath>

using namespace std;

// Задача 1: гипотенуза по двум катетам
struct task1 {
    double leg1, leg2;
    void input() {
        cout << "Задача 1. Введите длины двух катетов: ";
        cin >> leg1 >> leg2;
    }
    double solve() {
        return sqrt(leg1 * leg1 + leg2 * leg2);
    }
    void output() {
        cout << "Длина гипотенузы: " << solve() << endl;
    }
};

// Задача 2: положение байкера на МКАД (длина 109 км)
struct task2 {
    double V, T;
    void input() {
        cout << "Задача 2. Введите скорость и время движения: ";
        cin >> V >> T;
    }
    double solve() {
        const double r = 109.0;
        double mark = fmod(V * T, r);
        if (mark < 0) mark += r;
        return mark;
    }
    void output() {
        cout << "Положение на кольце: " << solve() << endl;
    }
};

int main() {
    task1 first;
    first.input();
    first.output();

    task2 second;
    second.input();
    second.output();

    return 0;
}