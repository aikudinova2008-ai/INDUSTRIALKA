#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> words;             // найденные уникальные слова

// Добавляет слово в список, если его там ещё нет
void addWord(string w) {
    while (!w.empty() && w.back() == '-') w.pop_back(); // убираем дефис в конце слова
    if (w.empty()) return;
    for (int i = 0; i < words.size(); i++) {
        if (words[i] == w) return;  // такое слово уже есть
    }
    words.push_back(w);
    cout << w << endl;              // выводим слово сразу при первой встрече
}

int main() {
    string line;
    string word = "";               // слово, которое сейчас собираем

    while (getline(cin, line)) {    // читаем весь текст построчно
        for (int i = 0; i < line.size(); i++) {
            unsigned char c = line[i];

            if (c == 0xD0 || c == 0xD1) {          // русская буква (2 байта в UTF-8)
                unsigned char a = c;
                unsigned char b = line[i + 1];
                if (a == 0xD0 && b >= 0x90 && b <= 0x9F) b = b + 0x20;            // А-П -> а-п
                else if (a == 0xD0 && b >= 0xA0 && b <= 0xAF) { a = 0xD1; b = b - 0x20; } // Р-Я -> р-я
                else if (a == 0xD0 && b == 0x81) { a = 0xD1; b = 0x91; }          // Ё -> ё
                word += (char)a;
                word += (char)b;
                i++;                                // пропускаем второй байт буквы
            }
            else if (c < 128 && isalnum(c)) {      // английская буква или цифра
                word += (char)tolower(c);
            }
            else if (c == '-' && !word.empty()) {  // дефис внутри слова (всё-таки)
                word += '-';
            }
            else {                                  // пробел или знак препинания: слово закончилось
                addWord(word);
                word = "";
            }
        }
        addWord(word);                              // конец строки тоже заканчивает слово
        word = "";
    }
    return 0;
}