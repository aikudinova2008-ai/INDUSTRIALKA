#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
    string s;
    getline(cin, s);              // читаем всю строку вместе с пробелами

    stack<char> st;               // стек для открывающих скобок
    bool ok = true;               // пока считаем, что всё правильно

    for (int i = 0; i < s.size(); i++) {
        char c = s[i];

        if (c == '(' || c == '[' || c == '{') {
            st.push(c);           // открывающую скобку кладём в стек
        }
        else if (c == ')' || c == ']' || c == '}') {
            if (st.empty()) {     // закрывающая есть, а открывающей нет
                ok = false;
                break;
            }
            char t = st.top();    // последняя открытая скобка
            st.pop();
            // проверяем, что скобки одного вида
            if ((c == ')' && t != '(') ||
                (c == ']' && t != '[') ||
                (c == '}' && t != '{')) {
                ok = false;
                break;
            }
        }
    }

    if (!st.empty()) ok = false;  // остались незакрытые скобки

    if (ok) cout << "yes";
    else cout << "no";
    return 0;
}