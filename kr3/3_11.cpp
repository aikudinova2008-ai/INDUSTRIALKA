// Работает для латиницы и кириллицы (при вводе в кодировке UTF-8).
#include <iostream>
#include <string>
using namespace std;

// Перевод строки UTF-8 в верхний регистр (ASCII + русский алфавит)
string toUpperUtf8(const string& s) {
    string r;
    r.reserve(s.size());
    for (size_t i = 0; i < s.size(); ) {
        unsigned char c = s[i];
        if (c < 0x80) {                                   // ASCII
            if (c >= 'a' && c <= 'z') c = c - 'a' + 'A';
            r += (char)c;
            i++;
        } else if ((c == 0xD0 || c == 0xD1) && i + 1 < s.size()) {
            unsigned char d = s[i + 1];
            unsigned char nc = c, nd = d;
            if (c == 0xD0 && d >= 0xB0 && d <= 0xBF) {            // а-п -> А-П
                nd = d - 0x20;
            } else if (c == 0xD1 && d >= 0x80 && d <= 0x8F) {     // р-я -> Р-Я
                nc = 0xD0; nd = d + 0x20;
            } else if (c == 0xD1 && d == 0x91) {                  // ё -> Ё
                nc = 0xD0; nd = 0x81;
            }
            r += (char)nc;
            r += (char)nd;
            i += 2;
        } else {                                          // прочие символы без изменений
            r += (char)c;
            i++;
        }
    }
    return r;
}

int main() {
    string s;
    cout << "Введите строку: ";
    getline(cin, s);
    cout << toUpperUtf8(s) << endl;
    return 0;
}