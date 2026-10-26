#include <iostream>
using namespace std;

// from — откуда, to — куда, aux — вспомогательная салфетка
void hanoi(int n, int from, int to, int aux) { //  ничего не возвращает
    if (n == 0)
        return;

    // переносим n-1 верхних ингредиентов на вспомогательную
    hanoi(n - 1, from, aux, to);

    // переносим самый большой (n-й) ингредиент на целевую
    cout << "Ingredient " << n << " move from " << from << " to " << to << endl;

    // переносим n-1 с вспомогательной на целевую
    hanoi(n - 1, aux, to, from);
}

int main() {
    int n;
    cin >> n;
    hanoi(n, 1, 3, 2);   // с 1 на 3, через 2
    return 0;
}