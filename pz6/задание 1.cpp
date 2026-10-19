#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {  // идём по строкам квадрата сверху вниз
        for (int j = 0; j < n; j++) { // идём по столбцам слева направо
            if (i + j < n - 1) { // клетка выше побочной диагонали
                cout << 0;
            } else if (i + j == n - 1) { / клетка лежит на побочной диагонали
                cout << 1;
            } else {
                cout << 2;
            }
            if (j < n - 1) cout << " ";
        }
        cout << endl;
    }
    return 0;
}
