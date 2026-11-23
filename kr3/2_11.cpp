#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

int main() {
    ifstream in("C:\\TIP\\kr3\\employees.txt");   // входной файл
    if (!in) {
        cout << "Не удалось открыть входной файл" << endl;
        return 1;
    }

    string name, maxName;
    double salary, maxSalary = 0;
    bool found = false;                           // нашли ли хотя бы одного сотрудника

    while (in >> name >> salary) {                // читаем пары "имя зарплата"
        if (!found || salary > maxSalary) {
            maxSalary = salary;
            maxName = name;
            found = true;
        }
    }
    in.close();

    if (!found) {
        cout << "Во входном файле нет данных" << endl;
        return 1;
    }

    ofstream out("C:\\TIP\\kr3\\result.txt");     // выходной файл
    if (!out) {
        cout << "Не удалось создать выходной файл" << endl;
        return 1;
    }
    out << fixed << setprecision(2);              // зарплата с двумя знаками после точки
    out << maxName << " " << maxSalary << endl;
    out.close();

    cout << "Готово: " << maxName << " " << fixed << setprecision(2) << maxSalary << endl;
    return 0;
}