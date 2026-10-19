// Задание 3, но циклы заменены: for -> while, while -> for
#include <iostream>
#include <string>
using namespace std;
int main() {
    int x, n;
    cin >> x >> n;

    string s = to_string(x);
    int step = 1;
    while (step < n) {
        string next = "";
        int len = s.length();
        int i = 0;
        while (i < len) {
            int j = i;
            for (; j < len && s[j] == s[i]; j++) {}
            next += to_string(j - i);
            next += s[i];
            i = j;
        }
        s = next;
        step++;
    }
    cout << s << endl;
    return 0;
}
