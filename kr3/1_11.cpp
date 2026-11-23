// НОК и НОД связаны формулой: НОК(a, b) · НОД(a, b) = |a · b|, значит НОК(a, b) = |a| / НОД(a, b) · |b|. НОД считается рекурсивно по алгоритму Евклида.
#include <iostream>
using namespace std;

// Рекурсивный НОД: gcd(a, 0) = a; gcd(a, b) = gcd(b, a mod b)
long long gcdRec(long long a, long long b) {
    if (b == 0) return a;
    return gcdRec(b, a % b);
}
// Для шага рекурсии используется рекурсивный gcdRec; деление до умножения
// уменьшает риск переполнения.
long long lcmRec(long long a, long long b) {
    if (a < 0) a = -a;
    if (b < 0) b = -b;
    if (a == 0 || b == 0) return 0;      // НОК(0, x) считаем равным 0
    return a / gcdRec(a, b) * b;
}

int main() {
    long long a, b;
    cout << "Введите два целых числа: ";
    if (!(cin >> a >> b)) {
        cout << "Ошибка: нужно ввести два целых числа." << endl;
        return 1;
    }
    cout << "НОК(" << a << ", " << b << ") = " << lcmRec(a, b) << endl;
    return 0;
}