//Объектно-ориентированный

#include <iostream>
#include <cmath>

using namespace std;

// Класс прямоугольного треугольника
class Triangle {
    double leg1, leg2;          // катеты
public:
    Triangle(double leg1_, double leg2_) : leg1(leg1_), leg2(leg2_) {}

    double findHypotenuse() const {
        return sqrt(leg1 * leg1 + leg2 * leg2);
    }
};

// Класс байкера на кольцевой дороге
class Biker {
    double V, T;                // скорость и время
    static constexpr double r = 109.0;   // длина кольца
public:
    Biker(double V_, double T_) : V(V_), T(T_) {}

    double findMark() const {
        double mark = fmod(V * T, r);
        if (mark < 0) mark += r;
        return mark;
    }
};

int main() {
    // Задача 1
    double leg1, leg2;
    cout << "Задача 1. Введите длины двух катетов: ";
    cin >> leg1 >> leg2;

    Triangle tri(leg1, leg2);
    double hyp = tri.findHypotenuse();
    cout << "Длина гипотенузы: " << hyp << endl;

    // Задача 2
    double V, T;
    cout << "Задача 2. Введите скорость и время движения: ";
    cin >> V >> T;

    Biker biker(V, T);
    double mark = biker.findMark();
    cout << "Положение на кольце: " << mark << endl;

    return 0;
}