#include <iostream>
using namespace std;

// НОД: если b == 0, то ответ a; иначе рекурсивно идём дальше
int gcdRecursive(int a, int b) {
    if (b == 0)
        return a;
    return gcdRecursive(b, a % b);
}

int main() {
    int a, b;
    cin >> a >> b;
    cout << gcdRecursive(a, b) << endl;
    return 0;
}