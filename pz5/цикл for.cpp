// for
#include <iostream>
using namespace std;

int main() {
    long long a, b; // объявляем два 64-битных целых числа
    cin >> a >> b;

    for (; a > b; ) {
        if (a % 2 == 0 && a / 2 >= b) {
            cout << ":2\n"; // выводим команду "разделить на 2"
            a /= 2;
            // иначе (нечётное или деление опасно) — вычитаем 1
        } else {
            cout << "-1\n"; // выводим команду "вычесть 1"
            a--;
        }
    }
    return 0;
}
