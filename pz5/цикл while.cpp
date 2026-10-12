// while
#include <iostream>
using namespace std;

int main() {
    long long a, b;
    cin >> a >> b;

    while (a > b) {
        if (a % 2 == 0 && a / 2 >= b) {
            cout << ":2\n"; // выводим команду "разделить на 2"
            a /= 2;
        } else {
            cout << "-1\n"; // иначе выводим команду "вычесть 1"
            a--;
        }
    }
    return 0;
}
