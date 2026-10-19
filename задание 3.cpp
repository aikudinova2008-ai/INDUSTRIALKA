#include <iostream>
#include <string>
using namespace std;
int main() {
    int x, n;
    cin >> x >> n;
    string s = to_string(x);

    for (int step = 1; step < n; step++) {
        string next = "";
        int len = s.length();
        int i = 0;
        for (i = 0; i < len; ) {
            int j = i;
            while (j < len && s[j] == s[i]) j++;
            next += to_string(j - i);
            next += s[i];
            i = j;
        }
        s = next;
    }
    cout << s << endl;
    return 0;
}