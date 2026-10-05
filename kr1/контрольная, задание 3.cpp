#include <iostream>
using namespace std;

int main() {
    double m, n;

    cout << "Введите m: ";
    cin >> m;

    cout << "Введите n: ";
    cin >> n;

    double result = -(n * n) * (12.0 * m + 15.0);
    cout << "Результат: " << result << endl;

    return 0;
}
