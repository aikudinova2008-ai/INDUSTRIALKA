#include <iostream>
using namespace std;
int main() {
    int n, m, w;
    cin >> n >> m >> w;
    bool grib[34][34] = {};   // с запасом

    for (int k = 0; k < w; k++) {
        int a, b;
        cin >> a >> b;
        grib[a][b] = true;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (grib[i][j]) {
                cout << '*';
            } else {
                int cnt = 0;
                for (int di = -1; di <= 1; di++) {
                    for (int dj = -1; dj <= 1; dj++) {
                        if (di == 0 && dj == 0) continue;
                        if (grib[i + di][j + dj]) cnt++;
                    }
                }
                cout << cnt;
            }
        }
        cout << endl;
    }
    return 0;
}
