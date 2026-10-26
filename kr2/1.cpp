#include <iostream>
using namespace std;

long long fastPow(long long base, int exp) { // возведение в степень
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1)        // степень нечётная 
            result *= base;
        base *= base;            // основание возводится в квадрат
        exp /= 2;                // степень уменьшается вдвое
    }
    return result;
}

int main() {
    long long base;
    int exp;
    cin >> base >> exp;
    cout << fastPow(base, exp) << endl;
    return 0;
}