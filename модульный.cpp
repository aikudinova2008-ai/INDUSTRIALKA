//Модульный

#include <iostream>
#include <cmath>

using namespace std;

// Модуль геометрии: работа с прямоугольным треугольником
namespace geometry {
    double findHypotenuse(double leg1, double leg2) {
        return sqrt(leg1 * leg1 + leg2 * leg2);
    }
}

// Модуль дороги: движение по кольцу длиной 109 км
namespace road {
    double findMark(double V, double T) {
        const double r = 109.0;
        double distance = V * T;
        double mark = fmod(distance, r);
        if (mark < 0) mark += r;
        return mark;
    }
}

int main() {
    // Задача 1
    double leg1, leg2;
    cout << "Задача 1. Введите длины двух катетов: ";
    cin >> leg1 >> leg2;

    double hyp = geometry::findHypotenuse(leg1, leg2);
    cout << "Длина гипотенузы: " << hyp << endl;

    // Задача 2
    double V, T;
    cout << "Задача 2. Введите скорость и время движения: ";
    cin >> V >> T;

    double mark = road::findMark(V, T);
    cout << "Положение на кольце: " << mark << endl;

    return 0;
}