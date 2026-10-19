#include <iostream>
#include <string>
using namespace std;
int main() {
    int x, n;
    cin >> x >> n;
    string s = to_string(x); // первый элемент записываем как строку

    for (int step = 1; step < n; step++) { // строим следующие элементы до
        string next = ""; // сюда соберём новый элемент
        int len = s.length(); // длина текущей строки
        int i = 0;
        for (i = 0; i < len; ) { // идём по строке, i сдвигаем вручную внутри
            int j = i; // j будет концом группы
            while (j < len && s[j] == s[i]) j++; // пока цифры такие же, двигаем j вправо
            next += to_string(j - i);  // дописываем, сколько раз цифра повторилась
            next += s[i];
            i = j; // переходим к началу следующей группы
        }
        s = next; // новый элемент становится текущим
    }
    cout << s << endl;
    return 0;
}
