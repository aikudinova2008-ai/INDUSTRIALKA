#include <iostream>                                  
#include <string>                                    
using namespace std;                                 
int main() {                                         
    int x, n;                                        
    cin >> x >> n;                                   
    string s = to_string(x);                         
    int step = 1;                                    // счётчик шагов, уже есть 1-й элемент
    while (step < n) {                               
        string next = "";                            
        int len = s.length();                        
        int i = 0;                                   // позиция начала группы одинаковых цифр
        while (i < len) {                            // идём по строке до конца
            int j = i;                               
            for (; j < len && s[j] == s[i]; j++) {}  // двигаем j вправо, пока цифры одинаковые
            next += to_string(j - i);                // дописываем, сколько раз цифра повторилась
            next += s[i];                            
            i = j;                                   // переходим к началу следующей группы
        }
        s = next;                                    // новый элемент становится текущим
        step++;                                      // переходим к следующему шагу
    }
    cout << s << endl;                               
    return 0;                                        
}
