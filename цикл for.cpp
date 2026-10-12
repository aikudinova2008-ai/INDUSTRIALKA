// for
#include <iostream>
using namespace std;

int main() {
    long long a, b;
    cin >> a >> b;

    for (; a > b; ) {
        if (a % 2 == 0 && a / 2 >= b) {
            cout << ":2\n";
            a /= 2;
        } else {
            cout << "-1\n";
            a--;
        }
    }
    return 0;
}