#include <iostream>
using namespace std;
int main() {
    int n, m, w;
    cin >> n >> m >> w;
    bool grib[34][34] = {};   // с запасом

    for (int k = 0; k < w; k++) {
        int a, b; // координаты очередного гриба
        cin >> a >> b;
        grib[a][b] = true; // отмечаем, что в клетке гриб
    }

    for (int i = 1; i <= n; i++) { // идём по строкам поля
        for (int j = 1; j <= m; j++) {
            if (grib[i][j]) { // идём по строкам поля
                cout << '*';
            } else {
                int cnt = 0;
                for (int di = -1; di <= 1; di++) { // сдвиг по строке: -1, 0, +1
                    for (int dj = -1; dj <= 1; dj++) {
                        if (di == 0 && dj == 0) continue; // саму клетку не считае
                        if (grib[i + di][j + dj]) cnt++; // сосед с грибом: увеличиваем счётчик
                    }
                }
                cout << cnt;
            }
        }
        cout << endl;
    }
    return 0;
}
