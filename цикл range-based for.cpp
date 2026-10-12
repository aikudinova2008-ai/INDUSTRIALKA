// range-based for
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    long long a, b;
    cin >> a >> b;

    vector<string> commands;
    while (a > b) {
        if (a % 2 == 0 && a / 2 >= b) {
            commands.push_back(":2");
            a /= 2;
        } else {
            commands.push_back("-1");
            a--;
        }
    }

    for (const string& command : commands) {
        cout << command << '\n';
    }
    return 0;
}