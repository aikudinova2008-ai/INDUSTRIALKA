#include <iostream>
#include <string>
using namespace std;

const int N = 100000;             // максимальный размер стека

struct MinStack {
    int data[N];                  // сами элементы стека
    int mins[N];                  // mins[i] = минимум среди data[0..i]
    int size = 0;                 // сколько элементов сейчас в стеке

    // добавить элемент в вершину
    void push(int x) {
        data[size] = x;
        if (size == 0 || x < mins[size - 1]) mins[size] = x;  // новый элемент меньше прежнего минимума
        else mins[size] = mins[size - 1];                     // иначе минимум не меняется
        size++;
    }

    // убрать элемент с вершины
    void pop() {
        size--;
    }

    // пустой ли стек
    bool empty() {
        return size == 0;
    }

    // элемент на вершине
    int top() {
        return data[size - 1];
    }

    // минимальный элемент всего стека
    int getMin() {
        return mins[size - 1];
    }
};

MinStack st;                      // глобальный стек (так безопаснее для памяти)

int main() {
    string cmd;
    while (cin >> cmd) {          // команды: push x, pop, top, min, empty
        if (cmd == "push") {
            int x;
            cin >> x;
            st.push(x);
        }
        else if (cmd == "pop") {
            if (st.empty()) cout << "error" << endl;
            else st.pop();
        }
        else if (cmd == "top") {
            if (st.empty()) cout << "error" << endl;
            else cout << st.top() << endl;
        }
        else if (cmd == "min") {
            if (st.empty()) cout << "error" << endl;
            else cout << st.getMin() << endl;
        }
        else if (cmd == "empty") {
            if (st.empty()) cout << "yes" << endl;
            else cout << "no" << endl;
        }
    }
    return 0;
}