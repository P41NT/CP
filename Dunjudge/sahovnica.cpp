#include <bits/stdc++.h>

using namespace std;

int main() {
    int r, c, a, b;
    cin >> r >> c >> a >> b;

    for (int i = 1; i <= r; i++) {
        for (int l = 1; l <= a; l++) {
            for (int j = 1; j <= c; j++) {
                for (int k = 1; k <= b; k++) {
                    if ((i + j) % 2 == 0)
                        cout << "X";
                    else
                        cout << ".";
                }
            }
            cout << endl;
        }
    }
}
