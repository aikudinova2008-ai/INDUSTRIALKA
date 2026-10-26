#include <iostream>  
#include <vector>     // библиотека для vector (динамический массив)
using namespace std;
int main() {
    // отсортированные по возрастанию массива
    vector<int> A = {1, 4, 7, 10, 13};
    vector<int> B = {2, 3, 8, 12};
    // i — индекс массива A
    // j — индекс массива B
    size_t i = 0, j = 0;
    while (i < A.size() && j < B.size()) {
        if (A[i] <= B[j]) {
            // A меньше или равен B —
            cout << A[i] << ' ';
            ++i;
        } else {
            cout << B[j] << ' ';
            ++j;
        }
    }
    // если B закончился раньше, чем A
    while (i < A.size()) {
        cout << A[i] << ' ';
        ++i;
    }
    // если A закончился раньше, чем B
    while (j < B.size()) {
        cout << B[j] << ' ';
        ++j;
    }
    cout << '\n';
    return 0; 
}
