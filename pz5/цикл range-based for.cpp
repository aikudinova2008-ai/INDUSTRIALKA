// range-based for
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    long long a, b;
    cin >> a >> b;

    vector<string> commands; // пустой динамический массив строк — сюда будем складывать команды
    while (a > b) {
        if (a % 2 == 0 && a / 2 >= b) {
            commands.push_back(":2"); // добавляем команду ":2" в конец вектора
            a /= 2;
        } else {
            commands.push_back("-1"); // иначе добавляем команду "-1"
            a--;
        }
    }
// range-based for: проходим по всем элементам вектора commands
    for (const string& command : commands) {
        cout << command << '\n'; // выводим очередную команду и перевод строки
    }
    return 0;
}
