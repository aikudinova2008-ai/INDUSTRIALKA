// задание №4, вариант 11
#include <iostream>
#include <cmath>
using namespace std;

void printStudentName() {
    cout << "Кудинова Александра" << endl;
}

void printPolynomialRoots(double a, double b, double c) {
    // особый случай: 0 = 0, корнем является любое число
    if (a == 0 && b == 0 && c == 0) {
        cout << "Любое действительное число является корнем" << endl;
        return;
    }

    if (a == 0 && b == 0) {
        cout << "Корней нет" << endl;
        return;
    }

    // если a = 0, уравнение превращается в линейное bx + c = 0
    if (a == 0) {
        cout << "Линейное уравнение, корень: x = " << -c / b << endl;
        return;
    }

    double d = b * b - 4 * a * c;

    if (d < 0) {
        cout << "Действительных корней нет" << endl;
    } else if (d == 0) {
        cout << "Один корень: x = " << -b / (2 * a) << endl;
    } else {
        double x1 = (-b + sqrt(d)) / (2 * a);
        double x2 = (-b - sqrt(d)) / (2 * a);
        cout << "Два корня: x1 = " << x1 << ", x2 = " << x2 << endl;
    }
}

void checkIsoscelesTriangle() {
    double sideA, sideB, sideC;
    cout << "Введите три стороны треугольника: ";
    cin >> sideA >> sideB >> sideC;

    // треугольник существует, только если сумма любых двух сторон больше третьей
    if (sideA + sideB <= sideC ||
        sideA + sideC <= sideB ||
        sideB + sideC <= sideA) {
        cout << "Треугольник с такими сторонами не существует" << endl;
        return;
    }

    if (sideA == sideB || sideA == sideC || sideB == sideC) {
        cout << "Треугольник равнобедренный" << endl;
    } else {
        cout << "Треугольник не равнобедренный" << endl;
    }
}

int main() {
    double a, b, c;
    char mode;

    cout << "Введите коэффициенты a, b, c: ";
    cin >> a >> b >> c;

    cout << "Введите символ (K / j / s): ";
    cin >> mode;

    switch (mode) {
        case 'K': case 'k': printStudentName(); break;
        case 'j': case 'J': printPolynomialRoots(a, b, c); break;
        case 's': case 'S': checkIsoscelesTriangle(); break;
        default:
            cout << "Неизвестный символ: '" << mode << "'" << endl;
    }

    return 0;
}
